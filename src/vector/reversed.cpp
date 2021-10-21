template<class T>
vector<T> reversed(vector<T> elements)
{
    auto ret = vector<T>(elements.begin(), elements.end());
    reverse(ret.begin(), ret.end());
    return ret;
}
