#pragma once
#include <cstdio>
#include <fstream>
#include <vector>
#include "Okres.h"
#include "Obec.h"
#include "Kraj.h"
#include "Data.h"
#include <libds/amt/implicit_sequence.h>
using namespace std;
class Nacitavac
{

	private:
		ifstream handler;
	public:
		Nacitavac(string menoSuboru);
		void setMenoSuboru(string menoSuboru);

		ds::amt::ImplicitSequence<Data> dajData();
		ds::amt::ImplicitSequence<Data*> dajDataSmernik();
		
		

		~Nacitavac();

		

	


		
		

};

