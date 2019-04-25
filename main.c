/*
 * Assignment 1: Ceaser Cipher 
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
    int increment; //Used in for loop as counter
    char alternatealpha[26] = {'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A'}; 
    //In this case im using a backwards alphabet





int index(char alternatealpha[],char findchar){
  for(int increment = 0 ; increment < 26; increment ++){
    if(alternatealpha[increment] == findchar){
      return increment;
    }
  }
  return -1;
}



char* encrypt(char *text,char alternatealpha[]){
  int length = strlen(text);
  char *entext = (char *) malloc(sizeof(char)*length);

  for(int increment = 0; increment < length; increment++){
    int enindex = toupper(text[increment]) - 'A'; //toupper makes any lowercase input uppercase
    if(enindex >= 0 && enindex < 26){ //if outside of
      entext[increment] = alternatealpha[enindex];
    }else{
      entext[increment] = text[increment];
    }
  }
  return entext;
}



char *decrypt(char *text,char alternatealpha[]){
  int length = strlen(text);
  char *detext = (char *) malloc(sizeof(char)*length);
  for(int increment = 0; increment <length; increment++){
    int deindex = toupper(text[increment]) - 'A';
    if(deindex >= 0 && deindex < 26){
      int codeindex = index(alternatealpha,toupper(text[increment]));
      detext[increment] = 'A' + codeindex;
    }else{
      detext[increment] = text[increment];
    }
  }
  return detext;
}





int main() { //Main function 
    
  
   
  	printf("Enter a message to encrypt/decrypt: "); //User inputs text
    fgets(text, MAX, stdin); //Asks user for text, stores in "text" variable
    
    printf("Please choose from menu:\n"); //Gives user choice of next for loop
    printf("1: Ceaser encrypt\n");
    printf("2: Ceaser decrypt\n");
    printf("3: Substitution encrypt\n");
    printf("4: Substitution decrypt\n");
    
    scanf("%d", &d); //This scans for user input, then sends either 1 or 2 to variable d which is used to pick a statement in the (switch statement) flow control
   
   
   switch(d) {
   case 1: //Ceaser encrypt
   
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
	case 3: {//Substitution encrypt
	
 
  char alternatealpha[26] = {'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A'};

  char *finalenmessage = encrypt(text,alternatealpha);
  printf("Encrypted Message: %s\n",finalenmessage);
  char *finaldemessage = decrypt(finalenmessage,alternatealpha);
  
	
	break;
	}
	
	
	case 4: {//Substitution decrypt
	
char alternatealpha[26] = {'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A'};

  char *finalenmessage = encrypt(text,alternatealpha);
  
  char *finaldemessage = decrypt(finalenmessage,alternatealpha);
  printf("Decrypted Message: %s\n",finaldemessage);

break;
	
	}
	
	

	
	return 0;
}
}
   

