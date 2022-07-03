#include <iostream>
#include <cstring>

char string[] = "This is the shared string they point at\n";

class abc{
    private:
        int a, b, c;
        static int count_of_objects;
        char* cptr;
    public:
        abc(){
            std::cout << "Constructor was invoked\n";

            a = b = c = 1;
            cptr = string;
            count_of_objects++;
        }
        ~abc(){
            std::cout << "DESTRUCTOR was invoked\n";

            if(count_of_objects <= 1){
                strcpy(cptr,"NEW STRING FROM DESTRUCTOR\n");

            } else {
                std::cout << "I am not last suriving object\n";
                std::cout << "I am not going to hurt s \n";
            }

            count_of_objects--;
            print_abc();
        }
        void print_abc(){
            std::cout << "In print_abc values are: \n";
            std::cout << a << " " << b << " " << c << std::endl;
            printf(string);
        }
};

int abc::count_of_objects = 0;

int main(){

    abc a1;
    abc a2;
    abc a3;

    return 0;
}
