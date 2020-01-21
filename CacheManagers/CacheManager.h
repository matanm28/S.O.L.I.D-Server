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
#include <functional>
#include "../Position.h"

using namespace std;


template<class Solution>
class CacheManager {
private:
    unsigned int capacity;
    unsigned int size = 0;
    hash<string> solutionHasher;
    unordered_map<string, pair<Solution, list<string>::iterator>> cache;
    list<string> lru = list<string>();

public:
    CacheManager() {
        this->capacity = 5;
    }

    explicit CacheManager(int capacity) {
        this->capacity = capacity;
    }

    void insert(string key, Solution obj) {
        //obj already in cache;
        auto entry = this->cache.find(key);
        if (!(entry == cache.end())) {
            this->lruElementUpdate(entry->first, entry->second.first, entry->second.second);
            //we have room available in cache
        } else if (this->canInsert()) {
            this->size++;
            this->lru.push_back(key);
            list<string>::iterator iter = this->lru.end();
            iter--;
            this->cache[key] = {obj, iter};
            this->writeToFile(key, obj);
            //no room available in cache
        } else {
            this->lruAndCacheUpdate(key, obj);
            this->writeToFile(key, obj);
        }
    }

    Solution get(string key) {
        if (!(this->cache.find(key) == this->cache.end())) {
            this->lruElementUpdate(key, this->cache[key].first, this->cache[key].second);
        } else {
            try {
                pair<string, Solution> entry = this->loadFromFile(key);
                this->lruAndCacheUpdate(entry.first, entry.second);
            } catch (const char *exception) {
                cerr << "key " << key << " doesn't exist" << endl;
                throw "key not found";
            }
        }
        return this->cache[key].first;
    }

    virtual ~CacheManager() {}

private:
    void writeToFile(string key, Solution obj) {
        string filePath = to_string(this->solutionHasher(key)) + ".txt";
        ofstream out_file{filePath, ios::out};
        if (out_file.is_open()) {
            out_file << obj;
            out_file.close();
        } else {
            string excep("error opening file");
            throw excep.c_str();
        }
    }

    pair<string, Solution> loadFromFile(string key) {
        Solution entryObj;
        string filePath = to_string(this->solutionHasher(key)) + ".txt";
        ifstream in_file{filePath, ios::in};
        if (in_file.is_open()) {
            in_file >> entryObj;
            in_file.close();
            return pair<string, Solution>(key, entryObj);
        } else {
            throw "no file found";
        }
    }

    void lruElementUpdate(string key, Solution obj, list<string>::iterator iter) {
        this->lru.erase(iter);
        this->lru.push_back(key);
        this->cache[key] = {obj, --this->lru.end()};
    }

    void lruAndCacheUpdate(string key, Solution obj) {
        this->cache.erase(this->lru.front());
        this->lru.pop_front();
        this->lru.push_back(key);
        this->cache[key] = {obj, --this->lru.end()};
    }

    bool canInsert() {
        return this->size < this->capacity;
    }

};


#endif //SOLID_SERVER_REDO_CACHEMANAGER_H
