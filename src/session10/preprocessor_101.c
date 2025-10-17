#include <stdio.h>
#include <stdlib.h>
#include "session10/welcome.h"

/**
 * @brief Exercise 5.1: Preprocessor 101
 * 
 * This program demonstrates conditional compilation using the preprocessor.
 * The welcome message is selected at compile time based on the LANGUAGE macro.
 */
int main(void)
{
    const char *msg = get_welcome_msg();
    printf("%s\n", msg);
    
    printf("\nCompiled on: %s at %s\n", __DATE__, __TIME__);
    
    #ifdef LANGUAGE
        printf("Language configuration: defined\n");
    #else
        printf("Language configuration: using default\n");
    #endif
    
    return EXIT_SUCCESS;
}

