#include "../std_lib_facilities.h"

vector<int> gv{1,2,4,8,16,32,64,128,256,512};

int factorial(int i){
    if (i==0||i==0)
    {
        return 1;
    }    
    return i*factorial(i-1);
}

void f(vector<int> arg){
    vector<int> lv(arg.size());
    copy(gv.begin(),gv.end(),lv.begin());
    for (int i = 0; i < lv.size(); i++)
    {
        cout<<"lv["<<i<<"]= "<<lv[i]<<'\n';
    }
    cout<<"-----------------------------------------"<<'\n';
    vector<int> lv2 = arg;
    //copy(arg.begin(),arg.end(),lv2.begin());
    for (int i = 0; i < lv2.size(); i++)
    {
        cout<<"lv2["<<i<<"]= "<<lv2[i]<<'\n';
    }
    
}


int main(){
    f(gv);
    vector<int> vv;
    for (int i = 0; i < 10; i++)
    {
        vv.push_back(factorial(i+1));
    }
    f(vv);
    
    return 0;
}