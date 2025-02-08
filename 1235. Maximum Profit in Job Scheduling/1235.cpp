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

    // Função para preencher o vetor p com o índice dos último trabalho compatível para cada trabalho
    void computeP(vector<int>& p, vector<Job>& jobs, int n) {
        for (int i = 0; i < n; i++) {
            p[i] = binarySearch(jobs, i);
        }
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        // Criação do vetor de trabalhos a partir das entradas
        std::vector<Job> jobs(n);

        for (int i = 0; i < n; i++)
            jobs[i] = {startTime[i], endTime[i], profit[i]};

        // Ordenação dos trabalhos pelo tempo de término
        std::sort(jobs.begin(), jobs.end(), compareByEndTime);
        
        vector<int> p(n);

        // Preenche o vetor p, que contém o último trabalho compatível para cada trabalho
        computeP(p, jobs, n);

        // Inicializa o primeiro valor de dp como 0
        vector<int> dp(n + 1);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            // Se incluir o trabalho i, o lucro é o lucro do trabalho i + o lucro do último trabalho compatível
            dp[i] = max(jobs[i - 1].profit + dp[p[i - 1]], dp[i - 1]);
        }

        // Retorna o lucro máximo possível
        return dp[n];
    }
};