//casting a class into a pre-defined type using functions
#include <iostream>
#include <ostream>

class timer{
    private:
        int hour, minute, second;
        friend std::ostream& operator << (std::ostream&, timer);
    public:
        timer();
        timer(int, int, int);
        int timer_to_int();
        float timer_to_float();
        char timer_to_char();
};
timer::timer():hour(0), minute(0), second(0){
}
timer::timer(int h, int m, int s):hour(h), minute(m), second(s){
}
int timer::timer_to_int(){
    return (int)(hour+minute+second);
}
float timer::timer_to_float(){
    return (float)(hour+minute+second);
}
char timer::timer_to_char(){
    return (char)(hour+minute+second);
}
std::ostream & operator << (std::ostream & os, timer a){
    os << "\tHour: "
    << a.hour
    << "\tMinute: "
    << a.minute
    << "\tSecond: "
    << a.second
    << std::endl;

    return os;
}

int main(){
    timer t1(1, 2, 3);
    std::cout << t1;

    std::cout << t1.timer_to_int() << std::endl;
    std::cout << t1.timer_to_float() << std::endl;
    std::cout << (char)(t1.timer_to_char()+70) << std::endl;
}