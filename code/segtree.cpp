struct segtree {
    vector<ll> tree;
    void init(ll n) {
        tree.resize(4 * n, 0);
    }
    void update(ll idx, ll lo, ll hi, ll x, ll val) {
        if (lo == hi) {
            tree[idx] += val;
            return;
        }
        ll md = (lo + hi) / 2;
        if (x <= md) {
            update(2 * idx, lo, md, x, val);
        } else {
            update(2 * idx + 1, md + 1, hi, x, val);
        }
        tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
    }

    ll query(ll idx, ll lo, ll hi, ll l, ll r) {
        if (l > hi or r < lo) return LONG_MAX;
        if (lo >= l and r >= hi) {
            return tree[idx];
        }
        ll md = (lo + hi) / 2;
        return min(query(2 * idx, lo, md, l, r),query(2 * idx + 1, md + 1, hi, l, r));
    }
};
