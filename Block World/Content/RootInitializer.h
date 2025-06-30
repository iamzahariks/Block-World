#include "Libraries.h"
#include "Classes/Init.h"
#include "Services/Init.h"

namespace Content {
	void Init() {
		Services::BlockService::Init();
		Services::ItemsService::Init();
	}
}