#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        bool sorted = true;
        for(int j=1;j<n;j++){
            if (a[j] < a[j - 1]){
                swap(a[j], a[j - 1]);
                sorted = false;
            }
        }
        if(sorted) break;
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}

// 15
// 7 8 1 1 2 -1 7 1 -10 100 50 8 4 3 -1