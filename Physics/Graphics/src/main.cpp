#include <print>
#include "Simulation.hpp"
int main() {
	std::println("[Graphics] Booting application...");

	Core::Simulation sim;
	sim.Init();
	
	sim.SpawnDrone(0.0f, 0.0f, 10.0f, 0.0f);
	sim.SpawnDrone(0.0f, 50.0f, 5.0f, 0.0f);
	sim.SpawnDrone(0.0f, 100.0f, 2.0f, 0.0f);
	sim.SpawnMissile(50.0f, 50.0f, 1);

	constexpr float DELTA_TIME = 0.016f;

	std::println("\n--- Starting Simulation Loop ---");

	for (int frame = 1; frame <= 5; ++frame) {
		if (frame == 3) {
			std::println(">>> HIT DETECTED ! Destroying ID 2 <<<");
			sim.DestroyDrone(2);
		}

		sim.Update(DELTA_TIME);

		std::println("Frame {}:", frame);

		for (const auto& drone : sim.GetDrones()) {
			if (drone.isActive) {
				std::println(" Drone ID {}: Pos({:.3f}, {:.3f})", drone.id,drone.position.x, drone.position.y);
			}
		}
	}

	std::println("--- Simulation Finished ---");
	return 0;
}
