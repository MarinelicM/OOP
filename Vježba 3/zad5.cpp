#include <iostream>
#include <string>
using namespace std;
string with_separators(string digits)
{
    int pocetak = 0;
    if (!digits.empty() && digits[0] == '-')
    {
        pocetak = 1;
    }
    for (int i = static_cast<int>(digits.size()) - 3; i > pocetak; i -= 3)
    {
        digits.insert(i, ".");
    }
    return digits;
}

string without_separators(string text)
{
    while (text.find('.') < text.size())
    {
        text.erase(text.find('.'), 1);
    }
    return text;
}

int main()
{
    string broj;
    cout << "Unesite broj: ";
    cin >> broj;
    cout << "S tockama: " << with_separators(broj) << endl;
    cout << "Bez tocaka: " << without_separators(broj) << endl;
}
