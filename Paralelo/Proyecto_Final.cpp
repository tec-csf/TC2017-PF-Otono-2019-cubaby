#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <unistd.h>
#include <algorithm>

using namespace std;

int hasAccident()
{
    srand(time(NULL));
    int random = rand() % 11;

    if (random == 5)
    {
        return 1;
    }
    else
        return 0;
}

void printStandings(vector<int> stands)
{
    vector<int> stripped;
    for (int s = 0; s < stands.size(); s++)
    {
        if (!count(stripped.begin(), stripped.end(), stands.at(s)))
        {
            stripped.push_back(stands.at(s));
        }
    }
    for (int c = 0; c < stripped.size(); c++)
    {
        printf("%d \n", stripped.at(c));
    }
}

int main(int argc, char const *argv[])
{
    if (argc == 1)
    {
        printf("Uso: ./Proyecto_Final <numero de etapas> <numero de competidores>");
    }

    int num_competidores, etapas;
    int r;
    int q;
    int progreso = 0;
    etapas = atoi(argv[1]);
    num_competidores = atoi(argv[2]);
    omp_set_num_threads(num_competidores);
    vector<int> standings;

#pragma omp parallel
    {
        for (q = 0; q < etapas + 1; q++)
        {
            printf("Etapa %d \n", q);
            printStandings(standings);
            standings.clear();

#pragma for private(r) reduction(+ \
                                 : progreso)
            for (r = 0; r < 100; r++)
            {
                int flag = hasAccident();
                if (flag == 1)
                {
                    sleep(0.002);
                }
                progreso += 1;
                int id = omp_get_thread_num() + 1;
                standings.push_back(id);
            }
        }
    }

    return 0;

    //TODO: Implementar accidentes,medir progreso, checar orden en vector,
}
