#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

int main(){
    int n;
    cin >> n;
    int a[n];
    int m = INT_MIN;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        m = max(m,a[i]);
    }
    int cnt[m+1]={0};
    for(int i=0;i<n;i++) cnt[a[i]]++;
    int pos=0;
    for(int i=0;i<=m;i++){
        for(int j=0;j<cnt[i];j++){
            a[pos] = i;
            pos++;
        }
    }        
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}