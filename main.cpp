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

    isless(temp1,temp2);*/


    size_t columns=0,count=0,i,j,slen=0;
    cerr<<"Enter count: ";
    cin>>count;

    temperature *arr = new temperature[count];

    cerr << "\nEnter lenght of string:";
    cin >> slen;

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
    for(i=0;i<count;i++)
        cin >> arr[i];

    cerr << "\nEnter number of bins: ";
    cin >> columns;


    temperature max = arr[0],min = arr[0];

    for(i=0;i<count;i++){
        if((isless(arr[i],min) == 1))
            min = arr[i];
        if(isless(max,arr[i]) == 1)
            max = arr[i];
    }

    size_t *bins = new size_t[columns];

    for(i=0;i<columns;i++)
        bins[i] = 0;


    convert(max.value,max.scale,'K');
    convert(min.value,min.scale,'K');

    for(i=0;i<count;i++) {
        if (arr[i].scale != 'K')
            convert(arr[i].value, arr[i].scale, 'K');

        size_t index = (size_t)((arr[i].value - min.value)/(max.value - min.value)*(columns-1));
        bins[index]++;
    }


    size_t maxlen=bins[0];
    for(i=0;i<columns;i++){
        if(bins[i]>maxlen)
            maxlen=bins[i];
    }

    float koef=1;
    if(maxlen>slen)
        koef = ((float)slen/maxlen);



    for(i=0;i<columns;i++){
        cout<<"\n"<<setw(6)<<bins[i]<<"|";
        for(j=0;j<bins[i]*koef;j++)
            cout<<"*";
    }

    delete[] arr;
    delete[] bins;

    return 0;
}