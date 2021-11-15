#include "../std_lib_facilities.h"

class Point{
    private:
        double x;
        double y;
    public:
        Point():x(0),y(0){}
        Point(double x, double y): x(x), y(y) {}
        double getx(){return x;}
        double gety(){return y;}
};
ostream& operator<<(ostream& os, Point& p){
    return os <<'('<<p.getx()<<','<<p.gety()<<')';
}
istream& operator>>(istream& is, Point& p){
    //(23,22)
    double x,y;
    char ch1,ch2,ch3;

    is >>ch1>>x>>ch2>>y>>ch3;
    p = Point{x,y};
    return is;
}
int main(){
    string filename = "mydata.txt";

    cout<<"Enter seven(7) (x,y) pairs, divide x from y with a space, then press enter, and enter the next pair!\nExample:\n 2 3 [ENTER]\n 23 -2 [ENTER]\n...\n";
    vector<Point> original_points;
    vector<Point> processed_points;
    double x,y;
    while (cin>>x>>y && original_points.size()<7)
    {
        Point p{x,y};
        original_points.push_back(p);
        if(original_points.size()==7){break;}
    }
    ofstream outs {filename};
    for(auto p : original_points){
        cout<<p<<'\n';
        outs<<p<<'\n';
    }
    outs.close();
    cout<<"A file named "<< filename << " was created, with the entered points stored in it.\n";
    ifstream ins {filename};
    for(Point p; ins>>p;){
        processed_points.push_back(p);
    }
    for(int i=0; i<processed_points.size();i++){
        Point p = processed_points[i];
        Point o = original_points[i];
        cout<<p;
        if(p.getx() != o.getx() || p.gety() != o.gety()){
            cout<<"Something's wrong!\n";
        }else{
            cout<<'\n';
        }
        
    }
    return 0;
}