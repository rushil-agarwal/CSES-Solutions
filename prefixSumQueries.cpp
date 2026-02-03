#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

struct node{
    ll sum, prefix;

    node(){
        sum =0, prefix=0;
    }
};

class segmentTree{
    int n;
    vector<node> tree;

public:

    segmentTree(int size){
        n = size;
        tree.resize(4*n);
    }

    void build(vector<ll> &nums, int idx, int left, int right){
        if(left == right){
            tree[idx].sum = nums[left];
            tree[idx].prefix = max(0LL, nums[left]);
            return;
        }
        int mid = (left+right)/2;
        build(nums, 2*idx, left, mid);
        build(nums, 2*idx+1, mid+1, right);

        tree[idx].sum = tree[2*idx].sum + tree[2*idx+1].sum;
        tree[idx].prefix = max(tree[2*idx].prefix, tree[2*idx].sum + tree[2*idx+1].prefix);
    }

    void build(vector<ll> &nums){
        build(nums, 1, 0, n-1);
    }

    void update(int idx, int left, int right, int updateIdx, ll value){
        if(left == right){
            tree[idx].sum = value;
            tree[idx].prefix = max(0LL, value);
            return;
        }

        int mid = (left+right)/2;

        if(updateIdx <= mid)
            update(2*idx, left, mid, updateIdx, value);
        else
            update(2*idx+1, mid+1, right, updateIdx, value);

        tree[idx].sum = tree[2*idx].sum + tree[2*idx+1].sum;
        tree[idx].prefix = max(tree[2*idx].prefix, tree[2*idx].sum + tree[2*idx+1].prefix);
    }

    void update(int idx, ll value){
        update(1, 0, n-1, idx, value);
    }

    node query(int idx, int left, int right, int queryLeft, int queryRight){
        if(queryLeft == left && queryRight == right)
            return tree[idx];

        int mid = (left+right)/2;

        if(queryRight <= mid)
            return query(2*idx, left, mid, queryLeft, queryRight);
        else if(queryLeft > mid)
            return query(2*idx+1, mid+1, right, queryLeft, queryRight);
        else {
            node leftPrefix = query(2*idx, left, mid, queryLeft, min(mid, queryRight));
            node rightPrefix = query(2*idx+1, mid+1, right, max(mid+1, queryLeft), queryRight);

            node ans;

            ans.sum = leftPrefix.sum + rightPrefix.sum;
            ans.prefix = max(leftPrefix.prefix, leftPrefix.sum + rightPrefix.prefix);

            return ans;
        }
    }

    ll query(int l, int r){
        return query(1, 0, n-1, l, r).prefix;
    }
};

void solve(){
    int n, q; cin >> n >> q;

    vector<ll> nums(n);

    for(int i=0; i<n; i++)
        cin >> nums[i];

    segmentTree sTree(n);

    sTree.build(nums);

    for(int i=0; i<q; i++){
        int type; 
        ll a, b;
        cin >> type >> a >> b;

        if(type == 1){
            sTree.update(a-1, b);
        } else {
            cout << sTree.query(a-1, b-1) << "\n";
        }
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