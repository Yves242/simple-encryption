#include "methods.h"

// Encrypts text given an unsigned character array. Appends to result[].
void encrypt(unsigned char stringArray[], int isCode) {

    // if it is for encrypting code
    if (isCode) {

        // compute first character for temp[0]
        int sum = 0;
        for (int i=0; i<strlen((char*)stringArray); i++) {
            sum += code[i]*(i+1);
        }
        char ascii_cmp = sum % USABLE_CHARS;

        // assign temp[0] and others to temp
        int i=0;
        result[i++] = ascii_cmp;
        transformArray();
        while (i<CODE_MAXLENGTH) {
            result[i++] = transformed[USABLE_CHARS - EXTRANEOUS - 1 + (rand()%50)];
        }

    // if it is for encrypting password or string
    } else {
        if (!is_transformed) transformArray();
        int result_index = strlen((char*)result)-1;
        for (int i=0; i<strlen((char*)stringArray); i++) {
            result[result_index+i] = transformed[stringArray[i]];
        }
    }
};

int main() {
    FILE *fp = fopen(FILENAME, "w");

    // prompt user input
    printf("Encrypt text: ");
    scanText(string, 1);
    printf("Using code: ");
    scanText(code, 2);
    printf("Using password: ");
    scanText(password, 3);
    
    //encrypt
    encrypt(code, 1);

    unsigned char splitter[2];
    if (transformed[USABLE_CHARS-1] == 255) splitter[0] = 0;
        else splitter[0] = transformed[USABLE_CHARS-1];
    if (transformed[USABLE_CHARS-2] == 255) splitter[1] = 0;
        else splitter[1] = transformed[USABLE_CHARS-2];
    
    result[strlen((char*)result)+1] = splitter[0];

    encrypt(password, 0);
    
    result[strlen((char*)result)+1] = splitter[1];

    encrypt(string, 0);

    // file print
    fprintf(fp, "%s", result);
    
    // show
    printf("\nSuccessfully saved to destination.");
}