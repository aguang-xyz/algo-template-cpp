#include <string>

inline string reversed(string s)
{
    auto ret = string(s);
    reverse(ret.begin(), ret.end());
    return ret;
}
