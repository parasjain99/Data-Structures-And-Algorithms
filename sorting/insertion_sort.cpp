#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n ; i++){
        int j = i;
        int temp = a[i];
        while(j>0 and a[j-1]>temp){
            a[j]=a[j-1];
            j--;
        }
        a[j] = temp;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}