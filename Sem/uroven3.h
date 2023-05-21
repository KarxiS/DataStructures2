#include <libds/amt/explicit_hierarchy.h>
#include <libds/adt/table.h>
#include "Data.h"
#pragma once
class uroven3
{
public:
	using tabulkaSekvencii = ds::adt::SortedSequenceTable<std::string, ds::amt::ImplicitSequence<Data*>*>*;
	auto main() -> int;
	tabulkaSekvencii naplnTabulku(tabulkaSekvencii tabulka, ds::amt::ImplicitSequence<Data*> sekvenciaObjektov);
};

