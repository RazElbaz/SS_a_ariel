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

int reverse(int num, int current)
{
    
    if (num == 0)
        return current;
 
    current = (current * 10) + (num % 10);
 
    return reverse(num / 10, current);
}

int isPalindrome(int num)
{
    int Num=num;
    int current=reverse(Num, 0);
    if(num==current) return 1;
    else return 0;
    
    
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