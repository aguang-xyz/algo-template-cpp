#ifndef VEC_H
#define VEC_H

template <typename T> class vec : std::deque<T> {

public:
  // Constructor (empty).
  vec() : std::deque<T>() {}

  // Constructor (from initial list).
  vec(initializer_list<T> init) : std::deque<T>(init) {}

  // Element access.

  // O(1) Returns a reference to the element at specified location.
  T &operator[](size_t pos) { return std::deque<T>::operator[](pos); }

  // O(1) Access the first element.
  T &front() { return std::deque<T>::front(); }

  // O(1) Access the last element.
  T &back() { return std::deque<T>::back(); }

  // Capacity.

  // O(1) Count the number of elements.
  size_t size() { return std::deque<T>::size(); }

  // O(1) Check whether the container is empty.
  bool empty() { return size() == 0; }

  // Modifiers.

  // O(1) Prepend the given element.
  void push_front(const T &x) { std::deque<T>::push_front(x); }

  // O(1) Append the given element.
  void push_back(const T &x) { std::deque<T>::push_back(x); }

  // O(1) Remove the first element.
  void pop_front() { std::deque<T>::pop_front(); }

  // O(1) Remove the last element.
  void pop_back() { std::deque<T>::pop_back(); }

  // LINQ.

  // O(n) Iterate all elements.
  template <typename Consume> void for_each(Consume consume) {
    std::for_each(this->begin(), this->end(), consume);
  }

  // O(n) Filter elements by specific condition.
  template <typename Pred> vec<T> where(Pred pred) {
    vec<T> ret;
    this->for_each([&pred, &ret](T &x) {
      if (pred(x)) {
        ret.push_back(x);
      }
    });
    return ret;
  }

  // O(n) Map elements to another elements.
  template <typename Result, typename Convert>
  vec<Result> select(Convert convert) {
    vec<Result> ret;
    this->for_each([&convert, &ret](T &x) { ret.push_back(convert(x)); });
    return ret;
  }

  // O(n) Cast.
  template <typename Result> vec<Result> cast() {
    return select<Result>([](T &x) { return (Result)x; });
  }

  // O(n) Check if all elements meet the given condition.
  template <typename Pred> bool all(Pred pred) {
    return where(pred).size() == size();
  }

  // O(n) Check if at least one element meets the given condition.
  template <typename Pred> bool any(Pred pred) {
    return false == where(pred).empty();
  }

  // O(n) Calculate the sum of elements.
  T sum() { return accumulate(this->begin(), this->end(), T()); }

  // O(n) Calculate the average of elements.
  T avg() { return empty() ? T() : sum() / size(); }

  // O(n) Find the maximum value.
  T max() {
    auto ptr = max_element(this->begin(), this->end());
    return ptr == this->end() ? numeric_limits<T>::min() : *ptr;
  }

  // O(n) Find the minimum value.
  T min() {
    auto ptr = min_element(this->begin(), this->end());
    return ptr == this->end() ? numeric_limits<T>::max() : *ptr;
  }

  // O(n) Get reversed vector of elements.
  vec<T> rev() {
    vec<T> ret;
    this->for_each([&ret](T &x) { ret.push_front(x); });
    return ret;
  }

  // O(n) Get sorted vector of elements.
  vec<T> sort() {
    vec<T> ret;
    this->for_each([&ret](T &x) { ret.push_back(x); });
    std::sort(ret.begin(), ret.end());
    return ret;
  }

  // O(n) Get sorted vector of elements.
  template <typename Extract> vec<T> order_by(Extract extract) {
    vec<T> ret;
    this->for_each([&ret](T &x) { ret.push_back(x); });
    std::sort(ret.begin(), ret.end(),
              [&extract](T &x, T &y) { return extract(x) < extract(y); });
    return ret;
  }

  // O(n) Get the vector of distinct elements.
  vec<T> uniq() {
    unordered_set<T> s(this->begin(), this->end());
    vec<T> ret;
    for (auto &x : s) {
      ret.push_back(x);
    }
    return ret;
  }

  // O(n) Generate an range.
  static vec<T> range(T start, int count) {
    vec<T> ret;
    while (count-- > 0) {
      ret.push_back(start++);
    }
    return ret;
  }

  // O(n) Generate a vector of repeated elements.
  static vec<T> repeat(T val, int count) {
    vec<T> ret;
    while (count-- > 0) {
      ret.push_back(val);
    }
    return ret;
  }
};

#endif
