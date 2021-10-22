struct treap
{
    int val, weight, size;
    treap *left, *right;

    treap(int val)
    {
        this->val = val;
        this->weight = rand();
        this->size = 1;
        this->left = this->right = NULL;
    }
};

inline int size(treap *x)
{
    return x == NULL ? 0 : x->size;
}

inline pair<treap*, treap*> split(treap *x, int val)
{
    if (x == NULL)
    {
        return make_pair((treap*) NULL, (treap*) NULL);
    }

    if (x->val <= val)
    {
        auto t = split(x->right, val);
        x->right = t.first;
        x->size = 1 + size(x->left) + size(x->right);
        return make_pair(x, t.second);
    }
    else
    {
        auto t = split(x->left, val);
        x->left = t.second;
        x->size = 1 + size(x->left) + size(x->right);
        return make_pair(t.first, x);
    }
}

inline treap *merge(treap *x, treap *y)
{
    if (x == NULL)
    {
        return y;
    }

    if (y == NULL)
    {
        return x;
    }

    if (x->val > y->val)
    {
        swap(x, y);
    }

    int total_size = size(x) + size(y);

    if (x->weight > y->weight)
    {
        x->right = merge(x->right, y);
        x->size = total_size;
        return x;
    }
    else
    {
        y->left = merge(x, y->left);
        y->size = total_size;
        return y;
    }
}

inline treap *insert(treap *x, int val)
{
    pair<treap*, treap*> t = split(x, val);
    return merge(merge(t.first, new treap(val)), t.second);
}

inline treap *erase(treap *x, int val)
{
    if (x == NULL)
    {
        return x;
    }

    if (val == x->val)
    {
        return merge(x->left, x->right);
    }

    if (val <= x->val)
    {
        x->left = erase(x->left, val);
    }
    else
    {
        x->right = erase(x->right, val);
    }

    x->size = 1 + size(x->left) + size(x->right);

    return x;
}

inline int kth(treap *x, int k)
{
    if (x == NULL)
    {
        return 0;
    }

    int left_size = size(x->left);

    if (k < left_size)
    {
        return kth(x->left, k);
    }

    if (k == left_size)
    {
        return x->val;
    }

    return kth(x->right, k - left_size - 1);
}

inline double median(treap *x)
{
    int n = size(x);

    if (n == 0)
    {
        return 0;
    }

    if (n % 2 == 1)
    {
        return kth(x, n / 2); 
    }
    else
    {
        return 0.5 * kth(x, n / 2) + 0.5 * kth(x, n / 2 - 1);
    }
}
