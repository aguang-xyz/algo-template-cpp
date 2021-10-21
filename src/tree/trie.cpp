#include <cstring>

struct trie
{
    trie *children[256];

    trie()
    {
        memset(this->children, 0, sizeof(trie*) * 256);
    }
};

inline vector<trie*> find(trie* &root, string path)
{
    if (root == NULL)
    {
        root = new trie();
    }

    auto ret = vector<trie*>({ root });

    auto ptr = root;
    for (auto &c : path)
    {
        if (ptr->children[c] == NULL)
        {
            ptr->children[c] = new trie();
        }

        ret.push_back(ptr = ptr->children[c]);
    }

    return ret;
}
