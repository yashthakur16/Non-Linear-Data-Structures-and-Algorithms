/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class compare
   {
       public:
       bool operator()(ListNode* a,ListNode* b)
       {
           return a->val > b->val;
       }
   };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int n=lists.size();
        priority_queue<ListNode*,vector<ListNode*>,compare> minheap;

        for (int i=0;i<n;i++)
        {
            if(lists[i]!=NULL)
            minheap.push(lists[i]);
        }

        ListNode* head=NULL;
        ListNode* tail=NULL;

        while(!minheap.empty())
        {
            ListNode* temp=minheap.top();
            minheap.pop();

            if(head==NULL)
            {
                head=temp;
                tail=temp;
                
            }
            else
            {
                tail->next=temp;
                tail=tail->next;
            }

            if(temp->next)
                {
                    minheap.push(temp->next);
                }

        }

        return head;

           
    }
};
