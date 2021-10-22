template<class T, class Consumer>
void each(vector<T> elements, Consumer consume)
{
	for (auto &x : elements)
	{
		consume(x);
	}
}