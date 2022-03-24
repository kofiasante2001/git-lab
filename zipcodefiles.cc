#include <iostream>
 #include <iomanip>
 #include <cstdlib>
 #include <string>
 #include <cctype>
 #include <fstream>
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
 bool isValid(string zipcode);

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
         bool value;
         int remainder;
         int checker;

         ifstream inStream;
         ofstream outStream;
         string file_name = "input1.txt";
         inStream.open(file_name);
         if(inStream.fail())
         {
             outStream << "The file did not open" << " " << file_name << endl;
             exit(0);
         }
         
         string fileName = "output2.txt";
         outStream.open(fileName);
         if(outStream.fail())
         {
             outStream << "The file did not open" << fileName << endl;
             exit(0);
         }
     do
     {
         string zip;
         inStream >> zip;
         outStream << "Enter a zipcode: " << zip << endl;

         if (zip.length() != 5)
         {
             outStream << "Error: Code is invalid" << endl;
         }
         value = isValid(zip);
         if(value == true)
         {
             outStream << "Code: | ";
             var1 = zip.at(0);
             outStream << getDigitCode(var1) << " ";
             number1 = int(var1) - 48;

             var2 = zip.at(1);
             outStream << getDigitCode(var2) << " ";
             number2 = int(var2) - 48;

             var3 = zip.at(2);
             outStream << getDigitCode(var3) << " ";
             number3 = int(var3) - 48;

             var4 = zip.at(3);
             outStream << getDigitCode(var4) << " ";
             number4 = int(var4) - 48;

             var5 = zip.at(4);
             outStream << getDigitCode(var5) << " ";
             number5 = int(var5) - 48;

             total = number1 + number2 + number3 + number4 + number5;
             getCheckDigitValue(total);
             remainder =  total % 10;
             if(remainder == 0)
             {
                 char convert = remainder + '0';
                 outStream << getDigitCode(convert);
             }
             else
             {
                 checker = 10 - remainder;
                 char convert1 =  checker + '0';
                 outStream << getDigitCode(convert1);
             }
             outStream << " |" << endl;
             outStream << "More codes? (y/n)" ;
         }
         else
         {
             outStream << "Code is invalid"<< endl;
             outStream << "More codes? (y/n)";
         }
         inStream >> answer;
     } while (answer == 'y');
     inStream.close();
     outStream.close();
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
  * @return int
  */
 int getCheckDigitValue(int sum)
 {
     int check;
     int rem = sum % 10;
     if (rem == 0)
     {
         char conv =  rem + '0';
          getDigitCode(conv);

     }
     else
     {
         check = 10 - rem;
         char conv1 =  check + '0';
          getDigitCode(conv1);

     }
     return sum;
 }

 /**
  * @brief This function checks to see if the code entered is a number
  * 
  * @param zipcode
  * @return bool 
  */ 
 bool isValid(string zipcode)
 {
     string a;
     for(int i = 0; i < 5; i++)
     {
         if(isdigit(zipcode.at(i)))
         {
             a = a + "a";
         }
         else
         {
             a = a + "b";
         }
     }
     if(a == "aaaaa")
     {
         return true;
     }
     else
         return false;
 } 