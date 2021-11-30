// Constructor (empty).
void vec_test_construct_1() {

  // Given.
  auto v = vec<int>();

  // Then.
  assert(v.empty() == true);
  assert(v.size() == 0);
}

// Constructor (from initial list).
void vec_test_construct_2() {

  // Given.
  auto v = vec<int>{1, 2, 3};

  // Then.
  assert(v.empty() == false);
  assert(v.size() == 3);
  assert(v[0] == 1);
  assert(v[1] == 2);
  assert(v[2] == 3);
  assert(v.front() == 1);
  assert(v.back() == 3);
}

// Element access.
void vec_test_element_access_1() {

  // Given.
  auto v = vec<int>{1, 2, 3};

  // When.
  v.front() = 0;
  v[1] = 1;
  v.back() = 2;

  // Then.
  assert(v[0] == 0);
  assert(v[1] == 1);
  assert(v[2] == 2);
}

// Modifiers.
void vec_test_modifiers_1() {

  // Given.
  auto v = vec<int>{1, 2, 3};

  // When.
  v.push_front(4);
  v.push_back(5);

  // Then.
  assert(v.empty() == false);
  assert(v.size() == 5);
  assert(v[0] == 4);
  assert(v[4] == 5);
  assert(v.front() == 4);
  assert(v.back() == 5);
}

// Modifiers.
void vec_test_modifiers_2() {

  // Given.
  auto v = vec<int>{1, 2, 3};

  // When.
  v.pop_front();
  v.pop_back();

  // Then.
  assert(v.empty() == false);
  assert(v.size() == 1);
  assert(v[0] == 2);
}

// LINQ.
void vec_test_linq_1() {

  // Given.
  auto v = vec<int>::range(0, 10);

  // When.
  v.for_each([](int &x) { x = 0; });

  // Then.
  assert(v.all([](int &x) { return x == 0; }) == true);
  assert(v.any([](int &x) { return x == 1; }) == false);
}

// LINQ.
void vec_test_linq_2() {

  // Given.
  auto v = vec<int>::range(0, 10);

  // When.
  auto odd = v.where([](int &x) { return x % 2 == 0; });

  // Then
  assert(odd.size() == 5);
  assert(odd.sum() == 20);
  assert(odd.avg() == 4);
  assert(odd.max() == 8);
  assert(odd.min() == 0);
}

// LINQ.
void vec_test_linq_3() {

  // Given.
  auto v = vec<int>::range(1, 4).cast<double>();

  // Then.
  assert((v.sum() - 10) < 0.001);
  assert((v.avg() - 2.5) < 0.001);
}

// LINQ.
void vec_test_linq_4() {

  // Given.
  auto v = vec<int>::range(1, 3).rev();

  // Then.
  assert(v[0] == 3);
  assert(v[1] == 2);
  assert(v[2] == 1);
}

// LINQ.
void vec_test_linq_5() {

  // Given.
  auto v = vec<int>{3, 0, 4, 2, 1}.sort();

  // Then.
  assert(v[0] == 0);
  assert(v[1] == 1);
  assert(v[2] == 2);
  assert(v[3] == 3);
  assert(v[4] == 4);
}

// LINQ.
void vec_test_linq_6() {

  // Given.
  auto v = vec<string>{"a", "ccc", "bb"}.order_by(
      [](string &s) { return s.length(); });

  // Then.
  assert(v[0] == "a");
  assert(v[1] == "bb");
  assert(v[2] == "ccc");
}

// LINQ.
void vec_test_linq_7() {

  // Given.
  auto v = vec<int>{1, 2, 3, 2, 1}.uniq();

  // Then.
  assert(v.size() == 3);
  assert(v[0] == 3);
  assert(v[1] == 2);
  assert(v[2] == 1);
}

// LINQ.
void vec_test_linq_8() {

  // Given.
  auto v = vec<int>::repeat(1, 10);

  // Then.
  assert(v.size() == 10);
  assert(v.all([](int &x) { return x == 1; }));
}

void vec_test() {
  vec_test_construct_1();
  vec_test_construct_2();
  vec_test_element_access_1();
  vec_test_modifiers_1();
  vec_test_modifiers_2();
  vec_test_linq_1();
  vec_test_linq_2();
  vec_test_linq_3();
  vec_test_linq_4();
  vec_test_linq_5();
  vec_test_linq_6();
  vec_test_linq_7();
  vec_test_linq_8();
}
