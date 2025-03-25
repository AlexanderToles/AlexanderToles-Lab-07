#include <stdio.h>
float celsius_to_fahrenheit(float celsius){
    float fahrenheit;
    fahrenheit = (9.0/5.0)*celsius+32;
    return fahrenheit;
}
float fahrenheit_to_celsius(float fahrenheit){
    float celsius;
    celsius = (5.0/9.0) * (fahrenheit-32);
    return celsius;
}
float celsius_to_kelvin(float celsius){
    float kelvin;
    kelvin = celsius + 273.15;
    return kelvin;
}
float kelvin_to_celsius(float kelvin){
    float celsius;
    celsius = kelvin - 273.15;
    //printf("kelvi_to_celsius called with %f and returning %f",kelvin,celsius);
    return celsius;
}

void categorizeTemp(float tempVal,int convTarget){
    switch(convTarget){
        case 2:
            tempVal = fahrenheit_to_celsius(tempVal);
            break;
        case 3:
            tempVal = kelvin_to_celsius(tempVal);
            break;
    }

}

void convertTemp(float tempVal, int tempScale, int convTarget){
    float convertedTemp;
    switch(tempScale){
        case 1:
            switch (convTarget){
            case 2:
                convertedTemp = celsius_to_fahrenheit(tempVal);
                break;
            case 3:
                convertedTemp = celsius_to_kelvin(tempVal);
                break;
            }
            break;
        case 2:
            switch (convTarget){
            case 1:
                convertedTemp = fahrenheit_to_celsius(tempVal);
                break;
            case 3:
                convertedTemp = fahrenheit_to_celsius(tempVal);
                convertedTemp = celsius_to_kelvin(convertedTemp);
                break;
            }
            break;
        case 3:
            switch (convTarget){
            case 1:
                convertedTemp = kelvin_to_celsius(tempVal);
                break;
            case 2:
                convertedTemp = kelvin_to_celsius(tempVal);
                convertedTemp = celsius_to_fahrenheit(convertedTemp);
                break;
            }
            break;
    }
    printf("converted temp: %f\n",convertedTemp);
}

int validateSelect(float tempVal, int tempScale, int convTarget){
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