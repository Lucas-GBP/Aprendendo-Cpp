#include <iostream>

#define HOUR_MAX 24
#define MINUTE_MAX 60
#define SECOND_MAX 60

struct timer_s{
    int day, hour, minute, second;
};

class timer{
    private:
        int day, hour, minute, second;
        friend std::ostream& operator << (std::ostream&, timer);
    public:
        timer();
        timer(int, int, int, int);

        void adjust_timer();

        timer operator ++ ();
        timer operator -- ();
        timer operator += (timer);
        timer operator -= (timer);
        timer operator + (timer);
        timer operator - (timer);

        bool operator == (timer);
        bool operator != (timer);
        bool operator > (timer);
        bool operator >= (timer);
        bool operator < (timer);
        bool operator <= (timer);
        
        operator timer_s();
        operator int();
        operator float();
};
timer::timer(): day(0), hour(0), minute(0), second(0){
}
timer::timer(int d,int h, int m, int s): day(d), hour(h), minute(m), second(s){
    adjust_timer();
}
void timer::adjust_timer(){
    if(second >= SECOND_MAX){
        do {
            minute++;
            second -= SECOND_MAX;
        } while (second >= SECOND_MAX);
    } else if(second < 0){
        do {
            minute--;
            second += SECOND_MAX;
        } while (second < 0);
    }

    if(minute >= MINUTE_MAX){
        do {
            hour++;
            minute -= MINUTE_MAX;
        } while (minute >= MINUTE_MAX);
    } else if(minute < 0){
        do {
            hour--;
            minute += MINUTE_MAX;
        } while (minute < 0);
    }

    if(hour >= HOUR_MAX){
        do {
            day++;
            hour -= HOUR_MAX;
        } while (hour >= HOUR_MAX);
    } else if(hour < 0){
        do {
            day--;
            hour += HOUR_MAX;
        } while (hour < 0);
    }
}
std::ostream & operator << (std::ostream & os, timer a){
    os << "Day: "
    << a.day
    << "\tHour: "
    << a.hour
    << "\tMinute: "
    << a.minute
    << "\tSecond: "
    << a.second
    << std::endl;

    return os;
}
timer timer::operator ++ (){
    second++;

    if(second <= SECOND_MAX){
        return *this;
    } else {
        second = 0;
        minute++;
    }

    if(minute <= MINUTE_MAX){
        return *this;
    } else {
        minute = 0;
        hour++;
    }

    if(hour <= HOUR_MAX){
        return *this;
    } else {
        hour = 0;
        day++;
    }

    return *this;
}
timer timer::operator -- (){
    second--;

    if(second < 0){
        second += SECOND_MAX;
        minute--;
    }
    if(minute < 0){
        minute += MINUTE_MAX;
        hour--;
    }
    if(hour < 0){
        hour += HOUR_MAX;
        day--;
    }

    return *this;
}
timer timer::operator += (timer t){
    day += t.day;
    hour += t.hour;
    minute += t.minute;
    second += t.second;

    adjust_timer();

    return *this;
}
timer timer::operator -= (timer t){
    day -= t.day;
    hour -= t.hour;
    minute -= t.minute;
    second -= t.second;
    adjust_timer();

    return *this;
}
timer timer::operator + (timer t){
    t.day += day;
    t.hour += hour;
    t.minute += minute;
    t.second += second;
    t.adjust_timer();

    return t;
}
timer timer::operator - (timer t){
    t.day = day - t.day;
    t.hour = hour - t.hour;
    t.minute = minute - t.minute;
    t.second = second - t.second;
    t.adjust_timer();

    return t;
}
bool timer::operator == (timer t){
    if( day == t.day &&
        hour == t.hour &&
        minute == t.minute &&
        second == t.second)
    {
        return true;
    }

    return false;
}
bool timer::operator != (timer t){
    if( day != t.day &&
        hour != t.hour &&
        minute != t.minute &&
        second != t.second)
    {
        return true;
    }

    return false;
}
bool timer::operator > (timer t){
    if(day > t.day){
        return true;
    }
    if(hour > t.hour){
        return true;
    }
    if(minute > t.minute){
        return true;
    }
    if(second > t.second){
        return true;
    }

    return false;
}
bool timer::operator >= (timer t){
    if(day >= t.day){
        return true;
    }
    if(hour >= t.hour){
        return true;
    }
    if(minute >= t.minute){
        return true;
    }
    if(second >= t.second){
        return true;
    }

    return false;
}
bool timer::operator < (timer t){
    if(day < t.day){
        return true;
    }
    if(hour < t.hour){
        return true;
    }
    if(minute < t.minute){
        return true;
    }
    if(second < t.second){
        return true;
    }

    return false;
}
timer::operator timer_s(){
    timer_s temp = {day, hour, minute, second};
    return temp;
}
timer::operator int(){
    int seconds = second + SECOND_MAX*(minute + MINUTE_MAX*(hour + day*HOUR_MAX));
    return seconds;
}
timer::operator float(){
    float days = day + ((float)hour + ((float)minute + (float)second/SECOND_MAX)/MINUTE_MAX)/HOUR_MAX;
    return days;
}


int main(){
    timer t1(5, 32, 45, 2);
    //std::cout << "Timer 01:\n"<< t1;
    timer t2(8, 12, 52, 123);
    //std::cout << "Timer 02:\n"<< t2;
    timer t3 = t1;
    t3 += t2;

    std::cout << t1;
    std::cout << (int)t1 << " | " << (float)t1 << std::endl;

    std::cout << t2;
    std::cout << t3;

    return 0;
}