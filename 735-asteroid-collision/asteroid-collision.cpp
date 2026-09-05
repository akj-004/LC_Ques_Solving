class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> s;
        int n = asteroids.size();
        
        for (int i=0 ; i<n ; i++){
            if (asteroids[i] >=0){
                s.push(asteroids[i]);  
            }

            else{
                if (s.empty()){
                    s.push(asteroids[i]);
                    continue;
                }
                while (!s.empty() && s.top() > 0 && (abs(asteroids[i]) > s.top())){
                    s.pop();
                }
                if (!s.empty() && (abs(asteroids[i]) == s.top())){
                    s.pop();
                    continue;
                }
                if (!s.empty() && (abs(asteroids[i]) < s.top())){
                    continue;
                }
                s.push(asteroids[i]);
            }
        }

        while (!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};