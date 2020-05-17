#include<bits/stdc++.h>

using namespace std;

int main(){
    int w,n;
    float cw,cb;
    cin>>n>>w;
    vector<pair<float,int> > list(n),ratio;//benifit&weight, ratio&id
    for(int i=0;i<n;i++){
        cin>>list[i].first>>list[i].second;
        ratio.push_back({(float)(list[i].second/list[i].first),i});
    }
    sort(ratio.begin(),ratio.end());
    cw=0;
    cb=0;
    cout<<"benifit\tweight\n";
    for(int i=0;i<n;i++){
        int pos = ratio[i].second;
        if(cw+list[pos].second<=w){
            cw+=list[pos].second;
            cb+=list[pos].first;
            cout<<list[pos].first<<"\t"<<list[pos].second<<endl;
        }
        else if(cw<w){
            cb = cb + ( (w - cw) / ratio[i].first);
            cw=w;
            cout << list[pos].first << "\t" << ratio[i].first * (w - cw) << endl;
            break;
        }
        else{
            break;
        }
        
    }
    cout<<"weight="<<cw<<"\tbenifit="<<cb;
}
