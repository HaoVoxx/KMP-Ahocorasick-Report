struct trie
{
    struct Node
    {
        bool check = 0;
        int end = 0;
        Node *node[26];
        Node *link;
        Node()
        {
            for(int i = 0; i < 26; i++)
                node[i] = NULL;
        }
    };
    Node *root = new Node;
    void add(std::string s)
    {
        Node *temp = root;
        for(int i = 0; i < s.size(); i++)
        {
            int idx = s[i] - 'a';
            if(temp->node[idx] == NULL)
                temp->node[idx] = new Node;
            temp = temp->node[idx];
            temp->link = root;
        }
        temp->end++;
    }
};