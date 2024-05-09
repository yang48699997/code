#include<bits/stdc++.h>

#define p2(i) (1 << i)
using namespace std;
int mod,inv2,n;

void XOR(int a[], int A[], int op) {
    for(int i = 0; i < p2(n); i++) A[i] = a[i];
    for(int i = 1; i < p2(n); i <<= 1) {
        for(int j = 0, p = i * 2; j < p2(n); j += p) {
            for(int k = 0; k < i; k++) {
                int x = A[j + k], y = A[j + i + k];
                if(op == 1)
                    A[j + k] = (1ll * x + y) % mod, A[j + i + k] = (1ll * x - y + mod) % mod;
                else 
                    A[j + k] = (1ll * x + y) % mod * inv2 % mod, A[j + i + k] = (1ll * x - y + mod) % mod * inv2 % mod;
            }
        }
    }
}