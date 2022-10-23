#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAXLENGTH 1000
#define CODE_MAXLENGTH 100
#define PWD_MAXLENGTH 100
#define USABLE_CHARS 254
#define EXTRANEOUS 50
#define FILENAME "output.ecf"

unsigned char string[STR_MAXLENGTH];
unsigned char code[CODE_MAXLENGTH];
unsigned char password[PWD_MAXLENGTH];
unsigned char temp[STR_MAXLENGTH];
unsigned char transformed[USABLE_CHARS];
int is_transformed = 0;

unsigned char result[STR_MAXLENGTH + PWD_MAXLENGTH + CODE_MAXLENGTH + 2];

// Cleans temp.
void cleanTemp() {
    for (int i=0; i<STR_MAXLENGTH; i++) {
        temp[i] = 0;
    }
}

// Allows you to scan properly to give way for other inputs.
void scanText(unsigned char stringArray[], int size_type) {
    
    // determine size
    int size=0;
    if (size_type == 1) size = STR_MAXLENGTH;
        else if (size_type == 2) size = CODE_MAXLENGTH;
        else size = PWD_MAXLENGTH; 
        
    // get string
    fgets(stringArray, size, stdin);
}

// Transforms array using code.
void transformArray() {

    // compute sum
    int sum = 0;
    for (int i=0; i<strlen((char*)code); i++) {
        sum += code[i]*(i+1);
    }

    // initialize tranformed array
    int factor = sum % USABLE_CHARS;
    for (int i=0; i<USABLE_CHARS; i++) {
        if (factor+i < USABLE_CHARS) transformed[i] = factor+i;
            else transformed[i] = factor-i;        
    }

    is_transformed = 1;
}


// // Decrypts input file to result
// void decrypt(FILE *fp) {

//     // 1. load strings to appropriate arrays
//     int i=0, code_done=0, pwd_done=0;
//     unsigned char ascii_cmp=0;    
//     while (fp != EOF && i<(STR_MAXLENGTH + PWD_MAXLENGTH + CODE_MAXLENGTH + 2)) {
//         character = fgetc(fp);
        
//         // place to code[] array if it is for the code.
//         if (!code_done) {
//             if (ascii_cmp+1 == 256) ascii_cmp = 0;
//             if (character == ascii_cmp) code_done = 1;
//                 else result[i++] = character;

//         // place to password[] array if it is for the password.
//         } else if (!pwd_done) {
//             if (ascii_cmp+2 == 256) ascii_cmp = 0;
//             if (character == ascii_cmp) pwd_done = 1;
//                 else result[i++] = character;

//         // else, it is a for the string. Place to string[]
//         } else {
//             result[i++] = character
//         };
        
//     }

//     // 2. Decrypt using 

// }