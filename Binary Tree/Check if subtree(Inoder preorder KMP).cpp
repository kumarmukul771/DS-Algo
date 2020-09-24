https://practice.geeksforgeeks.org/problems/check-if-subtree/1/
void storeInOrder(Node *root, vector<int> &inOrder) {
    if (!root) {
        inOrder.push_back(-1);
        return;
    }
    storeInOrder(root->left, inOrder);
    inOrder.push_back(root->data);
    storeInOrder(root->right, inOrder);
}

void storePreOrder(Node *root, vector<int> &preOrder) {
    if (!root) {
        preOrder.push_back(-1);
        return;
    }
    preOrder.push_back(root->data);
    storePreOrder(root->left, preOrder);
    storePreOrder(root->right, preOrder);
}

void computeLPSArray(vector<int> &pat, int M, vector<int> &lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

bool KMPSearch(vector<int> &txt, vector<int> &pat) {
    int M = pat.size();
    int N = txt.size();
    vector<int> lps(M);

    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            j = lps[j - 1];
            return true;
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return false;
}


void print(vector<int> &a) {
    for (int u : a) {
        cout << u << " ";
    }
    cout << "\n";
}

bool isSubTree(Node *T, Node *S) {
    if (S == nullptr)
        return true;
    if (T == nullptr)
        return false;

    vector<int> inOrderT, preOrderT, inOrderS, preOrderS;
    storeInOrder(T, inOrderT);
    storePreOrder(T, preOrderT);

    storeInOrder(S, inOrderS);
    storePreOrder(S, preOrderS);

    if (KMPSearch(inOrderT, inOrderS) && KMPSearch(preOrderT, preOrderS))
        return true;

    return false;
}