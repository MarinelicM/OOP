 #include <iostream>
 using namespace std;
 template <typename T>
 inline bool ascending(T a,T b){
    return a>b;
}
template <typename T>
inline bool descending(T a,T b){
    return a<b;
}
template <typename T>
void my_sort(T arr[], int n, bool (*cmp)(T, T)){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (cmp(arr[j], arr[j+1]))
            {
                T temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            
        }
        
    }
    
}
 int main(){
    double niz1[]={1.5, 36,8,2.6, 42.5, 48.1 };
    int niz2[]={99,421,1,24,85,3};
    char niz3[]={'b','g','e','t','a','o' };
    int n1=sizeof(niz1)/sizeof(double);
    int n2=sizeof(niz2)/sizeof(int);
    int n3=sizeof(niz3)/sizeof(char);
    my_sort(niz1,n1,ascending<double>);
    cout<<"Sortiranje double uzlazno: ";
    for (int i = 0; i < n1; i++)
    {
        cout<<niz1[i]<<" ";
    }

    my_sort(niz1,n1,descending<double>);
    cout<<endl<<"Sortiranje double silazno: ";
    for (int i = 0; i < n1; i++)
    {
        cout<<niz1[i]<<" ";
    }

    my_sort(niz2,n2,ascending<int>);
    cout<<endl<<"Sortiranje int uzlazno: ";
    for (int i = 0; i < n2; i++)
    {
        cout<<niz2[i]<<" ";
    }

    my_sort(niz2,n2,descending<int>);
    cout<<endl<<"Sortiranje int silazno: ";
    for (int i = 0; i < n2; i++)
    {
        cout<<niz2[i]<<" ";
    }

    my_sort(niz3,n3,ascending<char>);
    cout<<endl<<"Sortiranje char uzlazno: ";
    for (int i = 0; i < n3; i++)
    {
        cout<<niz3[i]<<" ";
    }
    
    my_sort(niz3,n3,descending<char>);
    cout<<endl<<"Sortiranje char silazno: ";
    for (int i = 0; i < n3; i++)
    {
        cout<<niz3[i]<<" ";
    }
 }