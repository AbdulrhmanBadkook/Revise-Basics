#pragma once
#include <iostream>


using namespace std;
class clsInputValidate
{
public:
    static int read_only_number() {
        int a;
        cout << "Please enter a numebr : " << endl;
        cin >> a;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Number, Enter a valid one: " << endl;
            cin >> a;
        }
        return a;
    }
    static int in_validate_number() {
        int input;

        do
        {
            cout << "Please enter a positive number : ";
            cin >> input;
        } while (input < 0);
        return input;

    }
};

