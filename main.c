#include <stdio.h>
#include <stdbool.h>

int main(void){

    int pass_length = 0;

    // password complexity modifiers
    bool use_uppercase = true;
    bool use_lowercase = true;
    bool use_numbers = true;
    bool use_symbols = true;

    printf("password generator\n");
    printf("enter password length: ");
    scanf("%d", &pass_length); // read user input, store it in pass_length memory address

    printf("generating password of %d characters...\n", pass_length);

    return 0;

}
