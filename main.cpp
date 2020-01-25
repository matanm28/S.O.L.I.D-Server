#define DEFAULT_PORT 5600

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

int main(int argc, char *argv[]) {
    int port;
    if (argc < 2) {
        port = DEFAULT_PORT;
    } else {
        try {
            port = stoi(argv[1]);
        } catch (exception &e1) {
            port = DEFAULT_PORT;
        }
    }
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
    MatrixHandler *matrixHandler4 = new MatrixHandler(solver4);
    ParallelServer *server = new ParallelServer(10);
    server->open(port, matrixHandler4);
    thread threadServer(&ParallelServer::run, server);
    sleep(60);
    server->stop();
    threadServer.join();
    cout << "Server done" << endl;

    return 0;
}