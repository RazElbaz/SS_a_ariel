#include "NumClass.h"
#include<math.h>
int isPrime(int num){
     if (num < 1) return 0;
     if (num % 2 == 0 && num > 2) return 0;
     for(int i = 3; i < num / 2; i+= 2)
     {
         if (num % i == 0)
             return 0;
     }
     return 1;
}

int Factorial(int num){
    if(num<=1) return 1;
    return num*Factorial(num-1);
}

int isStrong(int num){
    int Sum=0, check=num;
    if(num==0) return 0;
    while(num!=0){
        Sum=Sum+Factorial(num%10);
        num=num/10;
    }
    if(Sum==check) return 1;
    return 0;
}