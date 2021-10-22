template<class T, class Consumer>
void each(queue<T> &q, Consumer consume)
{
	while (!q.empty())
	{
		auto x = q.front();
		q.pop();
		consume(x);
	}
}