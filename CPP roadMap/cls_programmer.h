#pragma once
#include<iostream>
#include "cls_employee.h";
using namespace std;
class cls_programmer :public cls_employee {

    string _main_programming_language;
public:

    cls_programmer(int id, string first_name, string last_name, string email, string phone, string tit, string dep, int salary, string pr)
        :cls_employee(id, first_name, last_name, email, phone, tit, dep, salary) {

        _main_programming_language = pr;

    }
    void set_programming_language(string language) {

        _main_programming_language = language;

    }

    string get_programming_language() {

        return _main_programming_language;

    }
    void print_details() {

        cout << "INFO\n\n";
        cout << "______________________\n";
        cout << "ID         : " << get_id() << endl;
        cout << "First Name : " << get_f_name() << endl;
        cout << "Last name  : " << get_f_name() << endl;
        cout << "Full Name  : " << full_name() << endl;
        cout << "Email      : " << get_email() << endl;
        cout << "Phone      : " << get_phone() << endl;

        cout << "salary     : " << get_salary() << endl;
        cout << "Title      : " << get_title() << endl;
        cout << "Department : " << get_dep() << endl;
        cout << "Main Programming language : " << _main_programming_language;
        cout << "\n________________________\n";



    }
};

