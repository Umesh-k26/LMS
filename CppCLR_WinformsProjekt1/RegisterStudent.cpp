#include "pch.h"
#include "RegisterStudent.h"

namespace CppCLR_WinformsProjekt1 {
	RegisterStudent::RegisterStudent(void)
	{
		InitializeComponent();
	}
	RegisterStudent::RegisterStudent(String^ input_transfer_id, bool is_librarian_input)
	{
		InitializeComponent();
		transfer_id = input_transfer_id;
		is_librarian = is_librarian_input;
	}
	RegisterStudent::~RegisterStudent()
	{
		if (components)
		{
			delete components;
		}
	}

	System::Void RegisterStudent::RegisterStudent_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		WindowState = FormWindowState::Maximized;
	}

	System::Void RegisterStudent::RegisterStudent_Click(System::Object^ sender, System::EventArgs^ e) {

		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

		MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand("INSERT INTO library_system.student_data (student_name, student_dob, student_address, student_email, \
		student_mobile, student_profession, student_no_book_stat,student_fine, student_gender) \
		VALUES('" + this->name_txt->Text + "',\
		'" + this->dateTimePicker->Text + "',\
		'" + this->address_txt->Text + "',\
		'" + this->email_id_txt->Text + "',\
		" + this->mobile_no_txt->Text + ",\
		'" + this->profession_comboBox->Text + "',\
		" + this->status_no_txt->Text + ", 0, '" + Gender + "')	;", conDataBase);

		MySqlCommand^ cmdDataBase2 = gcnew MySqlCommand("USE library_system;INSERT INTO user_pass (student_id, user_password) \
		VALUES((SELECT student_id FROM student_data WHERE student_email = '" + this->email_id_txt->Text + "'), \
		'" + this->password_txt->Text + "');", conDataBase);

		MySqlCommand^ cmdDataBase3 = gcnew MySqlCommand("SELECT * FROM library_system.student_data \
	    WHERE student_email = '" + this->email_id_txt->Text + "';", conDataBase);

		MySqlDataReader^ myReader;
		try {
			conDataBase->Open();

			while (true)
			{
				if (String::Equals(this->password_txt->Text, this->re_password_txt->Text))
				{
					cmdDataBase1->ExecuteNonQuery();
					cmdDataBase2->ExecuteNonQuery();
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

			MessageBox::Show("Student registered successfully!");

			myReader = cmdDataBase3->ExecuteReader();

			if (myReader->Read())
			{
				int student_id = myReader->GetInt32("student_id");
				MessageBox::Show("Your id is " + student_id);
			}
			myReader->Close();

			this->name_txt->Text = "";
			this->dateTimePicker->Text = "";
			this->address_txt->Text = "";
			this->email_id_txt->Text = "";
			this->mobile_no_txt->Text = "";
			this->profession_comboBox->Text = nullptr;
			this->status_no_txt->Text = "";
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

	System::Void RegisterStudent::BackButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
}

