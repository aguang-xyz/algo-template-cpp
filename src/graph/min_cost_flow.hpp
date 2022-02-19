class MinCostFlow
{
    
private:

    struct edge
    {
        int src, tgt, cap, dis;
        edge *rev;
        
        edge(int _src, int _tgt, int _cap, int _dis)
        {
            src = _src;
            tgt = _tgt;
            cap = _cap;
            dis = _dis;
            rev = NULL;
        }
        
        void take(int _cap)
        {
            cap -= _cap;
            
            if (rev != NULL)
            {
                rev->cap += _cap;
            }
        }
    };
    
    int n, s, t;
    
    vector<vector<edge*>> edges;
    
    int spfa()
    {
        vector<bool> vis(n, false);
        vector<int> dis(n, INT_MAX);
        vector<edge*> from(n, NULL);
        
        vis[s] = true;
        dis[s] = 0;
        
        queue<int> que;
        que.push(s);
        
        while (!que.empty())
        {
            int x = que.front(); que.pop(); vis[x] = false;
            
            for (auto &e : edges[x])
            {
                if (e->cap > 0 && dis[x] + e->dis < dis[e->tgt])
                {
                    dis[e->tgt] = dis[x] + e->dis;
                    from[e->tgt] = e;
                    
                    if (!vis[e->tgt])
                    {
                        que.push(e->tgt);
                        vis[e->tgt] = true;
                    }
                }
            }
        }
        
        if (from[t] == NULL)
        {
            return 0;
        }
        
        int capLimit = INT_MAX, totalDis = 0;
        
        for (int x = t; x != s; x = from[x]->src)
        {
            capLimit = min(from[x]->cap, capLimit);
            totalDis += from[x]->dis;
        }
        
        cout << "flow(" << t;
        
        for (int x = t; x != s; x = from[x]->src)
        {
            from[x]->take(capLimit);
            cout << " <- " << from[x]->src;
        }
        
        cout << ") | cap = " << capLimit << ", dis = " << totalDis << endl;
        
        return capLimit * totalDis;
    }
    
public:
    
    MinCostFlow(int _n, int _s, int _t)
    {
        n = _n;
        s = _s;
        t = _t;
        
        edges = vector<vector<edge*>>(n);
    }
    
    void addEdge(int x, int y, int cap, int dis)
    {
        cout << "addEdge(" << x << ", " << y << ", " << cap << ", " << dis << ");" << endl;
        
        edge *a = new edge(x, y, cap, dis);
        edge *b = new edge(y, x, 0, -dis);
        
        a->rev = b;
        b->rev = a;
        
        edges[x].push_back(a);
        edges[y].push_back(b);
    }
    
    int solve()
    {
        int cost = 0;
        
        for (int tmp; (tmp = spfa()) > 0; )
        {
            cost += tmp;
        }
        
        return cost;
    }
};
