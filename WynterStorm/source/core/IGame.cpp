#include <core/IGame.h>
#include <game/Scene.h>
#include <objects/Player.h>
#include <events/ObjectCollision.h>
#include <components/PhysicalBody.h>
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

	scene.addObject(&player);
	
	scene.fireEvent<ws::events::ObjectCollision>(ws::events::ObjectCollision(&player, nullptr));
	

	auto physics = player.getComponent<ws::components::PhysicalBody>("physics");
	auto position = cpv(5, 150);
	physics->setPosition(position);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		float deltaTime = updateTimer.getElapsedTime().asSeconds();
		// only update game every 60th of a second
		if(deltaTime >= (1.0f/60.0f)) {
			updateTimer.restart();
			scene.update(deltaTime);
		}
		window.clear();
		
		scene.draw(window);
		
		window.display();
	}
	return 0;
}