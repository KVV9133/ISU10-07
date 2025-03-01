tree* findBrother(tree *root, int key) 
{
    tree *find = root;

    while (find && find->key != key) 
    {
        if (key < find->key)
            find = find->left;
        else
            find = find->right;
    }
    

    if (!find || !find->parent)
        return NULL;
    
    tree *parent = find->parent;
    
    if (parent->left == find)
        return parent->right;
    if (parent->right == find)
        return parent->left;

}
