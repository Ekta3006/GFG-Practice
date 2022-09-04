class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long sum)
    {
        vector<int> b;
    
        int curr_sum = arr[0], start = 0, i;
  
    for (i = 1; i < n; i++) {
        // you were not adding elements to the curr_sum
        curr_sum+=arr[i];
        while (curr_sum > sum && start < i)
        {
            curr_sum = curr_sum - arr[start];
            start++;
        }
        if (curr_sum == sum)
        {
           b.push_back(start+1);
           b.push_back(i+1);
           return b;
        }
    }
    // you were not checking if sum equals arr[0]
    if(arr[0]!=sum)
      b.push_back(-1);
    else return {1,1};
    return b;
    }
};
