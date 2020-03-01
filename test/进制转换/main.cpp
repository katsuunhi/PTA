#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Pto10(int x, int P){
    int y = 0;
    int produce = 1;
    while(x != 0){
        y += (x%10)*produce;
        x /= 10;
        produce *= P;
    }
    return y;
}

void _10toQ(int y, int Q, int z[]){
    int num = 0;
    do{
        z[num ++] = y%Q;
        y /= Q;
    }while(y != 0);
}

int main()
{
    int z[40];
    cout << Pto10(12, 8);
    _10toQ(16, 16, z);
    cout << endl << z[0] << z[1];
    return 0;
}
