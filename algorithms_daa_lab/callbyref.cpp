#include<bits/stdc++.h>

using namespace std;

void fun1(int &a, int b){
a++;
b++;
cout<<"a is:"<<a<<endl;
cout<<"b is:"<<b<<endl;
}

int main(){
int x=1,y=1;
fun1(x,y);
cout<<"x is:"<<x<<endl<<"y is"<<y;

}
