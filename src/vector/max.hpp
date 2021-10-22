template<class T>
T max(vector<T> elements)
{
    auto ptr = max_element(elements.begin(), elements.end());
    return ptr == elements.end() ? numeric_limits<T>::min() : *ptr;
}
