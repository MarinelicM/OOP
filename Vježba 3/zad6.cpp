#include <iostream>
#include <vector>
#include <string>
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

int main()
{
    string text;

    cout << "Unesite recenicu: ";
    getline(cin, text);
    vector<string> rijeci = split_words(text);
    cout << "Broj rijeci: " << rijeci.size() << endl;
    if (rijeci.empty())
    {
        cout << "Nema rijeci!" << endl;
        return 0;
    }

    string najdulja = rijeci[0];

    for (int i = 1; i < rijeci.size(); i++)
    {
        if (rijeci[i].size() > najdulja.size())
        {
            najdulja = rijeci[i];
        }
    }
    cout << "Najdulja: " << najdulja << endl;

    string obrnuto = "";
    for (int i = static_cast<int>(rijeci.size()) - 1; i >= 0; i--)
    {
        obrnuto += rijeci[i];

        if (i != 0)
        {
            obrnuto += "-";
        }
    }
    cout << obrnuto << endl;
    string prva = rijeci[0];
    for (int i = 1; i < rijeci.size(); i++)
    {
        if (rijeci[i] < prva)
        {
            prva = rijeci[i];
        }
    }
    cout << "Prva po abecedi: " << prva << endl;
}
