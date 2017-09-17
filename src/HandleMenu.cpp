#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>

#include "HandleMenu.hpp"

namespace Stage {
	enum Stage {
		LOAD_LOGO,
		LOAD_STARTUP_JINGLE,
		INTRO_ANIMATION_PLAY,
		LOAD_MAIN_MENU,
		DISPLAY_MAIN_MENU_SWAP,
		DISPLAY_MAIN_MENU
	};
}

static int currentStage = Stage::LOAD_LOGO;
static sf::SoundBuffer* soundBuffer[8];
static sf::Sound* sound[8];
static sf::Texture* texture[32];
static sf::Sprite* sprite[32];
static sf::Font* font[2];
static sf::Text* text[64];
static float timer = 0.0F;
static float interpolator[8];

void HandleMenu(float deltaTime) {
	switch (currentStage) {
	case Stage::LOAD_LOGO:
		texture[0] = new sf::Texture;
		texture[0]->loadFromFile("./data/logo.png");
		sprite[0] = new sf::Sprite(*(texture[0]));
		sprite[0]->setScale(0.5F, 0.5F);
		sprite[0]->setOrigin(276.0F, 64.0F);
		sprite[0]->setPosition(400.0F, 300.0F);
		sprite[0]->setColor(sf::Color(255, 255, 255, 255 * 0.8F));
		font[0] = new sf::Font;
		font[0]->loadFromFile("./data/cyberfont.ttf");
		currentStage = Stage::LOAD_STARTUP_JINGLE;
		break;
	case Stage::LOAD_STARTUP_JINGLE:
		soundBuffer[0] = new sf::SoundBuffer;
		soundBuffer[0]->loadFromFile("./data/startup.wav");
		sound[0] = new sf::Sound(*(soundBuffer[0]));
		sound[0]->play();
		timer = 5.0F;
		interpolator[0] = 0.5;
		interpolator[1] = 0.8;
		currentStage = Stage::INTRO_ANIMATION_PLAY;
		break;
	case Stage::INTRO_ANIMATION_PLAY:
		if (timer < 0.0F) {
			text[0] = new sf::Text("LOADING", *(font[0]), 20);
			text[0]->setFillColor(sf::Color(255, 255, 0, 255));
			sf::FloatRect rect = text[0]->getLocalBounds();
			text[0]->setOrigin(rect.left + rect.width / 2.0F, rect.top + rect.height / 2.0F);
			text[0]->setPosition(800.0F / 2.0F, 550.0F);
			timer = 6.0F;
			interpolator[0] = 0.9F;
			currentStage = Stage::LOAD_MAIN_MENU;
		} else {
			timer -= deltaTime;
			interpolator[0] = 0.5F + 0.3F * sin((M_PI / 2.0F) * (1.0F - (timer / 5.0F)));
			interpolator[1] = 0.8F + 0.2F * sin((M_PI / 2.0F) * (1.0F - (timer / 5.0F)));
			sprite[0]->setScale(interpolator[0], interpolator[0]);
			sprite[0]->setColor(sf::Color(255, 255, 255, 255 * interpolator[1]));
		}
		break;
	case Stage::LOAD_MAIN_MENU:
		if (timer < 0.0F) {
			delete sound[0];
			sound[0] = NULL;
			delete soundBuffer[0];
			soundBuffer[0] = NULL;
			delete text[0];
			text[0] = NULL;
			timer = 1.5F;
			interpolator[0] = 1.0F;
			currentStage = Stage::DISPLAY_MAIN_MENU_SWAP;
		} else {
			timer -= deltaTime;
			interpolator[0] = 0.95F + 0.1F * sin(12.5F * (M_PI / 2.0F) * (1.0F - (timer / 6.0F)));
			text[0]->setScale(interpolator[0], interpolator[0]);
		}
		break;
	case Stage::DISPLAY_MAIN_MENU_SWAP:
		if (timer < 0.0F) {
			timer = 0.0F;
			currentStage = Stage::DISPLAY_MAIN_MENU;
		} else {
			timer -= deltaTime;
			interpolator[0] = timer / 1.5F;
			sprite[0]->setPosition(276.0F / 4.0F + 16.0F + 315.0F * sin((M_PI / 2.0F) * interpolator[0]), 64.0F / 4.0F + 16.0F + 268.0F * sin((M_PI / 2.0F) * interpolator[0]));
			sprite[0]->setScale(0.25 + sin((M_PI / 2.0F) * interpolator[0]) * 0.55F, 0.25 + sin((M_PI / 2.0F) * interpolator[0]) * 0.55F);
		}
		break;
	case Stage::DISPLAY_MAIN_MENU:
		// draw menu
		break;
	}
}

void DrawMenu(sf::RenderWindow& window) {
	switch (currentStage) {
	case Stage::INTRO_ANIMATION_PLAY:
		window.draw(*(sprite[0]));
		break;
	case Stage::LOAD_MAIN_MENU:
		window.draw(*(sprite[0]));
		window.draw(*(text[0]));
		break;
	case Stage::DISPLAY_MAIN_MENU_SWAP:
		window.draw(*(sprite[0]));
		break;
	case Stage::DISPLAY_MAIN_MENU:
		// display menu
		window.draw(*(sprite[0]));
		break;
	}
}

/*
	Hello NiggerFaggot, i know you would read this code
	it is you destine to read good cyberspace matrix 100 tu531
	code source live. takeown pls do your kickcrap wideo nowwe!
*/
