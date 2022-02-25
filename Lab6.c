#include <stdio.h>
int num = 0;
int num2 = 0;
int num3 = 0;
int bitPlace = 0;

int zeroOrOne(int num, int bitPlace);
int bitCounter(int num2);
int powerOfTwo(int num3);

int main(){

    printf("Please enter a binary number and a bit place to check\nBinary Number:");
    scanf("%d", &num);
    printf("Bit places from least significant bit:");
    scanf(" %d", &bitPlace);

    zeroOrOne(num, bitPlace );

    printf("Please enter a 32-bit binary word:");
    scanf(" %d", &num2);

    bitCounter(num2);
    

    printf("Please enter another number to check if it is a power of 2:");
    scanf(" %d", &num3);

    powerOfTwo(num3);


    return 0;
}


//verifies if the bit at the bit bitPlace away from the least sig bit in the number num is a 1 or 0
int zeroOrOne(int num, int bitPlace){
    int result = 0;
    //shifts a 1 over bitPlace number of times and bitwise ands it with a 1
    if(num & (1 << bitPlace)){
        result = 1;
    }

    printf("The bit at %d places from the least significant bit is a %d\n", bitPlace , result);

    return 0;
    
}

//counts the number of 1's and 0's in the binary edition of that number
int bitCounter(int num2){

    int onesCount;
    int zerosCount;

    //for the 32 bits of the number, shifts a 1 over to each place and compares it to each bit, and keeps track of each result
    for(int i = 1; i <= 32; i++){

        //compares to each bit using 1 shifted over i times and a bitwise AND
        if(num2 & (1 << i)){
            onesCount++;
        }else {
            zerosCount++;
        }
    }

    printf("There are %d ones and %d zeros in the word\n", onesCount, zerosCount);

    return 0;
}

//Verifies that a number is a power of 2
int powerOfTwo(int num3){

    //checks if the number is positive and if the bitwise-and operation between N and N - 1 is equal to zero.
    //binary number powers of 2 all have a leading 1 followed by zeros
    //therefore the number 1 less than a power will have a leading 0
    //anding these with a bitwise and will produce a net 0 number
    // numbers 1 and less are invalid
     if( (num3 > 1) && (num3 & (num3 - 1)) == 0){
         printf("This number is a power of 2\n");
     }else{
         printf("This number is not a power of 2\n");
     }

    return 0;
}


