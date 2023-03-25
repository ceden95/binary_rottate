
#include <stdio.h>
#include <string.h>
#include <stdlib.h>/*for exit*/
#define LENGTH 512
int my_bcmp (const void *b1, const void *b2, int len);
void input_validation(float a, int b);
void len_validation(char str[], int len, int index);
void index_validation(char str[], int i, int x);

/*the program compares 2 sections in the string and returns 0 if the sections are equall, else - 1.
the sections are determined by the input from the user-
the 2 start index of the sections
and the length of the sections to compare
EDEN COHEN*/

int main()
{
    char str[LENGTH]= {0};
    float a;/*for input validation*/
    int isNumber;/*to indicate if the typed input is not a number*/
    int index1, index2, len;
    int answer;
    char *b1, *b2;
    char temp;/*temp statement to clear buffer in order to get a string with spacebar and tab keys*/

    /*length input*/
    printf("\ntype in the length to compare in the string: ");
    isNumber = scanf("%f", &a);
    input_validation(a, isNumber);/*program stops if the input is wrong*/
    len=(int)a;

    /*first index input*/
    printf("\ntype in index 1: ");
    isNumber = scanf("%f", &a); 
    input_validation(a, isNumber);
    index1=(int)a;

    /*second index input*/
    printf("\ntype index 2: ");
    isNumber  = scanf("%f", &a); 
    input_validation(a, isNumber);
    index2=(int)a;
 
    /*string input*/
    printf("\nwrite a sentence: ");
    scanf("%c",&temp); /*temp statement to clear buffer*/
    fgets(str, LENGTH, stdin);/*gets a string with spacebar and tab*/
    str[strlen(str)-1] = '\0';
   
    printf("\n\nthe string you typed is: %s\nthe length you chose to copmare is: %d\nfrom index: %d\nand from index: %d\n", str, len, index1, index2);
   
    index_validation(str, index1, 1);
    index_validation(str, index2, 2);   
    len_validation(str, len, index1);
    len_validation(str, len, index2);

    b1= str+(index1-1);
    b2= str+(index2-1);
    answer = my_bcmp(b1 ,b2 , len);
    printf("the answer is: %d, ", answer);
    if(!answer){
	printf("which means sections are equal\n");
    }else{
	printf("which means sections are not equal\n");	
    }

    return 0;
}


/*compare the sections and return 0 if sections are equal.*/
int my_bcmp (const void *b1, const void *b2, int len){
    
    int i;
    
    for (i=0; i<len; i++){
        if ((*(char*)b1-*(char*)b2) == 0){
            *(char*)b1 += 1;
            *(char*)b2 += 1;
        }else{
            return 1;
        }
        
    }
    return 0;
}

/*stops the program if the input from user is demical or negative number or if its not a number
a is the input from the user
b is 0 if the input is not a number*/
void input_validation(float a, int b){
    if (b == 0){
        printf("\nyou didnt typed a number, try next time\n");
        exit(1);
    }
    if (a<0){
        printf("\nyou have to type a positive number, try next time\n");
        exit(1);
    }
    if (a-(int)a != 0){
        printf("\nyou typed a decimal number. you have to type an integer, try next time\n");
        exit(1);
    }
}

/*stops the program if the input from user is out of string limits*/
void index_validation(char str[], int i, int x){
    if (strlen(str) < i){
    printf("\nindex %d is out of your string limit. next time make sure index is in the string boubderies.\n", x);
    exit(1);
    }
}

/*stops the program if the length needed to compare is out of string boundaries*/
void len_validation(char str[], int len, int index){
    if (strlen(str) < (index+len-1)){
        printf("\nyour compared section is out of your string limit. next time make sure your length to compare from the index you chose is in the string boubderies.\n");
        exit(1);
    }
    
}

