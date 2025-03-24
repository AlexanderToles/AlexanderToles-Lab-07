#include <stdio.h>
void printCombinations(int td,int fg,int s,int td2,int td1){
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3 pt FG %d Safety\n", &td2, &td1, &td, &fg, &s);
}
void searchCombinations(int score){
    int td,fg,s,td2,td1;
    if(score%3==0){
        fg = score/3;
    }
    if(score%2==0){
        s=score/2;
    }
    if(score%6==0){
        td=score/6;
    }
    if(score%8==0){
        td2=score/8;
    }
    if(score%7==0){
        td1=score/7;
    }
}
int main(){
    int score;
    printf("Enter Score: ");
    scanf("%d", &score);
    printf("\n%d", score);
    return 0;
}