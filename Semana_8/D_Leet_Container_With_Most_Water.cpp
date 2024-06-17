// https://leetcode.com/problems/container-with-most-water/description/
// Container With Most Water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int tam=height.size(),max=0;
        for(int i=0; i<tam; i++){
            for(int j=tam-1; j>i; j--){
                if(height[i]*(j-i)<max)
                    break;
                max=std::max(max,min(height[i],height[j])*(j-i));
            }
        }

        return max;
    }
};
