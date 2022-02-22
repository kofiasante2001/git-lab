#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>
using namespace std;

//These represent the bar code
const string one = ":::||";
const string two = "::|:|";
const string three = "::||:";
const string four = ":|::|";
const string five = ":|:|:";
const string six = ":||::";
const string seven = "|:::|";
const string eight = "|::|:";
const string nine = "|:|::";
const string zero = "||:::";

string getDigitCode(char digit);
int getCheckDigitValue(int sum);

/**
 * @brief This is the main function where we can print results to the screen
 *
 * @return int
 */
int main()
{
     int total;
        int number1;
        int number2;
        int number3;
        int number4;
        int number5;

        char var1;
        char var2;
        char var3;
        char var4;
        char var5;
        char answer;
    do
    {
        string zip;
        cout << "Enter a zipcode: ";
        cin >> zip;
        if (zip.length() != 5)
        {
            cout << "Error: Code is invalid" << endl;
        }
        else
        {
            cout << "Code: | ";
            var1 = zip.at(0);
            cout << getDigitCode(var1) << " ";
            number1 = int(var1) - 48;

            var2 = zip.at(1);
            cout << getDigitCode(var2) << " ";
            number2 = int(var2) - 48;

            var3 = zip.at(2);
            cout << getDigitCode(var3) << " ";
            number3 = int(var3) - 48;

            var4 = zip.at(3);
            cout << getDigitCode(var4) << " ";
            number4 = int(var4) - 48;

            var5 = zip.at(4);
            cout << getDigitCode(var5) << " ";
            number5 = int(var5) - 48;

            total = number1 + number2 + number3 + number4 + number5;
            getCheckDigitValue(total);
            cout << " |" << endl;
        }
        cout << "More codes? (y/n)" << endl;
        cin >> answer;
    } while (answer == 'y');
    return 0;
}

/**
 * @brief This function returns a barcode for single digit
 *
 * @param digit the function has a parameter called digit
 * @return string the function returns a string
 */
string getDigitCode(char digit)
{
    if (digit == '1')
    {
        return one;
    }
    if (digit == '2')
    {
        return two;
    }
    if (digit == '3')
    {
        return three;
    }
    if (digit == '4')
    {
        return four;
    }
    if (digit == '5')
    {
        return five;
    }
    if (digit == '6')
    {
        return six;
    }
    if (digit == '7')
    {
        return seven;
    }
    if (digit == '8')
    {
        return eight;
    }
    if (digit == '9')
    {
        return nine;
    }
    if (digit == '0')
    {
        return zero;
    }
    return " ";
}

/**
 * @brief This function returns the check digit
 *
 * @param sum the function has a parameter called sum
 * @return
 */
int getCheckDigitValue(int sum)
{
    int check;
    int rem = sum % 10;
    if (rem == 0)
    {
        char conv = '0' + rem;
        cout << getDigitCode(conv);
    }
    else
    {
        check = 10 - rem;
        char conv1 = '0' + check;
        cout << getDigitCode(conv1);
    }
    return sum;
}