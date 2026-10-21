#include <stdio.h>
#include <stdlib.h>

void read_file(char *filename)
{
    // TODO
    FILE *f = fopen(filename, "r");
    if(f == NULL){
        puts("error opening file");
        return;
    }
    
    char line[200];
    while(fgets(line, 200, f) != NULL){
        printf("%s", line);
    }
}

void write_file(char *filename, char *data)
{
    
    FILE *f = fopen(filename, "w");
    if(f == NULL){
        puts("error opening file");
        return;
    }
    fprintf(f, "------ BEGIN ------\n %s \n ------ END ------\n", data);
    fclose(f);

}

void usage(char *cmd)
{
    fprintf(stderr, "usage: %s r filename | w filename \"data\"\n", cmd);
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc == 1) usage(argv[0]);

    switch (argv[1][0]) {
    case 'r':
        if (argc != 3) usage(argv[0]);
        read_file(argv[2]);
        break;

    case 'w':
        if (argc != 4) usage(argv[0]);
        write_file(argv[2], argv[3]);
        break;

    default: usage(argv[0]);
    }
}