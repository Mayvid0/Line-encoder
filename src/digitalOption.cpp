#include <iostream>
#include <string>
#include "openWindow.h"
using namespace std;

void display()
{
    cout << "Enter a binary data stream: ";
    string dataStream;
    cin >> dataStream;
    for (int i = 0; i < dataStream.size(); i++)
    {
        if (dataStream[i] != '0' && dataStream[i] != '1')
        {
            cout << "Invalid input.Try again\n";
            handleDigitalOption(dataStream);
            return;
        }
    }
    handleDigitalOption(dataStream);
}

void handleDigitalOption(string &dataStream)
{

    int choice;
    while (true)
    {
        cout << "\n What type of encoding would you like to have: (Enter 1-5)\n";
        cout << "1. NRZ-L\n";
        cout << "2. NRZ-I\n";
        cout << "3. Manchester\n";
        cout << "4. Differential Manchester\n";
        cout << "5. AMI\n";
        cin >> choice;

        if (choice >= 1 && choice <= 5)
        {
            if (choice == 5)
            {
                cout << "\nWould you like to scramble it:\n";
                cout << "1. B8ZS\n";
                cout << "2. HDB3\n";
                int choice2;
                cin >> choice2;

                if (choice2 == 1)
                {
                    choice = 51;
                }
                else if (choice2 == 2)
                {
                    choice = 52;
                }
                else
                {
                    choice = 53;
                }
            }

            lineEncoding(dataStream, choice);
            break; 
        }
        else
        {
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    }
}
