#include "methods.h"

// Encrypts text given an unsigned character array.
unsigned char *encrypt(unsigned char stringArray[]) {
    transformArray();

    // encrypt
    for (int i=0; i<strlen(stringArray); i++) {
        temp[i] = transformed[stringArray[i]];
    }

    return temp;
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
    unsigned char splitter[] = ">";
    strncat(result, encrypt(code), strlen(code));   cleanTemp();
    strncat(result, splitter, 1);
    strncat(result, encrypt(password), strlen(password));   cleanTemp();
    strncat(result, splitter, 1);
    strncat(result, encrypt(string), strlen(string));   cleanTemp();

    
    // file print
    fprintf(fp, "%s", result);
    
    // show
    printf("\nSuccessfully saved to destination.");
}