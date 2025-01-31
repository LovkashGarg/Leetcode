class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
      auto const n = static_cast<int>(std::size(nums));

		auto curr = 0;

        // Ham yaha par store kar rhe hai hame kitna subtract karna hai har element me se 
        // ex for index 1 we subtract 2 becomes 0
        //  index 2 becomes 1  after subtraction curr = 2 +1 =3 
        //  at index 2 we also  update what we have to minus to new value which is 1

		for (auto i = 0; i < n; ++i)
		{
            // cout<<curr<<" "<<nums[i]<<endl;
			if (curr > nums[i]) { return false; }

			nums[i] -= curr;
			curr += nums[i];
			if (i >= k - 1) { curr -= nums[i - k + 1]; }
		}

		return curr == 0;

    }
};