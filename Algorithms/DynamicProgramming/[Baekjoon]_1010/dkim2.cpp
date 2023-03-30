#include <iostream>
using namespace std;

void Combination(int N, int M);

int main()
{
    int count;
    cin >> count;
    pair<int, int> PPP;
    for (int i = 0 ; i < count ; i++)
    {
        cin >> PPP.first >> PPP.second;
        if (PPP.first < PPP.second)
            swap<int>(PPP.first, PPP.second);
        Combination(PPP.first, PPP.second);
    }
}

void Combination(int N, int M)
{
    unsigned long res = 1;
    for (int i = 1 ; i <= M ; i++)
    {
        res *= (N - i + 1);
        res /= (i);
    }
    cout << res << endl;
}
