# BMICalculator

BMI stand for Body Mass Index and is a calculation that correlates to direct measure of body fat. It is a reliable indicator of
body fatness for people, even though it does not directly measure body fat. This program is designed interacts with a nurse but may be used by clients as well. I think it will be useful for nurses to fill out the little chart to give to the doctors. I imagine him/her seeing many people in a relatively short amount of time. The nurse would benefit from this as she/he doesn't have to write anything and can forward the document to the doctor. This may be done before or during or in small intervals. I think there might be a way to incorporate this into a larger program and make it more efficient and customizable by the nurse, as their needs and desires may change. I also made sure that each user's information is saved with their name. This can later be helpful to many things relating to understanding the business' client demographic.    

There are zero global variables, and four functions, including the main.The main has a while loop, an if-else statement, calls the other three functions and send info into the outfile, named BMICalculator.txt. The overall code follows a bottom-up style. The function ConvertToInches takes the ft & inch and turns it into all inches for calculation.

BMICalculator uses the cmath to calculate the BMI, and return the float value.

WeightStatus goes through each of the bmi values and classifies them as "underweight", "normal", "overweight", "obese", and "indeterminate". The indeterminate category includes both values too big and too small. This does not influence the if-else statements in the main function but does line up really nicely with it.

The main function declares bunch of variables and functions, then tries to open up a outfile, and then checks if its open. I like to call this section 'the initialization section'. After the initialization section, there is the 'meat' of the function--if-else loops nested in a while loop. The while loop check if data is valid before calculating the bmi. The bmi section contains the output direction. Once everything is calculated and sent, the program continues downwards, where it will find the steps to prompt the user again and get new values.

Note: the outfile has only 9 sets because -99 never makes it there! :)
