#pragma once
#include<iostream>
#include "cls_person1.h";
using namespace std; 
class cls_employee :public cls_person1 {
private:
    string _title;
    int _salary;
    string _department;

public:

    cls_employee(int id, string first_name, string last_name, string email, string phone, string tit, string dep, int salary) :
        cls_person1(id, first_name, last_name, email, phone) {
        _title = tit;
        _department = dep;
        _salary = salary;

    }
    void set_title(string tit) {


        _title = tit;
    }
    string get_title() {

        return _title;
    }
    void set_salary(int salary) {

        _salary = salary;
    }
    int get_salary() {

        return _salary;
    }
    void set_dep(string dep) {

        _department = dep;
    }
    string get_dep() {

        return _department;
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

        cout << "salary     : " << _salary << endl;
        cout << "Title      : " << _title << endl;
        cout << "Department : " << _department;
        cout << "\n________________________\n";

    }
};

