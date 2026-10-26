#include <iostream>
#include <array>
using namespace std;
constexpr int DAYS=7;
double total(const array<double, DAYS>& hours){
    double suma=0;
    for (int i = 0; i < DAYS; i++)
    {
        suma+=hours[i];
    }
    return suma;
}
int best_day(const array<double, DAYS>& hours){
    int najvise_sati=0;
    for (int i = 1; i < DAYS; i++)
    {
        if(hours[i] > hours[najvise_sati]){
            najvise_sati=hours[i];
        }
    }
    return najvise_sati+1;
}
int main(){
    array<double,DAYS> tjedan1;
    array<double, DAYS> tjedan2;
    for (int i = 0; i < DAYS; i++)
    {
        cout<<"Unesite sate: ";
        cin>>tjedan1[i];
    }
    cout<<"Ukupno sati ucenja prvi tjedan: "<<total(tjedan1)<<endl;
    cout<<"Dan s najvise sati ucenja: "<<best_day(tjedan1)<<". dan"<<endl;
    tjedan2.fill(1.5);
    if(tjedan1==tjedan2){
        cout<<"Tjedni su jednaki!"<<endl;
    }
    else{
        cout<<"Tjedni nisu jednaki!"<<endl;
    }
    if (tjedan1<tjedan2)
    {
        cout<<"Drugi tjedan je imao vise sati ucenja!"<<endl;
    }
    else{
        cout<<"Prvi tjedan je imao vise sati ucenja!"<<endl;
    }
    tjedan1.swap(tjedan2);
    cout<<"Ukupno sati ucenja prvi tjedan: "<<total(tjedan1)<<endl;
    cout<<"Ukupno sati ucenja drugi tjedan: "<<total(tjedan2)<<endl;
}