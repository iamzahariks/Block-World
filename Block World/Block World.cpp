#include <iostream>
#include "GameFlow/Libraries.h"
#include "GameFlow/Classes/Init.h"
#include "GameFlow/Services/Input/InputService.h"

// Launch Templates
void Init();
//

int main() {
	Init();
	std::cout << Blocks::GetBlockById("Grass")->GetTimeToDestroy(1) << std::endl;
	return 0;
}

void Init() {
	Blocks::Init();
}