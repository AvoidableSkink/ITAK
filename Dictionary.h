//
// Created by klind on 4/4/2017.
//

#ifndef GENERICDICTIONARY_DICTIONARY_H
#define GENERICDICTIONARY_DICTIONARY_H

#include <vector>
#include <iostream>
#include "KeyValue.h"

template <typename X, typename Y>
class Dictionary {
private:
    std::vector<KeyValue<X,Y>> myKeyVals;

public:
    Dictionary();
    Dictionary(int size);
    Dictionary(const Dictionary&);

    void add(X key, Y value);
    KeyValue<X, Y> getByKey(X key) const;
    KeyValue<X, Y> getByIndex(int index) const;
    void removeByKey(X key);
    void removeByIndex(int index);
    bool search(X k) const;

    int getCurrentCapacity() const { return myKeyVals.capacity(); }
    int getCount() const { return myKeyVals.size(); }
};

const int DEFAULT_DICTIONARY_SIZE = 10;

//default constructor
template <typename X, typename Y>
Dictionary<X,Y>::Dictionary() {
    myKeyVals.reserve(DEFAULT_DICTIONARY_SIZE);
}

//parameterized constructor
template <typename X, typename Y>
Dictionary<X,Y>::Dictionary(int size) {
    myKeyVals.reserve(size);
}

//copy constructor
template <typename X, typename Y>
Dictionary<X,Y>::Dictionary(const Dictionary & d) {
    myKeyVals = d.myKeyVals;
}

/**
 * if the given key doesnt already exist
 * create a KeyValue using the given parameters and add it to myKeyVals
 */
template <typename X, typename Y>
void Dictionary<X,Y>::add(X key, Y value) {
    if (!search(key)) {
        KeyValue<X, Y> myVal(key, value);
        myKeyVals.push_back(myVal);
    }
    else
        throw std::invalid_argument ("Cannot create duplicate Keys");
}

/**
 * search myKeyVals for given key
 * @param key used to search through the keyvalues
 * @return return the KeyValue found at location of given key
 */
template <typename X, typename Y>
KeyValue<X, Y> Dictionary<X,Y>::getByKey(X k) const{
    for (int i = 0; i < myKeyVals.size(); ++i) {
        if (myKeyVals[i].getKey() == k)
            return myKeyVals[i];
    }
}

template <typename X, typename Y>
KeyValue<X, Y> Dictionary<X,Y>::getByIndex(int index) const{
    if (index < myKeyVals.size() && index >= 0)
        return myKeyVals[index];
    else
        throw std::out_of_range ("Requested index is out of bounds.");
}

template <typename X, typename Y>
void Dictionary<X,Y>::removeByKey(X k) {
    for (int i = 0; i < myKeyVals.size(); ++i) {
        if (myKeyVals[i].getKey() == k)
        {
            myKeyVals.erase(myKeyVals.begin() + i);
            break;
        }
    }
}

template <typename X, typename Y>
void Dictionary<X,Y>::removeByIndex(int index) {
    if (index < myKeyVals.size())
        myKeyVals.erase(myKeyVals.begin() + index);
    else
        throw std::out_of_range ("Requested index is out of bounds.");
}

/**
 * search through existing keys to see if given key already exists
 * @tparam X
 * @tparam Y
 * @param k key that is being searched for
 * @return true if key is found, false if not found
 */
template <typename X, typename Y>
bool Dictionary<X,Y>::search(X k) const {
    for (int i = 0; i < myKeyVals.size(); ++i) {
        if (myKeyVals[i].getKey() == k)
            return true;
    }
    return false;
}

#endif //GENERICDICTIONARY_DICTIONARY_H
