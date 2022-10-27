#include <cassert>
#include <chrono>
#include <filesystem>
#include <iostream>

using namespace std::chrono_literals;

// Write a function that will do some looping -- we write it here
// so that we can get the compiler to generate the code that we are
// patching in.
void slow_down() {
    for (volatile unsigned int repetitions{0}; repetitions<10000; repetitions+=1) {
        // do nothing.
    }
    return;
}

// Just do some work so that we have something to time. That's all.
unsigned int worker() {
  volatile unsigned int result{0};
  // We are going to go up a directory because we are running from inside the build/ directory (typically)
  std::filesystem::path p{"../temp.txt"};

  try {
    auto stat{std::filesystem::file_size(p)};
    result = stat;
  } catch (std::filesystem::filesystem_error &fse) {
    std::cout << fse.what() << "\n";
  }

  return result;
}
int main() {
  std::cout << "Hello, World\n";
  unsigned int iterations{1000};

  auto total_time = 0ns;

  for (auto i{0u}; i < iterations; i++) {
    volatile unsigned int result{0};
    auto before = std::chrono::high_resolution_clock::now();
    result = worker();
    auto after = std::chrono::high_resolution_clock::now();

    total_time += (after - before);
  }

  std::cout << "Average time taken: " << (total_time.count() / static_cast<double>(iterations)) << " nanoseconds\n";
  return 0;
}