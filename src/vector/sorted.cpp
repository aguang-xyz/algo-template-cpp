template<class T, class Comparator>
vector<T> sorted(vector<T> elements, Comparator compare)
{
	auto ret = vector<T>(elements.begin(), elements.end());
	sort(ret.begin(), ret.end(), compare);
	return ret;
}