#include "NumClass.h"
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
    int reverse=0, current ;
     int Num=num;

    while (Num != 0) {
        current = Num % 10;
        reverse = reverse * 10 + current;
        Num = Num / 10;
    }

    if (num == reverse){
        return 1;

    }
     
     else{
        return 0;
     }
}

int isArmstrong(int num)
{
    int Sum=0;
    int digit=numberOfDigit(num);
    int cnt=num;
  while (num>=1)
  {
    int last=num%10;
    int current_sum=Power(last,digit);
    Sum=Sum+current_sum;
    num=num/10;
  }
  if(cnt==Sum)
  {
      return 1;
  }
  return 0;
  
}