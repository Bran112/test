#include "Game.h"
#include "Components.hpp"

#include "imgui.h"
#include <SFML/Graphics.hpp>


void Game::sMovement() {
	// TODO: implement all entity movement in this function
	for (auto entities : m_entities.getEntities())
	{
		if (entities->has<CInput>()) {
			if (entities->has<CMovement>()) {
				auto& InputComponent = entities->get<CInput>();
				auto& MovementComponent = entities->get<CMovement>();
				if (InputComponent.up == true) {
					MovementComponent.pos.y -= 10;
				}
				if (InputComponent.down == true) {
					MovementComponent.pos.y += 10;
				}
				if (InputComponent.left == true) {
					MovementComponent.pos.x -= 10;
				}
				if (InputComponent.right == true) {
					MovementComponent.pos.x += 10;
				}
			}
		}
	}
}
void Game::sUserInput() {
  // TODO: handle user input here
  // note that you should only be setting the player's input component variables
  // you should not implement the player's movement logic here
  // the movement system will read the variables you set in this function
	while (const std::optional event = m_window.pollEvent()) {
		if (event->is<sf::Event::Closed>())
		{
			m_window.close();
		}
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::W)
				for (auto entities : m_entities.getEntities())
				{
					if (entities->has<CInput>())
					{
						entities->get<CInput>().up = true;
					}
				}
			if (keyPressed->scancode == sf::Keyboard::Scancode::S)
				for (auto entities : m_entities.getEntities())
				{
					if (entities->has<CInput>())
					{
						entities->get<CInput>().down = true;
					}
				}
			if (keyPressed->scancode == sf::Keyboard::Scancode::D)
				for (auto entities : m_entities.getEntities())
				{
					if (entities->has<CInput>())
					{
						entities->get<CInput>().right = true;
					}
				}
			if (keyPressed->scancode == sf::Keyboard::Scancode::A)
				for (auto entities : m_entities.getEntities())
				{
					if (entities->has<CInput>())
					{
						entities->get<CInput>().left = true;
					}
				}
		}
		else if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>())
		{
			if (keyReleased->scancode == sf::Keyboard::Scancode::W)
				for (auto entities : m_entities.getEntities())
				{
					if (entities->has<CInput>())
					{
						entities->get<CInput>().up = false;
					}
				}
			if (keyReleased->scancode == sf::Keyboard::Scancode::S)
				for (auto entities : m_entities.getEntities())
				{
					if (entities->has<CInput>())
					{
						entities->get<CInput>().down = false;
					}
				}
			if (keyReleased->scancode == sf::Keyboard::Scancode::D)
				for (auto entities : m_entities.getEntities())
				{
					if (entities->has<CInput>())
					{
						entities->get<CInput>().right = false;
					}
				}
			if (keyReleased->scancode == sf::Keyboard::Scancode::A)
				for (auto entities : m_entities.getEntities())
				{
					if (entities->has<CInput>())
					{
						entities->get<CInput>().left = false;
					}
				}
		}



void Game::sRender();
{
	// TODO: Complete window rendering here
	// draws ImGui
	m_window.clear(sf::Color::Black);
	ImGui::SFML::Render(m_window);
	for (auto bubaa : m_entities.getEntities()) {
		if (bubaa->has<CShape>()) {
			auto& shapeComponent = bubaa->get<CShape>();
			shapeComponent.shape.setPosition(bubaa->get<CMovement>().pos);
			shapeComponent.shape.setFillColor(sf::Color::Yellow);
			m_window.draw(shapeComponent.shape);
		}
	}

	m_window.display();
}

void Game::spawnPlayer() {
	// TODO: create player entity and add components
	auto player = m_entities.addEntity("Player");
	player->add<CInput>();
	player->add<CShape>(10);
	player->add<CMovement>(10, 10);
}

std::shared_ptr<Entity> Game::player() {
	// TODO: return player entity
}

Game::Game() {}

void Game::run() {

	// TODO: set up while loop / window loop (TRUE)
	// this is where systems are updated
	m_window.create(sf::VideoMode({ 600, 700 }), "The window");
	while (m_window.isOpen()) {

	}

	ImGui::SFML::Shutdown();
}
}
