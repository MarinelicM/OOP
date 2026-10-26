#include <iostream>
using namespace std;
int& find_max(int arr[], int n)
{
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[max])
        {
            max = i;
        }
    }
    return arr[max];
}
int main()
{
    int numbers[] = {4, -7, 12, 0, 9, -3};
    cout << "Ispis niza:" << "\n";
    for (int i : numbers)
    {
        cout << i << "\t";
    }
    cout << endl << "Pretvoreni negativni brojevi:" << endl;
    for (int& i : numbers)
    {
        if (i < 0)
        {
            i = i * (-1);
        }
        cout << i << "\t";
    }
    cout << endl << "Najveci u nulu:" << endl;
    int n = sizeof(numbers) / sizeof(numbers[0]);
    find_max(numbers, n) = 0;
    for (int i : numbers)
    {
        cout << i << "\t";
    }
}