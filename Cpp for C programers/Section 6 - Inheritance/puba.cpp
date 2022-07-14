//a class that derives using public inheritance from base class coded in base_a.cpp
#ifndef PUBA_CPP
#define PUBA_CPP

#include <iostream>
#include "base_a.cpp"

class puba : public a{
    private:
        int puba_priv_var;
        void puba_priv_func();
    protected:
        int puba_prot_var;
        void puba_prot_func();
    public:
        int puba_pub_var;
        void puba_pub_func();
        void puba_print();
        void puba_call_em();
        puba();
        puba(int, int, int);
        ~puba();
};
puba::puba():puba_priv_var(11), puba_prot_var(22), puba_pub_var(33){
    std::cout << "puba class no arg constructor" << std::endl;
}
puba::puba(int priv, int prot, int pub):puba_priv_var(priv), puba_prot_var(prot), puba_pub_var(pub){
    std::cout << "puba class constructor" << std::endl;
}
puba::~puba(){
    std::cout << "puba Destructor" << std::endl;
}

void puba::puba_priv_func(){
    std::cout << "puba_priv_func\t"
    << " puba_priv_var: " << puba_priv_var 
    << " puba_prot_var: " << puba_prot_var
    << " puba_pub_var: " << puba_pub_var 
    << std::endl;
}
void puba::puba_prot_func(){
    std::cout << "puba_prot_func\t"
    << " puba_priv_var: " << puba_priv_var 
    << " puba_prot_var: " << puba_prot_var
    << " puba_pub_var: " << puba_pub_var 
    << std::endl;
}
void puba::puba_pub_func(){
    std::cout << "puba_pub_func\t"
    << " puba_priv_var: " << puba_priv_var 
    << " puba_prot_var: " << puba_prot_var
    << " puba_pub_var: " << puba_pub_var 
    << std::endl;
}
void puba::puba_print(){
    std::cout << "puba_print\t"
    << " puba_priv_var: " << puba_priv_var 
    << " puba_prot_var: " << puba_prot_var
    << " puba_pub_var: " << puba_pub_var 
    << std::endl;
}
void puba::puba_call_em(){
    puba_priv_func();
    puba_prot_func();
    puba_pub_func();
}

#endif