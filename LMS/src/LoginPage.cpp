#include "pch.h"
#include "LoginPage.h"
#include "HomePage.h"

namespace LMS {
	LoginPage::LoginPage(void)
	{
		InitializeComponent();
	}
	LoginPage::~LoginPage()
	{
		if (components)
		{
			delete components;
		}
	}

	System::Void LoginPage::LoginButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//***********************************************************************************************
		//UNCOMMENT line no : 24 to 73 AFTER CREATING 'connection_to_librarian_db', 'sql_connection_func' namespaces
		//***********************************************************************************************

		/*if (connection_to_librarian_db::is_librarian(this->username_txt->Text, this->password_txt->Text) == true)
		{
			MessageBox::Show("Username and password is correct");

			LMS::HomePage^ f2 = gcnew LMS::HomePage(this->username_txt->Text, true);
			this->Hide();
			if (f2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				this->username_txt->Text = "";
				this->password_txt->Text = "";
				this->Show();
			}
		}
		else
		{
			MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
			MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from library_system.user_pass WHERE \
				student_id='" + this->username_txt->Text + "' and user_password = '" + this->password_txt->Text + "' ;", conDataBase);

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
					MessageBox::Show("Username and password is correct");

					LMS::HomePage^ f2 = gcnew LMS::HomePage(this->username_txt->Text, false);
					this->Hide();
					if (f2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					{
						this->username_txt->Text = "";
						this->password_txt->Text = "";
						this->Show();

					}
				}
				else if (count == 0)
					MessageBox::Show("Username and password is incorrect ...Please try again");
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}*/

		//*****************************************************************
		//DELETE line no : 79 to 113 after above part is uncommented
		//*****************************************************************

		String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from library_system.user_pass WHERE \
				student_id='" + this->username_txt->Text + "' and user_password = '" + this->password_txt->Text + "' ;", conDataBase);

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
				MessageBox::Show("Username and password is correct");

				LMS::HomePage^ f2 = gcnew LMS::HomePage();
				this->Hide();
				if (f2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					this->username_txt->Text = "";
					this->password_txt->Text = "";
					this->Show();

				}
			}
			else if (count == 0)
				MessageBox::Show("Username and password is incorrect ...Please try again");
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	System::Void LoginPage::LoginPage_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		WindowState = FormWindowState::Maximized;
	}
}

