# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        temp=head
        ct=0
        while(temp):
            ct+=1
            temp=temp.next
        k=ct-n
        if(k==0):
            return head.next
        curr=head
        pos=0
        while(curr):
            pos+=1
            if(pos==k):
                curr.next=curr.next.next
                break
            curr=curr.next
        return head

        