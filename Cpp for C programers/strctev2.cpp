#include <stdio.h>

class abc{
    private:
        int c;
    protected:
        int b;
    public:
        int a;
        abc(int, int, int);
        abc(void);
        void set_vals(int, int, int);
        void print_vals();
};
abc::abc(int A, int B, int C){
    a = A;
    b = B;
    c = C;
}
abc::abc(void){
    a = 1;
    b = 2;
    c = 3;
}
void abc::set_vals(int A, int B, int C){
    this->a = A;
    this->b = B;
    this->c = C;
}
void abc::print_vals(){
    printf("a = %i \t b = %i \t c = %i \n",this->a, this->b, this->c);
}

int main(){
    // Now I try to create a2 and assign initial values to all three
    // fields. The function abc, which is a member function of the class
    // abc and which expects three integer arguments, will be called
    // Because abc(int,int,int) is a member function, it has access to
    // all three fields
    abc a2(5,6,7); // create an instance of an abc class object giving three integers as arguments
    a2.print_vals();
    // abc a1; // this line is now a problem
    // in the previous program, I provided NO CONSTRUCTOR
    // therefore C++ provided one for me
    // that DEFAULT NO ARGUMENT CONSTRUCTOR simply allocated the memory
    // for the variables
    // Now that I have provided a constructor function, I HAVE TO USE IT
    // the line
    // abc a1;
    // says to build an abc but it doesn't provide
    // the three integers that I said I would use to build one
    // SO what do you do? See the next program
    return 0;
}