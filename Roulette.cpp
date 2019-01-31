/*
Roulette Project
This program simulates a game of roulette with 10,000,000 tries
and checks statistical outcome of the random number generator.

Created by Angelo on 2/15/14.
Copyright (c) 2015 Angelo. All rights reserved.
*/

#include <iostream>
#include <cstdlib>      // For rand and srand
#include <ctime>        // For system time

using namespace std;

// Function prototypes that will return percent values

double singleBet( );
double firstSpreadBet( );

int main(int argc, const char * argv[])
{
    
    // Seed random number generator with system time
    unsigned seed = time(0);
    srand(seed);
    
    // Call function 3 times to calculate 3 probabilites for a single bet
    
    double probability = 0;
    for (int index = 0; index < 3; index++)
    {
        probability += singleBet( );
        cout << endl;       // skp line
    }
    
    // Calculate and display average probability
    
    cout << "The average probability of 3 tests is " << (probability / 3) * 100 << "%. " << endl;
    cout << endl;
    
    // Reset probability variable and calculate probabilites for a spread of winning numbers between 1 and 18
    
    probability = 0;
    for (int index = 0; index < 3; index++)
    {
        probability += firstSpreadBet( );
        cout << endl;       // skip line
    }
    
    // Calculate and display average probability
    
    cout << "The average probability of 3 tests is " << (probability / 3) * 100 << "%. " << endl;
    cout << endl;
    
    return 0;
}

// End main


// Function singleBet calculates the percentage of a winning number of a bet, the number 3, and calculates the chance of winning out of
// 10,000,000 times from a random number generator.

double singleBet( )
{
    // Local variables
    
    int total = 0, winner = 0, index = 0, random, bet = 3;
    double percent;
    
    // Loop to compare random numbers to the bet
    
    for (index; index < 10000000; index++)
    {
        // Formula for random values from 0 to 39
        random = 1 + rand() % 38;
        if (random == bet)
            winner++;            // increment to keep track of wins
        total++;                    // increment total to keep track of trials
    }
    
    // Calculate percent and return value
    
    percent =  (double) winner / total;             // typecast for decimal output
    
    // Display results and return percent to main
    
    cout << "The total number of wins for a bet of 3 is " << winner << "." << endl;
    cout << "The total number of trials is " << total  << "." << endl;
    cout << "The probability for a single digit winning is " << percent * 100 << "%." << endl;
    
    return percent;
}
// End singleBet function


// Function firstSpreadBet does same as singleBet but calculates the bet belonging to a spread of numbers from 1 to 18
// over the total number of outcomes.

double firstSpreadBet( )
{
    // Local variables
    
    int total = 0, winner = 0, index = 0, random;
    double percent;
    
    // Loop to compare random numbers to the bet
    
    for (index; index < 10000000; index++)
    {
        // Formula for random values from 1 to 38
        random = 1 + rand( ) % 38;
        if ( 1 <= random && random <= 18 )
            winner++;            // increment to keep track of winning numbers between 1 and 18
        total++;                    // increment total to keep track of trials
    }
    
    // Calculate percent and store value
    
    percent =  (double) winner / total;             // typecast for decimal output
    
    // Display results and return percent
    
    cout << "The total number of wins for a winning spread of 1 to 18 is " << winner << "." << endl;
    cout << "The total number of trials is " << total  << "." << endl;
    cout << "The probability for a winning number in a spread of 1 to 18 is " << percent * 100 << "%." << endl;
    
    return percent;
}
// End firstSpreadBet function


// End program

