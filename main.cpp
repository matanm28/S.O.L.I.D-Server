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
#include "Handlers/MatrixHandler.h"
#include "CacheManagers/CacheManager.h"

using namespace std;

int main() {
    //Problem = ISearchable<Position>*
    //Solution = vector<State<Position>>
    //Var = Position
    ifstream inFile("/home/matan/Desktop/CS/SOLID_Server_REDO/matrix_test.txt");
    ofstream outFile("/home/matan/Desktop/CS/SOLID_Server_REDO/matrix_test_output.txt");
    if (!inFile || !outFile) {
        cerr << "error opening file" << endl;
        return -1;
    }
    ////algorithms
    ISearcher<vector<State<Position> *>*, Position> *bestfs = new BestFS<vector<State<Position> *>*, Position>();
    ISearcher<vector<State<Position> *>*, Position> *dfs = new DFS<vector<State<Position> *>*, Position>();
    ISearcher<vector<State<Position> *>*, Position> *bfs = new BFS<vector<State<Position> *>*, Position>();
    ISearcher<vector<State<Position> *>*, Position> *aStar = new Astar<vector<State<Position> *>*, Position>();
    ////search solvers
    ISolver<ISearchable<Position> *, vector<State<Position> *>*> *solver1 = new SearchSolver<ISearchable<Position> *, vector<State<Position> *>*, Position>(
            bestfs);
    ISolver<ISearchable<Position> *, vector<State<Position> *>*> *solver2 = new SearchSolver<ISearchable<Position> *, vector<State<Position> *>*, Position>(
    CacheManager<string> *cacheManager = new CacheManager<string>(5);
    MatrixHandler *matrixHandler = new MatrixHandler(solver1, cacheManager);
    matrixHandler->handleClient(inFile, outFile);
    MatrixBuilder mb;
    ISearchable<Position> *matrix = mb.buildMatrix(inFile);
    ///call metrixBuilder

    ISearcher<vector<State<Position> *>, Position> *dfs = new DFS<vector<State<Position> *>, Position>();
    ISearcher<vector<State<Position> *>, Position> *bfs = new BFS<vector<State<Position> *>, Position>();
    ISearcher<vector<State<Position> *>, Position> *aStar = new Astar<vector<State<Position> *>, Position>();

    ISolver<ISearchable<Position> *, vector<State<Position> *>> *solver2 = new SearchSolver<ISearchable<Position> *, vector<State<Position> *>, Position>(
            dfs);
    ISolver<ISearchable<Position> *, vector<State<Position> *>*> *solver3 = new SearchSolver<ISearchable<Position> *, vector<State<Position> *>*, Position>(
            bfs);
    ISolver<ISearchable<Position> *, vector<State<Position> *>*> *solver4 = new SearchSolver<ISearchable<Position> *, vector<State<Position> *>*, Position>(
            aStar);
    ////client handlers
    MyClientHandler<ISearchable<Position>*, vector<State<Position>*>*, Position> *clientHandler1 = new MyClientHandler<ISearchable<Position>*, vector<State<Position>*>*, Position>(solver1);
    MyClientHandler<ISearchable<Position>*, vector<State<Position>*>*, Position> *clientHandler4 = new MyClientHandler<ISearchable<Position>*, vector<State<Position>*>*, Position>(solver4);
    clientHandler1->handleClient(inFile, outFile);
    clientHandler4->handleClient(inFile, outFile);

    return 0;
}