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

    
    int a = 0;
    int b = 1;
    //... c=3 etc? maybe 
    
    return 0;
}
