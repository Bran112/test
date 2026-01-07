#pragma once
#include "SFML/Graphics.hpp"

class Component {

public:
  bool exist = false;
};

class CInput : public Component {

public:
  bool up = false;
  bool down = false;
  bool left = false;
  bool right = false;
  bool shoot = false;
  bool canShoot = true;
  bool canJump = true;

  CInput() = default;
};

class CShape : public Component {

public:
  sf::CircleShape shape;
  CShape(float silhouette) { shape.setRadius(silhouette); }
  CShape() = default;
};

class CMovement : public Component {

public:
  sf::Vector2f pos;
  CMovement(float locx, float locy) {
    pos.x = locx;
    pos.y = locy;
  }
  CMovement() = default;
};
