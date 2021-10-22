template<class T>
vector<T> range(T from, T count)
{
    auto ret = vector<T>();
    
    for (T i = 0; i < count; i++)
    {
        ret.push_back(from + i);
    }

    return ret;
}
