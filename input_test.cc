#include<assert.h>
#include<iostream>
#include"temp.h"


void test_temperature_input() {
    temperature temp;
    std::istringstream iss1("10K");
    iss1 >> temp;
    assert(temp.value == 10);
    assert(temp.scale == 'K');

    std::istringstream iss2("10F");
    iss2 >> temp;
    assert(temp.value == 10);
    assert(temp.scale == 'F');

    std::istringstream iss3("10C");
    iss3 >> temp;
    assert(temp.value == 10);
    assert(temp.scale == 'C');

}

int main(){
    test_temperature_input();
    return 0;
}