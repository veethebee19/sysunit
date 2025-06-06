/*-
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2018 Ryan Stone
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "sysunit/Initializer.h"
#include "sysunit/TestSuite.h"

#include <vector>
#include <cstdio>
#include <typeinfo>

namespace SysUnit {

	namespace {
		struct InitializerComp
		{
			bool operator()(const Initializer * l, const Initializer * r) const
			{
				return *l < *r;
			}
		};

		typedef std::vector<Initializer*> InitList;

		InitList & GetInitList()
		{
			static InitList initList;

			return initList;
		}

		bool initialized = false;
	}

	Initializer::Initializer(int subsystem, int order)
	  : subsystem(subsystem),
	    order(order)
	{
		if (initialized)
			throw std::runtime_error("Initializer registered too late");
		GetInitList().push_back(this);
	}

	void TestSuite::SetUp()
	{
		printf("TestSuite::SetUp() CALLED. Initializer list size: %zu\n", GetInitList().size());
		auto & initList(GetInitList());
		std::sort(initList.begin(), initList.end(), InitializerComp());

		printf("--- Initializer List Contents (Sorted) ---\n");
		for (auto * init : initList) {
			//printf("  Initializer: Subsystem: %d, Order: %d, Object address: %p",
			//		               init->subsystem, init->order, (void*)init);
			printf(" (Type: %s)", typeid(*init).name());
			printf("\n");
			init->SetUp();
		}
		initialized = true;

		TestCaseSetUp();
	}

	void TestSuite::TearDown()
	{
		TestCaseTearDown();

		for (auto it = GetInitList().rbegin();
		    it != GetInitList().rend(); ++it)
		     (*it)->TearDown();
	}

	void TestSuite::TestCaseSetUp()
	{
	}

	void TestSuite::TestCaseTearDown()
	{
	}
}
