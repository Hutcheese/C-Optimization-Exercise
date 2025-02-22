#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>

void clear_screen() {
    // Clear the console screen
    printf("\033[H\033[J");
}

void characters() {
    char a = 'C';                   // single character         %c
    unsigned char ua = 'C';         // single character         %c
    char b[] = "haracters";         // string of characters     %s
    char *c = "haracters";          // string of characters     %s
    char d = 65;                    // ASCII value of 'A'       %c

    printf("Example of characters:\n\n");

    printf("    char a = 'C';               // Number of bytes:%d\n", sizeof(a));
    printf("        Ranges from -128 to 127\n");
    printf("    unsigned char ua = 'C';     // Number of bytes:%d\n", sizeof(ua));
    printf("        Ranges from 0 to 255\n\n");

    printf("    char b[] = \"haracters\";     // Number of bytes:%d\n", sizeof(b));
    printf("    char *c = \"haracters\";      // Number of bytes:%d\n", sizeof(&c));
    printf("        Address of b:  %p\n", (void *)b);  // prints the address of the array
    printf("        Address of &b: %p\n", (void *)&b); // prints the same address as above

    printf("        Address of c:  %p\n", (void *)c);  // prints the address of the string literal
    printf("        Address of &c: %p\n\n", (void *)&c); // prints the address of the pointer variable c

    printf("    char d = 65;                // Number of bytes:%d\n", sizeof(d));
    printf("    The ASCII value of 'A' is %d\n", d);
}

void ints_floats_and_doubles() {
    
    short s = 32767;                                    // signed short integer   %d
    unsigned short us = 65535;                          // unsigned short integer %u
    int i = 2147483647;                                 // signed integer       %d
    unsigned int ui = 4294967295;                       // unsigned integer     %u
    long int li = 9223372036854775807;                  // signed long integer %ld
    unsigned long int uli = 18446744073709551615;       // unsigned long integer %lu
    float a = 3.1415926535897932384626433832795;        // single precision float %f
    double b = 3.1415926535897932384626433832795;       // double precision float %f
    long double c = 3.1415926535897932384626433832795;  // extended precision float %Lf


    printf("Example of ints, floats and doubles:\n\n");
    printf("    short s = 32767;                                     // Number of bytes:%d\n", sizeof(s));
    printf("    unsigned short us = 65535;                           // Number of bytes:%d\n", sizeof(us));
    printf("    int i = 2147483647;                                  // Number of bytes:%d\n", sizeof(i));
    printf("    unsigned int ui = 4294967295;                        // Number of bytes:%d\n", sizeof(ui));
    printf("    long int li = 9223372036854775807;                   // Number of bytes:%d\n", sizeof(li));
    printf("    unsigned long int uli = 18446744073709551615;        // Number of bytes:%d\n\n", sizeof(uli));

    printf("    float a = 3.1415926535897932384626433832795;         // Number of bytes:%d\n", sizeof(a));
    printf("        Precision of 9 decimals:  %.9f\n", a);
    printf("    double b = 3.1415926535897932384626433832795;        // Number of bytes:%d\n", sizeof(b));
    printf("        Precision of 17 decimals: %.17lf\n", b);
    printf("    long double c = 3.1415926535897932384626433832795;   // Number of bytes:%d\n", sizeof(c));
    printf("        Precision of 21 decimals: %.21Lf\n\n", c);
}

void bools() {
    
    bool b = true; // boolean value %d
    _Bool b2 = 1;  // boolean value %d

    printf("Example of bools:\n\n");
    printf("    bool b = true; // Number of bytes:%d\n", sizeof(b));
    printf("        Ranges from 0 to 1\n");
    printf("        Value of b:  %d\n", b);
    printf("    _Bool b2 = 1;  // Number of bytes:%d\n", sizeof(b2));
    printf("        Ranges from 0 to 1\n");
    printf("        Value of b2: %d\n", b2);
}

// Function to request which topic to review
bool request_topic() {
    printf("Which topic do you want to review?\n\n");
    printf("1. Characters\n");
    printf("2. Ints, floats and doubles\n");
    printf("3. Booleans\n");
    printf("4. Exit\n\n");

    int choice;
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            characters();
            return true;
        case 2:
            ints_floats_and_doubles();
            return true;
        case 3:
            bools();
            return true;
        case 4:
            return false;
        default:
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
            return true;
    }   
}

int main() {
    bool study = true;
    
    while (study) {
        study = request_topic();
        printf("\nPress [Enter] to continue...\n");
        while(getchar() != '\n');
        getchar();  // Wait for the user to press Enter
        clear_screen();
    }
    
    printf("Exiting the program...\n");
    Sleep(1);
    clear_screen();

    return 0;
}