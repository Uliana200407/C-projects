#include <stdio.h>
#include <stdlib.h>

int main() {
    int  date, month, year, n, fault,day;
    char ch;
    printf("The app to find out the day of the week,from your notes\n\n");
    //checking for symbols
    do {
        fault = 0;
        printf("Enter a date here (1-31):\n");
        scanf("%d%c", &date, &ch);
        if ((ch != '\n') || (date <= 0)) {
            printf("Error,unavailable date:(\n");
            fflush(stdin);
            fault = 1;
        }
        ch = 0;
    } while (fault != 0);

    do {
        fault = 0;
        printf("Enter a month here (1-12):\n");
        scanf("%d%c", &month, &ch);
        if ((ch != '\n') || (month <= 0)||(month>=12)) {
            printf("Error,unavailable month:(\n");
            fflush(stdin);
            fault = 1;
        }
        ch = 0;

    } while (fault != 0);

    do {
        fault = 0;
        printf("Enter a year here:\n");
        scanf("%d%c", &year, &ch);
        if ((ch != '\n') || (year <= 1000) || (month >= 2199) || (year <= 1)) {
            printf("Error,unavailable year:(\n");
            fflush(stdin);
            fault = 1;
        }
        ch = 0;
    } while (fault != 0);

    int yearLp;
    if((year%4==0&&year%100!=0)||((year%4==0)&&(year%100==0)&&(year%400==0))) //checking leap year
    {
        yearLp = 1;
    }
    else
    {
        yearLp= 0;
    }
    if (month > 2) {
        n = 0;
    } else if (yearLp== 1 && (month <= 2)) {
        n = 1;
    } else if (yearLp == 0 &&
               (month <= 2))
    {
        n = 2;
    }
     day = (abs(365.25 * year) + abs(30.56 * month) + date + n) % 7;
    if(yearLp==0&&month==2&&date>28)
    {
        printf("That's not even a leap year,so your number shouldn't exceed 28\n");
        return(0);
    }
    else if(yearLp == 1 && month == 2 && date > 29)
    {
        printf("Here is a leap year!The max of February days is 29,not more...\n");
        return(0);
    }
    if(((month==1)||(month == 3)||(month==5)||(month==7)||(month==8)||(month==10)||(month==12))&&(date>31))
    {
        printf("Change the value, it's too big,mAX here is 31\n");
        return(0);
    }
    if (((month==4)||(month==6)||(month==9)||(month==11))&&(date>30))
    {
        printf("The month you have input has less number of days,mAx here is 30\n");
        return(0);
    }
    switch (day)
    {
        case 0 :
            printf("%d.%d.%d - your elected day is Monday", date, month, year);
            break;
        case 1:
            printf("%d.%d.%d - your elected day is Tuesday", date, month, year);
            break;
        case 2:
            printf("%d.%d.%d - your elected day is Wednesday", date, month, year);
            break;
        case 3:
            printf("%d.%d.%d - your elected day is Thursday", date, month, year);
            break;
        case 4:
            printf("%d.%d.%d - your elected day is Friday", date, month, year);
            break;
        case 5:
            printf("%d.%d.%d - your elected day is Saturday", date, month, year);
            break;
        case 6:
            printf("%d.%d.%d - your elected day is Sunday", date, month, year);
            break;
        default:
            break;
    }
    printf("\n\n");
    return 0;
}