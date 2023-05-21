#include <libds/amt/explicit_hierarchy.h>
#include "Data.h"
#include <cstdio>
#include <fstream>
#include <vector>
#include "Okres.h"
#include "Obec.h"
#include "Kraj.h"
#include "Data.h"
#include <libds/amt/implicit_sequence.h>

#pragma once
class nacitavacNezamestnanosti
{
private:
	ifstream handler;
public:
	nacitavacNezamestnanosti(std::string subor);
	void nacitajDoHierarchie(ds::amt::MultiWayExplicitHierarchy<Data>& hierarchia);
};

