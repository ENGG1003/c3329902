/*
 * Assignment 1: Ceaser Cipher 
 * by Trystan Auddino c3329902
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void inputCipher(char* text, int key); // Defining the function for taking user input, taking in text and key value

int main(void) { //Main function 
    
    int key = 1; 
    int d;
    char text[500]; //Maximum characters set to 500, should be enough
    
    int increment = 0;
    int newValue;
    char value;
    
    printf("Input text: "); //User inputs text
    fgets(text, sizeof(text), stdin); //Asks user for text, stores in "text" variable
    printf("%c", text);
    
    printf("\nPlease enter key: \t");
    scanf("%d", &key);
    
    printf("\nPlease choose following options:\n");
    printf("1 = Encrypt the text.\n");
    printf("2 = Decrypt the text.\n");
    scanf("%d", &d);
   
   
   switch(d)
   {
   case 1:
        for(increment = 0; (increment < 100 && text[increment] != '\0'); increment++)
            text[increment] = text[increment] + key; //Formula adds key to ASCII value
            printf("\nEncrypted string: %s\n", text);
            break;
   // printf("Encrypted text: ");
    
   // inputCipher(text, key); //Inserts result after printf statement
}

/*void inputCipher(char* text, int key) {
    
    int increment = 0;
    int newValue;
    char value;
    
    while(text[increment] != '\0' && strlen(text)-1 > increment){ //While variable "text" is at start, does not equal null and string length of "text" -1 is > "input" variable
        value = ((int)text[increment] -97 + key) % 26 + 97;  //Returns the character as a number, ( The -97 is counteract the ASCII values and start from 0)
        newValue = (char)(value); 
        printf("%c", value); // Print our encryted text
        increment++; //Increments the input variable 
    }*/
    
   }
