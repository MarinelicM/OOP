#include <iostream>
using namespace std;
inline double add(double a,double b){
    return a+b;
}
inline double subtract(double a,double b){
    return a-b;
}
inline double multiply(double a,double b){
    return a*b;
}
inline double divide(double a,double b){
    return a/b;
}
int main(){
    int a,b,operacija;
    cout<<"Unesite prvi broj: ";
    cin>>a;
    cout<<"Unesite drugi broj: ";
    cin>>b;
    double (*funkcije[4])(double,double)={add,subtract,multiply,divide};
    cout<<"Unesite koju operaciju zelite (0-3): ";
    cin>>operacija;
    if(operacija==3 && b==0){
        cout<<"DIjeljenje s 0 nije dozvoljeno!";
    }
    else
        cout<<"Rezultat vaseg racuna je: "<<funkcije[operacija](a,b);
}