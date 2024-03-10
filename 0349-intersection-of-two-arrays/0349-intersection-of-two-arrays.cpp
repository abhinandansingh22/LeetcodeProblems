class Solution {

bool isInArray(std::vector<int> &nums2, int &start_idx, int last_number){
	int end_idx = nums2.size()- 1;

	while(start_idx <= end_idx){
		int middle_idx = (start_idx + end_idx)/2;

		if(nums2[middle_idx] < last_number){
			start_idx = middle_idx + 1;
		}
		else if (nums2[middle_idx] > last_number){
			end_idx = middle_idx - 1;
		}
		else{
			start_idx = middle_idx;
			return true;
		}
	}
	return false;
}
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		std::vector<int> intersection;
		if(nums1.empty() || nums2.empty()){
			return intersection;
		}
		std::sort(nums1.begin(), nums1.end());
		std::sort(nums2.begin(), nums2.end());

		int last_number = -1;
		int start_idx = 0;
		int end_idx = nums2.size()-1;
		for(size_t i = 0; i < nums1.size(); ++i){
			if(nums1[i]!=last_number){
				last_number = nums1[i];

				if(nums2[end_idx] < last_number){
					// max number in nums2 is smaller than current nr in nums1
					break;
				}

				if(isInArray(nums2, start_idx, last_number)){
					intersection.push_back(last_number);
				}
			}
		}
		return intersection;
	}
};