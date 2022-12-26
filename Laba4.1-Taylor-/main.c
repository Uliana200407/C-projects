#include <stdio.h>
#include <math.h>
#define pi 3.142

int main() {
    double eps,n;
    float x1, x2,valueDiapazone,sinx,cosx,radian_x,denominator,element,x;
    
    printf("\nThat is an app to find out sin and cos values with a help of Taylor's range.\n");
    printf("___________________________________________________________________________\n\n");
    
    char ch,error;
    do
    {
        error=0;
        printf("1)Enter here the first limit : ");
        scanf("%f%c", &x1,&ch);
        if (ch!='\n')//checking buffering zone inputting (stdin)
        {
            error=1;
            fflush(stdin);
            printf("Error inputing x1\n");
        }
        ch = 0;
    } while(error);
    
    do
    {
        error=0;
        printf("2)Enter here the last limit : ");
        scanf("%f%c", &x2,&ch);
        if ((ch!='\n')||(x1>=x2))//checking buffering zone inputting (stdin)+ last limit check
        {
            error=1;
            fflush(stdin);
            printf("Error inputing x2\n");
        }
        ch = 0;
    } while(error);
    
    do
    {
        error=0;
        printf("3)Enter here the value of diapazone : ");
        scanf("%f%c", &valueDiapazone,&ch);
        if ((ch!='\n')||(valueDiapazone<=0))//checking buffering zone inputting (stdin)+ valueDiapazone check
        {
            error=1;
            fflush(stdin);
            printf("Error inputing valueDiapazone\n");
        }
        ch = 0;
    } while(error);
    
    do
    {
        error=0;
        printf("4)Enter here the accuracy : ");
        scanf("%lf%c", &eps,&ch);
        if ((ch!='\n')||(eps<=0))//checking buffering zone inputting (stdin)+ accuracy check
        {
            error=1;
            fflush(stdin);
            printf("Error inputing accuracy");
        }
        ch = 0;
    } while(error);
    
    printf("___________________________________________________________________________\n\n");
    printf("\t\t\t\t\t\t\t\tSin(x)_Table\n");
    printf("\n|Entered x|\t|Inbuilt values(sinx)|\t|Taylor's values(sinx)|\t|Contrast(sinx)|\n\n");
    
    
    x=x1;
    while (x <= x2) {      //cycle for new (x)es to x2
        radian_x= x * (pi / 180); //Find out radians
        denominator = sinx = radian_x;
        n = 1;
        while (fabs(denominator) >= 1/pow(10, eps)) {  //Condition for exiting the inner loop
            denominator *= (-radian_x * radian_x) / ((n + 1) * (n + 2));//Formula for sin
            sinx += denominator;
            n += 2;
        }
        
        printf("\t%.2f\t\t\t%f\t\t\t%f%\t\t\t\t%f\n", x, sinx, sin(radian_x),fabs(sinx - sin(radian_x)));
        x = x + valueDiapazone;
        printf("___________________________________________________________________________\n\n");
    }
    
    
    
    printf("\t\t\t\t\t\t\t\tCos(x)_Table\n");
    printf("\n|Entered x|\t|Inbuilt values(cosx)|\t|Taylor's values(cosx)|\t|Contrast(cosx)|\n\n");
    x=x1;
    while (x <= x2) {  //cycle for new (x)es to x2
        radian_x= x * (pi / 180); //Find out radians
        denominator = cosx = n = 1;
        while (fabs(denominator) >= 1/pow(10, eps)) { //Condition for exiting the inner loop
            denominator *= (-radian_x * radian_x) / (2*n*(2*n - 1));//Formula for cos
            cosx = cosx + denominator;
            n++;}
        printf("\t%.2f\t\t\t%f\t\t\t%f%\t\t\t\t%f\n", x, cosx, cos(radian_x),fabs(cosx - cos(radian_x)));
        x = x + valueDiapazone;
        printf("___________________________________________________________________________\n\n");
    }
}
       
