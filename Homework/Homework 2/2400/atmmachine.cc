#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
//1. Variables
    const double ACCOUNT_BALANCE = 1000.00;
    int pin = 1234;
    int attempts = 3;
    double withdrawal_amount;
    char transaction;

//2. Customer Input 
  do{
    cout << "Welcome to Bobcats Bank ATM machine" << endl; 
    cout << "Enter your PIN number: ";
    cin >> pin;
    while (attempts > 0)
    {
        if(pin == 1234)
        {
            cout << "Enter the amount you wish to withdraw: $";
            cin >> withdrawal_amount;
            while(true)
            {
                if (withdrawal_amount <= 1000.00){
                    cout << "Your current balance is $" << fixed << setprecision(2) << (ACCOUNT_BALANCE - withdrawal_amount) << endl;
                    break;
                }else{
                    cout << "You do not have enough funds, please try again" << endl;
                    cout << "Enter the amount you wish to withdraw: $";
                    cin >> withdrawal_amount;
                }
            }
            break;
        }
        else {
            attempts--;
            if(attempts > 0){
                cout << "Wrong PIN, please re-enter your PIN" << endl;
                cout << "You have " << attempts << "left" << endl;
                cout << "Enter the PIN number: ";
                cin >> pin;
            }
            else{
                cout << "Too many tries your account has been locked" << endl;
            }
        }
    }
    cout << "Another Transaction? " << endl;
    cin >> transaction; 
  } while (transaction == 'y' && (ACCOUNT_BALANCE > 0));
     return 0;
}