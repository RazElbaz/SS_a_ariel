#include"NumClass.h"
#include<math.h>

int Power(int a,  int b){
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return Power(a, b/2)*Power(a, b/2);
    return a * Power(a, b/2)*Power(a, b/2);
}

int numberOfDigit(int num){
    int counter=0;
    while(num>=1)
    {
        num=num/10;
        counter++;
    }
    return counter;
}

int isPalindrome(int num)
{
    int digit=numberOfDigit(num);
    int a=num%10;
    int b=(num/Power(10,digit-1));
    if(a!=b)
    {
        return 0;
    }
        num=num-(b*Power(10,digit-1));
        num=num/10;
        if(numberOfDigit(num)==1 || numberOfDigit(num)==0)
        {

            return 1;
        }
        return isPalindrome(num);
    
}

int isArmstrong(int num ){
    int digit = numberOfDigit(num);
    int cnt = num, Sum = 0;
    while (cnt!=0) {
        int r = cnt % 10;
        Sum += Power(r, digit);
        cnt = cnt / 10;
    }
 
    if (Sum == num)
        return 1;
    else
        return 0;
}