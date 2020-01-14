#include <iostream>
#include "Searchables/ISearchable.h"
#include "Searchables/Matrix.h"
#include "Searchers/BestFS.h"
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

    ISearcher<vector<State<Position>>, Position> *bfs = new BestFS<Position>();
    ISolver<ISearchable<Position>*, vector<State<Position>>> *solver = new SearchSolver<ISearchable<Position>*, vector<State<Position>>, Position>(bfs);
    ISearchable<Position>* matrix = new Matrix();
    //Matrix *matrix = new Matrix();
    //Matrix matrix;// = new Matrix();
    solver->solve(matrix);
    cout << "Hallelujah!" << std::endl;
    return 0;
}
    //SearchSolver<Matrix, vector<State<Position>>, Position> searchSolver = SearchSolver<Matrix, vector<State<Position>>, Position>(bfs);

    //ISolver<ISearchable<Position>*, vector<State<Position>*>> *solver = new SearchSolver<ISearchable<Position>*, vector<State<Position>*>, Position>();