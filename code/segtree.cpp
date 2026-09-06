struct segtree {
    vector<int> tree;

    void init(int n) {
        tree.resize(4 * n, 0);
    }

    void update(int id, int low, int high, int x, int val) {
        if (low == high) {
            tree[id] += val;
            return;
        }

        int md = (low + high) / 2;

        if (x <= md) {
            update(2 * id, low, md, x, val);
        } else {
            update(2 * id + 1, md + 1, high, x, val);
        }

        tree[id] = min(tree[2 * id], tree[2 * id + 1]);
    }

    int query(int id, int low, int high, int l, int r) {
        if (l > high or r < low) return INT_MAX;

        if (low >= l and r >= high) {
            return tree[id];
        }

        int md = (low + high) / 2;

        return min(
                   query(2 * id, low, md, l, r),
                   query(2 * id + 1, md + 1, high, l, r)
               );
    }
};
