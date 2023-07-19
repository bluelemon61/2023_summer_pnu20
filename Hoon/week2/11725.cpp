#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Tree {
    private:
        vector<vector<int>>* node;
        vector<int>* parent;
        queue<int> q;
        int len = 0;
    public:
        Tree(int size) {
            len = size+1;
            node = new vector<vector<int>>(size+1);
            parent = new vector<int>(size+1);
            (*parent)[1] = -1;
        }
        ~Tree() {
            delete node;
            delete parent;
        }
        // save the linked both node in node[a] and node[b]
        void insert(int a, int b) {
            (*node)[a].push_back(b);
            (*node)[b].push_back(a);
        }
        // Start with 1, save the parent node in parent[child] with BFS
        // Chat GPT says: (I asked 'Let me explain the BFS')
        // BFS is a graph traversal algorithm used to explore
        // all the vertices of a graph in breadth-first order,i.e.,
        // it visits all the vertices at the same level 
        // before moving on to the vertices at the next level.
        // I'll show you Graph algorithms(BFS, DFS, ...) in week 4.
        void parentify() {
            q.push(1);
            int now;
            while (q.size()) { // BFS is 
                now = q.front();
                q.pop();
                for (int i = 0; i < (*node)[now].size(); i++) {
                    if ((*parent)[(*node)[now][i]] == 0) { // If it hasn't parent already
                        q.push((*node)[now][i]);
                        (*parent)[(*node)[now][i]] = now;
                    }
                }
            }
        }
        int find_parent(int a) {
            return (*parent)[a];
        }
};

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int N, a, b;
    cin >> N;

    Tree tree(N);

    // step 1: link the both nodes
    for (int i=1; i<N; i++) {
        cin >> a;
        cin >> b;
        tree.insert(a, b);
    }

    // step 2:  save the node's parent in tree.parent to find quickly
    //          based on tree.node that saved linked nodes.
    //          More info in class Tree.parentify. scroll up.
    //          or put the mouse on .parentify() that in under line.
    tree.parentify();

    // step 3: print it
    for (int i=2; i<N+1; i++) {
        cout << tree.find_parent(i) << "\n";
    }

    return 0;
}