#include "session10/welcome.h"

// Define welcome messages for different languages
#define HELLO_EN "Hello, World!"
#define HELLO_ES "¡Hola, Mundo!"
#define HELLO_FR "Bonjour, le Monde!"
#define HELLO_DE "Hallo, Welt!"

// Define language tokens for comparison
#define EN 1
#define ES 2
#define FR 3
#define DE 4

// Default language if LANGUAGE is not defined
#ifndef LANGUAGE
    #define LANGUAGE EN
#endif

const char *get_welcome_msg(void)
{
    // Use preprocessor to select the correct message at compile time
    #if LANGUAGE == EN
        return HELLO_EN;
    #elif LANGUAGE == ES
        return HELLO_ES;
    #elif LANGUAGE == FR
        return HELLO_FR;
    #elif LANGUAGE == DE
        return HELLO_DE;
    #else
        #error "Unsupported LANGUAGE value. Supported: EN, ES, FR, DE"
    #endif
}
