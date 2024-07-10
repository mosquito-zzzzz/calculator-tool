#include <getopt.h>

#include <cstdlib>
#include <iostream>

int num_guessing_game(int num1);

int main(int argc, char *argv[]) {
  short int operation{0};
  bool is_guess{false};
  long double num1 = 0;
  long double num2 = 0;

  struct option long_options[] = {
      {"help", no_argument, 0, 'h'},
      {"add", no_argument, 0, 'a'},
      {"sub", no_argument, 0, 's'},
      {"mul", no_argument, 0, 'm'},
      {"div", no_argument, 0, 'd'},
      {"guess", no_argument, 0, 'g'},
      {0, 0, 0, 0}};  // specifies the end of the array.

  int opt{0};
  int option_index = 0;
  while ((opt = getopt_long(argc, argv, "hasmdg", long_options,
                            &option_index)) != -1) {
    switch (opt) {
      case 'h':
        std::cout << "Usage: " << argv[0] << " [options] [x] [y]*\n"
                  << "Options:\n"
                  << "  --help, -h     Show this help message and exit\n"
                  << "  --add, -a      Add two numbers\n"
                  << "  --sub, -s      Subtract two numbers\n"
                  << "  --mul, -m      Multiply two numbers\n"
                  << "  --div, -d      Divide two numbers\n"
                  << "  --guess -g     Number guessing game\n"
                  << "  * the second number is unecessery if you want to guess";
        return 0;

      case 'a':
        operation = 1;
        if (optind + 2 <= argc) {
          num1 = std::strtold(argv[optind], nullptr);
          num2 = std::strtold(argv[optind + 1], nullptr);
        } else {
          std::cerr << "Please provide two numbers after the operation."
                    << std::endl;
          return 1;
        }
        break;

      case 's':
        operation = 2;
        if (optind + 2 <= argc) {
          num1 = std::strtold(argv[optind], nullptr);
          num2 = std::strtold(argv[optind + 1], nullptr);
        } else {
          std::cerr << "Please provide two numbers after the operation."
                    << std::endl;
          return 1;
        }
        break;

      case 'm':
        operation = 3;
        if (optind + 2 <= argc) {
          num1 = std::strtold(argv[optind], nullptr);
          num2 = std::strtold(argv[optind + 1], nullptr);
        } else {
          std::cerr << "Please provide two numbers after the operation."
                    << std::endl;
          return 1;
        }
        break;

      case 'd':
        operation = 4;
        if (optind + 2 <= argc) {
          num1 = std::strtold(argv[optind], nullptr);
          num2 = std::strtold(argv[optind + 1], nullptr);
        } else {
          std::cerr << "Please provide two numbers after the operation."
                    << std::endl;
          return 1;
        }
        break;

      case 'g':
        operation = 5;

        num1 = std::strtold(argv[optind], nullptr);
        is_guess = true;
        break;

      default:
        std::cerr << "Invalid option. Use --help for usage information."
                  << std::endl;
        return 1;
    }
  }

  // Perform the operation based on the flag
  long double result;
  switch (operation) {
    case 1:
      result = num1 + num2;
      break;
    case 2:
      result = num1 - num2;
      break;
    case 3:
      result = num1 * num2;
      break;
    case 4:
      result = num1 / num2;
      break;
    case 5:
      num_guessing_game(num1);
      break;
    default:
      std::cerr << "Invalid operation. Use --help for usage information."
                << std::endl;
      return 1;
  }
  if (is_guess == false) {
    std::cout << "Result: " << result << std::endl;
    return 0;
  }

  return 0;
}

int num_guessing_game(int num1) {
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
