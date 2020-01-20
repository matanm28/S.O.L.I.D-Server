//
// Created by matan on 1/20/20.
//

#include "CacheManager.h"
#include "CacheManager.h"

template<class Solution>
CacheManager<Solution>::CacheManager(int capacity) {
    this->capacity = capacity;
}

template<class Solution>
CacheManager<Solution>::CacheManager() {
    this->capacity = 5;
}

template<class Solution>
void CacheManager<Solution>::insert(string key, Solution obj) {
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

template<class Solution>
Solution CacheManager<Solution>::get(string key) {
    if (!(this->cache.find(key) == this->cache.end())) {
        this->lruElementUpdate(key, this->cache[key].first, this->cache[key].second);
    } else {
        pair<string, Solution> entry = this->loadFromFile(key);;
        if (entry.first == this->null.first) {
            cerr << "key " << key << " doesn't exist" << endl;
            throw "key doesn't exist";
        }
        this->lruAndCacheUpdate(entry.first, entry.second);
    }
    return this->cache[key].first;
}

template<class Solution>
void CacheManager<Solution>::writeToFile(string key, Solution obj) {
    string filePath = this->className + key + ".txt";
    ofstream out_file{filePath, ios::binary | ios::out};
    if (out_file.is_open()) {
        out_file.write((char *) &obj, sizeof(Solution));
        out_file.close();
        return;
    } else {
        throw "error opening file";
    }
}

template<class Solution>
pair<string, Solution> CacheManager<Solution>::loadFromFile(string key) {
    Solution entryObj;
    string filePath = this->className + key + ".txt";
    ifstream in_file{filePath, ios::binary | ios::in};
    if (in_file.is_open()) {
        in_file.read((char *) &entryObj, sizeof(Solution));
        in_file.close();
        return pair<string, Solution>(key, entryObj);
    } else {
        return this->null;
    }
}

template<class Solution>
bool CacheManager<Solution>::canInsert() {
    return this->size < this->capacity;
}

template<class Solution>
void CacheManager<Solution>::lruElementUpdate(string key, Solution obj, list<string>::iterator iter) {
    this->lru.erase(iter);
    this->lru.push_back(key);
    this->cache[key] = {obj, --this->lru.end()};
}

template<class Solution>
void CacheManager<Solution>::lruAndCacheUpdate(string key, Solution obj) {
    this->cache.erase(this->lru.front());
    this->lru.pop_front();
    this->lru.push_back(key);
    this->cache[key] = {obj, --this->lru.end()};
}

template<class Solution>
CacheManager<Solution>::~CacheManager() {

}