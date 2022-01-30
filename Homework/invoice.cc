/**
* @file : invoice.cc
* @author : Kofi Asante Ampim Darkoh
* @date : 01/26/2022
* @brief : This is a program for processing store orders
*
*/

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


int main ()
{
    //Customers should enter 's' for Samsung products and 'v' for View Sonic programs

    //1. Variable Declarations
    string residence;
    string monitor_brand;
    int quantity;
    const double Price = 190.00;
    const double Price_2 = 170.00;
    const double Tax = 1.07;
    const double Discount_Rate = 0.95;
   
   //2. Customer Input
   cout << "First Customer" << endl;
   cout << "Monitor brand: ";
   cin >> monitor_brand; 
   cout << "Quantity: ";
   cin >> quantity;
   const double Sub_Total_Price = quantity * Price;
   cout << "Ohio Resident: ";
   cin >> residence;
   cout << fixed << setprecision(2) <<"Price: $" << Price << endl;
   cout << fixed << setprecision(2) <<"Sub total price: $" << Sub_Total_Price << endl;
   
   //3. Calculations
   if (quantity > 2){
       cout << fixed << setprecision(2) << Sub_Total_Price * Discount_Rate;
   } else {
       cout << "Discount: $0.0"<<endl;
   }
    if(residence == "Yes"){
        cout << fixed << setprecision(2) << "Total: " << "$" << Sub_Total_Price * Tax << endl;
    } else {
        cout << Sub_Total_Price << endl;
    } 
   
   //4. Customer Input  
   cout << "Second Customer" << endl;
   cout << "Monitor brand: " << endl;
   cin >> monitor_brand;
   cout << "Quantity: " << endl;
   cin >> quantity;
   const double Sub_Total_Price_2 = quantity * Price_2; 
   cout << "Ohio Resident: ";
   cin >> residence;
   cout << fixed << setprecision(2) <<"Price: $" << Price_2 << endl;
   cout << fixed << setprecision(2) <<"Sub total price: $" << Sub_Total_Price_2 << endl;
   
   //5. Calculations
   if (quantity > 2){
       cout << fixed << setprecision(2) << "Total: $" << Sub_Total_Price_2 * Discount_Rate << endl;
   } else {
       cout << "Discount: $0.0"<<endl;
   }
   if(residence == "Yes"){
        cout << fixed << setprecision(2) << "Total: $" << Sub_Total_Price_2 * Tax << endl;
    } else {
        cout << Sub_Total_Price << endl;
    } 


    //6. Customer Input
    cout << "Third Customer" << endl;
    cout << "Monitor brand: " << endl;
    cin >> monitor_brand;
    cout << "Quantity: " << endl;
    cin >> quantity;
    const double Sub_Total_Price_3 = quantity * Price_2;
    cout << "Ohio Resident: " << endl;
    cin >> residence;
    cout << fixed << setprecision(2) <<"Price: $" << Price_2 << endl;
    cout << fixed << setprecision(2) <<"Sub total price: $" << Sub_Total_Price_3 << endl;

    //7. Calculations
  if (quantity > 2){
       cout << fixed << setprecision(2) << "Pre Tax Total: $" << Sub_Total_Price_3 * Discount_Rate << endl;
   } else {
       cout << "Discount: $0.0"<<endl;
   }
   if(residence == "Yes"){
        cout << fixed << setprecision(2) << "Total: " << "$" << Sub_Total_Price_3 * Discount_Rate * Tax << endl;
    } else {
        cout << Sub_Total_Price_3;
    } 

    return 0;
} 