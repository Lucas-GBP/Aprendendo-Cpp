#include <iostream>
#include <ostream>

#define HOUR_MAX 24
#define MINUTE_MAX 60
#define SECOND_MAX 60


class fake;
class timer;

class fake{
    private:
        int var;
    public:
        fake();
        fake(int);
        operator timer();
        friend std::ostream& operator << (std::ostream&, fake);
};
class timer{
    private:
        int day, hour, minute, second;
        friend std::ostream& operator << (std::ostream&, timer);
    public:
        timer();
        timer(int, int, int, int);
        void adjust_timer();
        operator fake();
};

fake::fake(): var(0){
}
fake::fake(int VAR): var(VAR){
}
std::ostream& operator << (std::ostream& os, fake f){
    os << f.var << std::endl;
    return os;
}
fake::operator timer(){
    timer t((int)var, (int)(var*2), (int)(var*4), (int)(var*8));

    return t;
}

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
timer::operator fake(){
    fake f(second + SECOND_MAX*(minute + MINUTE_MAX*(hour + day*HOUR_MAX)));

    return f;
}


int main(){
    timer t1(4, 16, 55, 32);
    fake f1(87);
    std::cout << t1;
    std::cout << f1;
    std::cout << (fake)t1;
    std::cout << (timer)f1;

    return 0;
}