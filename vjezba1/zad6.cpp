#include <iostream>
using namespace std;
struct fraction
{
    int numerator;//brojnik
    int denominator;//nazivnik
    void reduce()
    {
        int a = numerator;
        int b = denominator;
        while (b != 0)
        {
            int priv = b;
            b = a % b;
            a = priv;
        }
        numerator/=a;
        denominator/=a;
    }
    double value()
    {
        return (double)numerator / denominator;
    }
    void print()
    {
        cout<<numerator<<"/"<< denominator;
    }
};
fraction sum(const fraction& a, const fraction& b)
{
    fraction result;
    result.numerator =a.numerator*b.denominator+b.numerator*a.denominator;
    result.denominator =a.denominator*b.denominator;
    result.reduce();
    return result;
}
int main()
{
    fraction a = {1, 2};
    fraction b = {1, 4};
    fraction c = sum(a, b);
    cout << "Prvi razlomak: ";
    a.print();
    cout << endl << "Drugi razlomak: ";
    b.print();
    cout << endl << "Zbroj: ";
    c.print();
    cout << endl << "Decimalna vrijednost: ";
    cout << c.value();
    return 0;
}