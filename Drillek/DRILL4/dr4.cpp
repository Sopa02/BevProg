#include "../std_lib_facilities.h"

int main(){

        
    while (true)
    {
        string StrA,StrB;
        double a,b;
        cout << "\n--------------------------------------\n";
        cout << "Type in a number (a)!\n";
        cin>>StrA;
        if (StrA=="|")
            break;
        a = stod(StrA);
        cout << "Type in a number (b)!\n";
        cin>>StrB;
        if (StrB=="|")
            break;
        b = stod(StrB);
        if (a==b)
        {
            cout<<"\nThe numbers are equal.\n";
            continue;
        }
        cout << "\nThe smaller number: " << min(a,b) 
        <<"\nThe larger number: "<<max(a,b)<<"\n";
        if (((min(a,b)/max(a,b))*100)>99)
        {
            cout << "\nThe numbers are almost equal.\n";
        }
        
    }

}