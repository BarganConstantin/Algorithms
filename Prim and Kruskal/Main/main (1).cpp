#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;

const int max_num = 2147483647;

int **A = nullptr;      //pentru date initiale
int **B = nullptr;      //pentru date finale
int n;                  //numarul de noduri

double density;         //densitatea grafului

int *visited;       //daca index == cu valoare nu a fost vizitat
int *queue;         //folosesc pentru prim
void show_matrix(int **tmp);    //afisare matrice de adiacenta

int min_cost = 0;   //costul minim pentru graf

void mem_alloc_matrix();
void random_graph(int v, double a, double b);

void Kruskal();

void Prim();
int check(int a, int b);

void init_Kruskal();
void init_Prim();

void delete_Kruskal();
void delete_Prim();

int main()
{

	//random_graph(5, 0.3, 0.6);
	n = 4;
	int C[5][5] = {
        {0,1,0,3},
        {1,0,3,4},
        {0,3,0,1},
        {3,4,1,0}
        };
	A = new int* [5];
	for (int i = 0; i < n; i++)
    {
        A[i] = new int[5];
        for (int j = 0; j < n; j++)
            A[i][j] = C[i][j];
    }

	show_matrix(A);
    cout << "\nDensitatea: " << density << endl;

	init_Kruskal();
	Kruskal();
	show_matrix(B);
	cout << "\nCostul = " << min_cost << endl;
	delete_Kruskal();

	random_graph(5, 0.3, 0.6);
	show_matrix(A);
    cout << "\nDensitatea: " << density << endl;
	init_Prim();
	Prim();
    show_matrix(B); //afisam matricea de adiacenta finala si costul minim obtinut
    delete_Prim();
	cout << "\nCostul = " << min_cost << endl;



		/*				//analiza empirica
	ofstream File("kruskal.txt");
	int k = 0;
	for (int i = 10; i < max_num; i *= 1.2)
	{
		random_graph(i, 0.7, 0.9);
		init_Kruskal();

		auto begin = chrono::high_resolution_clock::now();
		Kruskal();
		auto end = chrono::high_resolution_clock::now();
		auto dur = end - begin;
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << "Nr." << k << "   Nr.virfuri = " << i << "   Kruskal: " << ms;
		File << k << "\t\t\t" << i << "\t\t\t" << ms;

		delete_Kruskal();

		random_graph(i, 0.7, 0.9);

		init_Prim(); //initializa,

		begin = chrono::high_resolution_clock::now();
		Prim();
		end = chrono::high_resolution_clock::now();
		dur = end - begin;
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << "   Prim: " << ms << endl;
		File << "\t\t\t" << ms << endl;

		delete_Prim();
		k++;
	}
	File.close();*/
	return 0;
}

void show_matrix(int **tmp)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << tmp[i][j] << " ";
		cout << endl;
	}

}

void Kruskal()
{
    min_cost = 0;
	int min = max_num; //ponderea minima
	int edge_num = 0; //numarul de muchii
	int a = -1; //virfurile ce vor cuprinde muchia minima
	int b = -1;
	int j = 0;

	int ver = 0;

	while (edge_num < n - 1) //nr.muchii trebuie sa fie egal cu nr.virfuri - 1
	{
		min = max_num;
		for (int i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (i != j) //nu trebuie sa avem bucle
				{
					int s1 = visited[i]; //staut 1 nod
					int s2 = visited[j]; //staut 2 nod;

					if ((s1 && s2) == 0) //daca cel putin unul nu a fost vizitat vom verifica ponderea
					{
						if (A[i][j] != 0 && A[i][j] < min)
						{
							min = A[i][j];
							a = i;
							b = j;
						}
					}
				}
				j = 0;
			}

			if (i = n - 1 && min == max_num)
            {
                visited[b] = 0;
                visited[a] = 0;
                A[a][b] = 0;
                A[b][a] = 0;
                i = 0;


            }
		}
		B[a][b] = min; //adaugam muchia in matricea cu rezultatul
		B[b][a] = min;
		A[a][b] = max_num; //eliminam muchia din matricea initiala
		A[b][a] = max_num;
		edge_num += 1;    //incrementam numarul de muchii deja gasite
		min_cost += min;
		visited[a] = 0;
		visited[b] = 0;

	}
}


