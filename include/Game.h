#pragma once
#include "Entity.hpp"
#include "EntityManager.h"
#include "SFML/Graphics.hpp"
#include "imgui-SFML.h"

class Game {
  sf::RenderWindow m_window;
  EntityManager m_entities;

  void sRender();
  void sMovement();
  void sUserInput();

  void spawnPlayer();

  std::shared_ptr<Entity> player();

public:
  Game();
  void run();
};
