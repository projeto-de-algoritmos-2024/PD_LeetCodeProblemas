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

    bool compareByEndTime(Job &a, Job &b) {
        return a.endTime < b.endTime;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        std::vector<Job> jobs(n);

        for (int i = 0; i < n; i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});

        std::sort(jobs.begin(), jobs.end(), compareByEndTime);
        
    }
};