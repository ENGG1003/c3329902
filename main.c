/*
 * Assignment 1: Ceaser/Substitution Cipher/Decrypt
 * by Trystan Auddino c3329902
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100 



char text[500], ch; //Maximum characters set to 500, should be enough
    int key; //This key determines how many letters the rotation cipher will move
    int d=0; //For switch statement
    int increment = 0; //Used in loop as counter variable
    char alternatealpha[26] = {'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A'}; 
    //This is our alternate alphabet, A goes to Z, B goes to Y etc.



char* encrypt(char *text,char alternatealpha[]){
  int length = strlen(text);
  char *entext = (char *) malloc(sizeof(char)*length);

  for(int increment = 0; increment < length; increment++){
    int enindex = toupper(text[increment]) - 'A'; //toupper is used as assesment requires only uppercase output
    if(enindex >= 0 && enindex < 26){ //if inside of 26 letter alternate alphabet
      entext[increment] = alternatealpha[enindex];
    }else{
      entext[increment] = text[increment];
    }
  }
  return entext; //This function returns the encrypted text
}



int main() { //Main function 
    
  	printf("Enter a message to encrypt/decrypt: "); //User inputs text
    fgets(text, MAX, stdin); //Asks user for text, stores in "text" variable
    
    printf("Please choose from menu:\n"); //Gives user choice of next for loop
    printf("1: Ceaser encrypt\n");
    printf("2: Ceaser decrypt\n");
    printf("3: Run Substitution encrypt/decrypt equation\n");
    printf("4: Run brute force Ceaser decrypt equation\n");
      
    scanf("%d", &d); //This scans for user input, then sends either 1 or 2 to variable d which is used to pick a statement in the (switch statement) flow control
   
   
   switch(d) {
       
       
       
        case 1: {//Ceaser encrypt
   
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
        }
            
            
        case 2: {// Ceaser decrypt
    
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
        }
    
    
    
        case 3: {//Substitution encrypt/decrypt

            char *finalenmessage = encrypt(text,alternatealpha);
            printf("Encrypted/decrypted message: %s\n",finalenmessage);

  
	        break;
	       }
	
	
	
        case 4: {//Brute force Ceaser
	        key=0;
	        printf("Possible messages for the input: ");
            while(key <= 25){
        
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
		
		        printf("%s", text);
		
        
	        } key++;
		        }
		
	        break;
	
        }
    return 0;
    }
}
   

