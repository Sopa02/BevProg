#include "../std_lib_facilities.h"

void print_array10(ostream& os, int* a){
      for (int i = 0; i < 10; i++)
      {
          os << a[i] << '\n';
      }      
}
void print_array(ostream& os, int* a, int n){
      for (int i = 0; i < n; i++)
      {
          os << a[i] << '\n';
      }
}

void print_vector(ostream& os, vector<int> a){
    for(int i = 0; i < a.size(); i++){
        os << a[i] << '\n';
    }
}

int main(){
    //Drill part 1 --------------------------------------
    // a[10]
    cout<<"a\n";
    int size = 10;
    int* a = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << '\n';
    }
    delete[] a;

    // b[10]
    cout<<"b\n";
    int* b = new int[size];
    for (int i = 0; i < size; i++)
    {
        b[i] = 100+i;
    }
    print_array10(cout,b);
    delete[] b;

    //c[11]
    cout<<"c\n";
    int* c = new int[size+1];
    for (int i = 0; i < size+1; i++)
    {
        c[i] = 100+i;
    }
    print_array(cout,c,size+1);
    delete[] c;

    //d[20]
    cout<<"d\n";
    int* d = new int[size+10];
    for (int i = 0; i < size+10; i++)
    {
        d[i] = 100+i;
    }
    print_array(cout,d,size+10);
    delete[] d;


    //vector
    cout<<"e\n";
    vector<int> e;
    for (int i = 0; i < 10; i++)
    {
        e.push_back(100+i);
    }
    print_vector(cout,e);
    
    //Drill part 2 --------------------------------------
    cout<<"\n\n"<<"PART2"<<"\n\n";
    int* p1 = new int(7);
    cout << "Value of p1: " <<p1<< "\tThe value of the int it points to: "<<*p1<<'\n';
    int* p2 = new int[7];
    for (int i = 0; i < 7; i++)
    {
        p2[i] = pow(2,i);
    }
    cout<<"The value of the p2 pointer: "<<p2<<'\n'<<"The value of the array p2 points to: \n";
    print_array(cout,p2,7);

    int* p3 = p2;
    p2 = p1;
    p2 = p3;

    cout<<"Value of p1: "<<p1<<"\tPoints to:"<<*p1<<'\n';
    cout<<"Value of p2: "<<p2<<"\tPoints to:"<<*p2<<'\n';
    delete p1;
    delete[] p3;
    //10-12 with arrays
    p1 = new int[10];
    for (int i = 0; i < 10; i++)
    {
        p1[i]=pow(2,i);
    }
    p2 = new int[10];

    for (int i = 0; i < 10; i++)
    {
        p2[i]=p1[i];
    }
    delete[] p1;
    delete[] p2;
    //10-12 with vectors
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
       v1.push_back(pow(2,i));
    }
    vector<int> v2;
    for (int i = 0; i < v1.size(); i++)
    {
        v2.push_back(v1[i]);
    }
    return 0;
}