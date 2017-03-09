/*
Name: BMI Calculator
Author: Shahzoda Davlatova
Date: 03-04-17
Description:
    BMI stand for Body Mass Index and is a calculation that
correlates to direct measure of body fat. It is a reliable indicator of
body fatness for people, even though it does not directly measure body
fat.
    This program is designed interacts with a nurse but may be used by
clients as well. I think it will be useful for nurses to fill out the
little chart to give to the doctors. I imagine him/her seeing many
people in a relatively short amount of time. The nurse would benefit
from this as she/he doesn't have to write anything and can forward the
document to the doctor. This may be done before or during or in small
intervals. I think there might be a way to incorporate this into a
larger program and make it more efficient and customizable by the nurse,
as their needs and desires may change. I also made sure that each user's
information is saved with their name. This can later be helpful to many
things relating to understanding the business' client demographic.
    There are zero global variables, and four functions, including the
main.The main has a while loop, an if-else statement, calls the other
three functions and send info into the outfile, named BMICalculator.txt.
    The overall code follows a bottom-up style. The function
ConvertToInches takes the ft & inch and turns it into all inches for
calculation.
    BMICalculator uses the cmath to calculate the BMI, and return the
float value.
    WeightStatus goes through each of the bmi values and classifies them
as "underweight", "normal", "overweight", "obese", and "indeterminate".
The indeterminate category includes both values too big and too small.
This does not influence the if-else statements in the main function but
does line up really nicely with it.
    The main function declares bunch of variables and functions, then
tries to open up a outfile, and then checks if its open. I like to call
this section 'the initialization section'. After the initialization
section, there is the 'meat' of the function--if-else loops nested in a
while loop. The while loop check if data is valid before calculating the
bmi. The bmi section contains the output direction. Once everything is
calculated and sent, the program continues downwards, where it will find
the steps to prompt the user again and get new values.

Note: the outfile has only 9 sets because -99 never makes it there! :)
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

/******************converts height to inches***************************/
int ConvertToInches (int feet, int inches)
{
    int totalHeight;

    totalHeight = (feet * 12) + inches;
    return totalHeight;
}
/*********************calculates the bmi******************************/
float BMICalculator (int height, float weight)
{
    float bmi;

    bmi = weight / pow(height, 2) * 703;
    return bmi;
}
/***********declares the weight status based on the bmi****************/
string WeightStatus(float bmi)
{

    if (bmi > 0 && bmi <= 18.5)
        return "underweight";
    else if (bmi > 18.5 && bmi <= 24.9)
        return "normal";
    else if (bmi > 25.0 && bmi <= 29.9)
        return "overweight";
    else if (bmi > 29.9 && bmi <= 999)
        return "obese";
    else
        return "indeterminate";
}
/*********************************************************************/
int main()
{
    // DECLERATIONS variables
    int feet, inches, inchesTotal;
    float weight, bmi;
    string firstName, lastName;
    //DECLARATIONS/PROTOTYPE functions
    int ConvertToInches (int, int);
    float BMICalculator (int, float);
    string WeightStatus(float);

    //outfile
    ofstream outfile;
    outfile.open("BMICalculator.txt");
    //outfile opened failsafe
    if ( !outfile.is_open() ) {
        cout << endl << "ERROR FILE NOT FOUND/CANNOT OPEN." << endl
             << "Please notify the IT department.";
        exit(1);
    }//end of input

    //gets the first set of data
    cout << "Please enter the first then last name, "
         << "be sure to enter ONLY TWO names you associate with:\n";
    cin >> firstName >> lastName;
    cout << "Enter the height in: ft [space] inches format:\n";
    cin >> feet >> inches;
    inchesTotal = ConvertToInches(feet, inches);
    cout << "Now enter the weight in pounds:\n";
    cin >> weight;

    //repeats while loop while zero is not given/inputted
    while (weight != 0 && inchesTotal != 0 ) {
        //if input is negative
        if (weight < 0 || inches < 0 || feet < 0 ){
            cout << "Please double check the data and try again";
        }
        //if input is too large
        else if (weight > 999 || inches > 11 || feet > 10)
            cout << "Please double check the data and try again";
        //if input values seem plausible
        else {
            cout.setf(ios::fixed,ios::floatfield);

            bmi = BMICalculator(inchesTotal, weight);
            cout.precision(1);
            cout << "The BMI is " << bmi << ", ";
            cout << "indicating the weight is in the " << WeightStatus(bmi)
                 << " category for adults of this height." << endl;
            cout << "\nEnter 0 0 0 0 0 to end the program.\n";

            //returns stuff to the outfile
            outfile.precision(0);
            outfile << "\n\nPatient id: "<< firstName << " " << lastName << endl;
            outfile << "Height: " << feet << " feet " << inches << " inches.";
            outfile.precision(3);
            outfile << "\nWeight: " << weight << " pounds.";
            outfile << "\nThe BMI of the patient is " << bmi << ", indicating "
                    << WeightStatus(bmi) << " for adults of this height.";
        }//end of else

        //gets the next set of data to prevent an infinite loop
        cout << "\n\nPlease enter the first then last name, "
             << "be sure to enter ONLY TWO names you associate with:\n";
        cin >> firstName >> lastName;
        cout << "Enter the height in: ft [space] inches format:\n";
        cin >> feet >> inches;
        inchesTotal = ConvertToInches(feet, inches);
        cout << "Now enter the weight in pounds:" << endl;
        cin >> weight;
    }//end of while

    return 0;
}//end of main



