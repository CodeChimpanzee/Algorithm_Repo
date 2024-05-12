#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int coin, vector<int> cards) {
    int n = (int)cards.size();
    int answer = 0, chance = 1;
    int idx = n / 3;
    unordered_set<int> hands, discards;
    
    for(int i = 0; i < idx; i++)
        hands.insert(cards[i]);
    
    for(int i = 0; i < idx; i++)
        if(hands.find(n + 1 - cards[i]) != hands.end())
        {
            chance++;
            hands.erase(cards[i]);
            hands.erase(n + 1 -cards[i]);
        }
        
    while(chance-- > 0)
    {
        answer++;
        if(idx >= n) break;
        
        int d1 = cards[idx], d2 = cards[idx + 1];
        if(hands.find(n + 1 - d1) != hands.end() && coin > 0)
        {
            chance++;
            coin--;
            hands.erase(n + 1 - d1);
        }
        else
            discards.insert(d1);
        
        if(hands.find(n + 1 - d2) != hands.end() && coin > 0)
        {
            chance++;
            coin--;
            hands.erase(n + 1 - d2);
        }
        else
            discards.insert(d2);
        
        if(chance == 0 && coin >= 2)
            for(auto d : discards)
                if(discards.find(n + 1 - d) != discards.end())
                {
                    chance++;
                    coin -= 2;
                    discards.erase(n + 1 - d);
                    discards.erase(d);
                    break;
                }
        
        idx += 2;
    }
    
    return answer;
}