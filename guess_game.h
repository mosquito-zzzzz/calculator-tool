#pragma once
#include <iostream>

inline int num_guessing_game(int num1) {
  short num, guess;
  unsigned int tries = 1;

  srand(time(NULL));
  num = (rand() % num1) + 1;

  std::cout << "Enter a guess between 1 and " << num1 << ": " << "\n";

  do {
    std::cin >> guess;
    if (guess < num) {
      std::cout << "Too low!" << "\n";
      tries++;
    } else if (guess > num) {
      std::cout << "Too high!" << "\n";
      tries++;
    } else
      std::cout << "Correct! You guessed it in " << tries << " tries." << "\n";
  } while (guess != num);
  return 0;
}
