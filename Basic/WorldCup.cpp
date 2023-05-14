// Task: https://beta.programming.in.th/tasks/0028
// Algo: Custom sort
// Date: 14/5/2023

#include <bits/stdc++.h>
using namespace std;

class Team
{
public:
    int score;
    int goal;
    int goalAgainst;
    string name;

    bool operator<(const Team &o) const
    {
        if (score != o.score)
            return score > o.score;
        if (goal - goalAgainst != o.goal - o.goalAgainst)
            return goal - goalAgainst > o.goal - o.goalAgainst;
        return goal > o.goal;
    }
};

int main()
{
    const int n = 4;
    vector<Team> team(n);
    for (Team &t : team)
        cin >> t.name;

    vector<vector<int>> rawScores(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int &score : rawScores[i])
        {
            cin >> score;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (rawScores[i][j] > rawScores[j][i]) // i win j
            {
                team[i].score += 3;
            }
            else if (rawScores[i][j] == rawScores[j][i]) // i draw j
            {
                team[i].score += 1;
            }
            team[i].goal += rawScores[i][j];
            team[i].goalAgainst += rawScores[j][i];
        }
    }

    sort(team.begin(), team.end());

    for (Team &t : team)
        cout << t.name << " " << t.score << "\n";
}