//polymorphism in an ineritance relationship

// this program illustrates that a deriving class can redefine a function
// that is defined in the base class, this is due to a feature of the compiler known as complete
// function name resolution. Although a function call may look as simple as f1()
// to the compiler it looks like class_membership::f1()
#include <iostream>
class b {
    private:
        int var1;
    public:
        b(); // no arg constructor
        void set_var1(int); // will not be overloaded
        int get_var1(void); // will not be overloaded
        // this function is going to be redefined in the class
        // that inherits from class b, the question then will be;
        // in code that calls manipulate_var1, which function will
        // be called, the base class function or the derived class
        // function??
        void manipulate_var1(int); // do something to var1
        //Notice that nothing special or different is done to the function manipulate_var1. Nothing different is done
        //to a function that is going to be overloaded. No designer of a function could anticipate which of their
        //functions are going to be overloaded. You may have a pretty good idea, but you can't be sure. When you
        //are sure, then you will have access to another feature of inheritance called virtuality, which is discussed in
        //later programs. But for now, let's see how to deal with functions that are overloaded by the designer of the
        //deriving classes.
};
b::b() : var1(10){
    std::cout << "In b no arg constructor \n";
}
void b::set_var1(int ivar1){ // would do error checking here
    var1 = ivar1;
}
int b::get_var1(){
    return(var1);
}
// this function is called when the invoking object is of type class b
void b::manipulate_var1(int ix){
    // could do error checking here
    std::cout << "In base class manipulate_var1, multiplying "
    << var1 << " by " << ix << std::endl;
    var1 *= ix;
}
// the class pubb is an object of type b AND the additional fields varz and the additional functions
// pubb, set_var2, get_var2, and manipulate_var1
// // notice that manipulate_var1 has the same name and argument list as manipulate_var1 in the base
// class portion. The question then is how can the compiler or run time system decide which version
// of manipulate_var1 is to be called. Up until now we have said functions can have the same name as
// long as they have a different argument list. Here we have the same name and the same argument list
// the Compiler needs to decide whether you mean b::manipulate_var1(int) or
// pubb::manipulate_var1(int)
// the compiler decides based on the data type of the invoking object
// if manipulate_var1() is called via instance_of_base.manipulate_var1()
// then b::manipulate_var1 is called
// if manipulate_var1() is called via instance_of_derived.manipulate_var1()
// then pubb::manipulate_var1 is called

class pubb : public b{
    private:
        int var2;
    public:
        pubb(); // no arg constructor
        void manipulate_var1(int); // OVERLOADED FUNCTION
        // SAME FUNCTION EXISTS IN BASE CLASS
        void set_var2(int); // new function unique to pubb
        int get_var2(void);
};
pubb::pubb() : var2(5){
    std::cout << "In pubb no arg constructor \n";
}
void pubb::set_var2(int ivar2){
    var2 = ivar2;
}
int pubb::get_var2(){
    return(var2);
}
// this is the overloaded function
// it is called when the invoking object is of type pubb
void pubb::manipulate_var1(int ix){
    std::cout << "In derived class manipulate_var1, adding"
    << ix << " to " << this->get_var1() << std::endl
    << "multiplying "
    << var2 << " by " << 2 << std::endl;
    this->set_var1( this->get_var1() + ix);
    var2 *= 2;
}

int main(){
    // declare an object of the base type
    b obj1;
    // make calls to the base class functions
    std::cout << "Initial value of obj1.var1 is " << obj1.get_var1() << std::endl;
    obj1.set_var1(53);
    std::cout << "New value of obj1.var1 is " << obj1.get_var1() << std::endl;
    obj1.manipulate_var1(2); // base class function called
    std::cout << "New value of obj1.var1 is " << obj1.get_var1() << std::endl;
    // declare an object of the derived type
    pubb obj2;
    // make calls to the derived class functions
    std::cout << "\nInitial value of obj2.var1 is " << obj2.get_var1() << std::endl;
    std::cout << "Initial value of obj2.var2 is " << obj2.get_var2() << std::endl;
    std::cout << "Calling obj2.set_var1(7) and obj2.set_var2(17)\n";
    obj2.set_var1(7);
    obj2.set_var2(17);
    std::cout << "New value of obj2.var1 is " << obj2.get_var1() << std::endl;
    std::cout << "New value of obj2.var2 is " << obj2.get_var2() << std::endl;
    // Which manipulate_var1 will be called? Derived or Base?
    std::cout << "\nCalling manipulate_var1 via obj2.manipulate_var1(2) \n";
    obj2.manipulate_var1(2); // derived class function is called
    std::cout << "New value of obj2.var1 is " << obj2.get_var1() << std::endl;
    std::cout << "New value of obj2.var2 is " << obj2.get_var2() << std::endl;
    // force call to the base class functions
    std::cout << "\nCalling manipulate_var1 via obj2.b::manipulate_var1(2) \n";
    obj2.b::manipulate_var1(3); // base class function called because of name forcing
    std::cout << "New values for obj2 are " <<
    obj2.get_var1() << " " <<
    obj2.get_var2() << std::endl;

    return 0;
}