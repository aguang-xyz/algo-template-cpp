#include <vector>

template<class T, class UnaryPredicate>
vector<T> where(vector<T> elements, UnaryPredicate pred)
{
    auto ret = vector<T>();
    copy_if(elements.begin(), elements.end(), back_inserter(ret), pred);
    return ret;
}
