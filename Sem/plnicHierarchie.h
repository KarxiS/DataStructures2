#pragma once
#include <libds/amt/explicit_hierarchy.h>
#include "Data.h"
class plnicHierarchie
{
public:
	ds::amt::MultiWayExplicitHierarchy<Data>& hierarchiaLocal;
	plnicHierarchie(ds::amt::MultiWayExplicitHierarchy<Data>& hierarchia);
	void naplnKraje(ds::amt::ImplicitSequence<Data> vektorKraje);
	void naplnOkresy(ds::amt::ImplicitSequence<Data> vektorOkresy);
	void naplnObce(ds::amt::ImplicitSequence<Data> vektorObce);
	ds::amt::MultiWayExplicitHierarchy<Data>& getHierar();
};

