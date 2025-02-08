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

    int binarySearch(vector<Job>& jobs, int i) {
        int low = 0, high = i - 1;
        int result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (jobs[mid].endTime <= jobs[i].startTime) {
                result = mid + 1;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }

    void computeP(vector<int>& p, vector<Job>& jobs, int n) {
        for (int i = 0; i < n; i++) {
            p[i] = binarySearch(jobs, i);
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