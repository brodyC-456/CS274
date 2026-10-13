#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * Collapse spaces in a string. Assumes the passed-in string is mutable.
 *
 * Returns a pointer to the collapsed string.
 */
char *collapse(char *s)
{
    char *src = s;
    char *dest = s;
    int first_space = 0;
    int add_space = 0;
    int done = 0;
   


    while(!done){
        switch (*src){
            // Spaces
            case ' ':
                // If this is our first space, toggle booleans so we know to add a space next time we see a letter
                if(first_space){
                    add_space = 1;
                    first_space = 0;
                }
                // If not, walk source
                src++;
                break;
            // End of string
            case '\0':
                // Put a null pointer at dest and exit loop
                *dest = *src;
                done = 1;
                break;
            // All characters
            default:
                // If this is the start of a new word, we need to add a space
                if(add_space){
                    *dest = ' ';
                    dest++;
                    add_space = 0;
                }
                // Copy source into destination
                *dest = *src;
                // Walk both pointers forward 1
                dest++;
                src++;
                // Set first_space to true so we know when the next space happens
                first_space = 1;
                break;
        }
    }

    return s;
    
}

// -----------------------------------
// Please don't modify below this line
// -----------------------------------

/**
 * Run an individual test.
 */
void test(char *input, char *expected)
{
    char sa[128];
    char *red = "\033[1;91m"; // ANSI escape sequences
    char *green = "\033[1;92m";
    char *reset = "\033[0m";

    // Can't mutate string literals, so we copy to an array
    strncpy(sa, input, sizeof sa);

    char *result = collapse(sa);

    if (strcmp(result, expected) != 0)
        printf("%sFAIL%s: \"%s\" -> \"%s\"\n", red, reset, input, result);
    else
        printf("%sPASS%s: \"%s\" -> \"%s\"\n", green, reset, input, result);
}

/**
 * Main--run a bunch of tests.
 */
int main(void)
{
    char *teststr[][2] = {
        {"hi   ", "hi"},
        {"    hi", "hi"},
        {"        hi   ", "hi"},
        {"hi   there", "hi there"},
        {"  hi   there", "hi there"},
        {"hi   there   ", "hi there"},
        {"  hi   there   ", "hi there"},
        {"  hi   there     again   ", "hi there again"},
        {" a b       c d      ef   g", "a b c d ef g"},
        {"a", "a"},
        {"     ", ""},
        {"", ""},
        {NULL, NULL}
    };

    for (char *(*p)[2] = teststr; (*p)[0] != NULL; p++)
        test((*p)[0], (*p)[1]);
}