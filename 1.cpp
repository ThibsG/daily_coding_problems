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

int solve(const std::vector<int>& vec)
{
  int best = 0;
  for(size_t i = 0 ; i < vec.size() ; ++i )
  {
    for(size_t sub = 0 ; sub < vec.size() ; ++sub)
    {
      if(i == sub or sub == (i+1) or sub == (i-1))
        continue;

      auto sum = vec[i] + vec[sub];
      best = sum > best ? sum : best;
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
