#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

// It takes minimum number of swaps

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n-1; i++){
        int m = i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[m]) m=j;
        swap(a[i],a[m]);
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}