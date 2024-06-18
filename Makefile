clean:
	rm -rf build
build:
	bash -c scripts/cmake.sh
run:
	build/stopwatch
