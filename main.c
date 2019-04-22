/*
 * Assignment 1: Ceaser Cipher 
 * by Trystan Auddino c3329902
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void inputCipher(char* text, int key); // Defining the function for taking user input, taking in text and key value

int main(void) { //main function 
    
    int key = 1; 
    char text[500]; //Maximum characters set to 500, should be enough
    
    printf("Input text: "); //User inputs text
   
    fgets(text, sizeof(text), stdin); //Asks user for text, stores in "text" veriable
    
    inputCipher(char* text, int key)
}

void inputCipher(char* text, int key) {
    
    int input = 0;
    char newValue;
    char value;
    
    while(text[input] != '\0' && strlen(text)-1 > input){
        value = ((int)text[input] -97 + key) % 26 + 97;  //returns the character as a number, ( The -97 is counteract the ASCII values and start from 0)
        newValue = (char)(value);
        
        printf("\n %c", value);
    }
    return 0;
}
