#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @file super_assert.h
 * @brief Enhanced assert macro with configurable behavior.
 * 
 * Configuration macros:
 * - NDEBUG: If defined, super_assert does nothing (standard behavior)
 * - SUPER_ASSERT_TRACE: If defined to 1, prints messages even for passing assertions
 * - SUPER_ASSERT_PERMISSIVE: If defined to 1, prints warnings instead of aborting on failure
 * - SUPER_ASSERT_VERBOSE: If defined to 1, prints file, line, and function information
 */

#define BASENAME(file) (strrchr(file, '/') ? strrchr(file, '/') + 1 : \
                       (strrchr(file, '\\') ? strrchr(file, '\\') + 1 : file))

#ifdef NDEBUG
    #define super_assert(condition, message) ((void)0)
#else
    #ifndef SUPER_ASSERT_TRACE
        #define SUPER_ASSERT_TRACE 0
    #endif
    
    #ifndef SUPER_ASSERT_PERMISSIVE
        #define SUPER_ASSERT_PERMISSIVE 0
    #endif
    
    #ifndef SUPER_ASSERT_VERBOSE
        #define SUPER_ASSERT_VERBOSE 0
    #endif
    
    #if SUPER_ASSERT_VERBOSE
        #define LOCATION_PREFIX() \
            fprintf(stderr, "[%s:%d:%s] ", BASENAME(__FILE__), __LINE__, __func__)
    #else
        #define LOCATION_PREFIX() ((void)0)
    #endif
    
    #define super_assert(condition, message) \
        do { \
            if (!(condition)) { \
                LOCATION_PREFIX(); \
                fprintf(stderr, "Assertion failed: %s\n", message); \
                if (!SUPER_ASSERT_PERMISSIVE) { \
                    fprintf(stderr, "Aborting...\n"); \
                    abort(); \
                } else { \
                    fprintf(stderr, "Warning: Continuing execution despite failure\n"); \
                } \
            } else if (SUPER_ASSERT_TRACE) { \
                LOCATION_PREFIX(); \
                fprintf(stderr, "Assertion passed: %s\n", message); \
            } \
        } while (0)
#endif

