#include "DataGenerator.h"
#include "Random.h"

void generateData(int* toFill, int length) {
	Random r(length);
	for (int i = 0; i < length; i++) {
		toFill[i] = r.give();
	}
	return;
}