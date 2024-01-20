class trienode
{
    public:

    char data;
    trienode* children[26];
    bool isterminal;

    trienode(char data)
    {
        this->data = data;
        for (int i=0;i<26;i++)
        {
            children[i] = NULL;
        }
        isterminal = false;
    }
};

class Trie {
public:
        trienode* root;
    Trie() 
    {
        root=new trienode('\0');
    }
    void insertutil(trienode* root, string word)
    {
        if(word.length()==0)
        {
            root->isterminal=true;
            return;
        }

        int index=word[0]-'a';
        trienode* child;

        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
            child=new trienode(word[0]);
            root->children[index]=child;
        }

        insertutil(child,word.substr(1));

    }
    
    void insert(string word) 
    {
        insertutil(root,word);
    }

    bool searchutil(trienode* root, string word)
    {
        if(word.length()==0)
        {
            return root->isterminal;
        }

        int index=word[0]-'a';
        trienode* child;

        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
           return false;
        }

        return searchutil(child,word.substr(1));
    }
    
    bool search(string word) 
    {
        return searchutil(root,word);
    }
    bool prefixutil(trienode* root, string word)
    {
        if(word.length()==0)
        {
            return true;
        }

        int index=word[0]-'a';
        trienode* child=NULL;

        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
           return false;
        }

        return prefixutil(child,word.substr(1));
    }
    
    bool startsWith(string prefix) 
    {
        return prefixutil(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
