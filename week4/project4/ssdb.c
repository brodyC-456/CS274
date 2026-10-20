#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Information about each starship
 */
struct starship {
    char name[128];
    int passengers;
    float speed; // 1.0 = speed of light
    char destination[128];
};

int usage(){
    puts("usage: ssdb r rec | w rec name passengers speed dest");
    return 1;
}

/**
 * Gets the size of a struct by adding up all of its fields
 */
size_t get_size(struct starship *s){
    return sizeof(s->name) + sizeof(s->passengers) + sizeof(s->speed) + sizeof(s->destination);
}

/**
 * Read a given record number into the struct.
 */
void record_read(FILE *fp, int record_num, struct starship *s){
    size_t size = get_size(s);
    size_t offset = size * record_num;
    fseek(fp, offset, SEEK_SET);

    size_t read = fread(s, size, 1, fp);

    if(read == 0){
        puts("No record to read");
        return;
    }

    printf("Record %d:\n\n \tName:        %s\n \tPassengers:  %d\n \tSpeed:       %f\n \tDestination: %s\n\n", record_num, s->name, s->passengers, s->speed, s->destination);

}

/**
 * Write a given struct to the record number.
 */
void record_write(FILE *fp, int record_num, struct starship *s){
    size_t size = get_size(s);
    size_t offset = size * record_num;
    fseek(fp, offset, SEEK_SET);

    size_t write = fwrite(s, size, 1, fp);

    if(write == 0){
        puts("failed to write data");
    }

}

/**
 * Fills the struct with the arguments given by the user
 */

void fill_record(char *argv[], struct starship *s){
    strcpy(s->name, argv[3]);
    s->passengers = atoi(argv[4]);
    s->speed = atof(argv[5]);
    strcpy(s->destination, argv[6]);
}

int main(int argc, char *argv[]){

    // Declare struct and file pointer
    struct starship s;
    FILE *f = fopen("data.csv", "r+b");
    if(f == NULL){
        fopen("data.csv", "w+b");
    }

    // Need at least 2 args
    if(argc < 3){
        return usage();
    }

    // Grab the opening mode and record number
    char mode = argv[1][0];
    int record_num = atoi(argv[2]);

    // If our mode isn't r or w, print usage
    if(mode != 'r' && mode != 'w'){
        return usage();
    }

    // if we're reading, just read
    if(mode == 'r'){
        record_read(f, record_num, &s);
    }
    
    // if we're writing, fill the struct then write it
    if(mode == 'w'){
        if(argc != 7){
            return usage();
        }

        fill_record(argv, &s);  
        record_write(f, record_num, &s);
    }

    // Close the file pointer
    fclose(f);



}