#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool starts_with(const string& s, const string& prefix){
    if(prefix.size()>s.size()){
        return false;
    }
    return equal(prefix.begin(),prefix.end(),s.begin());
}
bool ends_with(const std::string& s, const std::string& suffix){
    if(suffix.size()>s.size()){
        return false;
    }
    return equal(suffix.rbegin(),suffix.rend(),s.rbegin());
}
int main(){
    vector<string> datoteka={"vjezba04.cpp", "slajdovi.pdf", "main.cpp", 
        "README.md", "vjezba04.h", "notes.txt", "vjezba03.cpp"};
    int br=0;
    for(int i=0;i<datoteka.size();i++){
        if(ends_with(datoteka[i],".cpp")){
            br++;
        }
    }
    cout<<"Postoji "<<br<<" datoteka koje zavrsavaju na .cpp"<<endl;
    datoteka.erase(
    remove_if(datoteka.begin(), datoteka.end(),
        [](const string& s) {
            return starts_with(s,"vjezba");
        }),
    datoteka.end()
);
cout<<"novi vektor: ";
for (int i = 0; i < datoteka.size(); i++)
{
    cout<<datoteka[i]<<" ";
}

}