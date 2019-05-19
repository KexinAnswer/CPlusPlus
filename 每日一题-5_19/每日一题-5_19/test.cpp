//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
//
//你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
//
//示例 :
//
//给定 nums = [2, 7, 11, 15], target = 9
//
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回[0, 1]

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int  i = 0;
		int j = 0;
		vector<int> ret;
		for (i = 0; i < nums.size() - 1; ++i)
		{
			for (j = i + 1; j < nums.size(); ++j)
			{

				if (nums[i] + nums[j] == target)
				{
					ret.push_back(i);
					ret.push_back(j);
				}


			}

		}
		return ret;

	}
};

// map
class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{

	std:map<int, int> mapCache;
		vector<int> ret;
		//if(nums.empty()) return ret ;
		for (int i = 0; i < nums.size(); i++)
		{
			int complement = target - nums[i];
			if (mapCache.find(complement) != mapCache.end())
			{
				ret.push_back(mapCache[complement]);
				ret.push_back(i);
				return ret;
			}
			mapCache[nums[i]] = i;
		}

		return ret;
	}
};

//map2
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result(2, -1);
		map<int, int> m;
		for (int i = 0; i < nums.size(); i++) {
			int j = target - nums[i];
			if (m.count(j) > 0) {
				result[1] = i;
				result[0] = m[j];
				return result;
			}
			m[nums[i]] = i;
		}
		return result;
	}
};