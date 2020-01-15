#include <iostream>
#include "Searchables/ISearchable.h"
#include "Searchables/Matrix.h"
#include "Searchers/BestFS.h"
#include "Searchers/DFS.h"
#include "Searchers/BFS.h"
#include "Searchers/ISearcher.h"
#include "Searchers/Searcher.h"
#include "Solver/ISolver.h"
#include "Solver/SearchSolver.h"
#include "Position.h"
#include "State.h"

using namespace std;
int main() {
    //Problem = ISearchable<Position>*
    //Solution = vector<State<Position>>
    //Var = Position

    ISearcher<vector<State<Position>*>, Position> *bestfs = new BestFS<vector<State<Position>*>, Position>();
    ISearcher<vector<State<Position>*>, Position> *dfs = new DFS<vector<State<Position>*>, Position>();
    ISearcher<vector<State<Position>*>, Position> *bfs = new BFS<vector<State<Position>*>, Position>();
    ISolver<ISearchable<Position>*, vector<State<Position>*>> *solver1 = new SearchSolver<ISearchable<Position>*, vector<State<Position>*>, Position>(bestfs);
    ISolver<ISearchable<Position>*, vector<State<Position>*>> *solver2 = new SearchSolver<ISearchable<Position>*, vector<State<Position>*>, Position>(dfs);
    ISolver<ISearchable<Position>*, vector<State<Position>*>> *solver3 = new SearchSolver<ISearchable<Position>*, vector<State<Position>*>, Position>(bfs);
    ISearchable<Position>* matrix = new Matrix();
    //todo:: maybe stack and not vector
    vector<State<Position>*> bestFS_trace = solver1->solve(matrix);
    vector<State<Position>*> DFS_trace = solver2->solve(matrix);
    vector<State<Position>*> BFS_trace = solver3->solve(matrix);
    cout << "Hallelujah!" << std::endl;
    return 0;
}