#include <iostream>
using namespace std;
inline bool ascending(int a,int b){
    return a>b;
}
inline bool descending(int a,int b){
    return a<b;
}
void my_sort(int arr[], int n, bool (*cmp)(int, int));
void my_sort(int arr[], int n, bool (*cmp)(int, int)){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (cmp(arr[j], arr[j+1]))
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            
        }
        
    }
    
}
int main(){
    int niz[]={4,8,62,10,25,8,3};
    int n=sizeof(niz)/(sizeof(int));
    my_sort(niz,n,ascending);
    cout<<"Uzlazno: ";
    for (int i : niz)
    {
        cout<<i<<" ";
    }
    my_sort(niz,n,descending);
    cout<<endl<<"Silazno: ";
    for (int i : niz)
    {
        cout<<i<<" ";
    }
    
}