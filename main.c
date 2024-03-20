#include <stdio.h>
#include <string.h>
#include "sha256.h"

void print_hash(BYTE hash[]) {
    for (int i = 0; i < SHA256_BLOCK_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

void hash_string(char *inputString) {
    SHA256_CTX ctx;
    BYTE hash[SHA256_BLOCK_SIZE];

    sha256_init(&ctx);
    sha256_update(&ctx, (BYTE*)inputString, strlen(inputString));
    sha256_final(&ctx, hash);
    print_hash(hash);
}

int main() {
    // Array of strings to hash
    char *stringsToHash[] = {
        "Hello, world!",
        "Analizar algoritmos esta bien cool",
        "Hello, world!",
        NULL // Marks the end of the array
    };

    for (int i = 0; stringsToHash[i] != NULL; i++) {
        printf("Hashing: %s\nHash: ", stringsToHash[i]);
        hash_string(stringsToHash[i]);
        printf("\n");
    }

    return 0;
}
