#include "Level.h"
#include <ArrowsIoEngine/Errors.h>
#include <fstream>
#include <ArrowsIoEngine/ResourceManager.h>
#include <iostream>

using namespace ArrowsIoEngine;
Level::Level(const std::string& fileName, int screenWidth, int screenHeight)
{
	//initializing ids for the level

	brick1Id = ResourceManager::getTexture("../Sparky-core/Textures/assets/brick-1.png").id;
	brick2Id = ResourceManager::getTexture("../Sparky-core/Textures/assets/brick-1.png").id;
	floorId = ResourceManager::getTexture("../Sparky-core/Textures/assets/back.png").id;
	spikeMinusId = ResourceManager::getTexture("../Sparky-core/Textures/assets/spike-.png").id;
	spikePlusId = ResourceManager::getTexture("../Sparky-core/Textures/assets/spike+.png").id;
	spikeUpId = ResourceManager::getTexture("../Sparky-core/Textures/assets/spike-up.png").id;
	spikeDownId = ResourceManager::getTexture("../Sparky-core/Textures/assets/spike-down.png").id;
	spikeHalfId = ResourceManager::getTexture("../Sparky-core/Textures/assets/spike-half.png").id;
	winningBrick = ResourceManager::getTexture("../Sparky-core/Textures/assets/win-brick.png").id;
	jumpBrick = ResourceManager::getTexture("../Sparky-core/Textures/assets/jumppad.png").id;

	//opening the level file
	std::ifstream file;
	file.open(fileName);

	//eeror checking
	if (file.fail())
		fatalError("Failed to open " + fileName);

	//loading the file data
	std::string line;
	while (std::getline(file, line))
	{
		m_levelData.push_back(line);
	}
	glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	Color color = { 255,255,255,255 };

	m_spriteBatch.init();
	m_spriteBatch.begin();

	//loops for rendering the level from text file
	for (int y = 0; y < m_levelData.size(); y++)
	{
		for (int x = 0; x < m_levelData[y].size(); x++)
		{
			char tile = m_levelData[y][x];
			glm::vec4 destRect(y*TILE_WIDTH, x*TILE_WIDTH, TILE_WIDTH, TILE_WIDTH);
			switch (tile)
			{
			case 'R':
				m_spriteBatch.draw(destRect, uvRect, brick2Id, 0.0f, color);
				break;
			case 'L':
				m_spriteBatch.draw(destRect, uvRect, brick1Id, 0.0f, color);
				break;
			case '-':
				m_spriteBatch.draw(destRect, uvRect, spikeMinusId, 0.0f, color);
				break;
			case '+':
				m_spriteBatch.draw(destRect, uvRect, spikePlusId, 0.0f, color);
				break;
			case 'l':
				m_spriteBatch.draw(destRect, uvRect, spikeHalfId, 0.0f, color);
				break;
			case 'S':
				m_spriteBatch.draw(destRect, uvRect, spikeDownId, 0.0f, color);
				break;
			case 's':
				m_spriteBatch.draw(destRect, uvRect, spikeUpId, 0.0f, color);
				break;
			case 'E':
				m_spriteBatch.draw(destRect, uvRect, winningBrick, 0.0f, color);
				break;
			case '.':
				m_spriteBatch.draw(destRect, uvRect, floorId, 0.0f, color);
				break;
			case 'G':
				m_spriteBatch.draw(destRect, uvRect, jumpBrick, 0.0f, color);
				break;
			default:
				std::cout << "Unexpected symbol " << tile << " at (" << y << ", " << x << ")\n";
				break;
			}
		}
	}

	m_spriteBatch.end();
}


Level::~Level()
{
}


void Level::draw()
{
	m_spriteBatch.renderBatch();
}