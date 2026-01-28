#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

class segmentTree{
    int n; 
    vector<ll> tree;

public:
    segmentTree(int size){
        n = size;
        tree.resize(4*n, 0);
    }

    void buildTree(vector<ll> &nums, int node, int left, int right){
        if(left == right){
            tree[node] = nums[left];
            return;
        }
        
        int mid = (left+right)/2;

        buildTree(nums, 2*node, left, mid);
        buildTree(nums, 2*node+1, mid+1, right);

        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    void buildTree(vector<ll> &nums){
        buildTree(nums, 1, 0, n-1);
    }

    int query(int node, int segmentLeft, int segmentRight, int value){
        if(segmentLeft > segmentRight || tree[node] < value )
            return -1;

        if(segmentLeft == segmentRight){
            return segmentLeft;
        }

        int mid = (segmentLeft+segmentRight)/2;

        if(tree[2*node] >= value)
            return query(2*node, segmentLeft, mid, value);
        else    
            return query(2*node+1, mid+1, segmentRight, value);
    }

    int query(int value){
        return query(1, 0, n-1, value);
    }

    void update(int node, int segmentLeft, int segmentRight, int idx, int value){
        if(segmentLeft > segmentRight)
            return ;

        if(segmentLeft == segmentRight){
            tree[node] = value;
            return;
        }

        int mid = (segmentLeft + segmentRight)/2;

        if(idx <= mid)
            update(2*node, segmentLeft, mid, idx, value);
        else
            update(2*node+1, mid+1, segmentRight, idx, value);

        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    void update(int idx, int value){
        update(1, 0, n-1, idx, value);
    }
};


void solve(){
    int n, m; cin >> n >> m;

    vector<ll> hotels(n), groups(m);

    for(int i=0; i<n; i++)
        cin >> hotels[i];

    segmentTree sTree(n);
    sTree.buildTree(hotels);
    
    for(int i=0; i<m; i++){
        ll group; cin >> group;

        int idx = sTree.query(group);
        
        if(idx == -1){
            cout << "0 ";
            continue;
        }
        
        hotels[idx] -= group;
        sTree.update(idx, hotels[idx]);

        cout << idx+1 << ' ';
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
  //  cin >> t;
    while(t--)
        solve();

    return 0;
}