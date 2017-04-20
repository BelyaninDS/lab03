#include<sstream>

#ifndef UNTITLED_TEMPERATURE_H
#define UNTITLED_TEMPERATURE_H




struct temperature
{
    double value;
    char scale;
};


std::istream &operator >>(std::istream& stream, temperature &temp);

temperature convert(double &input,char &from, char to);

bool isless(temperature input1,temperature input2);

bool check(temperature input);

#endif //UNTITLED_TEMPERATURE_H

//
// Created by u211-04 on 20.04.2017.
//