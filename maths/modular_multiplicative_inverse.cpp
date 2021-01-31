#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
// Modular multiplicative inverse of A mod M can only be calculated when A,M are coprimes
// Basic Approach here
int modInverse(int A, int M)
{
    A = A % M;
    for (int B = 1; B < M; B++)
        if ((A * B) % M)==1)
            return B;
}
//********************************************************************************************************//
// if M is prime
// Using Modular Exponent

long long modularExponentiation(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int modInverse(long long A, long long M)
{
    return modularExponentiation(A, M - 2, M);
}

//**********************************************************************************************************//

// Using extended Euclid

int d, x, y;
void extendedEuclid(int A, int B)
{
    if (B == 0)
    {
        d = A;
        x = 1;
        y = 0;
    }
    else
    {
        extendedEuclid(B, A % B);
        int temp = x;
        x = y;
        y = temp - (A / B) * y;
    }
}

int modInverse(int A, int M)
{
    extendedEuclid(A, M);
    return (x % M + M) % M; //x may be negative
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
}