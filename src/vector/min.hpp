template<class T>
T min(vector<T> elements)
{
    auto ptr = min_element(elements.begin(), elements.end());
    return ptr == elements.end() ? numeric_limits<T>::max() : *ptr;
}
