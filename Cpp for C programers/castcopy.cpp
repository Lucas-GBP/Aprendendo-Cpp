//building one instance of a class using another instance of the same class
#include <iostream>

class timer{
    private:
        int hour, minute, second;
        friend std::ostream& operator << (std::ostream&, timer);
    public:
        timer();
        timer(int, int, int);
        timer operator = (timer);
};
timer::timer():hour(0), minute(0), second(0){
}
timer::timer(int h, int m, int s):hour(h), minute(m), second(s){
}
std::ostream & operator << (std::ostream & os, timer a){
    os << "Hour: "
    << a.hour
    << "\tMinute: "
    << a.minute
    << "\tSecond: "
    << a.second
    << std::endl;

    return os;
}
timer timer::operator=(timer a){
    hour = a.hour;
    minute = a.minute;
    second = a.second;

    return (*this);
}

int main(){
    timer t1(1,2,3);
    std::cout << "t1:\n" << t1;

    timer t2(4,5,6);
    std::cout << "t2:\n" << t2;

    timer t3;
    std::cout << "t3:\n" << t3;

    t3 = t1;
    std::cout << "t1:\n" << t1 << "t3:\n" << t3;

    t3 = t2;
    std::cout 
        << "t1:\n" << t1 
        << "t2:\n" << t2 
        << "t3:\n" << t3;

    return 0;
}