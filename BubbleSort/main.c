#include <stdio.h>
//Bubblesort app


int main() {
    short n, checking;
    char ch, error;
    printf("Thats an app, in which you enter different numbers and it can automaticaly group them in the correct order :\n\n");
    printf("-----------------------------------------------------------------------------------------------------------\n");
    
    
    do {
        error = 0; //symbols checking
        printf("Input 1 to sort from the smallest num to the biggest or 2 to sort from the biggest num to the smallest:\n");
        scanf("%hd%c", &checking, &ch);
        if(ch != '\n') {
            printf("Invalid data,write one more time\n");
            fflush(stdin);
            error = 1;
            continue;
        }

        
        
        if(checking != 1 && checking != 2) {
            printf("Number is out of our range\n");
            fflush(stdin);
            error = 1;
            ch = ' ';
        }
    } while(error);
    ch = ' ';

  
    
    do {
        error = 0;
        printf("Size of the array:\n");
        scanf("%hd%c", &n, &ch);

        if(ch != '\n') {
            printf("Invalid data,write one more time\n");
            error = 1;
            fflush(stdin);
            continue;
        }

        if(n <= 0) {
            printf("The size of the array can't be lower then 1\n");
            error = 1;
            fflush(stdin);
            ch = ' ';
        }
    } while(error);
    ch = ' ';

    float Array[n];
    
    printf("Enter the elements of our array\n");
    for(short i = 0; i < n; i++) {
        do {
            error = 0;
            scanf("%f%c", &Array[i], &ch);

            if(ch != '\n') {
                printf(" Invalid data,write one more time\n");
                error = 1;
                fflush(stdin);
            }
        } while(error);
        ch = ' ';
    }

    for (short i = 0; i < n; i++) {   //creating loop for sorting numbers(comparison)
        for(short j = i+1; j < n; j++) { //for equels
            if (checking == 1) {
                if (Array[i] > Array[j]) {
                    float temp = Array[j];
                    Array[j] = Array[i];
                    Array[i] = temp;
                }
            } else {         // depends on the choice of a user
                if (Array[i] < Array[j]) {
                    float temporaryNum = Array[j];
                    Array[j] = Array[i];
                    Array[i] = temporaryNum;  //iніціалізація змінної
                }
            }
        }
    }

    for(short i = 0; i < n; i++) {
        printf("%g ", Array[i]);
    }

    return 0;
}

