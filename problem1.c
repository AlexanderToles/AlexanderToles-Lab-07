#include <stdio.h>
void printCombinations(int td,int fg,int s,int td2,int td1){
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG %d Safety\n", td2, td1, td, fg, s);
}
void searchCombinations(int score){
    int td,fg,s,td2,td1;
    td = fg = s =td2 = td1 = 0;
    int testScore[] = {2,3,6,7,8};
    
    for(int s_num = 0;s_num<5;s_num++){
        for(int fg_num = 0;fg_num<5;fg_num++){
            for(int td_num = 0;td_num<5;td_num++){
                for(int td1_num = 0;td1_num<5;td1_num++){
                    for(int td2_num = 0;td2_num<5;td2_num++){
                        if((s_num*2)+(fg_num*3)+(td_num*6)+(td1_num*7)+(td2_num*8)==score){
                            printCombinations(td_num,fg_num,s_num,td2_num,td1_num);
                        }
                    }
                }
            }
        }
    }
    
    
    

}
int main(){
    int score;
    printf("Enter Score: ");
    scanf("%d", &score);
    searchCombinations(score);
    return 0;
}