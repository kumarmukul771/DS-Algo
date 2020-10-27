struct Node* reverseList(struct Node *head)
{
    // code here
    // return head of reversed list
    Node* temp=NULL;
        
    while(1)
    {
        Node* t=head->next;
        
        if(head->next==NULL)
        {
            head->next=temp;
            break;
        }
        else head->next=temp;
        
        temp=head;
        
        head=t;
    }
    
    return head;
}