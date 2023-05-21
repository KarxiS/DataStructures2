
#include <libds/amt/implicit_sequence.h>
#include "Data.h"
#pragma once
class uroven1
{
public :
	using strukturaData = ds::amt::ImplicitSequence<Data>;
	auto main() -> int;
	void vypisStrukturu(strukturaData& struktura);
	void vynulujStrukturu(strukturaData& struktura);
};

