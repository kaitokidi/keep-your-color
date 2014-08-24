#include "wall.h"
#include "game.h"

Wall::Wall(Game & game, int type, float speed, const sf::Vector2f & pos, const sf::Vector2f & size)
  : Actor(game, type, speed), size(size) {
  this->pos = pos;
}

Wall::~Wall() {}

void Wall::update(float delta_time) {
  pos.x -= delta_time * speed;
}

void Wall::render() {
  sf::RectangleShape rectangle(size);
  rectangle.setPosition(pos);
  sf::Color color = colors[type];
  color.a = 40;
  rectangle.setFillColor(color);
  game.get_window().draw(rectangle);
}

const sf::Vector2f & Wall::get_size() {
  return size;
}
