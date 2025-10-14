#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <plplot/plplot.h>

#define CHUNK_SIZE 8192

typedef struct
{
    char *word;
    int frequency;
} WordEntry;

static int compareString(const void *a, const void *b)
{
    const char *const *sa = a;
    const char *const *sb = b;
    return strcmp(*sa, *sb);
}

static int compareEntry(const void *a, const void *b)
{
    const WordEntry *ea = a;
    const WordEntry *eb = b;
    if (ea->frequency == eb->frequency)
    {
        return strcmp(ea->word, eb->word);
    }
    return eb->frequency - ea->frequency;
}

static char *duplicateString(const char *source)
{
    size_t length = strlen(source);
    char *copy = malloc(length + 1);
    if (!copy)
    {
        return NULL;
    }
    memcpy(copy, source, length + 1);
    return copy;
}



/**
* @brief Reads the contents of the given file into a continuous array,
* any non-alphabetic character (numbers, symbols, ...) are replaced with a space.
* @param fileName The name of the file to read
* @param contents A pointer that will be allocated by the function and
contain the contents of the book.
**/
void readBook(const char *fileName, char **contents)
{
    FILE *file = fopen(fileName, "r");
    if (!file)
    {
        *contents = NULL;
        return;
    }

    size_t capacity   = CHUNK_SIZE;
    size_t length     = 0;
    int previousSpace = 1;
    char *buffer      = malloc(capacity);

    if (!buffer)
    {
        fclose(file);
        *contents = NULL;
        return;
    }

    int ch;
    while ((ch = fgetc(file)) != EOF)
    {
        if (isalpha(ch))
        {
            if (length + 1 >= capacity)
            {
                capacity *= 2;
                char *tmp = realloc(buffer, capacity);
                if (!tmp)
                {
                    free(buffer);
                    fclose(file);
                    *contents = NULL;
                    return;
                }

                buffer = tmp;
            }

            buffer[length++] = (char)tolower(ch);
            previousSpace    = 0;
        }
        else
        {
            if (!previousSpace)
            {
                if (length + 1 >= capacity)
                {
                    capacity *= 2;
                    char *tmp = realloc(buffer, capacity);
                    if (!tmp)
                    {
                        free(buffer);
                        fclose(file);
                        *contents = NULL;
                        return;
                    }
                    buffer = tmp;
                }
                buffer[length++] = ' ';
                previousSpace    = 1;
            }
        }
    }

    if (length > 0 && buffer[length - 1] == ' ')
    {
        length--;
    }

    if (length + 1 >= capacity)
    {
        char *tmp = realloc(buffer, length + 1);
        if (!tmp)
        {
            free(buffer);
            fclose(file);
            *contents = NULL;
            return;
        }
        buffer = tmp;
        capacity = length + 1;
    }

    buffer[length] = '\0';
    fclose(file);
    *contents = buffer;
}

/**
* @brief Counts the frequency of each word in the book.
* The caller is responsible for freeing the allocated memory.
* @param book A continuous array of characters containing the book.
* @param words A pointer to an array of strings that will be allocated by the function and contain the unique words in the book.
* @param frequencies A pointer to an array of integers that will be allocated by the function and contain the frequency of each word in the book.
* @param nWords A pointer to an integer that will be set to the number of unique words in the book.
**/
void countWords(const char *book, char ***words, int **frequencies, int *nWords)
{
    *words = NULL;
    *frequencies = NULL;
    *nWords = 0;

    if (!book)
    {
        return;
    }

    size_t capacity = 1024;
    size_t count = 0;
    char **tokens = malloc(capacity * sizeof(char *));
    if (!tokens)
    {
        return;
    }

    char *copy = duplicateString(book);
    if (!copy)
    {
        free(tokens);
        return;
    }

    char *token = strtok(copy, " ");
    while (token)
    {
        if (*token)
        {
            if (count >= capacity)
            {
                capacity *= 2;
                char **tmp = realloc(tokens, capacity * sizeof(char *));
                if (!tmp)
                {
                    free(copy);
                    for (size_t i = 0; i < count; ++i)
                    {
                        free(tokens[i]);
                    }
                    free(tokens);
                    return;
                }
                tokens = tmp;
            }

            tokens[count] = duplicateString(token);
            if (!tokens[count])
            {
                free(copy);
                for (size_t i = 0; i < count; ++i)
                {
                    free(tokens[i]);
                }
                free(tokens);
                return;
            }
            ++count;
        }
        token = strtok(NULL, " ");
    }

    free(copy);

    if (count == 0)
    {
        free(tokens);
        return;
    }

    qsort(tokens, count, sizeof(char *), compareString);

    char **unique = malloc(count * sizeof(char *));
    int *freq = malloc(count * sizeof(int));
    if (!unique || !freq)
    {
        for (size_t i = 0; i < count; ++i)
        {
            free(tokens[i]);
        }
        free(tokens);
        free(unique);
        free(freq);
        return;
    }

    size_t uniqueCount = 0;
    for (size_t i = 0; i < count;)
    {
        size_t j = i + 1;
        while (j < count && strcmp(tokens[i], tokens[j]) == 0)
        {
            ++j;
        }
        unique[uniqueCount] = tokens[i];
        freq[uniqueCount]   = (int)(j - i);
        ++uniqueCount;
        for (size_t k = i + 1; k < j; ++k)
        {
            free(tokens[k]);
        }
        i = j;
    }

    free(tokens);

    char **shrunkWords = realloc(unique, uniqueCount * sizeof(char *));
    if (shrunkWords)
    {
        unique = shrunkWords;
    }

    int *shrunkFreq = realloc(freq, uniqueCount * sizeof(int));
    if (shrunkFreq)
    {
        freq = shrunkFreq;
    }

    *words = unique;
    *frequencies = freq;
    *nWords = (int)uniqueCount;
}

