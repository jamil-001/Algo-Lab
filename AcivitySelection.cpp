#include<bits/stdc++.h>
using namespace std;
void maxActivity(int s[],int f[],int n)
{   
    int i,j;
    int count = 1;   //s //10,12,20
    i = 0;           //f //20,25,30
    for(j = 1;j < n; j++){
        if(s[j] >= f[i]){
            count++;
            i = j;
        }
    }
    cout << count;
}

int main(){
    int s[] = {12,10,20};
    int f[] = {25,20,30};
    int n = sizeof(s)/sizeof(s[0]);

    for(int k=0; k <n; k++){
        for(int l=k+1; l < n; l++){
            if(f[k] > f[l]){
                int temp = f[k];
                f[k] = f[l];
                f[l] = temp;

                temp = s[k];
                s[k] = s[l];
                s[l] = temp;
            }
        }
    }
    maxActivity(s,f,n);
    return 0;
}