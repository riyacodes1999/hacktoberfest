#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int tree[4*N];
// The segmented tree is created based on 1 indexing
int lazy[4*N];
void update(int tl, int tr, int ne, int idx, int curr) // update function tl tr the total range is given ne is the new value to replace with and idx is the place where the value should increase and curr is the current index of the tree which is pointing at:
{
    if (tl == idx && tr == idx)
    {
        tree[curr] = ne;
        return;
    }
    if (idx > tr || idx < tl)
        return;
    int mid = (tl + tr) / 2;

    update(tl, mid, ne, idx, 2 * curr);
    update(mid + 1, tr, ne, idx, 2 * curr + 1);

    int leftchild = 2 * curr, rightchild = 2 * curr + 1;
    tree[curr] = tree[leftchild] + tree[rightchild];
}

int sum_queries(int tl, int tr, int curr, int lidx, int ridx)
{
    if (tr < lidx || tl > ridx) // case 1 where the idx reaching out of bound
    {
        return 0;
    }
    if (tl >= lidx && tr <= ridx)//case 2 where the range totally lies inside the current range
    {
        if(lazy[curr] != 0)
        {
            tree[curr] += lazy[curr]*(tr - tl + 1);
            lazy[2*curr] = lazy[2*curr+1] = lazy[curr];
            lazy[curr] = 0;
        }
        return tree[curr];
    }
    int ans = 0, mid = (tl + tr) / 2;
    int leftchild = 2 * curr, rightchild = 2 * curr + 1;
    ans += sum_queries(tl, mid, leftchild, lidx, ridx);
    ans += sum_queries(mid + 1, tr, rightchild, lidx, ridx);
    tree[curr] = tree[2*curr] + tree[2*curr+1];
    return ans;
}

void range_updates(int tl, int tr, int curr, int ad, int lidx, int rdx)
{
    if(tr < lidx || tl > rdx)
        return;
    if(tl >= lidx && tr <= rdx)
    {
        lazy[curr] += ad;
        return;
    }
    int mid = tl + (tr - tl)/2;
    range_updates(tl, mid, 2*curr, ad, lidx, rdx);
    range_updates(mid+1, tr, 2*curr+1,ad,lidx,rdx);
}

int main()
{
    int n;//cout << "enter the number of elements want to store in the array:- ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int te;//cout <<"enter the element at idx " << i + 1 << ":- ";
        cin >> te;
        update(1, N - 1, te, i + 1, 1);
    }
    // cout << "How many queries want to give:- ";
    int m;
    cin >> m;
    while (m--)
    {
        // cout << "1 for update 2 for range sum:- ";
        int r;
        cin >> r;
        if (r == 1)
        {
            // cout << "give the index where you want to update and the new value by which to replace:- ";
            int te, idx;
            cin >> idx >> te;
            update(1, N - 1, te, idx, 1);
        }
        if(r == 3)
        {
            int l,r,ad;
            cin >> l >> r >> ad;
            range_updates(1,N-1,1,ad,l,r);
        }
        if(r == 2)
        {
            // cout << "give the left and right index in which you want to find the sum:- ";
            int l, r;
            cin >> l >> r;
            cout << sum_queries(1, N - 1, 1, l, r) << endl;
        }
    }
    return 0;
}