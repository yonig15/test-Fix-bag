#include <stdio.h>   

#pragma warning(disable:4996) //You need to put #pragma warning in order for the software to work

int main1_1()
{

    int a = 4;
    int b = 7; // There was no correct declaration of the variable b

    float c;

    scanf("%f", &c); // When using scanf, you need to refer to the address of the variable and not to the variable itself

    if (5 == c) { //When you want to check if two values are equal, you should write == and not =. One mention of the sign =  means we are performing a placement

        printf("%f", c); //You should write printf and not print

    }
    return 0; //At the end of main you should use return

}

