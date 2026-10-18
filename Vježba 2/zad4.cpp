#include <iostream>
using namespace std;
int twice(int a){
    return 2*a;
}
void my_transform(int arr[], int n, int (*f)(int)){
    for (int i = 0; i < n; i++)
    {
        arr[i]=f(arr[i]);
    }
    
}
int main(){
    int niz[]={50, 9, 471, 2, 3, 44};
    int n=sizeof(niz)/sizeof(int);
    my_transform(niz,n,twice);
    cout<<"Nakon twice: ";
    for(int i=0;i<n;i++)
        cout<<niz[i]<<" ";
    cout<<endl;
    my_transform(niz,n, [](int element){
        if(element %2==0){
            return element/2;
        }
        else
            return element*2;
    });
    cout<<"Nakon lambde: ";
    for(int i=0;i<n;i++)
        cout<<niz[i]<<" ";
    cout<<endl;
    int suma=0;
    int produkt=1;
    auto sum_prod=[&](int element){
        suma+=element;
        produkt*=element;
    };
    for(int i=0;i<n;i++)
        sum_prod(niz[i]);

    cout<<"Suma: "<<suma<<endl;
    cout<<"Produkt: "<<produkt<<endl;
    int prag=4;
    int s=0;
    auto suma_prag=[prag,&s](int element){
        if(element>prag)
            s+=element;
    };
    for(int i=0;i<n;i++)
        suma_prag(niz[i]);

    cout<<"Suma vecih od praga: "<<s<<endl;
}