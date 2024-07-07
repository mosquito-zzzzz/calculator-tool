#include <getopt.h>

#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  short int operation{0};
  long double num1 = 0;
  long double num2 = 0;

  struct option long_options[] = {
      {"help", no_argument, 0, 'h'},
      {"add", required_argument, 0, 'a'},
      {"sub", required_argument, 0, 's'},
      {"mul", required_argument, 0, 'm'},
      {"div", required_argument, 0, 'd'},
      {0, 0, 0, 0}};  // specifies the end of the array.

  int opt{0};
  int option_index = 0;
  while ((opt = getopt_long(argc, argv, "ha:s:m:d:", long_options,
                            &option_index)) != -1) {
    switch (opt) {
      case 'h':
        std::cout << "Usage: " << argv[0] << " [options]* [x] [y]\n"
                  << "Options:\n"
                  << "  --help, -h     Show this help message and exit\n"
                  << "  --add, -a      Add two numbers\n"
                  << "  --sub, -s      Subtract two numbers\n"
                  << "  --mul, -m      Multiply two numbers\n"
                  << "  --div, -d      Divide two numbers\n";
        return 0;

      case 'a':
      operation = 1;
      if (optind + 2 <= argc) {
          num1 = atoi(argv[optind]);
          num2 = atoi(argv[optind + 1]);
        } else {
          std::cerr << "Please provide two numbers after the operation."
                    << std::endl;
          return 1;
        }
        break;

      case 's':
      operation = 2;
      if (optind + 1 <= argc) {
          num1 = atoi(argv[optind]);
          num2 = atoi(argv[optind + 1]);
        } else {
          std::cerr << "Please provide two numbers after the operation."
                    << std::endl;
          return 1;
        }
        break;

      case 'm':
      operation = 3;
      if (optind + 1 <= argc) {
          num1 = atoi(argv[optind]);
          num2 = atoi(argv[optind + 1]);
        } else {
          std::cerr << "Please provide two numbers after the operation."
                    << std::endl;
          return 1;
        }
        break;

      case 'd':
      operation = 4;
        if (optind + 1 <= argc) {
          num1 = atoi(argv[optind]);
          num2 = atoi(argv[optind + 1]);
        } else {
          std::cerr << "Please provide two numbers after the operation."
                    << std::endl;
          return 1;
        }
        break;

      default:
        std::cerr << "Invalid option. Use --help for usage information."
                  << std::endl;
        return 1;
    }
  }

  // Perform the operation based on the flag
  int result;
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
    default:
      std::cerr << "Invalid operation. Use --help for usage information."
                << std::endl;
      return 1;
  }

  std::cout << "Result: " << result << std::endl;
        
  return 0;
}


int num_guessing_game() {
  short num, guess;
  unsigned int tries = 1;

  srand(time(NULL));
  num = (rand() % 100) + 1;

  std::cout << "Enter a guess between 1 and 100: " << "\n";

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
