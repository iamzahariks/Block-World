#include <iostream>
#include "Content/RootInitializer.h"

int main() {
	Content::Init();
	std::cout << Services::BlockService::GetBlockById("Grass")->GetTimeToDestroy(1) << std::endl;
	return 0;
}