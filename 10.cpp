/**
 * @file 10.cpp
 * This problem was asked by Apple.
 *
 * Implement a job scheduler which takes in a
 * function f and an integer n, and calls f after n milliseconds.
 */
#include <thread>
#include <chrono>


using namespace std::chrono_literals;

void delayedLaunch(auto&& f, unsigned int wait)
{
  std::chrono::milliseconds msecs(wait);
  std::this_thread::sleep_for(msecs);
  f();
}

int main(int argc, char** argv)
{
  try {
    auto func = [](){
      printf("Func has been called");
    };

    delayedLaunch(func, atoi(argv[1]));
  }catch(...) {
    return 1;
  }

  return 0;
};
