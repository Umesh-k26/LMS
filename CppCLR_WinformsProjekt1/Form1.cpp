#include "pch.h"
#include "Form1.h"

namespace CppCLRWinformsProjekt {
	Form1::Form1(void)
	{
		InitializeComponent();
	}
	Form1::~Form1()
	{
		if (components)
		{
			delete components;
		}
	}

	System::Void Form1::LoginButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (connection_to_librarian_db::is_librarian(this->username_txt->Text, this->password_txt->Text) == true)
		{
			MessageBox::Show("Username and password is correct");

			CppCLR_WinformsProjekt1::Form2^ f2 = gcnew CppCLR_WinformsProjekt1::Form2(this->username_txt->Text, true);
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

					CppCLR_WinformsProjekt1::Form2^ f2 = gcnew CppCLR_WinformsProjekt1::Form2(this->username_txt->Text, false);
					this->Hide();
					if (f2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					{
						this->username_txt->Text = "";
						this->password_txt->Text = "";
						this->Show();

					}
				}
				else if(count == 0)
					MessageBox::Show("Username and password is incorrect ...Please try again");
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}
	}

	System::Void Form1::Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		WindowState = FormWindowState::Maximized;
	}
}

