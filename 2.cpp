/**
 * @file 2.cpp
 *
 * This problem was asked by Facebook.
 *
 * Given a string of round, curly, and square open and closing brackets,
 * return whether the brackets are balanced (well-formed).
 *
 * For example, given the string "([])[]({})", you should return true.
 *
 * Given the string "([)]" or "((()", you should return false.
 */
#include <stack>
#include <stdexcept>

bool solve(const std::string& input)
{
  std::stack<char> brackets;

  for(auto&& c: input)
  {
    if(c == '(' or c == '[' or c == '{') {
      brackets.emplace(c);
      continue;
    }

    const auto& b = brackets.top();
    if((b == '(' and c != ')') or
       (b == '[' and c != ']') or
       (b == '{' and c != '}')) {
      return false;
    }
    brackets.pop();
  }

  return brackets.empty();
}

int main(int argc, char** argv)
{
  auto test = [](std::string&& input, auto&& expected) {
    if(solve(input) != expected)
      throw std::runtime_error("Problem using the solver !");
  };

  test("([])[]({})", true);
  test("([)]", false);
  test("((()", false);

  return 0;
};
