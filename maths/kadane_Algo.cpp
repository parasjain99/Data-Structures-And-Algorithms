#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
// Maximum subarray sum
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    int best =0,sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum = max(a[i],sum+a[i]);
        best = max(best,sum);
    }
    cout<<best;
    
}