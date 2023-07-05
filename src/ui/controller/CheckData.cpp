//
// Created by Маргарита  on 03.07.2023.
//

#include "CheckData.h"

bool CheckData::checkGraph(graph_t &graph) {

    if(graph.size() == 0)
        return false;

    bool check = true;

    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            if(i == j && graph[i][j] != INT_MAX)
            {
                check = false;
                graph[i][j] = INT_MAX;
            }
            else
            {
                if(graph[i][j] != graph[j][i]){
                    graph[j][i] = graph[i][j];
                    check = false;
                }
            }
        }
    }
    return check;
}