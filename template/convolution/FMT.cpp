int n,mod;
void OR(int a[], int A[], int op) {
    for(int i = 0; i < p2(n); i++) A[i] = a[i];
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < p2(n); j++) 
            if(j & p2(i)) A[j] = (1ll * A[j] + A[j ^ p2(i)] * op + mod) % mod;
}

void AND(int a[], int A[], int op) {
    for(int i = 0; i < p2(n); i++) A[i] = a[i];
    for(int i = 0; i < n; i++) 
        for(int j = p2(n)-1; j >= 0; j--) 
            if(!(j & p2(i))) A[j] = (1ll * A[j] + A[j ^ p2(i)] * op + mod) % mod;
}