#include "headAtoi.h"

int miAtoi (const char* s)
{
    int cad = 0, signo, sigNum;

    while(*s){

        if(*s != ' '){

            if(*s == '+' || *s == '-'){

                signo = (int)*s;

                (signo == 43)? (signo = 1) : (signo = 0);
            }
            else{

                if(*s > '0' && *s < '9' ){

                    sigNum = ((int)*s - 48);

                    cad *= 10;

                    cad += sigNum;
                }
            }
        }

        s++;
    }

    return (signo)? cad : (cad*-1);
}
