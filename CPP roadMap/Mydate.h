#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
namespace Mydate {
    enum en_month {
        January = 1, Feburay = 2, March = 3, April = 4, May = 5, June = 6, July = 7,
        August = 8, September = 9, October = 10, November = 11, December = 12
    };
    struct str_date {

        short year;
        short month;
        short day;
        short day_to_Add;

    };
    int check_number(string msg) {
        int num = 0;
        cout << msg;
        cin >> num;
        return num;

    }
    string return_month_name(int month) {

        switch (month)
        {
        case en_month::January:
            return " January";


        case en_month::Feburay:
            return " Feburay";

        case en_month::March:
            return " March";


        case en_month::April:
            return " April";

        case en_month::May:
            return " May";

        case en_month::June:
            return " June";

        case en_month::July:
            return " July";

        case en_month::August:
            return " August";

        case en_month::September:
            return " September";

        case en_month::October:
            return " October";

        case en_month::November:
            return " November";

        case en_month::December:
            return " December";

        default:
            return "Wrong day";

        }

    }




     



    bool leap_year(int year) {

        return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));

    }
    short NO_days_in_months(short year, short mon) {
        int num_of_days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return(mon == 2) ? (leap_year(year) ? 29 : 28) : num_of_days[mon - 1];

    }
    short get_index_of_day(short year, short month, int i) {
        int a = (14 - month) / 12;
        int y = year - a;
        int m = month + (12 * a) - 2;
        return  (i + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

    }
    string arr_of_days(short number_of_Day) {
        string daysOfWeek[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

        return daysOfWeek[number_of_Day];
    }
    short number_of_days_inyear(short year, short mon, short day) {
        int sum = 0;
        for (int i = 1; i < mon; i++)
        {
            sum += NO_days_in_months(year, i);
        }

        return sum + day;

    }

    str_date vlidate_date_basedon_sum(short year, short mon, short sum) {
        short numof_day_month = 0;//

        str_date days;
        days.year = year;
        for (int i = 1; i < mon; i++)
        {
            numof_day_month = NO_days_in_months(year, i);
            days.month = i + 1;
            if (sum > numof_day_month)
            {
                sum -= numof_day_month;
            }
            days.day = sum;
        }

        return days;
    }
    str_date days_to_date(str_date dt, short days) {
        short total_days = number_of_days_inyear(dt.year, dt.month, dt.day);
        total_days += days;
        short month_day = 0;
        dt.month = 1;
        while (true)
        {
            month_day = NO_days_in_months(dt.year, dt.month);
            if (total_days > month_day)
            {
                total_days -= month_day;
                dt.month++;
                if (dt.month > 12)
                {
                    dt.month = 1;
                    dt.year++;
                }
            }
            else
            {
                dt.day = total_days;
                break;
            }
        }


        return dt;

    }
    str_date fill_date() {
        str_date fill;
        fill.day = check_number("\nPlease enter day : ");
        fill.month = check_number("\nPlease enter month : ");
        fill.year = check_number("\nPlease enter year : ");

        return fill;
    }
    bool dates_compearing(str_date d1, str_date d2) {

        return  (d1.year < d2.year) ? true : ((d1.year == d2.year) ? (d1.month < d2.month ? true : (d1.month == d2.month ? d1.day < d2.day : false)) : false);
    }
    bool dates_similarity(str_date d1, str_date d2) {

        return (d1.year == d2.year) ? (d1.month == d2.month ? d1.day == d2.day : true) : false;
    }
    bool Is_last_month_in_year(str_date d) {
        return (d.month == 12) ? true : false;

    }
    bool Is_last_day_in_mon(str_date d) {
        return (d.day == NO_days_in_months(d.year, d.month)) ? true : false;

    }


    str_date increase_date_by_one_day(str_date d) {
        if (Is_last_day_in_mon(d))
        {
            if (Is_last_month_in_year(d)) {
                d.day = 1;
                d.month = 1;
                d.year++;
            }
            else
            {
                d.day = 1;
                d.month++;
            }
        }


        return d;
    }
    str_date increase_date_by_x_day(str_date d, short days_to_add) {
        str_date inerease_by_x = d;
        for (int i = 1; i <= days_to_add; i++)
        {


            inerease_by_x = increase_date_by_one_day(inerease_by_x);
            inerease_by_x.day++;
        }

        return inerease_by_x;
    }
    str_date increase_date_by_one_week(str_date d, short week_to_add) {
        str_date inerease_by_x = d;
        for (int i = 1; i <= week_to_add * 7; i++)
        {


            inerease_by_x = increase_date_by_one_day(inerease_by_x);
            ++inerease_by_x.day;
        }

        return inerease_by_x;
    }
    str_date increase_date_by_x_weeks(str_date d, short week_to_add) {
        str_date inerease_by_x = d;
        for (int i = 1; i < (week_to_add * 7) - 1; i++)
        {


            inerease_by_x = increase_date_by_one_day(inerease_by_x);
            inerease_by_x.day++;
        }

        return inerease_by_x;
    }
    str_date increase_date_by_one_month(str_date d, short month_toadd) {
        str_date inerease_by_x = d;
        short days_in_mon;
        for (int i = 1; i <= month_toadd; i++)
        {

            month_toadd = NO_days_in_months(inerease_by_x.year, inerease_by_x.month);

            inerease_by_x = increase_date_by_one_day(inerease_by_x);
            inerease_by_x.day++;

        }

        return inerease_by_x;
    }
    str_date increase_date_by_x_month(str_date d, short month_toadd) {
        str_date inerease_by_x = d;
        short days_in_mon;
        days_in_mon = NO_days_in_months(inerease_by_x.year, inerease_by_x.month);
        for (int i = 1; i < (month_toadd * days_in_mon) - 1; i++)
        {



            inerease_by_x = increase_date_by_one_day(inerease_by_x);

            inerease_by_x.day++;

        }

        return inerease_by_x;
    }


    str_date increase_date_by_one_year(str_date d, short year_toadd) {
        str_date inerease_by_x;
        inerease_by_x.day = d.day;
        inerease_by_x.month = d.month;
        inerease_by_x.year = d.year + year_toadd;


        return inerease_by_x;
    }
    str_date increase_date_by_x_year(str_date d, short year_toadd) {
        str_date inerease_by_x = d;
        inerease_by_x = increase_date_by_one_year(d, year_toadd);

        return inerease_by_x;
    }
    str_date increase_date_by_x_year_faster(str_date d, short year_toadd) {
        str_date inerease_by_x = d;
        for (int i = 1; i <= year_toadd; i++)
        {
            inerease_by_x = increase_date_by_one_day(inerease_by_x);

            inerease_by_x.year++;
        }

        return inerease_by_x;
    }
    str_date increase_date_by_one_decade(str_date d, short decade_toadd) {
        str_date inerease_by_x;
        inerease_by_x.day = d.day;
        inerease_by_x.month = d.month;
        inerease_by_x.year = d.year + 10 * (decade_toadd);


        return inerease_by_x;
    }

    str_date increase_date_by_x_decade(str_date d, short decade_toadd) {
        str_date inerease_by_x = increase_date_by_one_decade(d, decade_toadd);



        return inerease_by_x;
    }
    str_date increase_date_by_x_decade_faster(str_date d, short decade_toadd) {
        d.year += decade_toadd * 10;

        return d;
    }
    str_date increase_date_by_one_century(str_date d, short century_toadd) {
        str_date inerease_by_x = d;
        for (int i = 1; i <= century_toadd * 100; i++)
        {
            inerease_by_x = increase_date_by_one_day(inerease_by_x);

            inerease_by_x.year++;
        }

        return inerease_by_x;
    }
    str_date increase_date_by_one_millennium(str_date d, short millennium_toadd) {
        str_date inerease_by_x = d;
        for (int i = 1; i <= millennium_toadd * 1000; i++)
        {
            inerease_by_x = increase_date_by_one_day(inerease_by_x);

            inerease_by_x.year++;
        }

        return inerease_by_x;
    }


    void swap_dates(str_date& d1, str_date& d2) {
        str_date tem;

        tem.day = d1.day;
        tem.month = d1.month;
        tem.year = d1.year;
        //
        d1.day = d2.day;
        d1.month = d2.month;
        d1.year = d2.year;
        //
        d2.day = tem.day;
        d2.month = tem.month;
        d2.year = tem.year;
    }
    int difference_between_2dates(str_date d1, str_date d2, bool last_day = false) {
        int days = 0;
        int neg = 1;
        if (!dates_compearing(d1, d2))
        {
            swap_dates(d1, d2);
            neg = -1;
        }
        while (dates_compearing(d1, d2))
        {
            days++;
            d1 = increase_date_by_one_day(d1);
        }


        return last_day ? ++days * (neg) : (days) * (neg);
    }
    str_date system_date() {
        str_date Date;
        time_t t = time(0);
        tm* now = localtime(&t);
        Date.day = now->tm_mday;
        Date.month = now->tm_mon + 1;
        Date.year = now->tm_year + 1900;
        return Date;

    }


    str_date decrease_date_by_one_day(str_date d) {
        if (d.month == 1 && d.day == 1)
        {
            d.year--;
            d.month = 12;
            d.day = NO_days_in_months(d.year, d.month);
        }
        else
        {
            d.day--;
            if (d.day == 0)
            {
                d.month--;
                d.day = NO_days_in_months(d.year, d.month);
            }
        }


        return d;
    }

    str_date decrease_date_by_x_day(str_date d, short day_tormv) {
        for (int i = 1; i <= day_tormv; i++)
        {
            d = decrease_date_by_one_day(d);
        }
        return d;
    }
    str_date decrease_date_by_one_week(str_date d, short week_tormv) {
        for (int i = 1; i <= (week_tormv * 7); i++)
        {
            d = decrease_date_by_one_day(d);
        }
        return d;
    }
    str_date decrease_date_by_x_week(str_date d, short weeks_tormv) {

        d = decrease_date_by_one_week(d, weeks_tormv);

        return d;

    }
    str_date decrease_date_by_one_month(str_date d) {
        if (d.month == 1)
        {
            d.month = 12;
            d.year--;
        }
        else
        {
            d.month--;
        }
        short number_of_days_in_month = NO_days_in_months(d.year, d.month);
        if (d.day > number_of_days_in_month)
        {
            d.day = number_of_days_in_month;
        }

        return d;

    }
    str_date decrease_date_by_x_month(str_date d, short month_to_dec) {
        for (int i = 1; i <= month_to_dec; i++)
        {
            d = decrease_date_by_one_month(d);
        }


        return d;

    }
    str_date decrease_date_by_one_year(str_date d) {

        d.year--;

        return d;

    }
    str_date decrease_date_by_x_year(str_date d, short year_to_dec) {
        for (int i = 1; i <= year_to_dec; i++)
        {
            d.year--;
        }


        return d;

    }
    str_date decrease_date_by_x_year_faster(str_date d, short year_to_dec) {
        d.year = d.year - year_to_dec;

        return d;

    }
    str_date decrease_date_by_one_decade(str_date d) {

        d.year = d.year - 10;

        return d;

    }
    str_date decrease_date_by_x_decade(str_date d, short decade_to_dec) {

        for (int i = 1; i <= decade_to_dec; i++)
        {
            d = decrease_date_by_one_decade(d);
        }

        return d;

    }
    str_date decrease_date_by_x_decade_faster(str_date d, short decade_to_dec) {

        d.year = d.year - (decade_to_dec * 10);

        return d;

    }
    str_date decrease_date_by_one_century(str_date d) {

        d.year = d.year - 100;

        return d;

    }
    str_date decrease_date_by_one_millunneium(str_date d) {

        d.year = d.year - 1000;

        return d;

    }
















}