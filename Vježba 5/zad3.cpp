#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Song{
    public:
    string title,artist;
    int seconds;
};
class Album{
    public:
        Album(string t,int y,Song first):title(t),year(y){songs.push_back(first);}
        bool add(Song s){
            for(int i=0;i<songs.size();i++){
                if(s.title==songs[i].title){
                    return false;
                }
                
            }
            songs.push_back(s);
            return true;
        }
        int duration() const{
            int ukupno=0;
            for (int i = 0; i < songs.size(); i++)
            {
                ukupno+=songs[i].seconds;
            }
            return ukupno;
        }
        void print() const{
            int minute=0;
            int sekunde=0;
            minute=duration()/60;
            sekunde=duration()%60;
            cout<<title<<"("<<year<<" )"<<songs.size()<<" pjesme "<<minute<<":"<<sekunde<<endl;
            for (int i = 0; i < songs.size(); i++) {
        cout << "  " << i + 1 << ". " << songs[i].title << endl;
    }
        }
    private:
        string title;
        int year;
        vector<Song> songs;
};

int main()
{
    Album a("Sol Invictus", 2015, {"Sol Invictus", "Faith No More", 156});
    a.add({"Superhero", "Faith No More", 315});
    a.add({"Matador", "Faith No More", 368});
    std::cout << a.add({"Superhero", "Faith No More", 315}) << '\n';   // vec postoji
    a.print();
    return 0;
}