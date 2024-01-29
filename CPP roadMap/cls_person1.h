#pragma once
#include<iostream>
using namespace std;
class cls_person1 {

private:
    int _Id;
    string _f_name;
    string _l_name;
    string _email;
    string _phone;
public:

    cls_person1(int id, string first_name, string last_name, string email, string phone) {

        _Id = id;
        _f_name = first_name;
        _l_name = last_name;
        _email = email;
        _phone = phone;
    }
    void send_email(string header, string msg) {

        cout << "sent to successfully   " << _email << " \n " << header << " " << msg;
    }
    void send_sms(string msg) {

        cout << "sent to successfully  " << _phone << " \n" << msg;
    }
    void print_details() {

        cout << "INFO\n\n";
        cout << "______________________\n";
        cout << "ID : " << _Id << endl;
        cout << "First Name : " << _f_name << endl;
        cout << "Last name : " << _l_name << endl;
        cout << "Full Name : " << full_name() << endl;
        cout << "Email : " << _email << endl;
        cout << "Phone : " << _phone << endl;
        // cout << "Salary : " << cls_employee::get_salary() << endl;
        cout << "________________________\n";

    }
    int get_id() {

        return _Id;
    }
    void set_f_name(string fname) {

        _f_name = fname;
    }
    string get_f_name() {

        return _f_name;
    }
    void set_l_name(string lname) {

        _l_name = lname;
    }
    string get_l_name() {

        return _l_name;
    }
    void set_email(string email) {

        _email = email;
    }
    string get_email() {

        return _email;
    }
    void set_phone(string phone) {

        _phone = phone;
    }
    string get_phone() {

        return _phone;
    }


    string full_name() {

        return _f_name + " " + _l_name;
    }

};

