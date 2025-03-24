#include <iostream>

int scores[] = { 84, 92, 76, 81, 56 };

int main() {
    // Why no length provided? -> provided when compiling
    // https://stackoverflow.com/a/25232492
  int sum = 0;
  for (auto score : scores) {
    sum += score;
  }
  std::cout << "Sum of scores: " << sum << std::end(scores) << std::endl;
  return sum;
}