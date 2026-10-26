#include <iostream>
#include <string>
using namespace std;
bool split_email(const std::string& email, std::string& user,std::string& domain){
    size_t pozicija=email.find('@');
    if(pozicija==string::npos || pozicija!=email.rfind('@')){
        return false;
    } 
    
    if (pozicija == 0 || pozicija == (email.size() - 1))
    {
        return false;
    }
    user=email.substr(0,pozicija);
    domain=email.substr(pozicija+1);
    if(domain.find('.')==string::npos){
        return false;
    }
    return true;
}
int main(){
    string email,user,domain;
    cout<<"Unesite email: ";
    getline(cin,email);
    if(split_email(email,user,domain)){
        cout<<"Korisnik: "<<user<<endl<<"Domena: "<<domain<<endl;
    }
    else{
        cout<<"Neispravan email!";
    }
}