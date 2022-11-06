#include <stdio.h>   
#include <stdlib.h> 

#pragma warning(disable:4996)


// struct to collect counting info about english letters found in a text file. 

typedef struct letter {

    char small;

    char big;

    int counter;
    struct letter* next;//***I added pointers to next and prev***
    struct letter* prev;//***I added pointers to next and prev***

}letter;



//Function to free linked list 

void freeList(letter* head) {

    letter* releaseItem;

    letter* runItem = head;

    while (runItem != NULL) {

        releaseItem = runItem;

        runItem = runItem->next;//***A pointer to the next was missing

        free(releaseItem);

    }

}

int main()
{
   //Next two string represents all the english alphabets (small and capital) 

   char* smallAlpha = "abcdefghijklmnopqrstuvwxyz";

   char* bigAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

   int lettersCountArr[27] = { 0 }; // ***there ara 26 letter in English

   char readChar, ch;
   FILE* f;

   f = fopen("myFile.txt", "r");

   if (!f) { //***You need to check if there was a problem opening the file***

       //error
   }
   else
   {
       // Dis[lay the content of myFile.txt and count letters 
       printf("the content of myFile.txt:\n\n");

       while ((readChar = fgetc(f)) != EOF) { //*** the EOF insted 0

           printf("%c", readChar);

           for (int i = 0; i < strlen(smallAlpha); ++i) {

               if (readChar == smallAlpha[i] || readChar == bigAlpha[i]) {

                   lettersCountArr[i]++;
               }
           }
       }
       printf("\n");

       fclose(f);
   }
    


    // Build Linked list from file content 

    // Every node represent English letter (small and big). 

    letter* HEAD = NULL;

    letter* TAIL = NULL;



    for (int j = 0; j < strlen(smallAlpha); ++j) {

        letter* letterItem = (letter*)malloc(sizeof(letter));

        if (!letterItem) {

            puts("Error Allocating Memory!");

            exit(1);

        }

        letterItem->small = 'a' + j;

        letterItem->big = 'A' + j;

        letterItem->counter = lettersCountArr[j];



        // Creating the linked list 

        if (HEAD == NULL) {//***The first time you need to check if there is a head
            HEAD = letterItem;
            HEAD->next = NULL;
            HEAD->prev = NULL;
            TAIL = HEAD;
        }
        else {
            TAIL->next = letterItem;
            letterItem->prev = TAIL;
            TAIL = letterItem;
            TAIL->next = NULL;
        } 
    }

   return 0;
}