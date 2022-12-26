#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//For myself - y=k в степені під коренем x

int main() {
    float x, y1, d, power;
    int k,eps;
    char ch, error;
    printf("\nThat's the app to find the root on k-th power\n");
    printf("Your accuracy shouldn't be equal or more than value 8\n");
    printf("______________________________________________________\n");
    printf("\t\t\t\t\t\tUser_Input\n");

    do
    {
        error = 0;
        printf("1)Input x here : ");  //symbols checking
        scanf("%f%c", &x, &ch);
        if(ch!='\n')
        {
            error = 1;   //checking buffering zone stdin
          fflush(stdin);
            printf("Error inputting x\n");
        }
        //        ch = 0;
    } while(error);

    do
    {
        error = 0;
        printf("2)Input k (power) here : ");    //symbols checking
        scanf("%d%c", &k, &ch);
        if(ch!='\n')
        {
            error = 1;
          fflush(stdin);         //checking buffering zone stdin
            printf("Error inputting k\n");
        }
        //        ch = 0;
    } while(error);


    do {
        error = 0;
        printf("3)Input accuracy(e) here : ");   //symbols checking
        scanf("%d%c", &eps, &ch);
        if(ch!='\n' || eps < 0)       //checking buffering zone stdin and epsilon shouldn't be 0 or lower
        {
            error = 1;
          fflush(stdin);
            printf("Error inputting epsilon\n");
        }
        //        ch = 0;
    } while(error);
    
    printf("______________________________________________________\n\n");
    printf("\t\t\t\t\tResult_With_Accuracy\n\n");
    
    
    
    y1 = 1; //assignment for values
    d=1;

    if ((k!= 0) && (((k%2 == 0) && (x>0)) || (k%2 == 1))) { // checking for K

        while (fabs(d) >= (1 / pow(10, eps))) {  //comparing with d
            power = 1;
            for (int i = 1; i <= abs(k) - 1; i++) {
                power *= y1;
            }
            d = (x / power - y1) / abs(k);
            y1=y1+d;

            if(y1 == 0) y1 = -1;
        }

        if(k < 0) y1 = 1 / y1;
        printf("Resulting y is %.*f\n\n", eps, y1);
        
    } else {
        printf("Invalid data for x and k");   // Bluster
    }
    
    return 0;
}
