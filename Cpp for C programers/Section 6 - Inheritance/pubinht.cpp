//program to exercise class puba
#include <iostream>
#include "base_a.cpp"
#include "puba.cpp"

int main(){
    puba obj;

    obj.puba_call_em();
    obj.a_call_em();

    obj.puba_pub_var = 66;
    obj.a_pub_var = 21;

    obj.puba_call_em();
    obj.a_call_em();

    return 0;
}