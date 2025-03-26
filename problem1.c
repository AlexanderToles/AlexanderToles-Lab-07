//  EECS 348 LAB 07 PROBLEM 1
//  Football score calculator
//  INPUT: score
//  OUTPUT: possible score combinations
//  ALEXANDER TOLES      
//  MARCH 25 2025

#include <stdio.h>


//for each possible way to score, tests every combination of scores possible by iterating through each possible way to score


void searchCombinations(int score){ //takes in score
    for(int s_num = 0;s_num*2<score;s_num++){ //iterate from 0 to the max number of safetys possible

        for(int fg_num = 0;fg_num*3<score;fg_num++){ //iterate from 0 to the max number of field goals possible

            for(int td_num = 0;td_num*6<score;td_num++){ //iterate from 0 to the max number of touch downs possible

                for(int td1_num = 0;td1_num*7<score;td1_num++){ //iterate from 0 to the max number of touch downs with field goals possible

                    for(int td2_num = 0;td2_num*8<score;td2_num++){ //iterate from 0 to the max number of touch downs with safety possible

                        if((s_num*2)+(fg_num*3)+(td_num*6)+(td1_num*7)+(td2_num*8)==score){ //check if the combination equals the score, if so, print the score.

                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG %d Safety\n", td2_num, td1_num, td_num, fg_num, s_num);

                        }
                    }
                }
            }
        }
    }
    
    
    

}
void promptUser(){
    int score; //initialize score variable
    printf("\nEnter Score(Enter 0 or 1 to exit): ");
    scanf("%d", &score); //store variable
    if(score > 1){ //score must be greater than 1
        printf("Possible score combinations to make %d\n",score);
        searchCombinations(score); //search combinations
        promptUser(); //prompt the user again.
    }
    else{
        if(score < 0){
            printf("Score can not be negative"); //if score is negative,
            promptUser();
        }
        else{
            return; //end program
        }
        
    }
}
int main(){
    promptUser(); //prompt user
    return 0;
}