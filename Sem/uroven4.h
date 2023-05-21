#include <libds/amt/explicit_hierarchy.h>
#include "Data.h"
#pragma once
class uroven4
{
public:
	using strukturaData = ds::amt::ImplicitSequence<Data>;
	auto main() -> int;
	void vypisStrukturu(strukturaData& struktura);
	void vynulujStrukturu(strukturaData& struktura);
};

