#include <iostream>
#include <string>
#include "openWindow.h"
using namespace std;

int main()
{

    cout << "Select Option:\n";
    cout << "1. Digital\n";
    cout << "2. Analog\n";
    int choice;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        display();
        break;
    case 2:
        handleAnalogOption();
        break;
    }
    return 0;
}
