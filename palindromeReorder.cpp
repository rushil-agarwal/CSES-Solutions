#include<bits/stdc++.h>
using namespace std;

int main(){
    string str; cin >> str;
    vector<int> vec(26, 0);

    for(auto &ch: str)
        vec[ch-'A']++;

    int odd = -1;

    for(int i=0; i<26; i++) {
        if(vec[i]&1){
            if(odd != -1){
                cout << "NO SOLUTION" << endl;
                return 0;
            }

            odd = i;
        }
    }
    string ans = "";

    if(odd != -1) {
        vec['A' + odd]--;
        ans = string(1, 'A' + odd);
    }
    for(int i=0; i<26; i++){
        int len = vec[i]/2;
        ans = string(len, 'A'+i) + ans + string(len, 'A'+i);
    }

    cout << ans << endl;
    return 0;

}