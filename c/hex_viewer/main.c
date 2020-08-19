#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include "hex_utils.h"
#include "dbg.h"


void printStringWithoutNewline(char *str) {
    uint8_t i = 0;
    while(str[i] != '\0') {
        if(str[i] == '\n') {
            printf(".");
        } else {
            printf("%c", str[i]);
        }
        i++;
    }
}

void printfData(char *filename, uint8_t columns) {

    //Open file 
    FILE *file = fopen(filename, "r");

    int i = 0;
    char ch;

    while((ch = getc(file)) != EOF) {
        if (i >= columns) {
            str[i] = '\0';                          // Add NULL at the end of string

            printStringWithoutNewline(str);
            printf("\n");
            i = 0;
        }
        printf("%.2x ", ch);
        str[i] = ch;
        i++;
    }
}
int main() {

    char *filename = "data.txt";
    char str[50];
    

    // Open file
    
    check(file, "Error opening file.") 

    // Number of characters shown on one line = columns/2
    uint8_t columns = 45;   




    return 0;

error:
    exit(1);

}