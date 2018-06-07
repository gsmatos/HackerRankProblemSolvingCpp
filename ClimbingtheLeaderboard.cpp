#include <bits/stdc++.h>

using namespace std;

vector <int> leaderboardPositions (vector <int> scores) //Assign a position for each score
{
    vector <int> positions;
    int current_position = 1;
    for (int i = 0; i < scores.size(); ++i)
    {
        if (i > 0)
            {
                if (scores[i] == scores [i-1]){} else ++current_position;
            }
        positions.push_back(current_position);
    }
    return positions;
}

vector <int> climbingLeaderboard(vector <int> scores, vector <int> alice) {
    // Complete this function
    vector <int> position;
    vector<int> leaderboardPos = leaderboardPositions (scores);
    int num_of_scores = scores.size();
    int last_pos = scores.size();
    for (int i = 0; i < alice.size() ; ++i) //Test each of alice's scores
    {
        if (alice[i] < scores[num_of_scores-1]) //If it is worse than the last assign last position
        {
            position.push_back(leaderboardPos.back()+1);
            continue;
        }
        if (alice[i] >= scores[0]) //Assign first position if better than the first
        {
            position.push_back(1);
            continue;
        }
        int loop_start = last_pos;
        for (int j = loop_start; j >= 0; --j) //Compare alice's scores with the Leaderboard
        {
            if (alice[i] <= scores[j])
            {
                if (alice[i] == scores[j]) //If it has the same score, assign the same position
                {
                    position.push_back(leaderboardPos[j]);
                    last_pos = j;
                    break;
                }
                if (alice[i] < scores[j]) //If it has a lower score, assign the previous position
                {
                    position.push_back(leaderboardPos[j+1]);
                    last_pos = j;
                    break;
                }
            }
        }
    } 
    return position;
}

int main() {
    int n;
    cin >> n;
    vector<int> scores(n);
    for(int scores_i = 0; scores_i < n; ++scores_i)
    {
       cin >> scores[scores_i];
    }
    int m;
    cin >> m;
    vector<int> alice(m);
    for(int alice_i = 0; alice_i < m; ++alice_i)
    {
       cin >> alice[alice_i];
    }
    vector <int> result = climbingLeaderboard(scores, alice);
    for (ssize_t i = 0; i < result.size(); ++i) 
    {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
