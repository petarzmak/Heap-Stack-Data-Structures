#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stringStack.c" //remove this when done done

extern char *  pop();
extern void push(char *);
extern int isEmpty();

int main(int argc, char * argv[])
{
  int ch;
  char previous = '0';
  char previousTwo;
  char k = '`';
  char check[50];
  char idents[100];
  int i = 0;
 
  while ((ch = getchar()) != EOF) {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;
    //
    
	
    if (previous == '<' && isalpha(ch)){
		
		/*while (ch != '>'){
			if(getchar() == '<'){
				printf("Invalid Syntax");
				exit(1);
			} else
				break;
		}
		
		char idents[50];		
		idents[i] = ch;
		
    	push(&idents[i]);*/
    	
    	push(&k);
    	
    	while (ch != '>'){
			if(ch == '<'){
				printf("Invalid Syntax");
				exit(1);
			} else{
				idents[i] = ch;
				push(&idents[i]);
				i++;
				ch = getchar();
			}
				
		}
    	push(&k);
    } else if(previous == '/' && isalpha(ch) && previousTwo == '<' && isEmpty() == 0){
		
		//printf("\n");
		/*while (ch != '>'){
			char k = getchar();
			if(k == '\n' || k == '<'){
				printf("Invalid Syntax");
				exit(1);
			} else
				break;
		}
    	identity = ch;
    
    	if(identity != *pop()){
    		printf("Error\n");
    	    exit(1);
    	}*/
    	int k = 0;
    	char h = 'a';
    	pop();
    	while (h != '`'){
			h = *pop();
			if (h != '`'){
				check[k] = h;
				k++;
			}	
		}
		k--;
		
    	while (ch != '>'){
			if (check[k] != ch){
				printf("Tags do not match error");
				exit(1);
			}
			ch = getchar();
			k--;
		}
		
    }    
		previousTwo = previous;
		previous = ch;
		
    }
    if (isEmpty() == 1){
		printf("No Errors\n");
		exit(0);
	}else{
		printf("Error");
		exit(1);
	}

}
