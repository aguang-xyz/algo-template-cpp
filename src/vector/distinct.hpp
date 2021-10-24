template<class T>
vector<T> distinct(vector<T> elements)
{
    unordered_set<T> s(elements.begin(), elements.end());
    return vector<T>(s.begin(), s.end());
}
