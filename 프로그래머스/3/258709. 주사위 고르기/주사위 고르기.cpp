#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> dice) {
    int n = dice.size();
    vector<int> answer(n / 2);
    vector<int> select(n, 0);
        
    for(int i = 0; i < n / 2; i++)
        select[i] = 1;
    
    int maxv = 0;
    do
    {
        vector<int> achoose, bchoose;
        vector<int> asum, bsum;
        
        for(int i = 0; i < n; i++)
            if(select[i])
                achoose.push_back(i);
            else
                bchoose.push_back(i);
        
        int lim = pow(6, n / 2);
        for(int i = 0; i < lim; i++)
        {
            int code = i, asumt = 0, bsumt = 0;
            for(int j = 0; j < n / 2; j++)
            {
                int cur_dice = code % 6;
                asumt += dice[achoose[j]][cur_dice];
                bsumt += dice[bchoose[j]][cur_dice];
                code /= 6;
            }
            asum.push_back(asumt);
            bsum.push_back(bsumt);
        }
        
        sort(asum.begin(), asum.end());
        sort(bsum.begin(), bsum.end());

        int vcount = 0;
        for(int i = 0; i < lim; i++)
            vcount += distance(asum.begin(), lower_bound(bsum.begin(), bsum.end(), asum[i]));
        
        if(maxv < vcount)
        {
            maxv = vcount;
            copy(achoose.begin(), achoose.end(), answer.begin());
        }
    }
    while(prev_permutation(select.begin(), select.end()));
    
    for(int i = 0; i < answer.size(); i++)
        answer[i]++;
    return answer;
}