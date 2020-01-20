//
// Created by matan on 1/20/20.
//

#ifndef SOLID_SERVER_REDO_CACHEMANAGER_H
#define SOLID_SERVER_REDO_CACHEMANAGER_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <list>
#include <functional>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;


template<class Solution>
class CacheManager {
private:
    unsigned int capacity;
    unsigned int size = 0;
    unordered_map<string, pair<Solution, list<string>::iterator>> cache;
    list<string> lru = list<string>();

public:
    CacheManager();

    explicit CacheManager(int capacity);

    void insert(string key, Solution obj);

    Solution get(string key);

    virtual ~CacheManager();

private:
    void writeToFile(string key, Solution obj);

    pair<string, Solution> loadFromFile(string key);

    void lruElementUpdate(string key, Solution obj, list<string>::iterator iter);

    void lruAndCacheUpdate(string key, Solution obj);

    bool canInsert();

};


#endif //SOLID_SERVER_REDO_CACHEMANAGER_H
