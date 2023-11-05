#include <stdio.h>

#define LMonth 31
#define SMonth 30
#define VMonth 28

typedef enum {
    Sun,
    Mon,
    Jue,
    Wed,
    Thu,
    Fri,
    Sat
} WEEK;

typedef enum {
    January = 1,
    February,
    Match,
    Apirl,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
} MONTH;

void printMonHead(void)
{
   printf("    Sun    Mon    Jue    Wed    Thu    Fri    Sat\n");
}

void  printMonth(const WEEK firstDay, int length )
{
     WEEK weekDay = firstDay % 7;

     int i;

     printMonHead();

     for (i=0; i<weekDay;++i)
     {
         printf("       ");
     }

    for(i=1;i<=length;++i)
    {
          weekDay = (++weekDay)%7;
          printf("%7d", i);

          if(weekDay==0) printf("\n");
    }

    printf("\n");
}


int isLeapYear(const int yr)
{
    return ( yr%( yr%100 ? 4:400) ? 0 : 1);
}


int getYearDay(const int year)
{

    int lastYear = year-1;
    int yearNum = lastYear-1899;

    int walker,counter=0;
    for(walker=1900; walker < year; ++walker)
    {
        if(isLeapYear(walker)==1)
            ++counter;
    }

    return (365*yearNum+counter+1)%7;
}


void printYear(const int y)
{
    WEEK yDay = getYearDay(y);
    int  vDay = isLeapYear(y);

    int monWeeks[13];
    int monLen  [13];

    monLen[0]=0;
    monLen[January]=31;     monLen[February]=28+vDay;   monLen[Match]=31;
    monLen[Apirl]=30;       monLen[May]=31;             monLen[June]=30;
    monLen[July]=31;        monLen[August]=31;          monLen[September]=30;
    monLen[October]=31;     monLen[November]=30;        monLen[December]=31;

    monWeeks[0]=0;
    monWeeks[January]   = yDay;
    monWeeks[February]  = ((monWeeks[January]       +monLen[January]        )%7);
    monWeeks[Match]     = ((monWeeks[February]      +monLen[February]       )%7);
    monWeeks[Apirl]     = ((monWeeks[Match]         +monLen[Match]          )%7);
    monWeeks[May]       = ((monWeeks[Apirl]         +monLen[Apirl]          )%7);
    monWeeks[June]      = ((monWeeks[May]           +monLen[May]            )%7);
    monWeeks[July]      = ((monWeeks[June]          +monLen[June]           )%7);
    monWeeks[August]    = ((monWeeks[July]          +monLen[July]           )%7);
    monWeeks[September] = ((monWeeks[August]        +monLen[August]         )%7);
    monWeeks[October]   = ((monWeeks[September]     +monLen[September]      )%7);
    monWeeks[November]  = ((monWeeks[October]       +monLen[October]        )%7);
    monWeeks[December]  = ((monWeeks[November]      +monLen[November]       )%7);

    int i;
    for(i=January; i<=December; ++i)
    {
        printf("\n-------------------------------------------------\n");
        printf("                     %d, %d                      \n",y,i);
        printf("-------------------------------------------------\n");
        printMonth(monWeeks[i],monLen[i]);
        printf("\n");
    }

    return;
}


int main(void)
{
//  int y3 = 2000;
//  int y3 = 1946;
//  printYear(y3);
  int y;
  int quit=0;

  do
    {
        printf("Please enter which Year to Print For You (0 to quit): ");
        scanf("%d",&y);
        printf("\n");

        if(y==0)
            quit = 1;
        else
            printYear(y);

    }while(!quit);

  return 0;
}
