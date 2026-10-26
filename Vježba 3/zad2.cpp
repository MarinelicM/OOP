#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cout<<"Unesite broj dana: ";
    cin>>n;
    vector <double> temperatura(n);
    vector <double> promjena_temp;
    for (int i = 0; i < n; i++)
    {
        cout<<"Unesite temperature: ";
        cin>>temperatura[i];
    }
    if(n>1){
        promjena_temp.reserve(n-1);
    }
    for(auto i=temperatura.begin();(i+1)!=temperatura.end();++i){
            promjena_temp.push_back(*(i+1)-*i);
    }
    cout<<"Promjene temperature: ";
    for (auto i : promjena_temp)
    {
        cout<<i<<" ";
    }
    temperatura.resize(7,temperatura.back());
    cout<<endl<<"Izvjestaj: ";
    for (auto i : temperatura)
    {
        cout<<i<<" ";
    }
    
}