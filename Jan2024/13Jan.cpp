class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
        function<void(Node *)> helper = [&](Node * cur) {
            if(!cur)
                return;
                
            helper(cur -> next);
            
            int key = cur -> data;
            Node * next = cur -> next;
            
            while(next){
                if(next -> data < key){
                    cur -> data = next -> data;
                    cur = next;
                    next = cur -> next;
                }
                else{
                    break;
                } 
            }
            
            cur -> data = key;
        };
        
        helper(head_ref);
        
        return head_ref;
    }
    
};
