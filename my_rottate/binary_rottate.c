/*the program roteate the bit in an unsigned int X times from the user's input
it prints the decimal, hexadecimal, octal and binary number on screen BEFORE and AFTER change.
the number the program gets from input- changes it to an unsigned number!*/
/*EDEN COHEN*/

#include <stdio.h>
unsigned int my_rottate(unsigned int a, int b);
void decToBin(unsigned n);


int main()
{   
    unsigned int num;
    int r;
    unsigned int rotatedNumber;
    
    /*scan input from user*/
    printf("please enter a number and we will rotate it as many times you'll choose: ");
    scanf("%u", &num);
    printf("now enter a number of times to rotate: ");
    scanf("%d", &r);
    printf("\nyou chose the rottate %d times the number %u", r,num);
    /*print all the bases before change*/
    printf("\n\nthe decimal number you chose is: %u", num);
    printf("\nthe hexadecimal number is: %X", num);
    printf("\nthe octal number is: %o" , num);
    printf("\n\nthe binary number you chose is: ");
    decToBin(num);
    /*print all the bases after change*/
    printf("\nthe binary number after rotate: ");
    rotatedNumber = my_rottate(num, r);
    decToBin(rotatedNumber);
    printf("\n\nthe decimal number after the rotate is: %u", rotatedNumber);
    printf("\nthe  hexadecimal number after rottate is: %X", rotatedNumber);
    printf("\nthe octal number after rotatte is: %o\n" , rotatedNumber);

    return 0;
}

/*convert(print) decimal number to binary depends on the number of bytes */
void decToBin(unsigned n){
    
    unsigned i;
    for (i = 1 << ((sizeof(int)*8)-1); i > 0; i = i / 2){
        (n & i) ? printf("1") : printf("0");
    }
}

unsigned int my_rottate(unsigned int a, int b){
    
    int i;
    int unsigned leftbit = 1<<((sizeof(int)*8)-1);/*left bit 1, all other 0, depends on number of bytes*/
    int rightbit = 1;/*right bit 1, all other 0*/
    
    if (0 <= b){/*rotate right*/
        for (i=0; i < b; i++){ /*number of times to rotate*/
            if ((a&rightbit) == rightbit){/*if the right bit is one*/
                a = a>>1;
                a = a | leftbit;/*add 1 to left bit*/
            }else{
                a = a>>1;/*the bit is 0 and just rotate right*/
            }
            
        }
    }else{/*rotate left*/
        for (i=0; b < i; i--){
            if ((a&leftbit) == leftbit){
                a = a<<1;
                a = a | rightbit;
            }else{
                a = a<<1;
            }
        }
        
        
    }
    return a;
    
}
