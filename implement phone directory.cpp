class trienode
{
    public:

    char data;
    trienode* children[26];
    bool isterminal;

    trienode(char data)
    {
        this->data=data;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isterminal=false;
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
        }

        insertutil(child,word.substr(1));
    }

    void insert(string word)
    {
        insertutil(root,word);
    }

    void printsuggestion(trienode* curr,vector<string> &temp,string prefix)
    {
        if(curr->isterminal)
        {
            temp.push_back(prefix);
        }

        for(char ch='a';ch<='z';ch++)
        {
            trienode* next=curr->children[ch-'a'];

            if(next!=NULL)
            {
                prefix.push_back(next->data);
                printsuggestion(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }


    vector<vector<string>> solve(string str)
    {
        trienode* prev=root;
        string prefix="";
        vector<vector<string>> output;

        for(int i=0;i<str.size();i++)
        {
            char lastch=str[i];
            prefix.push_back(lastch);

            trienode* curr=prev->children[lastch-'a'];

            if(curr==NULL)
            {
                break;
            }
                vector<string> temp;
                printsuggestion(curr,temp,prefix);
                output.push_back(temp);
                temp.clear();
                prev=curr;      
        }

        return output;
    }
  
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
   trie* t=new trie;

   for (int i=0;i<contactList.size();i++)
   {
       t->insert(contactList[i]);
   }

   return t->solve(queryStr);
}
