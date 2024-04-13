#include "Game.h"

/**
 * @class Application
 * @brief The Application class represents the main application.
 *
 * This class handles the menu, leaderboard and the execution of the game itself.
 */
class Application {
public:
  /**
   * @brief Default constructor.
   *
   * This is the default constructor for the Application class.
   */
  Application() = default;

  /**
   * @brief Destroys the Application object.
   *
   * This is the default destructor for the Application class.
   */
  ~Application() = default;

  /**
   * @brief Displays the menu to choose from.
   *
   * This function initializes the application and starts the game. Displays a menu in which
   * the player can choose what to do. Show leaderboard, play the game or exit.
   *
   * @return True if the application starts successfully, false otherwise.
   */
  bool start();

  /**
   * @brief Initializes the game.
   * 
   * Sets up the whole game (board, figures, special objects...). Reads from configs.
   * 
   * @return True if initialization is successful.
  */
  bool initApp();

  /**
   * @brief Executes the game.
   *
   * Responsible for all of the game execution. Runs it in a while loop.
   */
  void run();

  /**
   * @brief Prints the leaderboard.
   *
   * This function prints the current leaderboard of the game.
   */
  void printLeaderboard() const;

  Game gamePac;
};