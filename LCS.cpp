#include<bits/stdc++.h>
using namespace std;

int lcs(string a, string b, int m, int n)
{
    int l[m+1] [m+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                l[i][j]=0;
            else if(a[i-1]==b[j-1])
                l[i][j]=l[i-1][j-1]+1;
            else
                l[i][j] = max(l[i-1][j],l[i][j-1]);
        }
    }
    return l[m][n];
}

int main()
{
    string a = "JAMILAHMED";
    string b = "NIYAZAHMED";
    int m = a.size();
    int n = b.size();
    cout<<lcs(a, b, m, n)<<endl;
}