#include <bits/stdc++.h>
using namespace std;

int main() {
    system("g++ -o rand.exe rand.cpp");
    system("g++ -o H.exe Householder.cpp");
    system("rand.exe > data.in");
    system("H.exe < data.in > H.out");
    return 0;
}