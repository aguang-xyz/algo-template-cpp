template<class T>
T max(vector<T> elements)
{
    auto ptr = max_element(elements.begin(), elements.end());
    return ptr == elements.end() ? numertic_limits<T>::min() : *ptr;
}