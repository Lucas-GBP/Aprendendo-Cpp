//casting a class into a pre-defined type using casting syntax
#include <iostream>

class timer{
    private:
        int hour, minute, second;
        friend std::ostream& operator << (std::ostream&, timer);
    public:
        timer();
        timer(int, int, int);
        operator int();
        operator float();
        operator char();
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
timer::operator int(){
    return (int)(hour+minute+second);
}
timer::operator float(){
    return (float)(hour+minute+second);
}
timer::operator char(){
    return (char)(hour+minute+second);
}

int main(){
    timer t1(10, 20, 30);

    std::cout << t1;
    
    std::cout << (int)t1 << std::endl;
    std::cout << (float)t1 << std::endl;
    std::cout << (char)t1 << std::endl;
}