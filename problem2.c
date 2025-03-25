#include <stdio.h>
void printMenu(){
    float tempVal;
    int tempScale;
    int convTarget;
    printf("Enter temperature: ");
    scanf("%f",&tempVal);
    printf("\nChoose current scale: \n\t1)Celcius\n\t2)Fahrenheit\n\t3)Kelvin\nSelection(1-3): ");
    scanf("%d",&tempScale);
    printf("\nConvert to: \n\t1)Celcius\n\t2)Fahrenheit\n\t3)Kelvin\nSelection(1-3): ");
    scanf("%d",&convTarget);
}

int main(){
    printMenu();
    return 0;
}