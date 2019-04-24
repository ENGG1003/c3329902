/*
 * Assignment 1: Ceaser Cipher 
 * by Trystan Auddino c3329902
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() { //Main function 
    
  
    char text[500], ch; //Maximum characters set to 500, should be enough
    int key;
    int d=1;
    int increment;
 
    
  	printf("Enter a message to encrypt/decrypt: "); //User inputs text
    gets(text); //Asks user for text, stores in "text" variable
      
    printf("Please enter key: ");
    scanf("%d", &key);
    
    printf("Please choose either encryption or decryption (1: Encrypt, 2: Decrypt)\n");
    scanf("%d", &d);
   
   
   switch(d) {
   case 1:
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
	}
	
	

	
	return 0;
}
    
   

