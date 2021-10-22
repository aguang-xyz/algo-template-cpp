inline bool is_prime(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }

    return true;
}

