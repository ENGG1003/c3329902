/*
 * Assignment 1: Ceaser Cipher 
 * by Trystan Auddino c3329902
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100 

int main() { //Main function 
    
  
    char text[500], ch; //Maximum characters set to 500, should be enough
    int key; //This key determines how many letters the rotation cipher will move
    int d=0; //For switch statement
    int increment; //Used in for loop as counter
 
    
  	printf("Enter a message to encrypt/decrypt: "); //User inputs text
    fgets(text, MAX, stdin); //Asks user for text, stores in "text" variable
    
    printf("Please choose from menu:\n"); //Gives user choice of next for loop
    printf("1: Ceaser encrypt\n");
    printf("2: Ceaser decrypt\n");
    printf("3: Substitution encrypt\n");
    printf("4: Substitution decrypt\n");
    
    scanf("%d", &d); //This scans for user input, then sends either 1 or 2 to variable d which is used to pick a statement in the (switch statement) flow control
   
   
   switch(d) {
   case 1:
   
    printf("Please enter key: "); 
    scanf("%d", &key); //Standard input, scans for key off user
    
       for(increment = 0; text[increment] != '\0'; ++increment){
		ch = text[increment];
		
		if(ch >= 'a' && ch <= 'z'){
			ch = ch + key;
			
			if(ch > 'z'){
				ch = ch - 'z' + 'a' - 1;
			}
			
			text[increment] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + key;
			
			if(ch > 'Z'){
				ch = ch - 'Z' + 'A' - 1;
			}
			
			text[increment] = ch;
		}
		
	}
		printf("Encrypted message: %s", text);
            break;
            
    case 2:
    
    printf("Please enter key: "); 
    scanf("%d", &key); //Standard input, scans for key off user
	    
	for(increment = 0; text[increment] != '\0'; ++increment){
		ch = text[increment];
		
		if(ch >= 'a' && ch <= 'z'){
			ch = ch - key;
			
			if(ch < 'a'){
				ch = ch + 'z' - 'a' + 1;
			}
			
			text[increment] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch - key;
			
			if(ch < 'A'){
				ch = ch + 'Z' - 'A' + 1;
			}
			
			text[increment] = ch;
		}
	}
	
	printf("Decrypted message: %s", text);
	break;
	
	case 3:
	
	printf("well well well");
	break;
	
	case 4: 
	
	printf("hi");
	break;
	
	}
	
	

	
	return 0;
}
    
   

