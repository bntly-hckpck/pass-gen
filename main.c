#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "generator.h"

int main(void){

    int pass_length = 0;
    char buffer[MAX_PASSWORD_LENGTH + 1];

    // password complexity modifiers
    bool use_uppercase = true; // A-Z letters
    bool use_lowercase = true; // a-z letters
    bool use_numbers = true; // 0-9 numbers
    bool use_symbols = true; // ! @ # $ % & + - ? _ symbols

    pass_options options; // struct instance

    // complexity modifiers passed to generator function
    options.use_uppercase = use_uppercase;
    options.use_lowercase = use_lowercase;
    options.use_numbers = use_numbers;
    options.use_symbols = use_symbols;

    printf("password generator\n");
    printf("enter password length: ");
    scanf("%d", &pass_length); // read user input, store it in pass_length memory address
    printf("generating password of %d characters...\n", pass_length);

    srand(time(NULL)); // random time-based number generator

    int result = pass_gen(buffer, pass_length, options); // call pass_gen function

    if (result == 0) { // check to see if generation successful
        printf("password: %s\n", buffer); // print generated password from buffer
    } else {
        printf("error!\n");
    }

    return 0; 

}
