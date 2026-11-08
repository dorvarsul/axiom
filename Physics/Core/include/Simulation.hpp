#pragma once
#include <vector>
#include <cstdint>

namespace Core {

struct Vector2D {
	float x = 0.0f;
	float y = 0.0f;
};

struct Drone {
	uint32_t id;
	Vector2D position;
	Vector2D velocity;
	float health;
	bool isActive;
};

struct Missile {
	uint32_t id;
	Vector2D position;
	Vector2D velocity;
	uint32_t targetId;
	bool isActive;
};

class Simulation {
private:
	std::vector<Drone> m_drones;
	std::vector<Missile> m_missiles;
	uint32_t m_nextEntityId = 1;

public:
	Simulation();
	void Init();

	void Update(float dt);

	void SpawnDrone(float x, float y, float vx, float vy);
	void SpawnMissile(float x, float y, uint32_t targetId);
	void DestroyDrone(uint32_t id);
	void CleanupDestroyedEntities();

	const std::vector<Drone>& GetDrones() const { return m_drones; }
	const std::vector<Missile>& GetMissiles() const { return m_missiles; }
};

}
