#include "methods.h"

int main() {
    FILE *fp = fopen(FILENAME, "r");
    FILE *fpp = fopen("decrypted.txt", "w");

    decrypt(fp);

    // prompt user input
    printf("Password for file: ");
    scanText(password, 3);

}