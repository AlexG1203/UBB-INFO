#include "validator.h"

void MedicamentValidator::validate(Medicament& medicament)
{
	string msg = "";
	if (medicament.getDenumire().length() == 0) msg += "denumire invalida!\n";
	if (medicament.getPret() < 0)msg += "pret invalid!\n";
	if (medicament.getProducator().length() == 0)msg += "producator invalid!\n";
	if (medicament.getSubstantaActiva().length() == 0)msg += "substanta activa invalida!\n";
	if (msg.length() > 0)throw ValidateException(msg);
}
