int num[N], low[N], deleted[N], timeDfs, scc;
stack<int> st;

void tarjan(int u) {

    num[u] = low[u] = ++timeDfs;
    st.push(u);

    for (int v : edge[u]) {

        if (deleted[v])
            continue;
        if (!num[v]) {

            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else
            low[u] = min(low[u], num[v]);
    }

    if (low[u] == num[u]) {

        scc++;
        int v;
        do {

            v = st.top();
            st.pop();
            deleted[v] = true;

        } while (v != u);
    }
}
