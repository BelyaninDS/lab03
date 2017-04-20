#include <iostream>
#include <iomanip>
#include <sstream>
#include <assert.h>
using namespace std;

char scale[]={'K','F','C'};
struct temperature
{
    double value;
    char scale;
};

istream &operator >>(istream& stream, temperature &temp);

void test_temperature_input(){
    temperature temp;
    istringstream iss1("10K");
    iss1>>temp;
    assert(temp.value == 10);
    assert(temp.scale == 'K');

    istringstream iss2("10F");
    iss2>>temp;
    assert(temp.value == 10);
    assert(temp.scale == 'F');

    istringstream iss3("10C");
    iss3>>temp;
    assert(temp.value == 10);
    assert(temp.scale == 'C');
}

istream &operator >>(istream& stream, temperature &temp){
    stream>>temp.value>>temp.scale;
    return stream;
}

temperature convert(double &input,char &from, char to){
switch (from) {
    case 'C':
        input += 273;
        break;
    case 'F':
        input = (5/9) * (input + 305);
        break;
    default:{}
}

switch(to){
    case 'C':
        input -= 273;
        break;
    case 'F':
        input = (9/5) * (input - 305);
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


int main(){

    temperature temp;
    /*test_temperature_input();

    cout<<"\nEnter tempereture: ";

    cin>>temp;
    cout<<temp.value<<temp.scale;


    char to;
    cout<<"\nConvert to: ";
    cin>>to;

    convert(temp.value,temp.scale,to);
    cout<<"\n"<<temp.value<<to;

    temperature temp1,temp2;
    cout<<"\nEnter temperatures to compare\n1: ";
    cin>>temp1;
    cout<<"\n2: ";
    cin>>temp2;

    isless(temp1,temp2);

    */
    size_t count=0,i,j,slen=0;
    cerr<<"Enter count: ";
    cin>>count;


    temperature *arr = new temperature[count];

    cerr<<"\nEnter lenght of string:";
    cin>>slen;

    if(slen<7) {
        cout << "\nError! lenght of string cannot be lesser than 7"<<"\nEnter again:";
        cin >> slen;
    }


    if(slen>80) {
        cout << "\nError! lenght of string cannot be bigger than 80"<<"\nEnter again:";
        cin >> slen;
    }


    if(slen<(count/3)) {
        cout << "\nError! lenght of string cannot be lesser than 1/3 of count"<<"\nEnter "
                "again:";
        cin >> slen;
    }


    cerr<<"\nEnter an array of temperatures:";
    for(i=0;i<count;i++) {
        cin >> arr[i];
        if (arr[i].scale != 'K')
            convert(arr[i].value, arr[i].scale, 'K');
    }



    size_t maxlen=arr[0].value;
    for(i=0;i<count;i++){
        if(arr[i].value>maxlen)
            maxlen=arr[i].value;
    }

    float koef=1;
    if(maxlen>slen)
        koef = ((float)slen/maxlen);



    for(i=0;i<count;i++){
        cout<<"\n"<<setw(6)<<arr[i].value<<arr[i].scale<<"|";
        arr[i].value *= koef;
        for(j=0;j<arr[i].value;j++)
            cout<<"*";
    }

    delete[] arr;
    //delete[] bins;

    return 0;
}