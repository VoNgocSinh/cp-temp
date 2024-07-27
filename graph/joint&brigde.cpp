int timeDfs, bridge;
int low[N], num[N];
bool joint[N];

void tarjan(int u, int par) {

    int child = 0;
    num[u] = low[u] = ++timeDfs;

    for (int x : edge[u]) {

        if (x == par)
            continue;
        if (!num[x]) {

            tarjan(x, u);
            child++;
            low[u] = min(low[u], low[x]);
            if (low[x] == num[x])
                bridge++;
                
            if (u == par) {

                if (child > 1)
                    joint[u] = true;
            }
            else if (low[x] >= num[u])
                joint[u] = true;
        }
        else
            low[u] = min(low[u], num[x]);
    }
}