/*
Kevin Irace
February 13, 2015
Computer Systems: Tues & Thurs @ 1:30pm
Prof. Signorile

Assignment2: Part D
 
 Finds all instances of the pattern GCAG

*/



#include <stdio.h>
#include <stdlib.h>

void getArray(char **t);
int  findMatch(char *line, char *index);
void printIt(char *ptr);
enum Statetype {START,G,GC,GCA,GCAG,SLASH,END};
int num;

int main(){
	char *text; //pointers for the characters you will read
	int num1;
	getArray(&text);
	num1 = findMatch(text, text);
	if(num == 0){
		printf("NO MATCH FOUND.\n");		
}
	else{
		printf("%i Match(es) Found!!!!\n", num1);
		
	}
}

void getArray(char **t){
	char b;
	char *k;
	int i = 0;

	k = (char *)malloc(sizeof(char));
	printf("Enter your characters on one line, then hit 'enter': \n");
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

int findMatch(char *line, char *index){
	int i=0;
	num = 0;
	char *a, *b;
	a = line;
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
			 num++;
			 i--;
			 state = START;
		 }
        	 else{
        		state = START;
		 }
       	 	 break;
	}
    	i++;
	}
 return num;
}
