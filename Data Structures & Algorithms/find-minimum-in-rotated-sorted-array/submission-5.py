class Solution:
    def check(self, nums:List[int], mid:int,high:int )->bool:
        last=nums[len(nums)-1]
        return nums[mid]<=last

    def findMin(self, nums: List[int]) -> int:
        ans=1e9
        low=0
        high=len(nums)-1
        while(low<=high):
            mid=low+(high-low)//2
            if(self.check(nums, mid,high)):
                ans=nums[mid]
                high=mid-1
            else:
                low=mid+1
        return ans
        