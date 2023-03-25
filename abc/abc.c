
/*the program takes string input from user and returns a sortened string- 
a string without an alphabetical sequence. 
for axample 'ABCDE' into 'A-E'.
except of the alphabetical sequence- the rest of the string stays the same with no changes. 

*the program differentiating between upper and lower cases(abCde is not a sequence).
*minimum sequence is a sequence of 3 letters minimum (ab is not a sequence).
EDEN COHEN
*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>
void change_string(char str[]);
#define LENGTH 80


int main()
{
    char str[LENGTH];
    printf("please enter a sequence of letters so we can return you the shortened version: ");
    fgets(str, LENGTH,stdin);
    printf("\nstr BEFORE change %s", str);
    change_string(str);
    printf("\nstr AFTER change %s", str);
    
    
    return 0;
}


/*the func changes a string to a sortened string- without an alphabetic sequence*/
void change_string(char str[]){
    
    int currentmove = 0;
    int pointerstart = 0;
    int counter = 1;
    
    while (currentmove < (strlen(str)+1)){

        if (isalpha(str[currentmove]) && str[currentmove+1]!='\0'){/*if letter isAlpha and not the end of string*/
            if (str[currentmove]+1 == str[currentmove+1] && isalpha(str[currentmove+1] )){/*if a sequence*/
                
                counter++; /*count the sequence*/
                currentmove++; /*continue to the next letter*/
            }
            else if (counter>2){/*if its the end of a good sequence*/
                str[pointerstart] = str[currentmove-counter+1];/*define the start letter of a right sequence*/
                str[pointerstart+1] = '-'; /*the next char after end of sequence is '-'*/
                str[pointerstart+2] = str[currentmove]; /*the end is the last char detected not a sequence later*/
                currentmove++;/*continue to the next letter*/
                pointerstart = pointerstart+3;/*define a new potential sequence*/
                /*str[pointerstart] = str[currentmove];*/
                counter = 1;
            }
            else{
                if (str[currentmove-1]+1 == str[currentmove]){/*to evoid overwriting the first letter in a sequence of two letters.*/
                    str[pointerstart] = str[currentmove-1];/*define first letter*/
                    pointerstart = pointerstart+1;
                    str[pointerstart] = str[currentmove];/*define second letter*/
                    currentmove++;
                    pointerstart = pointerstart+1;
                    counter = 1;
                }else{
                    str[pointerstart] = str[currentmove];/*define the letter not in a sequence to the right place in the string*/
                    currentmove++;
                    pointerstart = pointerstart+1;
                    counter = 1;
                }
            }
        }
        
        else{/*if its not a potential sequence- move next*/
            str[pointerstart] = str[currentmove];
            pointerstart++;
            currentmove++;
            counter = 1;
            
        }
    
    }
    str[currentmove] = '\0';/*define the end of the string*/
}



