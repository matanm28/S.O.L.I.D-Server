#include <iostream>
#include <fstream>
#include "Searchables/ISearchable.h"
#include "Searchables/Matrix.h"
#include "Searchers/BestFS.h"
#include "Searchers/DFS.h"
#include "Searchers/BFS.h"
#include "Searchers/Astar.h"
#include "Searchers/ISearcher.h"
#include "MatrixBuilder.h"
#include "Solver/ISolver.h"
#include "Solver/SearchSolver.h"
#include "Position.h"
#include "State.h"

using namespace std;
int main() {
    //Problem = ISearchable<Position>*
    //Solution = vector<State<Position>>
    //Var = Position
    ifstream inFile("/home/sapir/Desktop/SOLID_Server_REDO/matrix_test.txt");
    if (!inFile) {
        cerr << "error opening file" << endl;
        return -1;
    }
    MatrixBuilder mb;
    ISearchable<Position> *matrix = mb.buildMatrix(inFile);
    ///call metrixBuilder
    ISearcher<vector<State<Position>*>, Position> *bestfs = new BestFS<vector<State<Position>*>, Position>();
    ISearcher<vector<State<Position>*>, Position> *dfs = new DFS<vector<State<Position>*>, Position>();
    ISearcher<vector<State<Position>*>, Position> *bfs = new BFS<vector<State<Position>*>, Position>();
    ISearcher<vector<State<Position>*>, Position> *aStar = new Astar<vector<State<Position>*>, Position>();
    ISolver<ISearchable<Position>*, vector<State<Position>*>> *solver1 = new SearchSolver<ISearchable<Position>*, vector<State<Position>*>, Position>(bestfs);
    ISolver<ISearchable<Position>*, vector<State<Position>*>> *solver2 = new SearchSolver<ISearchable<Position>*, vector<State<Position>*>, Position>(dfs);
    ISolver<ISearchable<Position>*, vector<State<Position>*>> *solver3 = new SearchSolver<ISearchable<Position>*, vector<State<Position>*>, Position>(bfs);
    ISolver<ISearchable<Position>*, vector<State<Position>*>> *solver4 = new SearchSolver<ISearchable<Position>*, vector<State<Position>*>, Position>(aStar);
   // ISearchable<Position>* matrix = new Matrix();
    vector<State<Position>*> bestFS_trace = solver1->solve(matrix);
    vector<State<Position>*> DFS_trace = solver2->solve(matrix);
    vector<State<Position>*> BFS_trace = solver3->solve(matrix);
    vector<State<Position>*> Astar_trace = solver4->solve(matrix);
    return 0;
}