void link(Node *&p)
{
    for(int i = 0; i < 26; i++)
    {
        if(p->node[i] == NULL) continue;
        Node* temp = p->link;
        while(temp != root && temp->node[i] == NULL)
            temp = temp->link;
        if(temp->node[i] != NULL) (p->node[i])->link = temp->node[i];
        link(p->node[i]);
    }
}

void preprocessing()
{
    for(int i = 0; i < 26; i++)
        if(root->node[i]) link(root->node[i]);
}