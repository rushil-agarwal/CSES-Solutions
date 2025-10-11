#include<bits/stdc++.h>
using namespace std;


void funct(int n, int a, int b){
    if(!a && !b){
        cout << "YES" << endl;
        for(int i=1; i<=n; i++)
            cout << i << " ";
        cout << endl;
        for(int i=1; i<=n; i++)
            cout << i << " ";
        cout << endl;
        return;
    }

    if(a+b > n || !a || !b){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    vector<int> first, second;

    for(int i=1; i<=a+b; i++){
        first.push_back(i);
        second.push_back(i);
    }

    for(int i=0; i<a+b; i++){
        second[(i+b)%(a+b)] = first[i];
    }

    for(int i = a+b+1; i<=n; i++){
        first.push_back(i);
        second.push_back(i);
    }

    for(auto &it: first)
        cout << it << " ";
    cout << endl;
    for(auto &it: second)
        cout << it << " ";
    cout << endl;

}


int main(){
    int t; cin >> t;
    while(t){
        int n, a, b; cin >> n >> a >> b;

        funct(n, a, b);
        t--;
    }

    return 0;
}