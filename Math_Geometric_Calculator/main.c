#include <stdio.h>  //Our main library to work with input and output functions
#include <math.h>  //Our library to work with math functions
int main (void){
    int a, b, c, P;
    //side A - a,side B- b,side C-c,P-periemetr
    double hP,S,Ha,Hb,Hc,Ba,Bb,Bc,Ma,Mb,Mc;
    //H-heigts,B-bisectors,M-madianas,hP-half periemetr
    
    printf("\n The app to find out S, hP, P,heights, bisectors, medians of triangle.\n");
    printf("\nInput the a length: ");
    scanf("%d", &a);
    printf("\nInput the b length: ");// //The string function
    scanf("%d", &b);
    printf("\nInput the c length: ");
    scanf("%d", &c);
    
    printf("Input a, b and c:\n");
        if(scanf("%d\n %d\n %d", &a, &b, &c) <= 0) { //check for correct input
            printf("Invalid data\n");
            return 0;
        }
        
        //the option to check,that it can exist
        if(a < (b+c) && b < (a+c) && c < (b+a)){
            
            //Formula to calculate the periemetr
            P = a+b+c;
            //Formula to calculate the half of the periemetr
            hP=(a+b+c)/2;
            //We will find the square
            S = sqrt(hP *(hP-a)*(hP-b)*(hP-c));
            //Formula to find the height
            Ha = (2*S)/a;
            Hb = (2*S)/b; //Formula to find the height
            Hc = (2*S)/c;
            
            Ba = (2*sqrt(b*c*hP*(hP-a)))/(b+c);
            Bb = (2*sqrt(a*c*hP*(hP-b)))/(a+c); //Formula to find out bisectors
            Bc = (2*sqrt(a*b*hP*(hP-c)))/(a+b);
            
            Ma = (sqrt(2*b*b+2*c*c-a*a))/2;
            Mb = (sqrt(2*a*a+2*c*c-b*b))/2; //Formula to find out medianas
            Mc = (sqrt(2*b*b+2*a*a-c*c))/2;
            
            
            
            
            //output square,periemetr
            printf("\n\n Periemetr: ");
            printf("\n%s%d","P=", P);
            printf("\n\n Square: ");
            printf("\n%s%.2lf","S=", S);
            printf("\n\n Half periemetr: ");
            printf("\n%s%lf","hP=", hP);
            
            
            
            
            
            //output heights
            printf("\n\n Heigts: ");
            printf("\n%s%lf","Ha=", Ha);
            printf("\n%s%lf","Hb=", Hb);
            printf("\n%s%lf","Hc=", Hc);
            
            
            //output medianas
            printf("\n\n Medianas: ");
            printf("\n%s%lf","Ma=", Ma);
            printf("\n%s%lf","Mb=", Mb);
            printf("\n%s%lf","Mc=", Mc);
            
            //output bisectors
            printf("\n\n Bisectors: ");
            printf("\n%s%lf","Ba=", Ba);
            printf("\n%s%lf","Bb=", Bb);
            printf("\n%s%lf","Bc=", Bc);
        }
        else {
            printf("\n ERROR: No triangle existing\n");
            //triangle doesn't exist
        }
        printf("\n\n");
        return 0;
    }

    
    
    
 
    
   
