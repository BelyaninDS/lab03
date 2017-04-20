
#include"temp.h"
#include<sstream>



std::istream &operator >>(std::istream& stream, temperature &temp){
    stream>>temp.value>>temp.scale;
    return stream;
}

temperature convert(double &input,char &from, char to){
    switch (from) {
    case 'K':
        input -= 273;
        break;
    case 'F':
        input = (5.0/9.0)*(input - 32);
        break;
    default:{}
    }

    switch(to){
    case 'K':
        input += 273;
        break;
    case 'F':
        input = (9.0/5.0)*input + 32;
        break;
    default:{}
    }
    from=to;

}

bool isless(temperature input1,temperature input2)
{
    if(input1.value<input2.value)
        return 1;
    else
        return 0;
}

//
// Created by u211-04 on 20.04.2017.
//

