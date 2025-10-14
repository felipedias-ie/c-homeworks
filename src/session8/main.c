#include <stdio.h>
#include <stdlib.h>

void readBook(const char *fileName, char **contents);
void countWords(const char *book, char ***words, int **frequencies, int *nWords);
void writeFrequencies(const char *fileName, char **words, int *frequencies, int nWords);
void printHapax(char **words, int *frequencies, int nWords, int limit);
void plotFrequencies(const char *fileName, char **words, int *frequencies, int nWords);

static void freeWordData(char **words, int *frequencies, int nWords)
{
    if (!words)
    {
        free(frequencies);
        return;
    }

    for (int i = 0; i < nWords; ++i)
    {
        free(words[i]);
    }

    free(words);
    free(frequencies);
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "usage: %s <book> <output> [plot.png]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *book = NULL;
    readBook(argv[1], &book);
    if (!book)
    {
        fprintf(stderr, "failed to read book from %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    char **words = NULL;
    int *frequencies = NULL;
    int nWords = 0;
    countWords(book, &words, &frequencies, &nWords);
    free(book);

    if (!words || !frequencies || nWords == 0)
    {
        freeWordData(words, frequencies, nWords);
        fprintf(stderr, "no words to process\n");
        return EXIT_FAILURE;
    }

    writeFrequencies(argv[2], words, frequencies, nWords);
    printHapax(words, frequencies, nWords, 10);

    if (argc >= 4)
    {
        plotFrequencies(argv[3], words, frequencies, nWords);
    }

    freeWordData(words, frequencies, nWords);
    return EXIT_SUCCESS;
}
