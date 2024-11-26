#include<bits/stdc++.h>
using namespace std;
struct Item
{
    int profit, weight;
};

bool cmp(struct Item a, struct Item b)
{
    return a.profit > b.profit;
}
double frack(int W, struct Item arr[], int N)
{
    sort(arr, arr + N, cmp);
    double finalvalue = 0.0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i].weight <= W)
        {
            W -= arr[i].weight;
            finalvalue += arr[i].profit;
        }
        else
        {
            finalvalue
            += arr[i].profit
               * ((double)W / (double)arr[i].weight);
            break;
        }
    }
    return finalvalue;
}

int main()
{
    int W = 50;
    Item arr[3];
    arr[0].profit = 60;
    arr[0].weight = 10;
    
    arr[1].profit = 100;
    arr[1].weight = 20;
    
    arr[2].profit = 120;
    arr[2].weight = 30;
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << frack(W, arr, N);
    return 0;
}