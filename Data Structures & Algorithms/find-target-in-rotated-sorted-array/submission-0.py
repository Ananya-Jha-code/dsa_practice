class Solution:
    def check(self, nums:List[int], mid:int)->bool:
        return nums[mid]<=nums[len(nums)-1]
    def search(self, nums: List[int], target: int) -> int:
        low=0
        high=len(nums)-1
        ans=-1
        while(low<=high):
            mid=low+(high-low)//2
            if(self.check(nums,mid)):
                ans=mid #min element
                high=mid-1
            else:
                low=mid+1
        result=-1
        if target>=nums[ans] and target<=nums[len(nums)-1]:
            low=ans
            high=len(nums)-1
        else:
            low=0
            high=ans-1
        while(low<=high):
            mid=low+(high-low)//2
            if(target>=nums[mid]):
                low=mid+1
                if target==nums[mid]:
                    result=mid
            elif(target==nums[mid]):
                result=mid
            else:
                high=mid-1

        return result