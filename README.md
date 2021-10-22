# Algo Template CPP

A collection of commonly used code for Algorithms Contest written in C++.

## Number

* ![int from_bin(string bin)](src/number/from_bin.hpp)
* ![string to_bin(int num)](src/number/to_bin.hpp)
* ![int gcd(int x, int y)](src/number/gcd.hpp)
* ![bool is_prime(int x)](src/number/is_prime.hpp)
* ![vector<int> get_primes(int upper_bound)](src/number/get_primes.hpp)

## String

* ![string join(vector<string> wrods, char delimiter = ' ')](src/string/join.hpp)
* ![vector<string> split(string s, char delimiter = ' ')](src/string/split.hpp)
* ![bool not_empty(string &s)](src/string/not_empty.hpp)
* ![string reversed(string s)](src/string/reversed.hpp)

## Vector

* ![void each(vector<T> elements, Consumer consume)](src/vector/each.hpp)
* ![T max(vector<T> elements)](src/vector/max.hpp)
* ![T min(vector<T> elements)](src/vector/min.hpp)
* ![vector<T> range(T from, T count)](src/vector/range.hpp)
* ![vector<T> reversed(vector<T> elements)](src/vector/reversed.hpp)
* ![vector<T> select(vector<T> elements, UnaryOperation convert)](src/vector/select.hpp)
* ![vector<T> where(vector<T> elements, UnaryPredicate pred)](src/vector/where.hpp)
* ![vector<T> sorted(vector<T> elements, Comparator compare)](src/vector/sorted.hpp)

## Map

* ![TValue get_or_default(map<TKey, TValue> m, TKey key, TValue default_val)](src/map/get_or_default.hpp)
* ![TValue& put_if_absent(map<TKey, TValue> &m, TKey key, TValue val)](src/map/put_if_absent.hpp)

## Queue

* ![void each(queue<T> &q, Consumer consume)](src/queue/each.hpp)

## Tree

* ![treap](src/tree/treap.hpp)
  * `int size(treap *x)`
  * `pair<treap*, treap*> split(treap *x, int val)`
  * `treap *merge(treap *x, treap *y)`
  * `treap *insert(treap *x, int val)`
  * `treap *erase(treap *x, int val)`
  * `int kth(treap *x, int k)`
  * `double median(treap *x)`
* ![trie](src/tree/trie.hpp)
  * `vector<trie*> find(trie* &root, string path)`

## Graph

* ![unordered_map<int, int> spfa(unordered_map<int, vector<pair<int, int>>> &g, int src)](src/graph/spfa.hpp)
