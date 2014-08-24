#include "player.h"
#include "game.h"
#include <iostream>
#include "utils.h"
#include "input.h"

Player::Player(Game & game, int type, float speed) : Actor(game, type, speed) {
  size = sf::Vector2f(20, 20);
  pos.x = 50;
  pos.y = SCREEN_HEIGHT/2.0f - size.y/2.0f;
}

Player::~Player() {}

void Player::update(float delta_time) {
  const Input & input = game.get_input();
  if (input.key_down(input.Key::PLAYER_DOWN)) {
    pos.y = std::min(SCREEN_HEIGHT - size.y, pos.y + delta_time * speed);
  }
  if (input.key_down(input.Key::PLAYER_UP)) {
    pos.y = std::max(0.0f, pos.y - delta_time * speed);
  }
  if (input.key_pressed(input.Key::PLAYER_ACTION)) {
    type = 1-type;
  }
}

void Player::render() {
  sf::RectangleShape rectangle(size);
  rectangle.setPosition(pos);
  sf::Color color = colors[type];
  rectangle.setFillColor(color);
  game.get_window().draw(rectangle);
}

const sf::Vector2f Player::get_size() {
  return size;
}

void Player::set_pos(const sf::Vector2f & pos) {
  this->pos = pos;
}