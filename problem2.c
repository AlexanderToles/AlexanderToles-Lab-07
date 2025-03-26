//  EECS 348 LAB 07 PROBLEM 2
//  Temperature Conversion Utility
//  INPUT: Temperature, temperature scale, converted scale
//  OUTPUT: Converted temperature, temperature category, weather advisory
//  ALEXANDER TOLES      
//  MARCH 25 2025

#include <stdio.h>

float celsius_to_fahrenheit(float celsius){ //takes celsius, return fahrenheit
    float fahrenheit;
    fahrenheit = (9.0/5.0)*celsius+32;
    return fahrenheit;
}
float fahrenheit_to_celsius(float fahrenheit){ //takes fahrenheit, returns celsius
    float celsius;
    celsius = (5.0/9.0) * (fahrenheit-32);
    return celsius;
}
float celsius_to_kelvin(float celsius){ //takes celsius, returns kelvin
    float kelvin;
    kelvin = celsius + 273.15;
    return kelvin;
}
float kelvin_to_celsius(float kelvin){ //takes kelvin, returns celsius
    float celsius;
    celsius = kelvin - 273.15;
    return celsius;
}

void categorizeTemp(float tempVal,int convTarget){ //takes the temperature, and its converted scale
    int celsius; //initialize celsius variable, used for categorization
    char tempLabel; //create label for temperature scale
    switch(convTarget){ //for each scale, convert to celsius if necessary, and assign it an apporpriate label
        case 1:
            celsius = tempVal;
            tempLabel = 'C';
            break;
        case 2:
            celsius = fahrenheit_to_celsius(tempVal);
            tempLabel = 'F';
            break;
        case 3:
            celsius = kelvin_to_celsius(tempVal);
            tempLabel = 'K';
            break;
    }
    if(celsius < 0){ //categorize the temperature, print the temp and its label, and then the category and weather advisory
        printf("Converted Temperature: %f%c\n",tempVal,tempLabel);
        printf("Temperature Category: Freezing\n");
        printf("Weather Advisory: Stay indoors, wear winter clothing.\n");
    }
    if(celsius >= 0 && tempVal < 10){
        printf("Converted Temperature: %f%c\n",tempVal,tempLabel);
        printf("Temperature Category: Cold\n ");
        printf("Weather Advisory: Wear warm clothing. \n");

    }
    if(celsius >= 10 && tempVal < 25){
        printf("Converted Temperature: %f%c\n",tempVal,tempLabel);
        printf("Temperature Category: Comfortable\n");
        printf("Weather Advisory: You should feel comfortable.\n");

    }
    if(celsius >= 25 &&  tempVal < 35){
        printf("Converted Temperature: %f%c\n",tempVal,tempLabel);
        printf("Temperature Category: Hot\n");
        printf("Weather Advisory: Dress lightly, drink more water.\n ");

    }
    if(celsius >= 35){
        printf("Converted Temperature: %f%c\n",tempVal,tempLabel);
        printf("Temperature Category: Extreme heat\n");
        printf("Weather Advisory: Stay indoors, dress lightly\n");

    }
}

float convertTemp(float tempVal, int tempScale, int convTarget){ //takes in the temperature, and the menu selections
    float convertedTemp; //initialize the convertedTemp value
    switch(tempScale){ //for each temperature scale selection, convert it based on its conversion target selection.
        case 1: //if celsius is the current scale
            switch (convTarget){
            case 2: //if fahrenheit is the conversion scale
                convertedTemp = celsius_to_fahrenheit(tempVal); //set converted temp to the returned value of the conversion function
                break;
            case 3: //if kelvin is the conversion scale
                convertedTemp = celsius_to_kelvin(tempVal);
                break;
            }
            break;
        case 2: //if fahrenheit is the current scale
            switch (convTarget){
            case 1: //if celsius is the conversion scale
                convertedTemp = fahrenheit_to_celsius(tempVal);
                break;
            case 3: //if kelvin is the conversion scale
                convertedTemp = fahrenheit_to_celsius(tempVal); //convert to celsius, and then to kelvin, so an extra function is not needed
                convertedTemp = celsius_to_kelvin(convertedTemp);
                break;
            }
            break;
        case 3: //if kelvin is the current scale
            switch (convTarget){
            case 1: //if celsius is the conversion scale
                convertedTemp = kelvin_to_celsius(tempVal);
                break;
            case 2: //if fahrenheit is the conversion scale
                convertedTemp = kelvin_to_celsius(tempVal); //convert to celsius and then fahrenheit
                convertedTemp = celsius_to_fahrenheit(convertedTemp);
                break;
            }
            break;
    }
    return convertedTemp; //return the converted temp
}

int validateSelect(float tempVal, int tempScale, int convTarget){ //takes in the temperature, and the menu select variables
    int retryVal = 0; //if retryVal gets set to 1, then the menu needs to print again.
    if(tempScale > 3 || tempScale < 1){ //if temperature scale select is outside of range, print error and set retryVal to 1
        printf("Invalid selection for temperature scale. (Value must be between 1-3)\n");
        retryVal = 1;
    }
    if(convTarget > 3 || convTarget < 1){ //if the conversion scale select is out of range, print error, and set retryVal to 1
        printf("Invalid selection for conversion target. (Value must be between 1-3)\n");
        retryVal = 1;
    }
    if(retryVal == 0 && convTarget == tempScale){ //if targets in range, and they are equal, print error
        printf("Invalid selection for conversion target. (Conversion target can not match chosen scale)\n");
        retryVal = 1;
    }
    if(tempVal < 0 && tempScale == 3){ //if temperature is negative and kelvin is selected scale, print error
        printf("Invalid temperature value. (Kelvin Temperatures cannot be negative.)\n");
        retryVal = 1;
    }
    return retryVal;
}

void printMenu(){
    float tempVal; //initialize the temperature value, and a select for the temperature scale and the desired conversion scale
    int tempScale;
    int convTarget;
    printf("Enter temperature: ");
    scanf("%f",&tempVal);
    printf("\nChoose current scale: \n\t1)Celcius\n\t2)Fahrenheit\n\t3)Kelvin\nSelection(1-3): "); //print menu option, store value into variable
    scanf("%d",&tempScale);
    printf("\nConvert to: \n\t1)Celcius\n\t2)Fahrenheit\n\t3)Kelvin\nSelection(1-3): ");
    scanf("%d",&convTarget);

    if(validateSelect(tempVal,tempScale,convTarget) == 1){ //if validate select requires a reprint, do so
        printMenu();
    }
    else{
        categorizeTemp(convertTemp(tempVal,tempScale,convTarget),convTarget); //else, passthe converted temperature into categorizeTemp
    }
}



int main(){
    printMenu(); //start by printing the menu
    return 0;
}