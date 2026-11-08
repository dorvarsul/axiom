#include "Simulation.hpp"
#include <print>

namespace Core {
Simulation::Simulation() {
	m_drones.reserve(10000);
	m_missiles.reserve(10000);
}

void Simulation::Init() {
	std::println("[Core] Physics Engine Initialized successfully.");
}

void Simulation::SpawnDrone(float x, float y, float vx, float vy) {
	m_drones.push_back({
		.id = m_nextEntityId++,
		.position = {x, y},
		.velocity = {vx, vy},
		.health = 100.0f,
		.isActive = true
	});
}

void Simulation::SpawnMissile(float x, float y, uint32_t targetId) {
	m_missiles.push_back({
		.id = m_nextEntityId++,
		.position = {x, y},
		.velocity = {0.0f, 0.0f},
		.targetId = targetId,
		.isActive = true
	});
}

void Simulation::DestroyDrone(uint32_t id) {
	for (auto& drone : m_drones) {
		if (drone.id == id) {
			drone.isActive = false;
			break;
		}
	}
}

void Simulation::CleanupDestroyedEntities() {
	for (size_t i = 0; i < m_drones.size();) {
		if (!m_drones[i].isActive) {
			m_drones[i] = m_drones.back();
			m_drones.pop_back();
		} else {
			++i;
		}
	}

	for (size_t i = 0; i < m_missiles.size(); ) {
		if (!m_missiles[i].isActive) {
			m_missiles[i] = m_missiles.back();
			m_missiles.pop_back();
		} else{
			++i;
		}
	}
}

void Simulation::Update(float dt) {
	for (auto& drone : m_drones) {
		if (!drone.isActive) continue;

		drone.position.x += drone.velocity.x * dt;
		drone.position.y += drone.velocity.y * dt;
	}

	for (auto& missile : m_missiles) {
		if (!missile.isActive) continue;

		missile.position.x += missile.velocity.x * dt;
		missile.position.y += missile.velocity.y * dt;
	}

	CleanupDestroyedEntities();
}
}
