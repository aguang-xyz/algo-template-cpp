#include <queue>
#include <unordered_map>
#include <utility>

#include "../map/get_or_default.cpp"

inline unordered_map<int, int> spfa(unordered_map<int, vector<pair<int, int>>> &g, int src)
{
    auto EMPTY = vector<pair<int, int>>();

    auto distances = unordered_map<int, int>();
    distances[src] = 0; 
    
    auto que = queue<int>({ src  });
    auto visiting = unordered_set<int>({ src });

    while (!que.empty())
    {
        auto x = que.front();
        que.pop();
        visiting.erase(x);

        for (auto e : get_or_default(g, x, EMPTY))
        {
            auto y = e.first;
            auto d = e.second;
            
            if (get_or_default(distances, y, INT_MAX) > distances[x] + d)
            {
                distances[y] = distances[x] + d;

                if (visiting.find(y) == visiting.end())
                {
                    visiting.insert(y);
                    que.push(y);
                }
            }
        }
    }

    return distances;
}