/**
 * @author Kofi Ampim Darkoh
 * @date 03/19/2022
 * @brief this program is a card game and we are practising command line arguments,
 * arrays and random number generators
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int random(int numCards);
bool isTriangular(int number);
/**
 * @brief main where we call all functions and print results to the screen
 *
 * @param argc argument count
 * @param argv array of type string
 * @return int
 */
int main(int argc, char *argv[])
{
    srand(time(nullptr));
    int cards;
    cout << "argc: " << argc << endl;
    for (int i = 0; i < argc; i++)
    {
        string temp = argv[i];
        if (argc > 2)
        {
            cout << "Error: too many parameters";
            exit(0);
        }
        if (argc == 1)
        {
            cards = 45;
        }
        if (argc == 2)
        {
            cards = atoi(argv[1]);
        }
        cout << "Arg " << i << ": " << temp << endl;
        cards = atoi(argv[i]);
    }
    cout << isTriangular(cards) << endl;
    cout << random(cards) << endl;
    return 0;
}

/**
 * Function isTriangular returns true if the number entered is triangular
 * @param number triangular number
 * @return true if number is triangular
 * @return false if number is not triangular
 */
bool isTriangular(int number)
{
    int check = 0;
    for (int i = 0; i < number; i++)
    {
        check = check + i;
        if (number == check)
        {
            cout << "number of cards: " << number << endl;
            cout << "Boolean value: ";
            return true;
        }
    }
    cout << "Error: the number " << number << " is not a triangular number " << endl;
    return false;
}

/**
 * @brief random
 *
 * @param numCards
 * @return int
 */
int random(int numCards)
{
    int rounds = 0;
    int answer;
    int result;
    int randomNumber;
    int arr[] = {};
    int numPiles = 0;
    while (numCards != 0)
    {
        randomNumber = rand() % numCards + 1;
        int i = 0;
        arr[i] = randomNumber;
        cout << arr[i] << "\t";
        i++;
        numCards = numCards - randomNumber;
        numPiles++;
        for(int n = 0; n > 1; n++)
        {
            result = arr[n];
            if(result > 1)
            {
                answer = result - 1;
                cout << answer << "\t";
            }
           
        }
    }
    rounds++;
    cout << "\n" << "Number of rounds: " ;
    return rounds;
}