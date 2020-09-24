#include<bits/stdc++.h>
using namespace std;
void rec(int ind,vector<string>&dict,vector<string>& ans)
{
    int n=dict.size();

    if(ind>=n)
    return;

    if(ind==(n-1))
    {
        for(auto t:ans)
        cout<<t<<" ";

        cout<<endl;

        return;
    }

    int cnt=0;

    for(int i=ind+1;i<n;i++)
    {
        cnt=0;
        int sz=dict[i].size();

        for(int j=0;j<sz;j++)
        if(dict[ind][j]!=dict[i][j])
        cnt++;

        if(cnt==1)
        {
            ans.push_back(dict[i]);
            rec(i,dict,ans);

            ans.pop_back();
        }
    }
}
int main()
{
    int n;
    cin>>n;
    string st,en;
    cin>>st>>en;

    vector<string> dict,ans;
    dict.push_back(st);

    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        dict.push_back(s);
    }

    dict.push_back(en);

    rec(0,dict,ans);
}

Input=
5
hat dog
hot hog cat dat  dot