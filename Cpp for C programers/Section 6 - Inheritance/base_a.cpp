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
        void a_print();
        void a_call_em();
};
a::a():a_priv_var(1), a_prot_var(2), a_pub_var(3){
}


#endif