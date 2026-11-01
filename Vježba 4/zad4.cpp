#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct PasswordInfo{
    int length,digits,uppercase,special;
};
PasswordInfo analyze(const string& password){
    PasswordInfo info;
    info.length=password.size();
    info.digits=count_if(password.begin(),password.end(),[](unsigned char d){
        return isdigit(d);
    });
    info.uppercase=count_if(password.begin(),password.end(),[](unsigned char upper){
        return isupper(upper);
    });
    info.special=count_if(password.begin(),password.end(),[](unsigned char spec){
        return ispunct(spec);
    });
    return info;
}
bool is_strong(const PasswordInfo& info){
    if(info.length>=10 && info.digits>=1 && info.uppercase>=1 && info.special>=1){
        return true;
    }
    return false;
}
int main(){
    string password;
    cout<<"Unesite lozinku: ";
    getline(cin,password);
    PasswordInfo info=analyze(password);
    cout<<password;
    cout<<": duljina: "<<info.length<<", znamenke: "<<info.digits<<", velika: "<<info.uppercase<<", posebni: "<<info.special<<endl;
    if(is_strong(info)==1){
        cout<<"Lozinka je jaka";
    }
    else{
        cout<<"Lozinka je slaba";
    }
}