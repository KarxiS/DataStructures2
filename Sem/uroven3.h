#include <libds/amt/explicit_hierarchy.h>
#include <libds/adt/table.h>
#include "Data.h"
#pragma once
class uroven3
{
public:
	ds::amt::ImplicitSequence<Data*> vektorObce ;
	ds::amt::ImplicitSequence<Data*> vektorKraje;
	ds::amt::ImplicitSequence<Data*> vektorOkresy;

	using tabulkaData = ds::adt::SortedSequenceTable<std::string, ds::amt::ImplicitSequence<Data*>*>*;
	tabulkaData tabulkaKraj= new ds::adt::SortedSequenceTable<std::string, ds::amt::ImplicitSequence<Data*>*>();
	tabulkaData tabulkaOkres = new ds::adt::SortedSequenceTable<std::string, ds::amt::ImplicitSequence<Data*>*>();
	tabulkaData tabulkaKObec = new ds::adt::SortedSequenceTable<std::string, ds::amt::ImplicitSequence<Data*>*>();


	using tabulkaSekvencii = ds::adt::SortedSequenceTable<std::string, ds::amt::ImplicitSequence<Data*>*>*;
	auto main() -> int;
	tabulkaSekvencii naplnTabulku(tabulkaSekvencii tabulka, ds::amt::ImplicitSequence<Data*> sekvenciaObjektov);
	~uroven3();
};

