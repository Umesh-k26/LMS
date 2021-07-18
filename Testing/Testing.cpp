#include "pch.h"

#include "Testing.h"
#include "Functions/connection_sql_func.h"
#include "Functions/delete_profile_func.h"
#include "Functions/login_to_librarian_db.h"
#include "Functions/update_profile_func.h"

namespace Test_Connection_SQL {
	[TestFixture]
	public ref class TestHashFunctionClass
	{
	public:
		[Test]
		void hash_function_test() {
			String^ expected = "A8-2D-54-E8-1D-57-E6-A2-B4-6E-73-0E-01-F7-CA-47";
			String^ actual = sql_connection_func::password_hasher("kevin", "P@ssword");

			NUnit::Framework::Assert::AreEqual(expected, actual);

		}

	};
}

namespace Test_Delete_Func {
	[TestFixture]
	public ref class TestDeleteFunctions {
	public:

		[Test]
		void delete_member_profile_test() {
			bool expected = true;
			bool actual = LMS::dbInteract::delete_member_profile("8");
			NUnit::Framework::Assert::AreEqual(expected, actual);
		}

		[Test]
		void delete_book_profile_test() {
			bool expected = true;
			bool actual = LMS::dbInteract::delete_book_profile("49", "BORROWED", "900");
			NUnit::Framework::Assert::AreEqual(expected, actual);
		}
	};
}

namespace Test_Fine_Func {
	[TestFixture]
	public ref class TestFineFunction {
	public:
		[Test]
		void calculate_fine_test() {
			int expected = 2420;
			int actual = fine_func::calculate_fine(1, 3, "Faculty");

			NUnit::Framework::Assert::AreEqual(expected, actual);
		}
	};
}

namespace Test_Login_Librarian {
	[TestFixture]
	public ref class TestLoginLibrarian {
	public:
		[Test]
		void login_librarian_db_test() {
			bool expected = true;
			bool actual = connection_to_librarian_db::is_librarian("admin2", "admin2");

			NUnit::Framework::Assert::AreEqual(expected, actual);
		}
	};
}

namespace Test_Update_Profile_func {
	[TestFixture]
	public ref class TestUpdateProfile {
	public:
		[Test]
		void update_book_profile_test() {
			bool expected = true;
			bool actual = LMS::dbInteract::update_book_profile("55", 1);
			NUnit::Framework::Assert::AreEqual(expected, actual);
		}
	};
}