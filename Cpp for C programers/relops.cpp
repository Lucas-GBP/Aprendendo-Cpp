/*
**relational operations via operators on C++ classes
*/
#include <stdio.h>

#define TRUE    1
#define FALSE   0

class time{
    private:
        int hour, minute, second;
    public:
        time(int, int, int);
        //Operator routines
        int operator == (time);
        int operator != (time);
        int operator >  (time);
        int operator >= (time);
        int operator <  (time);
        int operator <= (time);
};
time::time(int H, int M, int S): hour(H), minute(M), second(S){};
//Operator routines
int time::operator == (time a){
    if((this->hour == a.hour) && (this->minute == a.minute) && (this->second == a.second)){
        return TRUE;
    }
    return FALSE;
}
int time::operator != (time a){
    if((this->hour != a.hour) || (this->minute != a.minute) || (this->second != a.second)){
        return TRUE;
    }
    return FALSE;
}
int time::operator > (time a){
    if(this->hour >= a.hour){
        if(this->hour > a.hour){
            return TRUE;
        }
    } else {
        return FALSE;
    }
    if(this->minute >= a.minute){
        if(this->minute > a.minute){
            return TRUE;
        }
    } else {
        return FALSE;
    }
    if(this->second > a.second){
        return TRUE;
    }
    return FALSE;
}
int time::operator >= (time a){
    if(this->hour >= a.hour){
        if(this->hour > a.hour){
            return TRUE;
        }
    } else {
        return FALSE;
    }
    if(this->minute >= a.minute){
        if(this->minute > a.minute){
            return TRUE;
        }
    } else {
        return FALSE;
    }
    if(this->second >= a.second){
        return TRUE;
    }
    return FALSE;
}
int time::operator < (time a){
    if(this->hour <= a.hour){
        if(this->hour < a.hour){
            return TRUE;
        }
    } else {
        return FALSE;
    }
    if(this->minute <= a.minute){
        if(this->minute < a.minute){
            return TRUE;
        }
    } else {
        return FALSE;
    }
    if(this->second < a.second){
        return TRUE;
    }
    return FALSE;
}
int time::operator <= (time a){
    if(this->hour <= a.hour){
        if(this->hour < a.hour){
            return TRUE;
        }
    } else {
        return FALSE;
    }
    if(this->minute <= a.minute){
        if(this->minute < a.minute){
            return TRUE;
        }
    } else {
        return FALSE;
    }
    if(this->second <= a.second){
        return TRUE;
    }
    return FALSE;
}

int main(){
    time timer_1(5,2,3);
    time timer_2(1,2,3);

    if(timer_1 == timer_2){
        printf("timer_1 is equal to timer_2\n");
    }
    if(timer_1 != timer_2){
        printf("timer_1 is different to timer_2\n");
    }
    if(timer_1 > timer_2){
        printf("timer_1 is bigger then timer_2\n");
    }
    if(timer_1 >= timer_2){
        printf("timer_1 is bigger or equal to timer_2\n");
    }
    if(timer_1 < timer_2){
        printf("timer_1 is lesser then timer_2\n");
    }
    if(timer_1 <= timer_2){
        printf("timer_1 is lesser or equal to timer_2\n");
    }

    printf("\n");
    return 0;
}