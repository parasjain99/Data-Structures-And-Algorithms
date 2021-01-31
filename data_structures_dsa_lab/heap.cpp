#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v, int p)
{
    if (p > v.size())
        return;
    int l = 2 * p + 1;
    int r = 2 * p + 2;
    int m = p;
    if (l < v.size() && v[l] > v[m])
        m = l;
    if (r < v.size() && v[r] > v[m])
        m = r;
    if (m != p)
    {
        swap(v[m], v[p]);
        heapify(v, m);
    }
}

void createHeap(vector<int> &v){
    for(int i=v.size()/2 ;i>=0 ;i--){
        heapify(v,i);
    }
}
int del(vector<int> &v){
    int x = v[0];
    v[0] = v.back();
    v.pop_back();
    heapify(v,0);
    return x;
}
void insert(vector<int> &v, int p){
    v.push_back(p);
    int i = v.size()-1;
    while(i>0){
        if(v[(i-1)/2]<v[i]){
            swap(v[(i-1)/2],v[i]);
            i=(i-1)/2;
        }
        else break;
    }
}
void heapSort(vector<int> &v){
    vector<int> v1;
    int s = v.size();
    for(int i=0;i<s;i++){
        v1.push_back(del(v));
    }
    v=v1;
}




int main(){
    vector<int> v;
    int x=1,y;
    while(x){
        cout<<"1 to display\n2 to insert\n3 to delete\n4 to sort\n5 to convert to heap\n0 to exit\n";
        cin>>x;
        switch(x){
            case 1:{
                for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
                cout<<endl;
                break;
            }
            case 2:{
                cout<<"enter value\n";
                cin>>y;
                insert(v,y);
                break;
            }
            case 3:{
                cout<<"deleted " <<del(v)<<endl;
                break;
            }
            case 4:{
                heapSort(v);
                break;
            }
            case 5:{
                createHeap(v);
                break;
            }
            default :{
                cout<<"Enter valid choice\n";
                // x=1;
            }
        }
    }
}