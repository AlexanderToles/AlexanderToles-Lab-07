#include <stdio.h>
void printCombinations(int td,int fg,int s,int td2,int td1){
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG %d Safety\n", td2, td1, td, fg, s);
}
void searchCombinations(int score){
    int td,fg,s,td2,td1;
    td = fg = s =td2 = td1 = 0;
    for(int s_num = 0;s_num*2<score;s_num++){

        for(int fg_num = 0;fg_num*3<score;fg_num++){

            for(int td_num = 0;td_num*6<score;td_num++){

                for(int td1_num = 0;td1_num*7<score;td1_num++){

                    for(int td2_num = 0;td2_num*8<score;td2_num++){

                        if((s_num*2)+(fg_num*3)+(td_num*6)+(td1_num*7)+(td2_num*8)==score){

                            printCombinations(td_num,fg_num,s_num,td2_num,td1_num);

                        }
                    }
                }
            }
        }
    }
    
    
    

}
int promptUser(){
    int score;
    printf("\nEnter Score(Enter 0 or 1 to exit): ");
    scanf("%d", &score);
    if(score > 1){
        printf("Possible score combinations to make %d\n",score);
        searchCombinations(score);
    }
    else{
        return;
    }
}
int main(){
    return 0;
}