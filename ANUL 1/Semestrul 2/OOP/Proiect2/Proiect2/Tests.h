#pragma once
#include "Domain.h"
#include "Repo.h"
#include "qassert.h"
#include "Service.h"
class Tests
{
private:
	void testDomain();
	void testRepo();
	void testService();
public:
	void testAll();
};

