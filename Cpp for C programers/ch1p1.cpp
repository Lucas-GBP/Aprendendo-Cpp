// ch1p1.cpp
// this program introduces C++ comments, variables, decisions and loops
// the double slashes are an addition to C++
// they are a commenting mechanism
// a double slash comment can begin anywhere on a line and continues
// until the end of that line and that line only
/* the slash asterisk, asterisk slash comment method */
/* is still
in use */
#if 0
    to comment out long passages
    of code, the #if 0 and the #ifdef mechanisms
    are still available
#endif
#include <stdio.h> // get access to printf scanf
#include <iostream> // get access to cout and cin
// main is still the program entry point and by default still returns an int
int main() {
    // the { is still the start of scope operator
    // the } is still the end of scope operator
    int i = 5; // int is still a keyword
    float f = 7.2; // float is still a keyword
    char x = 'a'; // char is still a keyword
    // all the decision structures are the same as in C, if, switch, goto
    if ( i < 7 ) // the relational operators are the same, < <= > >= != ==
    {
        printf("i was less than 7\n"); // if is identical
        printf("i was %i\n",i); // printf is identical, although often replaced with cout
    }
    else
    {
        std::cout << "i was greater than or equal to 7\n"; // cout is new
        std::cout << "i was " << i << std::endl; // it can replace printf
    }
    // all the looping structures are the same as in C for, while, do
    for ( i = 10; i < 13; i++ )
        printf("%i squared is %i \n",i, i*i);
}