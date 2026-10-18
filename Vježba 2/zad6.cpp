#include <iostream>
#include <string>
using namespace std;
struct Student {
    string ime;
    string jmbag;
    int godina;
    int ects;
    double prosjek;
};

void ispisi(Student& s){
    cout << s.ime << " " << s.jmbag << " "
         << s.godina << " " << s.ects << " "
         << s.prosjek << endl;
}

void povecaj_godinu(Student& s){
    s.godina++;
}

void filter_students(Student s[], int n,
                     void (*action)(Student&),
                     bool (*cond)(const Student&)){
    for(int i=0; i<n; i++){
        if(cond(s[i])){
            action(s[i]);
        }
    }
}

int main(){
    Student studenti[] = {
        {"Ivan", "001", 1, 50, 4.2},
        {"Ana", "002", 1, 0, 3.0},
        {"Marko", "003", 2, 40, 3.8},
        {"Petra", "004", 2, 55, 4.5},
        {"Luka", "005", 1, 30, 3.2}
    };
    int n = sizeof(studenti) / sizeof(Student);
    cout << "Studenti prve godine s polozenim ispitom:" << endl;
    filter_students(studenti, n, ispisi, [](const Student& s){
        return s.godina == 1 && s.ects > 0;
    });

    cout << "\nStudenti s prosjekom vecim od 3.5:" << endl;
    filter_students(studenti, n, ispisi, [](const Student& s){
        return s.prosjek > 3.5;
    });

    filter_students(studenti, n, povecaj_godinu, [](const Student& s){
        return s.ects >= 45;
    });

    cout << "\nStudenti nakon povecanja godine:" << endl;
    for(int i=0; i<n; i++){
        ispisi(studenti[i]);
    }
}
