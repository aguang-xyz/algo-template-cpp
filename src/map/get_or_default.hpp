#include <map>
#include <unordered_map>

template<class TKey, class TValue>
inline TValue get_or_default(map<TKey, TValue> &m, TKey key, TValue default_val)
{
    if (m.find(key) == m.end())
    {
        return default_val;
    }

    return m[key];
}

template<class TKey, class TValue>
inline TValue get_or_default(unordered_map<TKey, TValue> &m, TKey key, TValue default_val)
{
    if (m.find(key) == m.end())
    {
        return default_val;
    }

    return m[key];
}
