//a class that derives using private inheritance from base class coded in base_a.cpp
#ifndef PRIVA_CPP
#define PRIVA_CPP

#include <iostream>
#include "base_a.cpp"

class priva : private a{
    private:
        int priva_priv_var;
        void priva_priv_func();
    protected:
        int priva_prot_var;
        void priva_prot_func();
    public:
        int priva_pub_var;
        void priva_pub_func();
        void priva_print();
        void priva_call_em();
        priva();
        priva(int, int, int);
        ~priva();
};
priva::priva():priva_priv_var(10), priva_prot_var(20), priva_pub_var(30){
    std::cout << "priva class no arg constructor" << std::endl;
}
priva::priva(int priv, int prot, int pub):priva_priv_var(priv), priva_prot_var(prot), priva_pub_var(pub){
    std::cout << "priva class constructor" << std::endl;
}
priva::~priva(){
    std::cout << "priva Destructor" << std::endl;
}

void priva::priva_priv_func(){
    std::cout << "priva_priv_func\t"
    << " priva_priv_var: " << priva_priv_var 
    << " priva_prot_var: " << priva_prot_var
    << " priva_pub_var: " << priva_pub_var 
    << std::endl;
    
    a_prot_func();
}
void priva::priva_prot_func(){
    std::cout << "priva_prot_func\t"
    << " priva_priv_var: " << priva_priv_var 
    << " priva_prot_var: " << priva_prot_var
    << " priva_pub_var: " << priva_pub_var 
    << std::endl;
}
void priva::priva_pub_func(){
    std::cout << "priva_pub_func\t"
    << " priva_priv_var: " << priva_priv_var 
    << " priva_prot_var: " << priva_prot_var
    << " priva_pub_var: " << priva_pub_var 
    << std::endl;
}
void priva::priva_print(){
    std::cout << "priva_print\t"
    << " priva_priv_var: " << priva_priv_var 
    << " priva_prot_var: " << priva_prot_var
    << " priva_pub_var: " << priva_pub_var 
    << std::endl;
}
void priva::priva_call_em(){
    priva_priv_func();
    priva_prot_func();
    priva_pub_func();
}

#endif