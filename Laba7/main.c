#include <stdio.h>
#include <math.h>
double F1(double x, double t){
    return cos(t/x)-2*sin(1/x)+1/x;
}
double F2(double x, double t){
    return sin(log(x))-cos(log(x))+t*(log(x));
}
double FindRoot(double (*f)(double, double),double a,double b,double eps, double t,int choiceMethod){
    double x;
    if(choiceMethod==1){
        while((fabs(b-a))>eps){
        x=(a+b)/2;
            if((f(a, t)*f(x, t))>0) a=x;
            else b=x;
        }
    }
    else if (choiceMethod==2){
        x = b;
        double delta;
        do{
            delta = f(x, t)/((f(x + eps, t)-f(x, t))/eps);
            x = x - delta;
        }
        while(fabs(delta) > eps);
    }
    return x;
}

int main(){
    printf("\t\tA program to solve given functions with two methods : \n");
    printf("\t--------------------------------------------------------------\n");
    double a,b,t, eps, x1;
    char ch,error;
    short checking;
    int choiceFunction,choiceMethod;
    
    do
    {
        error=0;
    printf("1)Enter a(the first limit) -> ");
    scanf("%lf%c", &a,&ch);
        if (ch!='\n')//checking buffering zone inputting (stdin)
        {
            error=1;
            fflush(stdin);
            printf("Error inputing a\n");
        }
        ch = 0;
    } while(error);
    
    do
    {
        error=0;
    printf("2)Enter b(the last limit) -> ");
    scanf("%lf%c", &b,&ch);
        if ((ch!='\n')||(b<=a))//checking buffering zone inputting (stdin)
        {
            error=1;
            fflush(stdin);
            printf("Error inputing b\n");
        }
        ch = 0;
    } while(error);
    
    do
    {
        error=0;
    printf("3)Enter t(additional variable) -> ");
    scanf("%lf%c", &t,&ch);
        if (ch!='\n')//checking buffering zone inputting (stdin)
        {
            error=1;
            fflush(stdin);
            printf("Error inputing t\n");
        }
        ch = 0;
    } while(error);
    
    do
    {
        error=0;
    printf("4)Enter accuracy(epsilon) -> ");
    scanf("%lf%c", &eps,&ch);
        if ((ch!='\n')||(eps<=0))//checking buffering zone inputting (stdin)
        {
            error=1;
            fflush(stdin);
            printf("Error inputing eps\n");
        }
        ch = 0;
    } while(error);
    
    eps=1/pow(10,eps);
    printf("\t--------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tAppoint with a choice : \n");
    printf("\t--------------------------------------------------------------\n");
    do
    {
        error=0;
    printf("1)Enter function you would like to choose 1st or 2nd -> ");
    scanf("%d%c",&choiceFunction,&ch);
        if (ch!='\n')//checking buffering zone inputting (stdin)
        {
            error=1;
            continue;}
        
        if(choiceFunction != 1 && choiceFunction != 2) {
            printf("Number is out of our range\n");
            fflush(stdin);
            error = 1;
            ch = ' ';
        }
    } while(error);
    ch = ' ';
            
    do
    {
        error=0;
    printf("2)Enter Method 1st(Dividing) or 2nd(Neuton) -> ");
    scanf("%d%c",&choiceMethod,&ch);
        if (ch!='\n')//checking buffering zone inputting (stdin)
        {
            error=1;
            continue;}
        
        if(choiceMethod != 1 && choiceMethod != 2) {
            printf("Number is out of our range\n");
            fflush(stdin);
            error = 1;
            ch = ' ';
        }
    } while(error);
    ch = ' ';
    printf("\t--------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\tResult : \n");
    printf("\t--------------------------------------------------------------\n");
    
    if(choiceFunction == 1){
        x1=FindRoot(F1,a,b,eps,t,choiceMethod);
           printf("x = %lf\n",x1);
    }
    else if (choiceFunction==2){
        x1=FindRoot(F2,a,b,eps,t,choiceMethod);
           printf("\n\nx = %lf\n",x1);
    }
    
}

