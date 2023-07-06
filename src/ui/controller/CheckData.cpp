//
// Created by Маргарита  on 03.07.2023.
//

#include "CheckData.h"
#include <climits>

bool CheckData::checkGraph(graph_t &graph)
{

    if (graph.size() == 0)
        return false;

    bool check = true;

    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            if (i == j && graph[i][j] != INT_MAX)
            {
                check = false;
                graph[i][j] = INT_MAX;
            } else
            {
                if (graph[i][j] != graph[j][i])
                {
                    graph[j][i] = graph[i][j];
                    check = false;
                }
            }
        }
    }
    return check;
}

int CheckData::addEdge(std::vector<std::pair<int, std::pair<int, int>>>& list_edge, int distance, int departure, int arrival, int n)
{

    if(arrival>=n || departure>=n)
        return -2;

    for (int i = 0; i < list_edge.size(); i++)
    {
        if(list_edge[i].second.first == departure && list_edge[i].second.second == arrival){
            list_edge[i].first = distance;
            return i;
        }
    }
    std::pair<int, std::pair<int, int>> element =
            std::pair(distance,
                      std::pair(departure, arrival));


    list_edge.push_back(element);

    return -1;
}