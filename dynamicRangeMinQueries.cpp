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
        tree.resize(4*n, LLONG_MAX);
    }

    void buildTree(vector<ll> &nums, int node, int left, int right){
        if(left == right){
            tree[node] = nums[left];
            return;
        }

        int mid = (left+right)/2;

        buildTree(nums, 2*node, left, mid);
        buildTree(nums, 2*node+1, mid+1, right);

        tree[node] = min(tree[2*node], tree[2*node+1]);
    }

    void update(int node, int left, int right, int updateIdx, ll newVal){
        if(left == right){
            tree[node] = newVal;
            return;
        }

        int mid = (left+right)/2;

        if(updateIdx <= mid)
            update(2*node, left, mid, updateIdx, newVal);
        else
            update(2*node+1, mid+1, right, updateIdx, newVal);

        tree[node] = min(tree[2*node], tree[2*node+1]);
    }

    ll query(int node, int segmentLeft, int segmentRight, int queryLeft, int queryRight ){

        if(queryLeft > queryRight)
            return LLONG_MAX;

        if(segmentLeft == queryLeft && segmentRight == queryRight){
            return tree[node];
        }

        int mid = (segmentLeft + segmentRight)/2;

        ll leftMin = query(2*node, segmentLeft, mid, queryLeft, min(queryRight, mid));
        ll rightMin = query(2*node+1, mid+1, segmentRight, max(queryLeft, mid+1), queryRight);

        return min(leftMin, rightMin);
    }

    void buildTree(vector<ll> &nums){
        buildTree(nums, 1, 0, n-1);
    }

    void update(int idx, ll value){
        update(1, 0, n-1, idx, value);
    }

    ll query(int left, int right){
        return query(1, 0, n-1, left, right);
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    vector<ll> nums(n);
    segmentTree sTree(n);

    for(int i=0; i<n; i++)
        cin >> nums[i];

    sTree.buildTree(nums);

    for(int i=0; i<q; i++){
        ll type, a, b;
        cin >> type >> a >> b;

        if(type == 1){
            sTree.update((int)a-1, b); 
        } else {
            cout << sTree.query(a-1, b-1) << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
 //   cin >> t;
    while(t--)
        solve();

    return 0;
}