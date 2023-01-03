//
//  Q4.cpp
//  EC327_PA1
//
//  Created by Brennan Mahoney on 10/5/22.
//


#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>


using namespace std;

int runningsum; // makes it a global variable

int blackjack(int num1, int num2) //makes first function
{
    if (num1 >10 || num1<2)
    {
        return -1;
    }
    if (num2 >10 || num1<2)
    {
        return -1;
    }
    int total = num1 + num2;
    
    return total;
}

int blackjack(char let1, char let2) // second function
{
    int num1, num2;
    if (let1 == 'A'){
        num1 = 11;
    }
     else if (let1 == 'J' || let1 == 'Q' || let1 == 'K'){
        num1 = 10;
    }
    else
    {
        return -1;
    }
    
    if (let2 == 'A'){
        num2 = 11;
    }
    else if (let2 == 'J' || let2 == 'Q' || let2 == 'K'){
        num2 = 10;
    }
    else
    {
        return -1;
    }
    
    
    int total = num1 + num2;
    
    return total;
}

int blackjack(int num1, char let1) // third function
{
    int num2;
    if (let1 == 'A'){
        num2 = 11;
    }
    else if (let1 == 'J' || let1 == 'Q' || let1 == 'K'){
        num2 = 10;
    }
    else
    {
        return -1;
    }
    if (num1 >10 || num1<2)
    {
        return -1;
    }
    
    int total = num1 + num2;
    
    return total;
}

int blackjack(char let1, int num1)
{
    int num2;
    if (let1 == 'A')
    {
        num2 = 11;
    }
    else if (let1 == 'J' || let1 == 'Q' || let1 == 'K')
    {
        num2 = 10;
    }
    else
    {
        return -1;
    }
    
    int total = num1 + num2;
    
    return total;
}

int blackjack(int num1)
{
    runningsum += num1;
    if (runningsum <= 21)
    {
    return (runningsum);
    }
    else
    {
        return -1;
    }
}

int blackjack(char let1)
{
    int num1;
    if (let1 == 'A')
    {
        num1 = 11;
    }
   else if (let1 == 'J' || let1 == 'Q' || let1 == 'K')
    {
        num1 = 10;
    }
   else{
       return -1;
   }
    runningsum += num1;
    if (runningsum <= 21)
    {
    return (runningsum);
    }
    else
    {
        return -1;
    }
}

int main() {
    cout << "Welcome to EC327 Blackjack" << endl;
    //variables
    char decision;
    srand(time(0));
    int number1 = rand() % 12 + 2; // makes random number
    int number2 = rand() % 12 + 2;
    char let1, let2;
    int total;
    
    // converting numbers to the face cards

    if(number1 == 11)
    {
        let1 = 'A';
    }
    if(number2 == 11)
    {
        let2 = 'A';
    }
    
    if(number1 == 12)
    {
        let1 = 'J';
    }
    if(number2 == 12)
    {
        let2 = 'J';
    }
    
    if(number1 == 13)
    {
        let1 = 'Q';
    }
    if(number2 == 13)
    {
        let2 = 'Q';
    }
    
    if(number1 == 14)
    {
        let1 = 'K';
    }
    if(number2 == 14)
    {
        let2 = 'K';
    }

    
    if ((number1 >=2 && number1<=10) && (number2 >=2 && number2<=10)) // two non face cards
    {
        total = blackjack(number1, number2);
        if (total == -1)
        {
            cout << "ERROR" << endl;
        }
        runningsum = total;
    }
    
    if ((number1 >=2 && number1>10) && (number2 >=2 && number2<=10))// one face card and one non face card
    {
        total = blackjack(let1, number2);
        if (total == -1)
        {
            cout << "ERROR" << endl;
        }
        runningsum = total;
    }
    
    if ((number1 >=2 && number1<=10) && (number2 >=2 && number2>10)) // one non face card and one face card
    {
        total = blackjack(number1, let2);
        if (total == -1)
        {
            cout << "ERROR" << endl;
        }
        runningsum = total;
    }
    
    if ((number1 >=2 && number1>10) && (number2 >=2 && number2>10))// two face cards
    {
        total = blackjack(let1 , let2);
        if (total == -1)
        {
            cout << "ERROR" << endl;
        }
        runningsum = total;
    }
    // to check to see the total
    
    cout << "Total: " << runningsum << endl;
    cout << "Draw again (y/n)" << endl; // asking to go again, checks this in the while loop
    cin >> decision;
    
    while (decision == 'y' && total<21 && total !=-1) // loops until they opt out, win or lose
    {
        number1 = rand() % 12 + 2;
        
            if (number1 >=2 && number1<=10)
                {
                total = blackjack(number1);
                }
            else if (number1 >=2 && number1>10)
                {
                    if(number1 == 11)
                    {
                        let1 = 'A';
                    }
                    if(number1 == 12)
                    {
                        let1 = 'J';
                    }
                    if(number1 == 13)
                    {
                        let1 = 'Q';
                    }
                    if(number1 == 14)
                    {
                        let1 = 'K';
                    }
                    total = blackjack(let1);
                }
        
        if (total == -1)
        {
            cout << "FAILED BLACKJACK" << endl;
        }
        else if(total == 21)
        {
            cout << "WON BLACKJACK" << endl;
        }
        else
        {
            cout << "Total: " << total << endl;
            cout << "Draw again (y/n)" << endl;
            cin >> decision;
        }

    }
    
    if (total <21 && total != -1)
    {
        cout << "You quit with: "<< total << endl; // this appears only if they select no as a decision
    
    }
    
    
    return 0;
}
