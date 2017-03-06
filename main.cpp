/*
Name: BMI Calculator
Author: Shahzoda Davlatova
Date: 03-04-17
Description:

*/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
/******************converts height to inches***************************/
int ConvertToInches (int feet, int inches) {
    int in, ft, totalHeight;
    cin >> ft >> in;

    totalHeight = (ft * 12) + in;
    return totalHeight;
}
/*********************calculates the bmi******************************/
float BMICalculator (int hght, float wght){
    int height;
    float weight, bmi;

    bmi = weight / height * height;
    return bmi;
}
/***********declares the weight status based on the bmi****************/
string WeightStatus(float bmii){
    float bmi;

    if (bmi < 18.5)
        return "Underweight";
    if (bmi > 18.5 && bmi < 24.9)
        return "Normal";
    if (bmi > 25.0 && bmi < 29.9)
        return "Overweight";
    if (bmi > 30.0)
        return "Obese";
}
/*********************************************************************/
int main(){
    //variables
    int ft, in, inches, i;
    float weight, bmi;
    //functions
    int ConvertToInches (int, int);
    float BMICalculator (int, float);
    string WeightStatus(float);

    for (i = 0; i < 10; i++){
        cout << "Enter your height in ft then inches"<< endl;
        inches = ConvertToInches(ft, in);
        cout << "Now enter your weight " << endl;
        cin >> weight;
        cout << "Your BMI is " << BMICalculator(inches, weight) << ", ";
        bmi = BMICalculator(inches, weight);
        cout << "indicating your weight is in the " << WeightStatus(bmi)
             << " category for adults of your height." << endl << endl;
    }

    return 0;
}




/*














int main (){
    //function prototypes
    float ConvertToInches (int ft, int inch);
    float BMICalculator (int height, float weight);
    string WeightStatus (void);
    //variable declarations
    int heightFt, heightIn, finalHeight;
    float weight;

    cout << "Hello! Welcome to the Body Mass Index, or BMI, calculator."
         << "Please insert your height in ft and inches, but omit the "
         << "apostrophe.\n";
    cin >> heightFt >> heightIn;
    float ConvertToInches (heightFt, heightIn);

    cout << "Now, insert your weight in pounds.";
    cin >> weight;

    string BMICalculator(finalHeight, weight)


    cout << "Your BMI is " << BMICalculator() << ", "
         << "indicating your weight is in the " <<

}

*/
