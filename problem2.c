#include <stdio.h>



void convertTemp(int tempVal, int tempScale, int convTarget){
    switch(tempScale){
        case 1:
            switch (convTarget){
            case 2:
            case 3:
            }
        case 2:
            switch (convTarget){
            case 1:
            case 3:
            }
        case 3:
            switch (convTarget){
            case 1:
            case 3:
            }
        
    }
}

int validateSelect(int tempVal, int tempScale, int convTarget){
    int retryVal = 0;
    if(tempScale > 3 || tempScale < 1){
        printf("Invalid selection for temperature scale. (Value must be between 1-3)\n");
        retryVal = 1;
    }
    if(convTarget > 3 || convTarget < 1){
        printf("Invalid selection for conversion target. (Value must be between 1-3)\n");
        retryVal = 1;
    }
    if(retryVal == 0 && convTarget == tempScale){
        printf("Invalid selection for conversion target. (Conversion target can not match chosen scale)\n");
        retryVal = 1;
    }
    if(tempVal < 0 && tempScale == 3){
        printf("Invalid temperature value. (Kelvin Temperatures cannot be negative.)\n");
        retryVal = 1;
    }
    return retryVal;
}

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

    if(validateSelect(tempVal,tempScale,convTarget) == 1){
        printMenu();
    }
    else{
        convertTemp(tempVal,tempScale,convTarget);
    }
}



int main(){
    printMenu();
    return 0;
}