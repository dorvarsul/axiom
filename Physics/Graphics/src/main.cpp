#include <print>
#include "Simulation.hpp"
int main() {
	std::println("[Graphics] Booting application...");

	Core::Simulation sim;
	sim.Init();
	
	return 0;
}
