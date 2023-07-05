//
// Created by Маргарита  on 03.07.2023.
//

#include "ControllerUI.h"
#include "../../randomizer/Randomizer.h"


const graph_t &ControllerUI::initFile(std::string sourceFile)
{


    std::string sep = " ";

    std::ifstream file(sourceFile);

    std::string line;
    int j = 0, i = 0;
    int n = 0;
    if (file.is_open())
    {
        getline(file, line);
        //std::cout<<line<<"\n";
        std::string token;
        size_t pos;
        while ((pos = line.find(sep)) != std::string::npos)
        {
            token = line.substr(0, pos);
            //std::cout << token << std::endl;
            line.erase(0, pos + sep.length());
            n++;
        }
        if (line != "")
        {
            n++;
        }
    }

    initMax(n);
    file.clear();
    file.seekg(0);

    if (file.is_open())
    {
        while (file)
        {
            getline(file, line);
            //std::cout<<line<<"\n";
            std::string token;
            size_t pos;
            while ((pos = line.find(sep)) != std::string::npos)
            {
                token = line.substr(0, pos);
                line.erase(0, pos + sep.length());
                //std::cout<<i<<" "<<j<<": "<<token<<"\n";
                if (i < n && j < n)
                {
                    graph[i][j] = stoi(token);
                }
                j++;
            }
            if (line != "")
            {
                //std::cout<<i<<" "<<j<<": "<<token<<"\n";
                if (i < n && j < n)
                {
                    graph[i][j] = stoi(line);
                }
            }
            i++;
            j = 0;
        }
    } else
    {
        std::cout << "cry baby";
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << graph[i][j] << " ";
        }
        std::cout << "\n";
    }

    return graph;
}

const graph_t &ControllerUI::initAdd(std::vector<std::pair<int, std::pair<int, int>>> list_edge, int n)
{

    initMax(n);
    for (int i = 0; i < list_edge.size(); i++)
    {
        if (list_edge[i].second.first < n && list_edge[i].second.second < n)
        {
            graph[list_edge[i].second.first][list_edge[i].second.second] = list_edge[i].first;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << graph[i][j] << " ";
        }
        std::cout << "\n";
    }

    return graph;
}

const graph_t &ControllerUI::initRandom(int n)
{

    Randomizer randomizer;
    if (n == 0)
    {
        n = randomizer.getRandomInt(1, 99);
    }

    initMax(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = randomizer.getRandomInt(1, INT_MAX);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << graph[i][j] << " ";
        }
        std::cout << "\n";
    }

    return graph;
}

void ControllerUI::initMax(int n)
{
    graph.resize(n);
    for (int i = 0; i < n; i++)
    {
        graph[i].resize(n, INT_MAX);
    }
}

void ControllerUI::check()
{
    std::cout << "checked" << settings.population_size;
}
