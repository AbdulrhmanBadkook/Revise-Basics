#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
namespace Myprint{

    void print_vector_of_int(vector <int>& v_test) {

        cout << " Vector's number : \n";
        for (int& x : v_test) {

            cout << x << "\n";

        }

    }
    void Print_file_content(string file_name) {
        fstream input;
        input.open(file_name, ios::in);
        if (input.is_open())
        {
            string line;
            while (getline(input, line))
            {
                if (line!="")
                {
                    cout << line << endl;
                }
                
            }
            input.close();
        }

    }

}