struct TrieNode {

    TrieNode* child[2];
    int cnt;
    TrieNode() {

        cnt = 0;
        for (int i = 0; i < 2; i++) child[i] = NULL;

    }
    
} * root = new TrieNode();

struct Trie {

    void Insert(int so, int k, TrieNode * node) {

        int BIT = ((so & (1 << k)) && 1);
        if (node->child[BIT] == NULL) node->child[BIT] = new TrieNode();
        node = node->child[BIT];
        if (k == 0 && node->cnt == 0) 
            node->cnt++, n++;
        else if (k > 0) {

            Insert(so, k - 1, node);
            node->cnt = 0;
            if (node->child[0] != NULL) node->cnt += node->child[0]->cnt;
            if (node->child[1] != NULL) node->cnt += node->child[1]->cnt;

        }

    }

    void Delete(int so, int k, TrieNode * node) {

        int BIT = ((so & (1 << k)) && 1);
        if (node->child[BIT] == NULL) return;
        node = node->child[BIT];
        if (k == 0 && node->cnt > 0) 
            node->cnt--, n--;
        else if (k > 0) {

            Delete(so, k - 1, node);
            node->cnt = 0;
            if (node->child[0] != NULL) node->cnt += node->child[0]->cnt;
            if (node->child[1] != NULL) node->cnt += node->child[1]->cnt;

        }

    }

    int Count(int so) {

        TrieNode * node = root;
        int res = 0;
        for (int i = 30; i >= 0; i--) {

            int BIT = ((so & (1 << i)) && 1);
            if (BIT && node->child[0] != NULL) res += node->child[0]->cnt;
            if (node->child[BIT] == NULL) break;
            node = node->child[BIT];

        }

        return res;

    }

    int Kth(int so) {
        
        TrieNode * node = root;
        int res = 0;
        for (int i = 30; i >= 0; i--) {

            if (node->child[0] != NULL && node->child[0]->cnt >= so) {

                node = node->child[0];

            } else {

                if (node->child[0] != NULL) so -= node->child[0]->cnt;
                node = node->child[1];
                res += (1 << i);

            }

        }

        return res;

    }

} Trie;


// KMS = 1e9 (trong truong hop c co the am)
//Trie.Insert(c + KMS, 30, root);
//Trie.Delete(c + KMS, 30, root);
//Trie.Count(c + KMS)
//Trie.Kth(c) - KMS 