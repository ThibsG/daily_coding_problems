/**
 * @file 3.cpp
 *
 * This problem was asked by Amazon.

 * Given an array of numbers, find the maximum sum of any contiguous subarray of the array.
 * For example, given the array [34, -50, 42, 14, -5, 86], the maximum sum would be 137, since we would take elements 42, 14, -5, and 86.
 * Given the array [-5, -1, -8, -9], the maximum sum would be 0, since we would not take any elements.
 * Do this in O(N) time.
 */
#include <vector>
#include <stdexcept>

/**
 * Naive O(n^2) solution
 */
int solveNaive(const std::vector<int>& input)
{
  int sum = 0;

  for(std::size_t i = 0 ; i < input.size() ; ++i) {
    int tmpSum = 0;

    for(std::size_t j = i+1 ; j < input.size() ; ++j) {
      tmpSum += input.at(j);

      if(tmpSum > sum)
        sum = tmpSum;
    }
  }

  return sum;
}


int main(int argc, char** argv)
{
  auto test = [](std::vector<int>&& vec, int expected) {
    auto result = solveNaive(vec);

    if(result != expected)
      throw std::runtime_error("Problem using the solver !");
  };

  test({34, -50, 42, 14, -5, 86}, 137);
  test({-5, -1, -8, -9}, 0);
  test({-5, 6, 7, 1, 4, -8, 16}, 26);

  return 0;
};
