/*
Kevin Irace
February 13, 2015
Computer Systems: Tues & Thurs @ 1:30pm
Prof. Signorile

Assignment2: Part A
 
 Checks for isntance of pattern GCAG in input text

*/


#include <stdio.h>
#include <stdlib.h>

void getArray(char **t);
char *findMatch(char *line, char *index);
void printIt(char *ptr);
enum Statetype {START,G,GC,GCA,GCAG,SLASH,END};
int pos;

int main(){
	char *text, *pattern; //pointers for the characters you will read

	getArray(&text);
	pattern = findMatch(text, text);
	printf("Pattern: GCAG\n");
	if(pattern == NULL){
		printf("NO MATCH FOUND.\n");		
}
	else{
		printf("A Match Has Been Found!!!!\n");
		printf("And It Starts At Location %i (starting from the left at 0)\n", pos);
		printIt(pattern);
		
	}
}

void getArray(char **t){
	char b;
	char *k;
	int i = 0;

	k = (char *)malloc(sizeof(char));
	printf("Enter your characters on one line, then hit 'enter': \n");
	printf("\n");
	printf("Input :\t");
	while(1)
    	{	
		b = getchar();
		if (b == '\n')
			break;
		*(k+i) = b;
		i++;
		k = realloc(k,i+1);
  	}
	*(k+i) = '\0';
	*t = k;
		
}

void printIt(char *ptr){
	int i = 4;	
	printf("Remaining Text:\t");
	while (*(ptr+i) != '\0'){
		printf("%c",*(ptr+i));
		i++;
	}
	printf("\n");

}

char *findMatch(char *line, char *index){
	int i=0;
	char *a;
	a = line;
	char *b;
	b = index;
  	enum Statetype state = START;
	char *match; 
  
  	while (*(b + i) != '\0'){
    	 switch (state) {
   	   case START:
       		 if (*(b+i) == 'G'){
       		   	 state = G;
			 match = b + i;
		}
       		 else
       		  	 state = START;
       	   	 break;
	   case G:
		if (*(b+i) == 'C')
			state = GC;
		else if (*(b+i) == 'G')
			state = G;
		else
			state = START;
		break;
     	   case GC:
       		 if (*(b+i) == 'A'){
         		 state = GCA;
		 }
       		 else
         		 state = START;
       	  	 break;
      	  case GCA:
       		 if (*(b+i) == 'G'){
			 pos = i-3;
			 return match;
		 }
        	 else{
        		state = START;
		 }
       	 	 break;
	}
    	i++;
	}
 return NULL;
}
