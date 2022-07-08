//math operations via operators on C++ classes
//polymorphic math operators
#include <stdio.h>

class time{
    private:
        int day;
        int hour, minute, second;
    public:
        time();
        time(int, int, int, int);
        time operator ++ (int);
        time operator += (time);
        time operator + (time);
        void print_time();

};
time::time(): hour(0), minute(0), second(0), day(0){
}
time::time(int h, int m, int s, int d):day(d){
    if(h < 24){
        hour = h;
    } else {
        hour = 23;
    }

    if(m < 60){
        minute = m;
    } else {
        minute = 59;
    }

    if(s < 60){
        second = s;
    } else {
        second = 59;
    }
}
time time::operator++(int){
    hour++;
    if(hour >= 24){
        hour = 0;
        day++;
    }

    return (*this);
}
time time::operator+=(time b){
    second += b.second;
    while(second > 59){
        second -= 60;
        minute++;
    }
    minute += b.minute;
    while(minute > 59){
        minute -= 60;
        hour++;
    }
    hour += b.hour;
    if(hour > 23){
        hour -= 24;
        day++;
    }
    day += b.day;

    return *this;
}
time time::operator+(time b){
    time temp;

    temp.second = second + b.second;
    while(temp.second > 59){
        temp.second -= 60;
        temp.minute++;
    }
    temp.minute = minute + b.minute;
    while(temp.minute > 59){
        temp.minute -= 60;
        temp.hour++;
    }
    temp.hour = hour + b.hour;
    while(hour > 23){
        temp.hour -= 24;
        temp.day++;
    }
    temp.day = day + b.day;

    return temp;
}
void time::print_time(){
    printf("second:%i\tminute:%i\thour:%i\tday:%i\n", 
        this->second,
        this->minute,
        this->hour,
        this->day
    );
}

int main(){

    time t1(32, 55, 14, 1);
    time t2(1, 1, 1, 5);
    time a;
    t1.print_time();

    t1++;
    t1.print_time();

    t1 += t2;
    t1.print_time();

    a = t1+t2;
    a.print_time();

    return 0;
}