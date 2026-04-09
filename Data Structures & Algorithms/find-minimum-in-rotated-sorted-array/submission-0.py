class Solution:
    def check(self, nums:List[int], mid:int,high:int )->bool:
        return nums[mid]<nums[high]

    def findMin(self, nums: List[int]) -> int:
        low=0
        high=len(nums)-1
        while(low<high):
            mid=low+(high-low)//2
            if(self.check(nums, mid,high)):
                high=mid
            else:
                low=mid+1
        return nums[low]
        