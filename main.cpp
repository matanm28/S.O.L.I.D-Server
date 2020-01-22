#include <iostream>
#include <fstream>
#include "Searchables/ISearchable.h"
#include "Searchers/BestFS.h"
#include "Searchers/DFS.h"
#include "Searchers/BFS.h"
#include "Searchers/Astar.h"
#include "Searchers/ISearcher.h"
#include "Solver/ISolver.h"
#include "Solver/SearchSolver.h"
#include "Handlers/MatrixHandler.h"
#include "Servers/IServer.h"
#include "Servers/SerialServer.h"
#include "Servers/ParallelServer.h"
#include <thread>


using namespace std;

int main() {
    //Problem = ISearchable<Position>*
    //Solution = vector<State<Position>>
    //Var = Position
    /*ifstream inFile("/home/matan/Desktop/CS/SOLID_Server_REDO/matrix_test.txt");
    ofstream outFile("/home/matan/Desktop/CS/SOLID_Server_REDO/matrix_test_output.txt");
    if (!inFile || !outFile) {
        cerr << "error opening file" << endl;
        return -1;
    }*/
    ////algorithms
    ISearcher<vector<State<Position> *> *, Position> *bestfs = new BestFS<vector<State<Position> *> *, Position>();
    ISearcher<vector<State<Position> *> *, Position> *dfs = new DFS<vector<State<Position> *> *, Position>();
    ISearcher<vector<State<Position> *> *, Position> *bfs = new BFS<vector<State<Position> *> *, Position>();
    ISearcher<vector<State<Position> *> *, Position> *aStar = new Astar<vector<State<Position> *> *, Position>();
    ////search solvers
    ISolver<ISearchable<Position> *, vector<State<Position> *> *> *solver1 = new SearchSolver<ISearchable<Position> *, vector<State<Position> *> *, Position>(
            bestfs);
    ISolver<ISearchable<Position> *, vector<State<Position> *> *> *solver2 = new SearchSolver<ISearchable<Position> *, vector<State<Position> *> *, Position>(
            dfs);
    ISolver<ISearchable<Position> *, vector<State<Position> *> *> *solver3 = new SearchSolver<ISearchable<Position> *, vector<State<Position> *> *, Position>(
            bfs);
    ISolver<ISearchable<Position> *, vector<State<Position> *> *> *solver4 = new SearchSolver<ISearchable<Position> *, vector<State<Position> *> *, Position>(
            aStar);
    ////client handlers
    MatrixHandler *matrixHandler1 = new MatrixHandler(solver1);
    MatrixHandler *matrixHandler4 = new MatrixHandler(solver4);
    SerialServer *serialServer = new SerialServer();
    /*serialServer->open(5600,matrixHandler1);
    serialServer->run();*/
    ParallelServer *server = new ParallelServer(10);
    server->open(5601, matrixHandler4);
    thread threadServer(&ParallelServer::run, server);
    sleep(5);
    server->stop();
    threadServer.join();
    cout << "Server done" << endl;

    return 0;
}