void writeFrequencies(const char *fileName, char **words, int *frequencies, int nWords)
{
    if (!words || !frequencies || nWords <= 0)
    {
        return;
    }

    FILE *file = fopen(fileName, "w");
    if (!file)
    {
        return;
    }

    WordEntry *entries = malloc((size_t)nWords * sizeof(WordEntry));
    if (!entries)
    {
        fclose(file);
        return;
    }

    for (int i = 0; i < nWords; ++i)
    {
        entries[i].word = words[i];
        entries[i].frequency = frequencies[i];
    }

    qsort(entries, (size_t)nWords, sizeof(WordEntry), compareEntry);

    for (int i = 0; i < nWords; ++i)
    {
        fprintf(file, "%d %d %s\n", i + 1, entries[i].frequency, entries[i].word);
    }

    free(entries);
    fclose(file);
}

void printHapax(char **words, int *frequencies, int nWords, int limit)
{
    if (!words || !frequencies || nWords <= 0)
    {
        return;
    }

    if (limit < 0)
    {
        limit = 0;
    }

    char **examples = NULL;
    if (limit > 0)
    {
        examples = malloc((size_t)limit * sizeof(char *));
        if (!examples)
        {
            limit = 0;
        }
    }

    int total = 0;
    int kept = 0;

    for (int i = 0; i < nWords; ++i)
    {
        if (frequencies[i] == 1)
        {
            ++total;
            if (kept < limit)
            {
                examples[kept++] = words[i];
            }
        }
    }

    printf("hapax legomena: %d\n", total);

    if (kept > 0)
    {
        printf("examples:");
        for (int i = 0; i < kept; ++i)
        {
            printf(" %s", examples[i]);
        }
        printf("\n");
    }
    else if (limit > 0)
    {
        printf("examples: none\n");
    }

    free(examples);
}

void plotFrequencies(const char *fileName, char **words, int *frequencies, int nWords)
{
    if (!fileName || !words || !frequencies || nWords <= 0)
    {
        return;
    }

    WordEntry *entries = malloc((size_t)nWords * sizeof(WordEntry));
    if (!entries)
    {
        return;
    }

    for (int i = 0; i < nWords; ++i)
    {
        entries[i].word = words[i];
        entries[i].frequency = frequencies[i];
    }

    qsort(entries, (size_t)nWords, sizeof(WordEntry), compareEntry);

    PLFLT *ranks = malloc((size_t)nWords * sizeof(PLFLT));
    PLFLT *values = malloc((size_t)nWords * sizeof(PLFLT));
    PLFLT *logRanks = malloc((size_t)nWords * sizeof(PLFLT));
    PLFLT *logValues = malloc((size_t)nWords * sizeof(PLFLT));
    if (!ranks || !values || !logRanks || !logValues)
    {
        free(entries);
        free(ranks);
        free(values);
        free(logRanks);
        free(logValues);
        return;
    }

    for (int i = 0; i < nWords; ++i)
    {
        ranks[i] = (PLFLT)(i + 1);
        values[i] = (PLFLT)entries[i].frequency;
        logRanks[i] = log10(ranks[i]);
        logValues[i] = log10(values[i]);
    }

    plsdev("pngcairo");
    plsfnam(fileName);
    plinit();
    PLFLT xMin = logRanks[0];
    PLFLT xMax = logRanks[nWords - 1];
    PLFLT yMin = logValues[nWords - 1];
    PLFLT yMax = logValues[0];
    plenv(xMin, xMax, yMin, yMax, 0, 0);
    pllab("log10 rank", "log10 frequency", "Zipf plot");
    plcol0(2);
    plpoin(nWords, logRanks, logValues, 2);
    plend();

    free(entries);
    free(ranks);
    free(values);
    free(logRanks);
    free(logValues);
}