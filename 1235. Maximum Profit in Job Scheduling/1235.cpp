#include <vector>
#include <algorithm>
using namespace std;

struct Job
{
    int startTime;
    int endTime;
    int profit;
};

class Solution {
public:

    static bool compareByEndTime(Job &a, Job &b) {
        return a.endTime < b.endTime;
    }

    void computeP(vector<int> &p, vector<Job> &jobs, int n) {
        for (int i = 0; i < n; i++) {
            p[i] = 0;

            for (int j = i - 1; j >= 0; j--) {
                if (jobs[i].startTime >= jobs[j].endTime) {
                    p[i] = j + 1;
                    break;
                }
            }
        }   
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        std::vector<Job> jobs(n);

        for (int i = 0; i < n; i++)
            jobs[i] = {startTime[i], endTime[i], profit[i]};

        std::sort(jobs.begin(), jobs.end(), compareByEndTime);
        
        vector<int> p(n);

        computeP(p, jobs, n);

        vector<int> dp(n + 1);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i] = max(jobs[i - 1].profit + dp[p[i - 1]], dp[i - 1]);
        }

        return dp[n];
    }
};