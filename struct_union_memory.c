#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define char_int_double_struct
typedef struct {
    char *name;
    int age;
    double height;
} char_int_double_struct;

// Define char_double_int_struct
typedef struct {
    char *name;
    double height;
    int age;
} char_double_int_struct;

// Define int_double_char_struct
typedef struct {
    int age;
    double height;
    char *name;
} int_double_char_struct;

// Define int_char_double_struct
typedef struct {
    int age;
    char *name;
    double height;
} int_char_double_struct;

// Define double_int_char_struct
typedef struct {
    double height;
    int age;
    char *name;
} double_int_char_struct;

// Define short_int_double_struct
typedef struct {
    short int age;
    double height;
    char *name;
} short_int_double_struct;

// Define double_char_int_struct
typedef struct {
    double height;
    char *name;
    int age;
} double_char_int_struct;

// Define int_double_char_union_struct
typedef struct {
    union {
        int age;
        double height;
        char *name;
    };
} int_double_char_union;


void print_struct_sizes() {
    printf("Size of char_int_double_struct: %zu bytes (char* + int + double, no padding needed)\n", sizeof(char_int_double_struct));
    printf("Size of char_double_int_struct: %zu bytes (char* + double + int, padding needed for double alignment)\n", sizeof(char_double_int_struct));
    printf("\n");

    printf("Size of int_double_char_struct: %zu bytes (int + double + char*, padding needed for double alignment)\n", sizeof(int_double_char_struct));
    printf("Size of short_int_double_struct: %zu bytes (short int + double + char*, padding needed for double alignment)\n", sizeof(short_int_double_struct));
    printf("Size of int_char_double_struct: %zu bytes (int + char* + double, no padding needed)\n", sizeof(int_char_double_struct));
    printf("\n");

    printf("Size of double_int_char_struct: %zu bytes (double + int + char*, no padding needed)\n", sizeof(double_int_char_struct));
    printf("Size of double_char_int_struct: %zu bytes (double + char* + int, no padding needed)\n", sizeof(double_char_int_struct));
    printf("\n");

    printf("Size of int_double_char_union: %zu bytes\n", sizeof(int_double_char_union));
}

int main() {
    print_struct_sizes();
    return 0;
}