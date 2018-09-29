#pragma once
#include <glm/glm.hpp>
#include <ArrowsIoEngine\SpriteBatch.h>
#include <ArrowsIoEngine\ResourceManager.h>
#include <ArrowsIoEngine\GLTexture.h>
#include <string>
#include <vector>
#include "Bullet.h"
#include "Level.h"
#include "Sockets.h"

const int MIN_WALL_DISTANCE = 3;
using namespace ArrowsIoEngine;
class Character
{
public:
	Character(std::string name, glm::vec2 pos, int person, glm::vec2 dim, int speed, const std::vector<std::string>& levelData);
	~Character();
	int timer_nitro = 0;
	void draw(SpriteBatch& spriteBatch);
	void moveUP(int vertical_speed);
	void moveDOWN();
	void moveRIGHT();
	void moveLEFT();
	void setDefaultSpeedBlack();
	void nitro();
	void setDefaultSpeed();
	void decHealth();
	int timer_slow = 0;
	// make private
	int m_time_rem = 0;
	float air_pos_x = getPosition().x, air_pos_y = getPosition().y;
	bool is_d_pressed = false;
	bool is_a_pressed = false;
	int h_speed = 0;
	bool c1 = false;
	bool c2 = false;
	bool c3 = false;
	bool c4 = false;
	int m_is_called_by = 1;
	bool m_hasReachedGround = false;
	bool m_first_time = true;
	int m_direction = -1;	// 0 means steady, -1 means down and 1 means up

	bool damageTaken(int damage, int livePlayer, int callerPlayer, int playerType);
	void setGunType(int i) { gunID = i; }
	void setLife(bool v) { life = v; }
	//getters
	glm::vec2 getPosition() { return (m_position + glm::vec2(m_dim.x / 2, m_dim.y / 2)); }	//dimension added to get position of the centre of the character
	int getHealth() { return m_health; }
	glm::vec2 getDim() { return m_dim; }
	void increaseHealth();
	std::string getData();
	std::string getNameScore() { return m_name + "\t\t\t" + std::to_string(m_score); }
	//setters
	void setData(float x, float y, int health);
	void setHeart(int heart);
	bool getLife() { return life; }
	int getGunType() { return gunID; }

private:
	glm::vec2 m_position, m_dim;
	glm::vec4 m_uv = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
	Color m_color = { 255,255,255,255 };
	std::string m_name;
	int m_person;
	GLuint m_texId;	//stores the ids of the textures. non-shooting mode, shooting mode
	int m_state;	//stores if it is in shooting mode or non shooting mode
	int m_vertical_speed = 0;
	int m_speed;
	int m_gravity = -1;
	int m_health = 7;
	int m_score = 0;
	std::vector<std::string> m_levelData;
	
	int gunID;
	int m_currentGunIndex;
	bool life = true;

	std::string m_filePaths[4] = { "../Sparky-core/Textures/Characters/char1.png","../Sparky-core/Textures/Characters/char2.png","../Sparky-core/Textures/Characters/char3.png","../Sparky-core/Textures/Characters/char4.png" };
};

