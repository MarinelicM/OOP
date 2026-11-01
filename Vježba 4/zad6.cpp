#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;
vector<string> split_words(const string& text)
{
    vector<string> rijeci;
    size_t pocetak = 0;

    while (pocetak < text.size())
    {
        if (text[pocetak] == ' ')
        {
            pocetak++;
            continue;
        }
        size_t kraj = text.find(' ', pocetak);

        if (kraj == string::npos)
        {
            kraj = text.size();
        }
        rijeci.push_back(text.substr(pocetak, kraj - pocetak));
        pocetak = kraj;
    }

    return rijeci;
}
int main(){
    vector <string> rjecnik={"programski", "jezik", "c++", "je", "brz", "i", "mocan", "ali", "nije","jednostavan", "za", "pocetnike"};
    sort(rjecnik.begin(),rjecnik.end());
    string recenica;
    cout<<"Unesite recenicu: ";
    getline(cin,recenica);
    vector<string> rijeci=split_words(recenica);
    int br=0;
    vector<string> nepoznate;
    for(string &rijec:rijeci){
        rijec.erase(remove_if(rijec.begin(),rijec.end(),[](char c){
            if(c==',' || c=='.'){
                return true;
            }
            else{
                return false;
            }
        }),rijec.end());
        for (int i = 0; i < rijec.size(); i++)
        {
            if(isupper(rijec[i])){
                rijec[i]=tolower(rijec[i]);
            }
        }
        if(!binary_search(rjecnik.begin(),rjecnik.end(),rijec)){
            br++;
            nepoznate.push_back(rijec);
        }
    }
    cout<<"Broj nepoznatih rijeci: "<<br<<" ";
    for (int i = 0; i < nepoznate.size(); i++)
    {
        cout<<nepoznate[i]<<" ";
    }
    
}