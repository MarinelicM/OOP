#include <iostream>
#include <string>
using namespace std;
class Ticket{
    private:
    string naziv;
    int id;
    static int brojac;
    public:
    Ticket(string n): naziv(n){
        brojac++;
        id=brojac;
    }
    static int issued(){
        return brojac;
    }
    int get_id() const{
        return id;
    }
};
int Ticket::brojac = 0;
int main()
{
    std::cout << Ticket::issued() << '\n';
    Ticket t1("Shame, Zagreb");
    Ticket t2("Shame, Zagreb");
    Ticket t3("Viagra Boys, Ljubljana");
    std::cout << t1.get_id() << ' ' << t2.get_id() << ' ' << t3.get_id() << '\n';
    std::cout << Ticket::issued() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    0
    1 2 3
    3
*/
