#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[1000][1000];
void printPascal()
{
    for (ll line = 0; line < 1000; line++)
    {

        for (ll i = 0; i <= line; i++)
        {

        if (line == i || i == 0)
            arr[line][i] = 1;

        else
            arr[line][i] = arr[line - 1][i - 1] +
                            arr[line - 1][i];

        }

    }
}


int main()
{
    ll n,t;
    cin>>t;
    ll n1=1000;
    printPascal();
    for(ll i=0;i<t;i++)
    {
        cin>>n;
        for(ll j=0;j<=n;j++)
        cout<<arr[n][j]<<" ";
        cout<<endl;
    }

    return 0;
}



