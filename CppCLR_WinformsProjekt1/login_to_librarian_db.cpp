#include "pch.h"
#include "login_to_librarian_db.h"
#include "connection_sql_func.h"

namespace connection_to_librarian_db {
	bool is_librarian(String^ username_input, String^ password_input)
	{
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from test.student_data WHERE \
	    username='" + username_input + "' and password = '" + password_input + "' ;", conDataBase);

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
				/*MessageBox::Show("Username and password is correct");

				CppCLR_WinformsProjekt1::Form2^ f2 = gcnew CppCLR_WinformsProjekt1::Form2;
				this->Hide();
				if (f2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					this->username_txt->Text = "";
					this->password_txt->Text = "";
					this->Show();

				}*/
				//
				//	IN FORM 1 IF THIS IS TRUE THEN OPEN FORM 2 WITH ALL BUTTONS ALLOWED FOR LIBRARAIN
				//

				return true;

			}
			/*else if (count > 1)
			{
				MessageBox::Show("Duplicate username and password ...Access denied");
			}
			else
				MessageBox::Show("Username and password is incorrect ...Please try again");
			*/

		}
		catch (Exception^ ex)
		{
			//MessageBox::Show(ex->Message);

		}
		return false;
	}
}
