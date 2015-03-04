#include <bits/stdc++.h>

using namespace std;

struct trie_node
{
    bool word;
    struct trie_node* child[26];
    public:
    trie_node()
    {
        word=false;
        for(int i=0;i<26;++i)
            child[i]=NULL;
    }
};
trie_node* root;
void init()
{
    root=new trie_node();
}

void insert(trie_node* node, string s)
{
    for(int i=0;i<s.length();++i)
    {
        if(!node->child[s[i]-'a'])
            node->child[s[i]-'a']=new trie_node();
        node=node->child[s[i]-'a'];
    }
    node->word=true;
}

bool search(trie_node* node, string s)
{
    for(int i=0;i<s.length();++i)
    {
        if(!node->child[s[i]-'a']) return false;
        node=node->child[s[i]-'a'];
    }
    return node->word;
}
int main()
{
    init();
    insert(root,"garvit");
    cout<<search(root,"garvi");
    return 0;
}

