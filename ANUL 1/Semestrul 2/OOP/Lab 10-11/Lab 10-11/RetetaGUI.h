#pragma once
#include "FilteredMedsGUI.h"
#include<vector>

class RetetaGUI : public FilteredMedsGUI {
public:
	RetetaGUI(std::vector<Medicament> meds) :FilteredMedsGUI{ meds } {};
};