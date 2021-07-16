#pragma once

#include "Functions/fine_function.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace MySql::Data::MySqlClient;
using namespace NUnit::Framework;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace Microsoft::VisualStudio::TestTools;

namespace Test_Namespace1 {
	[TestFixture]
	public ref class TestClass1
	{
	public:
		[Test]
		void fine_method_test() {
			int expected = 2;
			int actual = fine_func::calculate_fine(1,3,"Faculty");

			NUnit::Framework::Assert::AreEqual(expected, actual);


		}

		[Test]
		void method2()
		{


		}
	
	};
}
