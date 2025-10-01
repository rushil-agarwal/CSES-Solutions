#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n; cin >> n;
    ll sum = n*(n+1)/2;

    if(sum&1){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<int> first, second;
    ll firstSum=n, secondSum =0;
    first.push_back(n);

    for(int i = n-1; i>0; i--){
        if(firstSum >= secondSum){
            secondSum += i;
            second.push_back(i);
        } else {
            firstSum += i;
            first.push_back(i);
        }
    }

    cout << first.size() << endl;
    for(auto &it: first)
        cout << it << " ";

    cout << endl << second.size() << endl;
    for(auto &it: second)
        cout << it <<  " ";
    cout << endl;
    return 0;


}