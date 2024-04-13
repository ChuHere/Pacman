#pragma once

#include <string>

/**
 * @class Config
 * @brief The Config class represents the game configuration.
 *
 * This class is capable of reading the game configuration from textfiles.
 * It manages the game, including map settings and power-up duration.
 */
class Config {
public:
  /**
   * @brief Constructs a Config object.
   */
  Config();

  /**
   * @brief Loads the game configuration from a file.
   *
   * This function loads the game configuration from the specified file.
   *
   * @param file The path to the configuration file.
   * @return True if the configuration is successfully loaded, false otherwise.
   */
  bool loadConfig(const std::string& file);

  /**
   * @brief Checks if the map has all the necessities.
   *
   * This function checks if the map is valid.
   *
   * @param file The path to the map file.
   * @return True if the map is valid, false otherwise.
   */
  bool checkMap(const std::string& file);

  std::string mapDiff;
  int powerupDur;
  size_t mapHeight;
  size_t mapWidth;
};