#include <stdio.h>
int fTwo(long card,int *f,int *s);
void WhatCard(long card);
void IsValid(int second, int werent,long card);
int WerentMultied(long card);
int SecondToLast(long card);
int Range(long number);
long GetPositiveInpt(void);

int main(void)
{
    long Input = GetPositiveInpt();
    int range = Range(Input);
    // printf("%li\n",range);

    int second_to_last = SecondToLast(Input);
    // printf("%i\n",second_to_last);

    int werent = WerentMultied(Input);
    // printf("%i\n",werent);

    IsValid(second_to_last,werent,Input);

}

long GetPositiveInpt(void)
{
    long Input;
    do
    {
        printf("Number: ");
        scanf("%li",&Input);
    } while (Input<0);
    return Input;
}

int Range(long number)
{
    int range = 0;
    while (number!=0)
    {
        number/=10;
        range++;
    }
    return range;
}

int SecondToLast(long card)
{
    card/=10;
    int sum = 0;

    while (card!=0)
    {
        int digit = card % 10;
        card/=100;
        digit *= 2;
        if (Range(digit)==2)
        {
            sum += digit % 10;
            // printf("digit bölü 10 %i\n",digit%10);
            digit/=10;

            sum += digit % 100;
            // printf("digit bölü yüz %i\n",digit%100);
        }
        else
        {
            sum += digit;
            // printf("düz digit %i\n",digit);
        }
    }
    return sum;
}

int WerentMultied(long card)
{
    int sum = 0;
    while (card!=0)
    {
        int x = card % 10;
        card/=100;
        sum += x;
    }
    // printf("%i\n",sum);
    return sum;
}

void IsValid(int second, int werent,long card)
{
    int validness = second+werent;
    // printf("sum: %i\n",validness);
    if (validness%10==0)
    {
        WhatCard(card);

    }
    else
    {
        printf("INVALID\n");
    }
}


int fTwo(long card,int *f,int *s)
{
    // printf("%li\n",card);

    int fR = Range(card)-1;
    int sR = Range(card)-2;

    // printf("%i\n",Range(card));

    long fD = 1;
    long sD = 1;

    for (int i = 0; i < fR; i++)
    {
        // printf("%li\n",f);
        fD *= 10;
    }
    
    for (int i = 0; i < sR; i++)
    {
        sD *= 10;
    }
    // printf("%li\n%li\n",fD,sD);

    int firstNum = (card/fD)%10;
    int secondNum = (card/sD)%10;
    int sum = (firstNum*10)+secondNum;
    *f = firstNum;
    *s = sum;
}
void WhatCard(long card)
{
    int f,s;
    fTwo(card,&f,&s);

    if (Range(card) == 15 & s==34 || s==37)
    {
        printf("AMEX\n");
    }
    else if (Range(card) == 16 & s==51 ||s==52 || s==53 || s==54 || s==55)
    {
        printf("MASTERCARD\n");
    }
    else if (Range(card) == 13 || Range(card) == 16 & f==4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}