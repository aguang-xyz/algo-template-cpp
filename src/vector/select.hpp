template<class T, class UnaryOperation>
vector<T> select(vector<T> elements, UnaryOperation convert)
{
    auto ret = vector<T>();
    transform(elements.begin(), elements.end(), back_inserter(ret), convert);
    return ret;
}
