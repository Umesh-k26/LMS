#include "pch.h"
#include "login_to_librarian_db.h"
#include "connection_sql_func.h"

namespace connection_to_librarian_db {
	bool is_librarian(String^ username_input, String^ password_input)
	{
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT * FROM library_system.library_user_pass WHERE \
	    library_username='" + username_input + "' and library_password = '" + password_input + "' ;", conDataBase);

		MySqlDataReader^ myReader;
		try {
			conDataBase->Open();
			myReader = cmdDataBase->ExecuteReader();
			int count = 0;
			while (myReader->Read())
			{
				count += 1;
			}
			if (count == 1)
			{
				//
				//	IN FORM 1 IF THIS IS TRUE THEN OPEN FORM 2 WITH ALL BUTTONS ALLOWED FOR LIBRARAIN
				//
				MessageBox::Show("You are librarian");
				return true;
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
		conDataBase->Close();
		return false;
	}
}
