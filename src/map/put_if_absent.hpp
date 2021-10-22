template<class TKey, class TValue>
inline TValue& put_if_absent(map<TKey, TValue> &m, TKey key, TValue val)
{
    if (m.find(key) == m.end())
    {
        m[key] = val;
    }

    return m[key];
}

template<class TKey, class TValue>
inline TValue& put_if_absent(unordered_map<TKey, TValue> &m, TKey key, TValue val)
{
    if (m.find(key) == m.end())
    {
        m[key] = val;
    }

    return m[key];
}
