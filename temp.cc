
#include"temp.h"
#include<iostream>
#include<assert.h>





std::istream &operator >>(std::istream& stream, temperature &temp){
    stream >> temp.value;
    char symbol;
    stream >> symbol;
    switch (symbol) {
        case 'K': temp.scale = Kelvin; break;
        case 'F': temp.scale = Fahrenheit; break;
        case 'C': temp.scale = Celsius; break;
        default : std::cerr<<"\nError! Wrong scale.";
    }
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
    convert(input1.value,input1.scale,'K');
    convert(input2.value,input2.scale,'K');
    if(input1.value<input2.value)
        return 1;
    else
        return 0;
}

bool check(temperature input)
{
    convert(input.value,input.scale,'K');
    if(input.value < 0)
        return 1;
    else
        return 0;
    }





//
// Created by u211-04 on 20.04.2017.
//

