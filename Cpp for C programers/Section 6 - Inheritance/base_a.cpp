//a class that can stand by itself and be used as a base class
#ifndef BASE_A_CPP
#define BASE_A_CPP

#include <iostream>

class a{
    private:
        int a_priv_var;
        void a_priv_func();
    protected:
        int a_prot_var;
        void a_prot_func();
    public:
        int a_pub_var;
        void a_pub_func();

        a();
        a(int, int, int);
        ~a();
        void a_print();
        void a_call_em();
};
a::a():a_priv_var(1), a_prot_var(2), a_pub_var(3){
    std::cout << "a class no arg constructor" << std::endl;
}
a::a(int priv, int prot, int pub):a_priv_var(priv), a_prot_var(prot), a_pub_var(pub){
    std::cout << "a class constructor" << std::endl;
}
a::~a(){
    std::cout << "a Destructor" << std::endl;
}

void a::a_priv_func(){
    std::cout << "a_priv_func\t"
    << " a_priv_var: " << a_priv_var 
    << " a_prot_var: " << a_prot_var
    << " a_pub_var: " << a_pub_var 
    << std::endl;
}
void a::a_prot_func(){
    std::cout << "a_prot_func\t"
    << " a_priv_var: " << a_priv_var 
    << " a_prot_var: " << a_prot_var
    << " a_pub_var: " << a_pub_var 
    << std::endl;
}
void a::a_pub_func(){
    std::cout << "a_pub_func\t"
    << " a_priv_var: " << a_priv_var 
    << " a_prot_var: " << a_prot_var
    << " a_pub_var: " << a_pub_var 
    << std::endl;
}
void a::a_print(){
    std::cout << "a_print\t"
    << " a_priv_var: " << a_priv_var 
    << " a_prot_var: " << a_prot_var
    << " a_pub_var: " << a_pub_var 
    << std::endl;
}
void a::a_call_em(){
    a_priv_func();
    a_prot_func();
    a_pub_func();
}
#endif