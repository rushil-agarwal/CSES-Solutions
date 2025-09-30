#include<bits/stdc++.h>
using namespace std;

int main(){
    string str; cin >> str;
    int ans = 1, curr = 1;

    for(int i = 1; i<str.length(); i++){
        if(str[i] == str[i-1]){
            curr++;
        } else {
            ans = max(ans, curr);
            curr =  1;
        }
    }

    ans = max(ans, curr);

    cout << ans << endl;

    return 0;
}