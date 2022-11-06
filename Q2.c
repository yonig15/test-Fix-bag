#include <stdio.h>   
#include <stdlib.h> 

#pragma warning(disable:4996) //You need to put #pragma warning in order for the software to work

int main1_2()
{

        int x = 5;
        int y = 10; //***You need to define values for the variables + define y separately***

        int nums[6];

        int* arrPtr;

        

        // Section A - Print the variables 

        puts("***** Section A *****");

        printf(" Base = %d\n", x);

        printf(" Height = %d\n", y);

        printf(" Area = %d\n", (x * y)/2); //***The formula for calculating the area of a triangle is length times height divided by 2***



        // Section B - Print the static array "nums". 

        puts("***** Section B *****");

        int i = 0;

        while (i < 6) {

            printf("  nums[%d] = %d\n", i, nums[i]=i+2);
            i++; //***The variable i should be advanced in order to avoid an infinite loop***
        }



        // Section C - Print allocated array. 

        puts("***** Section C *****");

        arrPtr = malloc(sizeof(int*) * 6);//***In the question they asked for an array with a size of 6 and not 10, and in addition to make a malloc for the pointer***



        if (arrPtr) {

            for (int i = 0; i < 6; i++) {

                printf("array[%d] = %d\n", i, arrPtr[i]=i+5);

            }

        }
        else {

            printf("Error Allocating Memory!\n");

            exit(1);

        }
        free(arrPtr);//At the end of dynamic memory, we need to released the memory
    return 0;

}

