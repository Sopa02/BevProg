#include "../std_lib_facilities.h"
//try this 1.
void suspicious(vector<int>& v, int s)
{
    int* p;
    int* q;
    try
    {
        p = new int[s];
        vector<int>v1;
        // . . .
    }
    catch(const std::exception& e)
    {
        delete[] p;
        cout << e.what() << '\n';
        throw;
    }
    try
    {
        q = new int[s];
        vector<double> v2;
        // . . .
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        delete[] p;
        delete[] q;
    }

    delete[] p;
    delete[] q;

}

int main(){

    return 0;
}