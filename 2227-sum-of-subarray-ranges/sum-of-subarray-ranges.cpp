class Solution{
 private:

    // array for next smaller element indices
    vector <int> findNSE ( vector<int> &arr){
        int n = arr.size();

        vector<int> ans(n);

        stack<int> s;

        // start traversing from back
        for (int i=n-1 ; i>=0 ; i--){

            // get the current element
            int currEle = arr[i];

            // remove elements that are not smaller ( greater than or equal to)
            while (!s.empty() && arr[s.top()] >= currEle){
                s.pop();
            }

            // store next smaller element index
            if (!s.empty()){
                ans[i] = s.top();
            }
            else{
                ans[i]=n;
            }

            // push current index in stack
            s.push(i);
        }

        return ans;
    }


    // array for next greater element indices
    vector<int> findNGE (vector<int> &arr){

        int n = arr.size();

        vector<int> ans(n);

        stack<int> s;

        for (int i=n-1 ; i>=0 ; i--){
            // find curr element
            int currEle = arr[i];

            // remove elements that are not greater (smaller than or equal to)
            while (!s.empty() && arr[s.top()] <= currEle){
                s.pop();
            }

            // store next greater element index
            if (!s.empty()){
                ans[i] = s.top();
            }
            else{
                ans[i] = n;
            }

            // push curr index in stack
            s.push(i);
        }

        return ans;
    }


    // arr for previous smaller or equal element indices
    vector<int> findPSEE (vector<int> &arr){
        
        int n = arr.size();

        vector<int> ans(n);

        stack<int> s;

        for (int i=0 ; i<n ; i++){
            // find curr element
            int currEle = arr[i];

            // remove all elements which are not smaller (greater than )
            while (!s.empty() && arr[s.top()] > currEle){
                s.pop();
            }

            // store prev smaller element index
            if (!s.empty()){
                ans[i] = s.top();
            }
            else{
                ans[i] = -1;
            }

            // push curr index in stack
            s.push(i);
        }

        return ans;
    }


    // arr for prev greater or equal element indices
    vector<int> findPGEE (vector<int> &arr){
        
        int n = arr.size();

        vector<int> ans(n);

        stack<int> s;

        for (int i=0 ; i<n ; i++){
            
            // find curr element
            int currEle = arr[i];

            // remove all elements which are not greater (smaller than )
            while (!s.empty() && arr[s.top()] < currEle){
                s.pop();
            }

            // store prev greater element index
            if(!s.empty()){
                ans[i] = s.top();
            }
            else{
                ans[i] = -1;
            }

            // push curr index in stack
            s.push(i);
        }

        return ans;
    }

    // function to find sum of minm values in all subarrays
    long long sumSubarrayMins (vector<int> &arr){

        // find next smaller and prev smaller or equal indices
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        int n = arr.size();

        long long sum = 0;

        // traverse L to R
        for (int i=0 ; i<n ; i++){

            // count of possible left boundaries
            long long left = i - psee[i];

            // count of possible right boundaries
            long long right = nse[i] - i;

            // count of subarrays where curr element is minm
            long long freq = left*right;

            // contribution of curr element
            long long val = freq*arr[i];

            // update sum
            sum += val;
        }

        return sum;
    }

    // func to find sum of maxm vlaues in all subarrays
    long long sumSubarrayMaxs (vector<int> &arr){

        // find next greater and prev greater or equal indices
        vector<int> nge = findNGE(arr);
        vector<int> pgee = findPGEE(arr);

        int n = arr.size();

        long long sum = 0;

        for (int i=0 ; i<n ;  i++){

            // count of possible left boundaries 
            long long left = i-pgee[i];

            // count of possible right boundaries
            long long right = nge[i] - i;

            // count of subarray where curr element is max
            long long freq = left * right;

            //contribution of curr element
            long long val = freq * arr[i];

            //update sum
            sum += val;
        }

        return sum;
    }

 public:
    long long subArrayRanges (vector<int> &arr){
        return sumSubarrayMaxs(arr) - sumSubarrayMins(arr);
    }
};