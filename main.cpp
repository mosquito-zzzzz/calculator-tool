#include <getopt.h>

#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  int operation = 0;
  int num1 = 0;
  int num2 = 0;

  struct option long_options[] = {
      {"help", no_argument, 0, 'h'},
      {"add", no_argument, 0, 'a'},
      {"sub", no_argument, 0, 's'},
      {"mul", no_argument, 0, 'm'},
      {"div", no_argument, 0, 'd'},
      {"num1", required_argument, 0, 'x'},
      {"num2", required_argument, 0, 'y'},
      {0, 0, 0, 0}};  // specifies the end of the array.

  int opt;
  int option_index = 0;
  while ((opt = getopt_long(argc, argv, "hasmdx:y:", long_options,
                            &option_index)) != -1) {
    switch (opt) {
      case 'h':
        std::cout << "Usage: " << argv[0] << " [options]\n"
                  << "Options:\n"
                  << "  --help, -h     Show this help message and exit\n"
                  << "  --add, -a      Add two numbers\n"
                  << "  --sub, -s      Subtract two numbers\n"
                  << "  --mul, -m      Multiply two numbers\n"
                  << "  --div, -d      Divide two numbers\n"
                  << "  --num1, -x <num1>  First number\n"
                  << "  --num2, -y <num2>  Second number\n";
        return 0;
      case 'a':
        operation = 1;
        break;
      case 's':
        operation = 2;
        break;
      case 'm':
        operation = 3;
        break;
      case 'd':
        operation = 4;
        break;
      case 'x':
        num1 = atoi(optarg);  // atoi(optarg) converts the string to an integer
        break;
      case 'y':
        num2 = atoi(optarg);  // atoi(optarg) converts the string to an integer
        break;
      default:
        std::cerr << "Invalid option. Use --help for usage information."
                  << std::endl;
        return 1;
    }
  }

  // Perform the operation based on the flag
  int result = 0;
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
