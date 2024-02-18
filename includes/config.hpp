#ifndef CONFIG_H
#define CONFIG_H

struct config
{
	static constexpr int frameRate{60};
	static constexpr int windowWidth{520};
	static constexpr int windowHeight{450};
	static constexpr float snowballSpeed{6.0f};
	static constexpr float snowboardWidth{60.0f};
	static constexpr float snowboardHeight{20.0f};
	static constexpr float snowboardSpeed{10.0f};
	static constexpr float brickWidth{43.f};
	static constexpr float brickHeight{20.f};
	static constexpr float bricksOffset{brickWidth * 0.5};
	static constexpr int brickColumns{10};
	static constexpr int brickRows{4};
	static constexpr int brickColorLevels{3};
	static constexpr int lives{3};
};

#endif // CONFIG_H