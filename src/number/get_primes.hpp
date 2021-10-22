inline vector<int> get_primes(int upper_bound)
{
    vector<int> primes;
    unordered_set<int> non_primes;

    for (int i = 2; i <= sqrt(upper_bound); i++)
    {
        if (non_primes.find(i) == non_primes.end())
        {
            primes.push_back(i);

            for (int j = i + i; j <= upper_bound; j++)
            {
                non_primes.insert(j);
            }
        }
    }

    return primes;
}
