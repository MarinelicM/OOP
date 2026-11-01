#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Song{
    string title, artist;
    int year,plays;
};
void print_song(const Song &s){
    cout<<"Naslov:"<<s.title<<" Izvodac:"<<s.artist
    <<" Godina:"<<s.year<<" Broj slusanja:"<<s.plays;

}
int main(){
    vector<Song> pjesme={{"Klinka","Jala&Buba",2017,100264},
                        {"Stari lav","Željko Samarđić",2010,50487},
                        {"Godzilla","Jala&Buba",2017,2048752},
                        {"Lavica","Jelena Rozga",2020,421548}};
    sort(pjesme.begin(),pjesme.end(),[](const Song& a,const Song& b){
        if(a.year==b.year){
            return a.title<b.title;
        }
        return a.year<b.year;});
    for(int i=0;i<pjesme.size();i++){
        print_song(pjesme[i]);
        cout<<endl;
    }
    string izvodac;
    cout<<"Unesite izvodaca: ";
    getline(cin,izvodac);
    int br=0;
    int najstarija=-1;
    for(int i=0;i<pjesme.size();i++){
        if(pjesme[i].artist==izvodac){
            br++;
            if(najstarija==-1){
                najstarija=i;
            }
        }
    }
    if (br == 0) {
    cout << "Izvodac nema pjesama!";
}
else {
    cout << "Izvodac ima " << br << " pjesama i najstarija je ";
    print_song(pjesme[najstarija]);
    cout << endl;
}
int najslusanija = 0;

for (int i = 1; i < pjesme.size(); i++) {
    if (pjesme[i].plays > pjesme[najslusanija].plays) {
        najslusanija=i;
    }
}
cout<<"Najslusanija pjesma je: ";
print_song(pjesme[najslusanija]);
}