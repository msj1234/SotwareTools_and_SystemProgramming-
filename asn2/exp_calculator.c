#include <stdio.h>

//program to calculate an expression
//initalize function to calcuate answer
float answer(float base, int exp);

float main(){
        float base; //represent base number
        int exp; //represents exponent

        //ask user for base and exponent
        printf("please enter base: ");
        scanf("%f", &base);
        printf("\nplease enter Exponent: ");
        scanf("%d", &exp);

        //checkign if base is > 0
        if(base>=0.0000001){
                 //proceed with calcualtion
                printf(" base: %f and exponenet: %d is = %f\n", base, exp, answer(base,exp));
        }
        else{
               printf("base is 0.0000001, program terminated.\n");
               return 0;
        }

}
//function to calculate the answer
float answer(float base, int exp){
        //base case
        if(exp == 0){ //any number with exp 0 = 1
                return 1;
        }
        //any int with exponent 1 = actual integer
        else if(exp == 1){
                return base;
        }
        //recursive part
        //if exp is even 
        else if( exp %2 == 0){
                //if it is even a^n is (a^n/2)^2
                float calc = (answer(base, exp/2)) * (answer(base, exp/2));
                return calc;
        }
        else{ //exponent is odd
                float calc = answer(base, (exp-1)/2) * answer(base, (exp-1)/2) * base;
                return calc;
        }
}
