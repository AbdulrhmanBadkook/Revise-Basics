#pragma once
#include <iostream>

using namespace std;
namespace readin {

    int read_only_number() {
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
    int in_validate_number() {
        int input;

        do
        {
            cout << "Please enter a positive number : ";
          cin >> input;
        } while (input < 0);
        return input;

    }

    void input_array_element(int No_element[100], int& arry_length) {

        cout << "Please enter how many element do you need : ";
        cin >> arry_length;
        for (int i = 1; i <= arry_length; i++)
        {
            cout << "Please enter Element  [ " << i << " ] :";
            cin >> No_element[i];
        }

    }

}
