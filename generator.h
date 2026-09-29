#ifndef GENERATOR_H
#define GENERATOR_H
#include <stddef.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 128

typedef struct {
    bool use_uppercase; // A-Z
    bool use_lowercase; // a-z
    bool use_numbers; // 0-9
    bool use_symbols; // special chars
} pass_options;

int pass_gen(char *buffer, size_t length, pass_options options); // random password generator

#endif
