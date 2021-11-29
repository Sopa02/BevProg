#include "../std_lib_facilities.h"

int ga[10]{1,2,4,8,16,32,64,128,256,512};

int factorial(int i){
    if (i==0||i==0)
    {
        return 1;
    }    
    return i*factorial(i-1);
}

void f(int array[], int length){
    int la[10];
    
    for (int i = 0; i < 10; i++)
    {

        la[i] = ga[i];
        cout<<la[i]<<'\n';
    }
    cout<<"--------------------------------------\n";
    int* p = new int[length];
    for (int i = 0; i < length; i++)
    {
        p[i] = array[i];
        cout<<p[i]<<'\n';
    }
    delete[] p;
    
}


int main(){
     cout<<"----------------------ga-------------------------\n";
     f(ga,10);
     cout<<"----------------------aa-------------------------\n";

    int aa[10];
    for (int i = 0; i < 10; i++)
    {
        aa[i] = factorial(i+1);
        
        //cout<<i<<"!= "<< factorial(i)<<'\n';
    }
    f(aa,10);


}