#pragma warning(disable:4996)
#include <stdio.h>
//That's a header library to work with input and output functions.
#include <curses.h>
//That's a library for text interface

int roman(int, int, char);
//Variaties of c variable.

int main()
//a function,any code is inside curly brackets.
{
    // input number
    int a;
    printf("Please enter a number in arabian here: \n");//The output to screen,ask the user to enter number to a.
    scanf("%u", &a);
    /*to take input from the user(it allows to read formatted input from the standart,as keyboards,& - a ponter,that stores the memory adress,u is unsigned,hole number*/

    // print number in roman format(symbols represent numbers)
    a = roman(a, 1000, 'M');
    a = roman(a, 500, 'D');
    a = roman(a, 100, 'C');
    a = roman(a, 50, 'L');
    a = roman(a, 10, 'X');
    a = roman(a, 5, 'V');
    a = roman(a, 1, 'I');
    getchar();
    //function to read a single character from the standart input and rerurns it to the program
    return 0;
    //output from the function
}
int roman(int number, int digit, char symbol)
{
    while (number >= digit)
        //Well,the while expression - true if number >= digit,then false .
    {
        putchar(symbol);
        //So let's output the Roman letter
        number = number - digit;
    }
    return(number);
}

//The function roman will operate the main
