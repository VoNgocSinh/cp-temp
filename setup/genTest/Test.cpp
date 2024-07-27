#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l, int r) {

    if (l > r) {
        cout << "Error l > r\n";
        assert(l > r);
    }

    return l + abs((int)rng() % (r - l + 1));

}

void komasan(){


}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    komasan();

}