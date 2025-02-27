long long INF = 1e9;
const int N = 101;

struct maximumMaching {

    template<class A,class B> inline void maximize(A& x, B y) {x = max(x, y);};
    template<class A,class B> inline void minimize(A& x, B y) {x = min(x, y);};
    
    int c[N][N], fx[N], fy[N], trace[N], link[N], dmin[N], matchX[N], matchY[N];
    queue<int> st;

    int n;

    void init(int _n) {

        n = _n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                c[i][j] = INF;
        for (int i = 1; i <= n; i++) {

            fx[i] = fy[i] = INF;
            matchX[i] = matchY[i] = 0;
        }
    }

    void addEdge(int u, int v, int w) {minimize(c[u][v], w);}

    int getC(int i, int j) {

        return c[i][j] - fx[i] - fy[j];
    }

    int findPath() {

        while (! st.empty()) {

            int i = st.front();
            st.pop();
            for (int j = 1; j <= n; j++) {

                if (trace[j]) continue;
                int w = getC(i,j);
                
                if (w == 0) {
                
                    trace[j] = i;
                    if (matchY[j] == 0) return j;
                    st.push(matchY[j]);
                }
                
                if (dmin[j] > w) {
                    
                    dmin[j] = w;
                    link[j] = i;
                }
            }
        }
        
        return -1;

    }

    int Rotate(int s) {
       
        int del = INF;
        for (int j = 1; j <= n; j++)
            if (trace[j] == 0) 
                del = min(del, dmin[j]);
       
        fx[s] += del;
        for (int j = 1; j <= n; j++)
            if (trace[j]) {

                int i = matchY[j];
                fx[i] += del;
                fy[j] -= del;
            } else
                dmin[j] -= del;

        for (int j = 1; j <= n; j++)
            if (trace[j] == 0 && dmin[j] == 0) {
           
                trace[j] = link[j];
                if (matchY[j] == 0) return j;
                st.push(matchY[j]);
            }

        return -1;
    
    }

    void solve(int s) {

        for (int j = 1; j <= n; j++) {
            
            trace[j] = 0;
            dmin[j] = getC(s,j);
            link[j] = s;
        }

        st = queue<int>();
        st.push(s);
        int t = -1, k;
        while (t == -1) {

            t = findPath();
            if (t == -1) t = Rotate(s);
        }

        while (t != 0) {
        
            s = trace[t];
            k = matchX[s];
            matchX[s] = t;
            matchY[t] = s;
            t = k;
        }
    }

    int match() {

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                minimize(fx[i], c[i][j]);
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= n; i++)
                minimize(fy[i], c[i][j] - fx[i]);
        
        for (int i = 1; i <= n; i++)
            solve(i);

        int res = 0;

        for (int i = 1; i <= n; i++)
            if (c[i][matchX[i]] < INF)
                res += c[i][matchX[i]];

        // for (int i = 1; i <= n; i++)
        //     if (matchX[i])
        //         cout << i << ' ' << matchX[i] << '\n';

        return res;
    }
} match;