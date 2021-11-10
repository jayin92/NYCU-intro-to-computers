#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    string a, b;
    cin >> a >> b;
    int sza = a.size();
    int szb = b.size();
    vector<int> aa(sza);
    vector<int> bb(szb);
    vector<int> res(sza+szb+10, 0);
    for(int i=0;i<sza;i++){
        aa[i] = a[sza-1-i] - '0';
    }

    for(int i=0;i<szb;i++){
        bb[i] = b[szb-1-i] - '0';
    }
    for(int j=0;j<szb;j++){
        for(int i=0;i<sza;i++){
            res[i+j] += aa[i] * bb[j];
        }
    }
    int carry = 0;
    for(int i=0;i<sza+szb+10;i++){
        res[i] += carry;
        carry = res[i] / 10;
        res[i] %= 10;
    }
    bool flag = true;
    for(int i=sza+szb+9;i>=0;i--){
        if(flag){
            if(res[i] != 0){
                flag = false;
                cout << res[i];
            }
        } else {
            cout << res[i];
        }
    }
    if(flag){
        cout << 0;
    }
    cout << endl;
}