/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* head{nullptr};
    ListNode* tail{nullptr};
    
    struct MyComp {
      int operator()(ListNode* a, ListNode* b) {
        return (a->val > b->val);  
      }  
    };
    priority_queue <ListNode*, vector<ListNode*>, MyComp> min_heap;
    for (auto n : A) {
        min_heap.push(n);
        //cout << "Push " << n->val << endl;
    }
    
    while (!min_heap.empty()) {
        ListNode* tmp = min_heap.top();
        min_heap.pop();
        
        if (!tail) {
            head = tail = tmp;
        } else {
            tail->next = tmp;
            tail = tmp;
        }
        
        if (tmp->next) {
            min_heap.push(tmp->next);
            tmp->next = nullptr;
        }
    }
    
    return head;
}
