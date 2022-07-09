//taking over the i/o operators for a class
#include <iostream>

class timer{
    private:
        int day, hour, minute, second;
    public:
        timer();
        timer(int, int, int);
    private:
        friend std::ostream& operator << (std::ostream&, timer);
};
timer::timer():day(0), hour(0), minute(0), second(0){
}
timer::timer(int h, int m, int s):day(0), hour(h), minute(m), second(s){
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

int main(){

    timer t1(50, 23, 17);
    std::cout << t1;

    return 0;
}