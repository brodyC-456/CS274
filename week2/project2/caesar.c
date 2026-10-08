#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/stat.h>

#define ALPHA_LENGTH 26  

/**
 * Frequencies of English letters.
 */
float freqs_english[26] = {
    0.08167f,  /* A */
    0.01492f,  /* B */
    0.02782f,  /* C */
    0.04253f,  /* D */
    0.12702f,  /* E */
    0.02228f,  /* F */
    0.02015f,  /* G */
    0.06094f,  /* H */
    0.06966f,  /* I */
    0.00153f,  /* J */
    0.00772f,  /* K */
    0.04025f,  /* L */
    0.02406f,  /* M */
    0.06749f,  /* N */
    0.07507f,  /* O */
    0.01929f,  /* P */
    0.00095f,  /* Q */
    0.05987f,  /* R */
    0.06327f,  /* S */
    0.09056f,  /* T */
    0.02758f,  /* U */
    0.00978f,  /* V */
    0.02360f,  /* W */
    0.00150f,  /* X */
    0.01974f,  /* Y */
    0.00074f,  /* Z */
};

/**
 * Read a file into memory.
 *
 * Returns a pointer to the file data. This data should be freed with
 * `free()`. `size` is an out parameter that will hold the file size.
 */
char *read_file(char *filename, int *size){
    struct stat sb;
    int total_size = 0;

    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        perror("fopen");
        return NULL;
    }

    // Get the file size
    if (fstat(fd, &sb) == -1) {
        perror("fstat");
        close(fd);
        return NULL;
    }

    // Allocate that many bytes of space
    char *data = malloc(sb.st_size);

    // Read the file into that
    int byte_count;

    while ((byte_count = read(fd, data + total_size, 4096)) > 0)
        total_size += byte_count;

    *size = total_size;

    close(fd);

    return data;
}

/* HELPERS */

/**
 * Returns an alphabetic index for a character
 */

int get_char_index(char c){
    return c - 'A';
}

/**
 * Decrypts the data with the given rotation
 */

void rotate_data(char data[], int data_size, int rot){
    for(int i = 0; i < data_size; i++){
        if(isalpha(data[i])){
            // Change the alphabetic index of the character
            int char_index = (get_char_index(data[i]) + rot) % ALPHA_LENGTH;
            // Revert it back to the char value
            data[i] = char_index + 'A';
        }
    }
}




/**
 * Performs a single rotation of the frequencies
 * Called at the end of each rotation calculation in find_rotation
 */

void get_next_rotation(float freqs[]) {
    // store the current freq of Z for later
    float last = freqs[ALPHA_LENGTH - 1];
    // rotate Z - B
    for (int i = ALPHA_LENGTH - 1; i > 0; i--) {
        freqs[i] = freqs[i - 1];
    }
    // store the prior frequency of Z in A
    freqs[0] = last;
}



/**
 * Get the letter frequencies for file data.
 */
void get_freqs(char data[], int data_size, float freqs[]){

    int num_alpha = 0;
    // Add one to each frequency when we come accross the letter
    for(int i = 0; i < data_size; i++){
        if(isalpha(data[i])){
            freqs[get_char_index(data[i])] += 1.0;
            num_alpha++;
        }
    }

    // Divide each frequency by data length for fractional freq
    for(int i = 0; i < ALPHA_LENGTH; i++){
        freqs[i] /= num_alpha;
        // printf("freq of %c: %f\n", i + 'A', freqs[i]);

    }
    
    
    
     
}

/**
 * Compare freqs to English freqs and figure out which shift gives us
 * the least error.
 */
int find_rotation(float freqs[]){
    float smallest_chi_score = 10000.0;
    int best_rotation = 0;

    // for each rotation, find the overall chi score
    // If the chi score is the best we've seen so far, then record this as the best rotation
    for(int i = 0; i < ALPHA_LENGTH; i++){
        float chi_score = 0;
        for(int j = 0; j < ALPHA_LENGTH; j++){
            float observed = freqs[j];
            float expected = freqs_english[j];
            float diff = observed - expected;
            chi_score += (diff * diff) / expected;
            
        }
        // printf("rot %d: %f\n", i, chi_score);
        if(chi_score < smallest_chi_score){
            smallest_chi_score = chi_score;
            best_rotation = i;
        }
        get_next_rotation(freqs);
    }

    // return best rotation
    // printf("%d\n", best_rotation);
    return best_rotation;


}

/**
 * Decrypt the ciphertext and print to the screen.
 */
void decrypt(char data[], int data_size, int rot){
    rotate_data(data, data_size, rot);
    printf("%s\n", data);
}

/**
 * Main.
 */
int main(int argc, char *argv[]){

    if (argc != 2) {
        fprintf(stderr, "usage: caesar filename\n");
        return 1;
    }

    char *filename = argv[1];

    int data_size, rot;
    char *data = read_file(filename, &data_size);

    if (data == NULL) {
        return 2;
    }

    float freqs[26] = {0};

    get_freqs(data, data_size, freqs);
    rot = find_rotation(freqs);
    decrypt(data, data_size, rot);

    free(data);
}
