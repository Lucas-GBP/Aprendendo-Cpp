#include <stdio.h>
#include <iostream>

class abc{
    public:
        int a;
        abc(int, int, int);
        abc();
        void set_vals(int, int, int);
        void print_vals();
    protected:
        int b;
    private:
        int c;
};
abc::abc(int A, int B, int C) : a(A), b(B), c(C){ //INVOCATION LINE INITIALIZATION
    std::cout << "Three Argument Constructor Called \n";
}
abc::abc() : a(0), b(0), c(0){
    std::cout << "NO ARGUMENT CONSTRUCTOR CALLED\n";
}
void abc::set_vals(int A, int B, int C){
    this->a =  A;
    this->b = B;
    this->c = C;
}
void abc::print_vals(){
    printf("a = %i\tb = %i\tc = %i\n", this->a, this->b, this->c);
}

int main(){
    abc a1;
    a1.print_vals();

    a1.set_vals(2, 3, 5);
    a1.print_vals();

    abc a2(7, 11, 13);
    a2.print_vals();
    
    a2.set_vals(42, 69, 98);
    a2.print_vals();

    return 0;
}