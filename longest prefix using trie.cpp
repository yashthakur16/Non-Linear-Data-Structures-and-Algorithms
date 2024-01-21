class trienode
{
    public:

    char data;
    trienode* children[26];
    bool isterminal;
    int childrencount;

    trienode(char data)
    {
        this->data=data;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isterminal=false;
        childrencount=0;
    }

};

class trie
{
    public:

    trienode* root;

    trie()
    {
        root=new trienode('\0');
    }

    void insertutil(trienode* root,string word)
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
            root->childrencount++;
        }

        insertutil(child,word.substr(1));
    }

    void insert(string word)
    {
        insertutil(root,word);
    }

    void lcp(string str,string &ans)
    {
        for(int i=0;i<str.length();i++)
        {
            char ch=str[i];

            if(root->childrencount==1)
            {
                ans.push_back(ch);
                int index=ch-'a';
                root=root->children[index];
            }
            else
            {
                break;
            }
            if(root->isterminal==true)
            {
                break;
            }
        }

        return;
    } 
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    trie* t=new trie;
    for(int i=0;i<n;i++)
    {
        t->insert(arr[i]);
    }

    string str=arr[0];
    string ans="";

    t->lcp(str,ans);

    return ans;

    
}


