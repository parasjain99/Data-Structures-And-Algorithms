#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

//function to check prime number in O(sqrt(n))
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
//function to return prime factorization of a number in O(sqrt(n))
vector<int> factors(int n){
    vector<int> f;
    for(int i=0;i*i<=n;i++){
        while(n%i==0){
            f.push_back(i);
            n/=i;
        }
    }
    if(n>1) f.push_back(n);
    return f;
}


//Sieve of Eratosthenes
//This code will compute all the prime numbers that are smaller than or equal to N.
bool isPrime[N + 1];
void sieve(int N)
{
    for (int i = 0; i <= N; ++i)
    {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= N; ++i)
    {
        if (isPrime[i] == true)
        { //Mark all the multiples of i as composite numbers
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }
}


//sieve to mark least prime factor / smallest prime factor of each number less than n

int spf[n + 1];
void MinPrimeSieve(int n){
    for(int i=1;i<n;i++) spf[i] = i;
    for (int i = 2; i * i <= n; ++i){
        if (spf[i] == i)
        { //If i is prime
            for (int j = i * i; j <= n; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}


//return prime factorization of number using sieve

vector<int> factorize(int n){
    int spf[n + 1];
    for (int i = 1; i < n; i++)
    {
        spf[i] = i;
    }
    for (int i = 2; i * i <= n; ++i)
    {
        if (spf[i] == i)
        { //If i is prime
            for (int j = i * i; j <= n; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
    vector<int> res;
    while (n != 1)
    {
        res.push_back(spf[n]);
        n /= spf[n];
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}