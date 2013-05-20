#include <core/IGame.h>
#include <game/Scene.h>
#include <objects/Player.h>
#include <events/ObjectCollision.h>
#include <components/Physics2D.h>
#include <components/Renderable.h>

ws::core::IGame::IGame(void) {
	window.create(sf::VideoMode(800, 600), "WynterStorm");
}

ws::core::IGame::~IGame(void) {
}

	
int ws::core::IGame::Run() {
	sf::Clock updateTimer;
	ws::game::Scene scene;
	ws::objects::Player player;
	ws::events::ObjectCollision objectCollisionEvent(nullptr);

	scene.addObject(&player);
	
	scene.fireEvent<ws::events::ObjectCollision>(ws::events::ObjectCollision(nullptr));
	

	auto physics = player.getComponent<ws::components::Physics2D>("physics");
	auto position = physics->getPosition();
	position = sf::Vector2f(3.0f, 14.0f);
	physics->setPosition(position);
	physics->setConstantForce(sf::Vector2f(3.0f, 14.0f));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		float deltaTime = updateTimer.getElapsedTime().asSeconds();
		updateTimer.restart();
		scene.update(deltaTime);
		window.clear();
		
		scene.draw(window);
		
		window.display();
	}
	return 0;
}