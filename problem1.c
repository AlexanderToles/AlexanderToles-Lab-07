#include <stdio.h>
void printCombinations(int td,int fg,int s,int td2,int td1){
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG %d Safety\n", td2, td1, td, fg, s);
}
void compareScores(int i, int score, int s,int fg, int td, int td1, int td2){
    int testScore[] = {2,3,6,7,8};
    if(score >= score-testScore[i]){
        if(score-testScore[i]<0){
            compareScores(0,score,s,fg,td,td1,td2);
        }
        else{
            switch(score-testScore[i]){
                case 0:
                switch(testScore[i]){
                    case 2:
                        s++;
                        //printf("s: %d\n",s);
                        break;
                    case 3:
                        fg++;
                        //printf("fg: %d\n",fg);
                        break;
                    case 6:
                        td++;
                        //printf("td: %d\n",td);
                        break;
                    case 7:
                        td1++;
                        //printf("td1: %d\n",td1);
                        break;
                    case 8:
                        td2++;
                        //printf("td2: %d\n",td2);
                        break;
                }
                    //printf("Score: %d, testScore: %d\n, score-testScore[i]: %d\n", score,testScore[i], score-testScore[i]);
                    printCombinations(td,fg,s,td2,td1);
                    break;
                case 1:
                    //printf("Score: %d, testScore: %d\n, score-testScore[i]: %d\n", score,testScore[i], score-testScore[i]);
                    i++;
                    compareScores(i,score,s,fg,td,td1,td2);
                    break;
                default:
                switch(testScore[i]){
                    case 2:
                        s++;
                        //printf("s: %d\n",s);
                        break;
                    case 3:
                        fg++;
                        //printf("fg: %d\n",fg);
                        break;
                    case 6:
                        td++;
                        //printf("td: %d\n",td);
                        break;
                    case 7:
                        td1++;
                        //printf("td1: %d\n",td1);
                        break;
                    case 8:
                        td2++;
                        //printf("td2: %d\n",td2);
                        break;
                }
                    //printf("Score: %d, testScore: %d\n, score-testScore[i]: %d\n", score,testScore[i], score-testScore[i]);
                    score = score-testScore[i];
                    compareScores(i,score,s,fg,td,td1,td2);
                    break;
            }
        }
        }
        
    
}
void searchCombinations(int score){
    int td,fg,s,td2,td1;
    td = fg = s =td2 = td1 = 0;
    int testScore[] = {2,3,6,7,8};
    
    for(int i = 0;i<5;i++){
        if(score >= testScore[i]){
            compareScores(i,score,s,fg,td,td1,td2);
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