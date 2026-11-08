.PHONY: all config build run clean

all: config build run
config:
	@echo "==> Configuring project..."
	cmake -B build -S . -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	ln -sf build/compile_commands.json

build:
	@echo "==> Building project..."
	cmake --build build -j$(nproc)

run:
	@echo "==> Running SimulationApp..."
	./build/Graphics/SimulationApp

clean:
	@echo "==> Cleaning build files..."
	rm -rf build compile_commands.json
