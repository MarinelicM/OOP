#include <iostream>
using namespace std;
namespace geo{
    const double PI=3.1415;
}
double area(double r){
    return r*r*(geo::PI);
}
double area(double a, double b){
    return a*b;
}
int area(int a){
    return a*a;
}
void print_line(char c = '-', int length = 30){
    cout<<"\n";
    for (int i = 0; i < length; i++)
    {
        cout<<c;
    }
    cout<<"\n";    
}
int main(){
    cout<<area(5);
    print_line();
    cout<<area(5.0);
    print_line();
    cout<<area(2,3);
    print_line();
    cout<<area('A');

}