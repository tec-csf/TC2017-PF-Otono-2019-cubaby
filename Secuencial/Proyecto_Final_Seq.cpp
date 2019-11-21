
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include <chrono>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

bool comparison(const pair<int, microseconds> &a, const pair<int, microseconds> &b)
{
    return a.second < b.second;
}

int hasAccident()
{
    int random = rand() % 11;

    if (random == 5)
    {
        return 1;
    }
    else
        return 0;
}

void printStandings(vector<int> stands, vector<microseconds> times)
{
    vector<int> stripped;
    vector<pair<int, microseconds>> joined;

    for (int s = 0; s < stands.size(); s++)
    {
        pair<int, microseconds> temp;
        temp.first = stands.at(s);
        temp.second = times.at(s);
        joined.push_back(temp);

        if (!count(stripped.begin(), stripped.end(), stands.at(s)))
        {
            stripped.push_back(stands.at(s));
        }
    }
    sort(joined.begin(), joined.end(), comparison);
    for (int c = 0; c < joined.size(); c++)
    {
        cout << "Competidor " << joined.at(c).first << " Con: " << joined.at(c).second.count() << " microsegundos " << endl;
    }
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    if (argc < 3)
    {
        printf("Uso: ./Proyecto_Final <numero de etapas> <numero de competidores>");
        exit(0);
    }

    int num_competidores, etapas;
    int progreso = 0;
    etapas = atoi(argv[1]);
    num_competidores = atoi(argv[2]);
    vector<int> standings;
    vector<microseconds> tiempos;

    for (int q = 0; q < etapas + 1; q++)
    {
        printf("Etapa %d \n", q);
        printStandings(standings, tiempos);
        standings.clear();
        tiempos.clear();
        for (int v = 1; v < num_competidores + 1; v++)
        {
            auto start = high_resolution_clock::now();
            for (int r = 0; r < 100; r++)
            {
                int flag = hasAccident();
                if (flag == 1)
                {
                    // printf("Accidente de %d \n", v);
                    sleep(0.002);
                }
                progreso += 1;
            }
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            tiempos.push_back(duration);
            standings.push_back(v);
        }
    }

    return 0;

    //TODO: Implementar accidentes,medir progreso, checar orden en vector,
}
