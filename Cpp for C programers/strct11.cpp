#include <stdio.h>
#include <iostream>

const char* months[12] = {
    "January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"
};
const int days_per_month[12] = {
     31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

class date{
    public:
        //Constructors
        date();
        date(int);
        date(int, int);
        date(int, int, int);
        //Routines
        void print_date();
        void set_year(int);
        void set_month(int);
        void set_day(int);
        void set_date(int, int, int);
    private:
        //Variables
        int day, month, year;
        //Subroutines [Error checking]
        int verify_month(int);
        int verify_day(int);
        int verify_date(int, int, int);
};
//Class "date" functions
date::date(){
    day = 1;
    month = 1;
    year = 1900;
}
date::date(int Y): year(Y){
    day = 1;
    month = 1;
}
date::date(int Y, int M): year(Y){
    month = verify_month(M);
    day = 1;
}
date::date(int Y, int M, int D): year(Y){
    month = verify_month(M);
    day = verify_day(D);
};
void date::print_date(){
    printf("Data: %i/%s/%i\n", this->day, months[this->month-1], this->year);
}
void date::set_year(int Y){
    this->year = Y;
}
void date::set_month(int M){
    this->month = verify_month(M);
}
void date::set_day(int D){
    this->day = verify_day(D);
}
void date::set_date(int Y, int M, int D){
    this->year = Y;
    this->month = verify_month(M);
    this->day = verify_day(D);
}
int date::verify_month(int M){
    if(M > 0 && M < 13){
        return M;
    }
    std::cout << "ERROR - Invalid Month, returning 1\n";
    return 1;
}
int date::verify_day(int D){
    if(D > 0 && D <= days_per_month[this->month-1]){
        return D;
    }
    std::cout << "ERROR - Invalid Day, returning 1\n";
    return 1;
}

int main(){
    date date_1;
    date_1.print_date();

    date date_2(1987, 3, 27);
    date_2.print_date();

    date_1.set_date(3897, 53, -1);
    date_1.print_date();

    date_1.set_date(2022, 7, 3);
    date_1.print_date();

    return 0;
}
