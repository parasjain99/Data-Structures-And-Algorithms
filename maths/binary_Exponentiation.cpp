#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

// Binary Exponentiation

    //Recursive Approach

long long binpow(long long a, long long b){
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2) // b is odd
        return res * res * a;
    else    //b is even
        return res * res;
}

//Iterative Approach

long long binpow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)  // equivalent condition if (b%2==1)
            res = res * a;
        a = a * a;
        b >>= 1;    // right shift equivalent to b/=2
    }
    return res;
}

// Modular Exponent

long long mpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0){
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

//Works for -ve powers

float power(float x, int y)
{
    float temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
    {
        if (y > 0)
            return x * temp * temp;
        else
            return (temp * temp) / x;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
}