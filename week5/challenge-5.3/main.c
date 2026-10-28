#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *my_strdup(char *src)
{
    // TODO
    // You may *not* use the built-in strdup() for this challenge.
    char *str = malloc(strlen(src) + 1);
    strcpy(str, src);
    return str;
}

void upper_string(char *s)
{
    // TODO
    for(int i = 0; *s != '\0'; i++){
        *s = toupper(*s);
        s++;
    }
    
}

int main(void)
{
    char *orig = "And the flowers are still standing!";
    char *s = my_strdup(orig);

    printf("Original : \"%s\"\n", orig);
    printf("Duplicate: \"%s\"\n", s);

    upper_string(s);

    printf("Original : \"%s\"\n", orig);
    printf("Uppercase: \"%s\"\n", s);

    // TODO
    free(s);
}