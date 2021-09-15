/// @file main.cpp
/// @brief Program Main File 
///
/// Controls all objects, options, errors and exceptions
/// in order to display all features of Core Coin
#ifdef __unix__         
#elif defined(_WIN32) || defined(WIN32) 
#define OS_Windows
#endif

#include <cstdio>
#include <getopt.h>

#include "../include/greedy.hpp"

/** @name Main File Functions */
/// @{
void help();
void error();
/// @}

/// @brief Program Options
const option long_options[] = { {"help", 0, 0, 'h'}, {0, 0, 0, 0} };

/// @brief Using the defined classes, Core Coin launches an interactive menu with 
/// all the options to calculate and display the solution for a change of money
/// @param argc Argument Number
/// @param argv Argument Vector
/// @return Exit Code
int main(int argc, char** argv) {
  try {
    // Argument Handler
    int c, option_index;
      while ((c = getopt_long (argc, argv, "h", long_options, &option_index)) != -1) {
          switch (c) {
            case 'h':
              help();
              return 0;
            default:
              error();
              return 1;
          }
      }
    
    unsigned option = 1;
    float amount, coinValue;
    std::set<Coin> coins;
    Greedy algorithm;
    
    #ifdef OS_Windows
      system("cls");
    #else
      system("clear");
    #endif
    
    // Interactive Menu
    while (option != 0) {
      std::cout << "-------------------------------------------------------------------------------" << std::endl;
      std::cout << "Greedy Algorithm for change of money"											   << std::endl;
      std::cout << "-------------------------------------------------------------------------------" << std::endl;
      std::cout << "[0] Exit"                                                                        << std::endl;
      std::cout << "-------------------------------------------------------------------------------" << std::endl;
      std::cout << "[1] Return an amount of money"                                                   << std::endl;
      std::cout << "[2] Show last change"                                                            << std::endl;
      std::cout << "[3] Insert new type of coin to the algorithm"                                    << std::endl;
      std::cout << "[4] View availables types of coins"                                              << std::endl;
      std::cout << "-------------------------------------------------------------------------------" << std::endl;
      std::cout << "Insert Option ---> "; std::cin >> option;
      std::cout << "-------------------------------------------------------------------------------" << std::endl;
      switch (option) {
        case 0:
          break;
        case 1:
          std::cout << "Amount: "; std::cin >> amount;
          std::cout << "-------------------------------------------------------------------------------" << std::endl;
          try {
            algorithm.returnChange(amount); std::cout << algorithm << std::endl;
          }
          catch (NoSolution& e) {
            std::cout << e.what() << std::endl;
          }
          break;
        case 2:
          std::cout << algorithm << std::endl;
          break;
        case 3:
          std::cout << "Introduce coin value (in Euros)"                        						   << std::endl;
          std::cout << "-------------------------------------------------------------------------------" << std::endl;
          std::cout << "Value: "; std::cin >> coinValue;
          algorithm.insertCoin(Coin(coinValue));
          break;
        case 4:
          coins = algorithm.getCoins();
          std::cout << "There are coins of ";
          for (std::set<Coin>::iterator it = coins.begin(); it != coins.end(); ++it) {
            std::cout << (*it);
            if (it != prev(coins.end()))
              std::cout << ", ";
          }
          std::cout << std::endl;
          break;
        default:
          std::cout << "Unknown Option..." << std::endl;
          break;
      }
      if (option != 0) {
        std::cout << "-------------------------------------------------------------------------------" << std::endl;
        std::cin.ignore().get();
        #ifdef OS_Windows
          system("cls");
        #else
          system("clear");
        #endif
      }
    }
  }
  catch (std::exception& e) {
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    std::cout << e.what() << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
  }
  return 0;
}

/// @brief User Guide
///
/// Shows message explaining all Core Coin features
/// @return Void
void help(void) {
  std::cout << "-------------------------------------------------------------------------------" << std::endl;
  std::cout << "Core Coin Execution: ./Change"                                                	   << std::endl;
  std::cout << "-------------------------------------------------------------------------------" << std::endl;
  std::cout << "Once launched, the program will show a interactive menu"                         << std::endl;
  std::cout << "displaying all available options"                                                << std::endl;
  std::cout << "-------------------------------------------------------------------------------" << std::endl;
  std::cout << "[0] Exit"                                                                        << std::endl;
  std::cout << "-------------------------------------------------------------------------------" << std::endl;
  std::cout << "[1] Return an amount of money"                                                   << std::endl;
  std::cout << "[2] Show last change"                                                            << std::endl;
  std::cout << "[3] Insert new type of coin to the algorithm"                                    << std::endl;
  std::cout << "[4] View availables types of coins"                                              << std::endl;
  std::cout << "-------------------------------------------------------------------------------" << std::endl;
}

/// @brief Error message
///
/// For unknown commands, displays an error message showing information of all possible options
/// @return Void
void error(void) {
  std::cout << "-------------------------------------------------------------------------------" << std::endl;
  std::cout << "./Change [-h|--help]"            								  				   << std::endl;
  std::cout << "-------------------------------------------------------------------------------" << std::endl;
  std::cout << "[-h|--help]	Shows User's Guide"												   << std::endl;
  std::cout << "-------------------------------------------------------------------------------" << std::endl;
}