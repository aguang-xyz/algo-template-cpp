template<class T>
T min(vector<T> elements)
{
    auto ptr = min_element(elements.begin(), elements.end());
    return ptr == elements.end() ? numertic_limits<T>::max() : *ptr;
}