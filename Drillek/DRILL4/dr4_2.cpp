#include "../std_lib_facilities.h"

int main(){

    double smallest,largest,a,converted,sum;
    int i = 0;
    sum = 0;
    string unit;

    while (cin>>a>>unit)
    {
        cout << "\n--------------------------------------\n";
        
        //Conversion for comparing the numbers
        if (unit == "cm")
        {
            converted = a;
        }else
        if (unit == "m")
        {
            converted = a*100;
        }else
        if (unit == "in")
        {
            converted = a*2.54;
        }else
        if (unit == "ft")
        {
            converted = a*12*2.54;
        }else{
            cout<<"This unit of measurement is not supported!\n";
            break;
        }
        
        //Comparison
        if(i == 0){
            cout<<"This is the first number you've entered: " << a << unit << "\n";
            cout<<"It it both the largest and the smallest.\n";
            smallest = converted;
            largest = converted;
            i++;
        }else
        if (converted<smallest)
        {
            cout<<"The number you've entered: " << a << unit << " - The smallest so far.\n";
            smallest = converted;
        }else
        if (converted>largest)
        {
            cout<<"The number you've entered: " << a << unit << " - The largest so far.\n";
            largest = converted;
        }else
            cout<<"The number you've entered: " << a << unit << "\n";

        sum += converted;

    }
    cout << "The sum of the units given: " << sum/100 << "meters.\n";
}