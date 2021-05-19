#include "pch.h"
#include "RegisterLibrarian.h"
#include "connection_sql_func.h"

namespace CppCLR_WinformsProjekt1 {
	RegisterLibrarian::RegisterLibrarian(void)
	{
		InitializeComponent();
	}
	RegisterLibrarian::RegisterLibrarian(String^ input_transfer_id, bool is_librarian_input)
	{
		transfer_id = input_transfer_id;
		is_librarian = is_librarian_input;
		InitializeComponent();
	}
	RegisterLibrarian::~RegisterLibrarian()
	{
		if (components)
		{
			delete components;
		}
	}

	System::Void RegisterLibrarian::RegisterLibrarian_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		WindowState = FormWindowState::Maximized;
	}

	System::Void RegisterLibrarian::RegisterLibrarian_Click(System::Object^ sender, System::EventArgs^ e) {

		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand("INSERT INTO library_system.library_user_pass \
		VALUES('" + this->librarian_username_txt->Text + "',\
		'" + this->password_txt->Text + "',\
		'" + this->name_txt->Text + "',\
		'" + this->dateTimePicker->Text + "',\
		'" + this->address_txt->Text + "',\
		'" + this->email_id_txt->Text + "',\
		'" + this->mobile_no_txt->Text + "',\
		'" + Gender + "')	;", conDataBase);

		MySqlCommand^ cmdDataBase2 = gcnew MySqlCommand("SELECT * FROM library_system.library_user_pass \
	    WHERE library_username = '" + this->librarian_username_txt->Text + "';", conDataBase);

		MySqlDataReader^ myReader;
		try {
			conDataBase->Open();
			while (true)
			{
				if (String::Equals(this->password_txt->Text, this->re_password_txt->Text))
				{
					cmdDataBase1->ExecuteNonQuery();
					break;
				}
				else
				{
					MessageBox::Show("Re-enter same password");
					this->password_txt->Text = "";
					this->re_password_txt->Text = "";
					return;
				}
			}

			MessageBox::Show("Librarian registered successfully!");

			myReader = cmdDataBase2->ExecuteReader();

			if (myReader->Read())
			{
				MessageBox::Show("Your username is " + myReader->GetString("library_username"));
			}
			myReader->Close();

			this->name_txt->Text = "";
			this->librarian_username_txt->Text = "";
			this->dateTimePicker->Text = "";
			this->address_txt->Text = "";
			this->email_id_txt->Text = "";
			this->mobile_no_txt->Text = "";
			this->password_txt->Text = "";
			this->re_password_txt->Text = "";
			this->male_rbtn->Checked = false;
			this->female_rbtn->Checked = false;

		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
		conDataBase->Close();
	}

	System::Void RegisterLibrarian::BackButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
}

