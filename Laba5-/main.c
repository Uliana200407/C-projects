#include <stdio.h>
#include <time.h> //we need it to call randomizer in C
#include <stdlib.h>
#include <string.h>


/*listString - matrix (arrays of arrays)
listString[i] - massive
listString[i][j] - element of matrix*/

int random_range(int range_min, int range_max); //we bring our function to the top
void output(int quantityLine, int quantitySymbols, char matrix[quantityLine][quantitySymbols]);
void copy_array(const char *from, char *to, int symbolsAmount);



int main()
{
    srand(time(NULL)); //randomizer in C, which attaches to time in your device
    
    char ch,error; //set the variables
    int quantityLine;
    int quantitySymbols;
    
    do
    {
        error=0;
        printf("Enter lines amount: "); //checking symbols
        scanf("%d%c",&quantityLine,&ch);
        if ((ch!='\n')||(quantityLine<=0))//checking buffering zone inputting (stdin) + substracrion check
        {
            error = 1;
            fflush(stdin);
            printf("Error inputing\n");
        }
        ch = 0;
        
    }
    while(error);
           
    do
    {
        error=0;
        printf("Enter amount of symbols in one line : ");  //checking symbols
        scanf("%d%c",&quantitySymbols,&ch);
        if ((ch!='\n')||(quantitySymbols<=0)) //checking buffering zone inputting (stdin) + substracrion check
        {
            error = 1;
              fflush(stdin);
               printf("Error inputing\n");
        }
        ch = 0;
    }
    while(error);
   

    char listString [quantityLine][quantitySymbols]; //creating two massives in one matrix(listString)

    for (int i = 0 ; i < quantityLine; i++) { //creating two loops for lines(i) and for crossing row and column(j)
        for (int j = 0; j < quantitySymbols; j++) {
            char ch;
            do{
                ch = (char)random_range(65,122);
                /* creating the random range relying on the the table ASCII,we have appropriate diapazone
                 from 65 to 125 */
            } while((int)ch <= 96 && (int)ch >= 91);/*but here we have checking only for letters, cause in that diapazone, we have also symbols*/
            listString[i][j] = ch; //char assignment to elements of massive
        }
    }

    output(quantityLine,quantitySymbols, listString);
    for(int i=0;i<quantityLine-1;i++){ //here we operate sorting operations in increasing manner with lines
        for(int j=i+1;j<quantityLine;j++){
            if(strcmp(listString[i],listString[j]) > 0){ /*comparing two lines,their ASCCI codes, that continues to the end of process of finding out all different symbols or to the end of the line */
                char tmp[quantitySymbols];
                copy_array(listString[i], tmp, quantitySymbols);
                copy_array(listString[j], listString[i], quantitySymbols);
                copy_array(tmp, listString[j], quantitySymbols);
            }
        }
    }
    output(quantityLine, quantitySymbols, listString);
}

int random_range(int range_min, int range_max ){ //returning random int number from range_min to range_max diapazone

    return (range_min + rand() % (range_max - range_min +1 ));
}

void output(int quantityLine, int quantitySymbols, char matrix[quantityLine][quantitySymbols]){
    printf("\n");
    for (int i = 0 ; i < quantityLine; i++) {
        for (int j = 0; j < quantitySymbols; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void copy_array(const char *from, char *to, int symbolsAmount){ /*we need to overturn our massive one by one,so we set massive from,massive to and exactly size of massive*/
    for (int i = 0; i < symbolsAmount; ++i) { /* with the help of that loop, we overturn symbols from massive (from) to massive (to)*/
        to[i] = from[i];
    }
}
