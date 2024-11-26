#include<bits/stdc++.h>
using namespace std;
int ZeoroOneKnapsack(int weight[],int value[],int n,int capacity)
{
     int k[n+1][capacity+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=8;j++)
        {
            if(i==0||j==0)
                k[i][j]=0;
            else if(j<weight[i-1])
                k[i][j]=k[i-1][j];
            else
                k[i][j]=max(value[i-1]+k[i-1][j-weight[i-1]],k[i-1][j]);
        }
    }
    
    return k[n][capacity];
}
int main()
{
    int weight []={3,4,6,5};
    int value[]={2,3,1,4};
    int n=4,capacity=8;
    cout<<ZeoroOneKnapsack(weight,value,n,capacity);

}