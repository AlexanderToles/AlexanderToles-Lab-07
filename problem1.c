#include <stdio.h>
void printCombinations(int td,int fg,int s,int td2,int td1){
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3 pt FG %d Safety\n", td2, td1, td, fg, s);
}

void searchCombinations(int score){
    int td,fg,s,td2,td1;
    td = fg = s =td2 = td1 = 0;
    int testScore[] = {2,3,6,7,8};
    int i = 0;
    while(testScore[i] <= score){
        switch(i){
            case 2:
                s++;
                break;
            case 3:
                fg++;
                break;
            case 6:
                td++;
                break;
            case 7:
                td1++;
                break;
            case 8:
                td2++;
                break;
        }
        printf("\n%d", i);
        switch(score-testScore[i]){
            case 0:
                printf("Score: %d, testScore: %d\n, score-testScore[i]: %d", score,testScore[i], score-testScore[i]);
                printCombinations(td,fg,s,td2,td1);
                break;
            case 1:
                i++;
                break;
            default:
                score = score-testScore[i];
                break;
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