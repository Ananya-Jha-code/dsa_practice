# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def split(self, head: Optional[ListNode])->Optional[listNode]:
        fast, slow=head,head
        while(fast and fast.next):
            slow=slow.next
            fast=fast.next.next
        second=slow.next
        slow.next=None
        return second

    def reverse(self, head:Optional[ListNode])->Optional[ListNode]:
        prev=None
        curr=head
        while(curr):
            temp=curr.next
            curr.next=prev
            prev=curr
            curr=temp
        return prev
        
    def merge(self, list1:Optional[ListNode], list2:Optional[ListNode])->None:
        while(list2):
            temp1=list1.next
            temp2=list2.next

            list1.next=list2
            list2.next=temp1

            list1=temp1
            list2=temp2

    
    def reorderList(self, head: Optional[ListNode]) -> None:
        if not head:
            return None

        second=self.split(head)
        second=self.reverse(second)
        self.merge(head,second)
        