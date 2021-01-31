//greatest common divisor/ Heighest Common Factor;
#include<bits/stdc++.h>
using namespace std;

// gcd basic algo
int GCD(int A, int B) {
    int m = min(A, B), gcd;
    for(int i = m; i > 0; --i)
        if(A % i == 0 && B % i == 0) {
            gcd = i;
            return gcd;
        }
}

//recursive approach using euclid formula, here (a>b) 
int gcdEuclid(int a,int b)		
	{
		int x=max(a,b);
		b=min(a,b);
		a=x;
		if(b==0)
			return(a);
			
		else
			return gcdEuclid(b,a%b);
	}
	//iterative approach using euclid formula, here (a>b)

	int gcd(int a, int b)
	{
		int temp;
		while (b != 0)
		{
			temp = a % b;
			a = b;
			b = temp;
		}
		return a;
	}

int main(){
	
	int x,y;
	cin>>x>>y;
	cout<<"gcd is "<<gcdEuclid(x,y);
	
	return(0);
}