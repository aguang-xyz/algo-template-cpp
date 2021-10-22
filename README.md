# Algo Template CPP

A collection of commonly used code for Algorithms Contest written in C++.

## Number

* ![int from_bin(string bin)](src/number/from_bin.cpp)
* ![string to_bin(int num)](src/number/to_bin.cpp)
* ![int gcd(int x, int y)](src/number/gcd.cpp)
* ![bool is_prime(int x)](src/number/is_prime.cpp)
* ![vector<int> get_primes(int upper_bound)](src/number/get_primes.cpp)

## String

* ![string join(vector<string> wrods, char delimiter = ' ')](src/string/join.cpp)
* ![vector<string> split(string s, char delimiter = ' ')](src/string/split.cpp)
* ![bool not_empty(string &s)](src/string/not_empty.cpp)
* ![string reversed(string s)](src/string/reversed.cpp)

## Vector

* ![void each(vector<T> elements, Consumer consume)](src/vector/each.cpp)
* ![T max(vector<T> elements)](src/vector/max.cpp)
* ![T min(vector<T> elements)](src/vector/min.cpp)
* ![vector<T> range(T from, T count)](src/vector/range.cpp)
* ![vector<T> reversed(vector<T> elements)](src/vector/reversed.cpp)
* ![vector<T> select(vector<T> elements, UnaryOperation convert)](src/vector/select.cpp)
* ![vector<T> where(vector<T> elements, UnaryPredicate pred)](src/vector/where.cpp)
* ![vector<T> sorted(vector<T> elements, Comparator compare)](src/vector/sorted.cpp)

## Map

* ![TValue get_or_default(map<TKey, TValue> m, TKey key, TValue default_val)](src/map/get_or_default.cpp)
* ![TValue& put_if_absent(map<TKey, TValue> &m, TKey key, TValue val)](src/map/put_if_absent.cpp)

## Queue

* ![void each(queue<T> &q, Consumer consume)](src/queue/each.cpp)

## Tree

* ![treap](src/tree/treap.cpp)
  * `int size(treap *x)`
  * `pair<treap*, treap*> split(treap *x, int val)`
  * `treap *merge(treap *x, treap *y)`
  * `treap *insert(treap *x, int val)`
  * `treap *erase(treap *x, int val)`
  * `int kth(treap *x, int k)`
  * `double median(treap *x)`
* ![trie](src/tree/trie.cpp)
  * `vector<trie*> find(trie* &root, string path)`

## Graph

* ![unordered_map<int, int> spfa(unordered_map<int, vector<pair<int, int>>> &g, int src)](src/graph/spfa.cpp)