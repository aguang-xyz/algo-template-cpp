inline vector<string> split(string s, char delimiter = ' ')
{
    auto words = vector<string>({ "" });

    for (auto &c : s)
    {
        if (c == delimiter)
        {
            words.push_back("");
        }
        else
        {
            words.back().push_back(c);
        }
    }

    return words;
}
