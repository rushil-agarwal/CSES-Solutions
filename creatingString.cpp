#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n == 1)
        return 1;
    return n*factorial(n-1);
}

int main(){
    string str; cin >> str;
    int total = factorial((int)str.length());

    vector<int> freq(26, 0);

    for(char &ch: str)
        freq[ch-'a']++;

    for(auto &it: freq){
        if(it > 1)
            total/=factorial(it);
    }
    sort(str.begin(), str.end());
    cout << total << endl;

    do{
        cout << str << endl;
    } while(next_permutation(str.begin(), str.end()));

    return 0;

}