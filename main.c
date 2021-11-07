#include<math.h>
#include "NumClass.h"
#include <stdio.h>
#include "basicClassification.c"
#include "advancedClassificationRecursion.c"
#include "advancedClassificationLoop.c"


 void main(){

     int num1,num2,min,max;
     scanf("%d",&num1);
     scanf("%d",&num2);
     if(num1<num2){
         min=num1;
         max=num2;
     }
     else{
         min=num2;
         max=num1; 
     }
    
     printf("The Armstrong numbers are:");
     for(int i=min;i<=max;i++){
         int current=isArmstrong(i);
         if(current==1)printf(" %d ",i);
     }
     printf("\n");
      printf("The Palindromes are:");
     for(int i=min;i<=max;i++){
         int current=isPalindrome(i);
         if(current==1)printf(" %d",i);
     }

     printf("\n");
     printf("The Prime numbers are:");
     for(int i=min;i<=max;i++){
         int current=isPrime(i);
         if(current==1) {
             printf(" %d",i);
         }
     }
     
      printf("\n");
      printf("The Strong numbers are:");
     for(int i=min;i<=max;i++){
         int current=isStrong(i);
         if(current==1)printf(" %d",i);
     }
      printf("\n");
 

     
 }