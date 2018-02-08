/**
 * @file 1.cpp
 * This problem was asked by Airbnb.
 *
 * Given a list of integers, write a function
 * that returns the largest sum of non-adjacent numbers.
 *
 * For example, [2, 4, 6, 8] should return 12, since we pick 4 and 8.
 * [5, 1, 1, 5] should return 10, since we pick 5 and 5.
 */
#include <vector>
#include <stdexcept>
#include <iostream>

int solve(const std::vector<int>& vec)
{
  int best = 0;
  for(size_t i = 0 ; i < vec.size() ; ++i)
  {
    auto checkBest = [&](int&& sum) {
      best = sum > best ? sum : best;
    };

    // Lower part
    for(int lSub = 0 ; lSub < (int)i-1 ; ++lSub) {
      checkBest(vec[i] + vec[lSub]);
    }

    // Higher part
    for(size_t hSub = i+2 ; hSub < vec.size() ; ++hSub) {
      checkBest(vec[i] + vec[hSub]);
    }
  }
  return best;
}

int main(int argc, char** argv)
{
  auto test = [](std::vector<int>&& vec, int expected) {
    auto result = solve(vec);

    if(result != expected)
      throw std::runtime_error("Problem using the solver !");
  };

  test({2, 4, 6, 8}, 12);
  test({5, 1, 1, 5}, 10);

  return 0;
};
