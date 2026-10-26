#include <stdio.h>


int add(int x, int y)
{
    return x + y;
}

int main(void)
{
    printf("1 + 2 = %d\n", add(1, 2));
}

// Question: What do you conclude must be present in <stdio.h>

    // stdio.h must include a definition of puts somewhere.