void mem_alloc_matrix()
{
    A = new int *[n];
    B = new int *[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new int[n];
        B[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            A[i][j] = 0;
            B[i][j] = 0;
        }
    }

}

void random_graph(int v, double a, double b)
{
    n = v;                      //setam numarul de virfuri
    double tmp_density;                  //densitatea local
    int edge = 0;               //numarul de muchii adaugate
    int max_edge = (n - 1) * (n - 1);
    mem_alloc_matrix();                 //alocam memorie si initializam cu 0

    int mode = 0;         //modul 0 initializeaza prima data graful cu n - 1 muchii

    int step = n;
    int step_in_for = 0;

    do
    {
        if (mode == 0)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j && i > 0)
                    {
                        A[i][j - 1] = rand() % 3;
                        while (A[i][j - 1] == 0) //in caz ca s-a generat 0
                        {
                            A[i][j - 1] = rand() % 3;
                        }
                        A[i - 1][j] = A[i][j - 1];
                        edge++;
                    }
                }
            }
            mode = 1;
            if (n == 2) break;   //cazul in care graful nu poate fi considerat rar mediu sau dens
            if (n == 3) break;
        }
        else
        {    //vom adauga treptat muchii pina cind nu satisfacem conditia de densitate
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (step_in_for >= step && i != j)
                    {
                        A[i][j] = rand() % 10;
                        while (A[i][j] == 0)  //in caz ca s-a generat 0
                        {
                            A[i][j] = rand() % 10;
                        }
                        A[j][i] = A[i][j];
                        edge++;
                        step_in_for = 0;
                    }
                    step_in_for++;
                }
            }
            step--;
        }
        tmp_density = (double) edge / max_edge;
    }
    while (tmp_density < a || tmp_density > b);

    density = tmp_density;
}

void Prim()
{
    min_cost = 0;
	int a;
	int b;
	int edge_count = 0;
	int min = max_num;

	while (edge_count != n - 1)
	{
		min = max_num;
		for (int i = 0; i < n; i++)
		{
			int q;
			if (queue[i] > -1)
			{
				q = queue[i]; //luam din coada cite un element care deja e vizitat si verificam ponderea ramurilor ce duc spre alte virfuri
			}
			else
			{
				break;
			}
			for (int j = 0; j < n; j++)
			{
				if (A[q][j] != 0 && check(q, j)) //verificam daca e diferit de zero si daca nu a fost deja vizitat
				{
					if (A[q][j] < min)
					{
						min = A[q][j];
						a = q;
						b = j;
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (queue[i] == b) //daca elementul deja este in coada
			{
				break;
			}
			if (queue[i] == -1) //introducem elementul in coada
			{
				queue[i] = b;
				break;
			}
		}

		visited[b] = 1;
		A[a][b] = max_num; //muchiile deja utilizate le excludem din datele initiale pentru a evita repetari
		A[b][a] = max_num;
		B[a][b] = min; //inscriem muchia noua in matricea ce va contine rezultatele
		B[b][a] = min;

		min_cost += min;

		edge_count++;

	}

}

int check(int a, int b)
{
	int status_a;
	int status_b;

	status_a = visited[a];
	status_b = visited[b];
	if (status_a == 1 && status_b == 1) return 0;
	return 1;
}

void init_Kruskal()
{
	//initializam matricea cu noduri vizitati
	visited = new int[n];
	for (int i = 0; i < n; i++) //notam nodurile nevizitate cu 0
	{
		visited[i] = 0;
	}
}

void init_Prim()
{
	visited = new int[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = 0;
	}
	visited[0] = 1;

	queue = new int[n];
	for (int i = 0; i < n; i++)
	{
		queue[i] = -1;
	}
	queue[0] = 0;

}

void delete_Kruskal()
{
	for (int i = 0; i < n; i++)
	{
		delete[] A[i];
	}
	delete[] A;
    A = nullptr;

    for (int i = 0; i < n; i++)
	{
		delete[] B[i];
	}
	delete[] B;
    B = nullptr;

	delete[] visited;
}

void delete_Prim()
{
	for (int i = 0; i < n; i++)
	{
		delete[] A[i];
	}
	delete[] A;
	A = nullptr;

    for (int i = 0; i < n; i++)
	{
		delete[] B[i];
	}
	delete[] B;
    B = nullptr;

	delete[] visited;
	visited = nullptr;

	delete[] queue;
	queue = nullptr;
}
