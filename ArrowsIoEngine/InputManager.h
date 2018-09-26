#pragma once
#include <unordered_map>
#include <glm\glm.hpp>
namespace ArrowsIoEngine {

	class InputManager
	{
	public:
		InputManager();
		~InputManager();

		void update();

		void pressKey(unsigned int keyID);
		void releaseKey(unsigned int keyID);

		// Returns True if key is held down
		bool isKeyDown(unsigned int keyID);

		// Returns True if key is just pressed
		bool isKeyPressed(unsigned int keyID);

		void setMouseCoords(float x, float y);

		glm::vec2 getMouseCoords() const { return _mouseCoords; }

	private:
		// Returns True if key was held down
		bool wasKeyDown(unsigned int keyID);

		std::unordered_map<unsigned int, bool> _keyMap;
		std::unordered_map<unsigned int, bool> _previousKeyMap;
		glm::vec2 _mouseCoords;
	};
}

