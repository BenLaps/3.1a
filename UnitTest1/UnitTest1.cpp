#include "pch.h"
#include "CppUnitTest.h"
#include "../3.1a/3.1a.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int N = 1;
			Student* s = new Student[N];
			s->lastname = "Protsak";
			s->cours = 2;
			s->spec = "it";
			s->physic = 5;
			s->informatic = 5;
			s->math = 5;
			
			Assert::IsTrue(Count(s, N) >0);
		}
	};
}
