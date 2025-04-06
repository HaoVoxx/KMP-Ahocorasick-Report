int checkPrefix(Node *r)
{
        if(r == root) return 0;
        int count = 0;
        if(r->end && !r->check) 
        {
            r->check = 1;
            count++;
        }
        return count + checkPrefix(r->link);
}

int travel(std::string s, int idx, Node *r)
{
    if(idx == s.size()) return 0;
    int count = 0;
    if(r->end) 
    {
        r->check = 1;
        count++;
    }
    count += checkPrefix(r->link);
    int indx = s[idx] - 'a';
    if(r->node[indx]) count += travel(s, idx + 1, r->node[indx]);
    else if(r != root) count += travel(s, idx, r->link);
    return count;
}