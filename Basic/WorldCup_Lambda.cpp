// Task: https://beta.programming.in.th/tasks/0028
// Algo: Custom sort with lambda
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

    sort(team.begin(), team.end(), [&](const Team &a, const Team &b)
         {
        if (a.score != b.score)
            return a.score > b.score;
        if (a.goal - a.goalAgainst != b.goal - b.goalAgainst)
            return a.goal - a.goalAgainst > b.goal - b.goalAgainst;
        return a.goal > b.goal; });

    for (Team &t : team)
        cout << t.name << " " << t.score << "\n";
}