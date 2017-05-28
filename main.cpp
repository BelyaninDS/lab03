#include <iostream>
#include <iomanip>
#include "temp.h"


using namespace std;

int main(){



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
    for(i=0;i<count;i++) {
        cin >> arr[i];
        if (check(arr[i]) != 0) {
            cout << "\nError! Wrong temperature";
            return 0;
        }
    }
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