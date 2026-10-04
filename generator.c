#include "generator.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// define char arrays for each complexity modifier
char uppercase_chars[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char lowercase_chars[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char numbers_chars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char symbols_chars[] = {'!', '@', '#', '$', '%', '&', '+', '-', '?', '_'};

// password generation function
int pass_gen(char *buffer, size_t length, pass_options options) {

    char pool[256]; // pool array on stack, enough for maximum possible chars
    int pool_size = 0; // counts how many chars are added to pool

    // input validation, reject if length exceeds max
    if (length > MAX_PASSWORD_LENGTH) {
        return -1;  
    }

    // input validation, reject if no modifier is enabled
    if (!options.use_uppercase && !options.use_lowercase && !options.use_numbers && !options.use_symbols) {
        return -1;
    }

    // build pools by copying all chars from enabled modifiers arrays
    if (options.use_uppercase == true) {
        for (int i = 0; i < 26; i++) {
            pool[pool_size + i] = uppercase_chars[i];
        }
        pool_size += 26;
    }

    if (options.use_lowercase == true) {
        for (int i = 0; i < 26; i++) {
            pool[pool_size + i] = lowercase_chars[i];
        }
        pool_size += 26;
    }

    if (options.use_numbers == true) {
        for (int i = 0; i < 10; i++) {
            pool[pool_size + i] = numbers_chars[i];
        }
        pool_size += 10;
    }

    if (options.use_symbols == true) {
        for (int i = 0; i < 10; i++) {
            pool[pool_size + i] = symbols_chars[i];
        }
        pool_size += 10;
    }

    // randomly select chars from pool, loops selected length times
    for (int i = 0; i < length; i++) {
        int idx = rand() % pool_size;
        buffer[i] = pool[idx];
    }

    buffer[length] = '\0'; // null terminator addition
    return 0; // confirm successful generation

}
