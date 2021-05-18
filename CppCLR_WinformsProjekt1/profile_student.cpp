#include "pch.h"
#include "profile_student.h"

namespace CppCLR_WinformsProjekt1 {

	profile_student::profile_student(void)
	{
		InitializeComponent();
		//
		//TODO: Add the constructor code here
		//
	}

	profile_student::profile_student(String^ label_text_id)
	{
		InitializeComponent();
		transfer_id_student = label_text_id;
		//
		//TODO: Add the constructor code here
		//
	}

	profile_student::~profile_student()
	{
		if (components)
		{
			delete components;
		}
	}

	System::Void profile_student::profile_student_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		CenterToScreen();
		//FormBorderStyle = Windows::Forms::FormBorderStyle::None;
		WindowState = FormWindowState::Maximized;
		//this->label1->Text = list_of_students_page::global_student_id_passed;
		//this->label1->Text = transfer_id_student;

		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT * FROM library_system.student_data\
		WHERE student_id = " + transfer_id_student + ";", conDataBase);
		MySqlDataReader^ myReader;
		try {
			conDataBase->Open();
			myReader = cmdDataBase->ExecuteReader();

			while (myReader->Read())
			{
				String^ printing_name;
				String^ printing_id;
				String^ printing_profession;
				String^ printing_email;
				String^ printing_mobile;
				String^ printing_address;
				//String^ printing_dob;
				printing_id = myReader->GetString("student_id");
				printing_name = myReader->GetString("student_name");
				printing_profession = myReader->GetString("student_profession");
				printing_email = myReader->GetString("student_email");
				printing_mobile = myReader->GetString("student_mobile");
				printing_address = myReader->GetString("student_address");
				//printing_dob = myReader->GetString("student_dob");

				MySql::Data::Types::MySqlDateTime new_dob;
				new_dob = myReader->GetMySqlDateTime("student_dob");
				this->name_txt->Text = printing_name;
				this->student_id_txt->Text = printing_id;
				this->email_id_txt->Text = printing_email;
				this->mobile_no_txt->Text = printing_mobile;
				this->address_txt->Text = printing_address;

				//this->dob_student_txt->Text = printing_dob;
				this->dob_student_txt->Text = new_dob.ToString();

				this->profession_txt->Text = printing_profession;
				//listBox1->Items->Add(printing_names);

				this->dateTimePicker->Value = new_dob.GetDateTime();

			}
			fill_data_grid();

		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
	}

	System::Void profile_student::update_profile_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		MessageBox::Show("Update profile");
		//this->dob_student_txt->Visible = false;
		this->update_profile_button->Visible = false;
		this->confirm_change_button->Visible = true;
		this->dateTimePicker->Visible = true;
		this->name_txt->ReadOnly = false;
		this->profession_txt->ReadOnly = true;
		this->email_id_txt->ReadOnly = false;
		this->mobile_no_txt->ReadOnly = false;
		this->address_txt->ReadOnly = false;
		this->profession_selector->Visible = true;
		this->profession_selector->Text = this->profession_txt->Text;

	}

	System::Void profile_student::delete_profile_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		MessageBox::Show("Delete Profile");
		if (MessageBox::Show("The profile will be deleted. Do you want to contiue?", "Warning", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK)
		{
			MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
			MySqlCommand^ cmdDataBase = gcnew MySqlCommand("DELETE FROM library_system.student_data WHERE student_id = " + this->student_id_txt->Text + ";", conDataBase);
			MySqlDataReader^ myReader;
			try {
				conDataBase->Open();
				myReader = cmdDataBase->ExecuteReader();
				MessageBox::Show("Profile is deleted");
				while (myReader->Read())
				{

				}


			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);

			}
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
		else
		{
			//Do nothing
		}
	}

	System::Void profile_student::confirm_change_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		MessageBox::Show("Changes made");


		this->profession_txt->Text = this->profession_selector->Text;
		this->dob_student_txt->Text = this->dateTimePicker->Text;


		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("UPDATE library_system.student_data set student_id = \
		" + this->student_id_txt->Text + ",student_name = '" + this->name_txt->Text + "',student_dob = '" + this->dob_student_txt->Text + "', student_profession = '" + this->profession_txt->Text + "', student_email='" + this->email_id_txt->Text + "', student_mobile=" + this->mobile_no_txt->Text + ", student_address = '" + this->address_txt->Text + "'WHERE student_id = " + this->student_id_txt->Text + ";", conDataBase);
		MySqlDataReader^ myReader;
		try {
			conDataBase->Open();
			myReader = cmdDataBase->ExecuteReader();
			MessageBox::Show("Profile is updated");
			while (myReader->Read())
			{

			}


		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
		//this->dob_student_txt->Visible = true;
		this->update_profile_button->Visible = true;
		this->confirm_change_button->Visible = false;
		this->dateTimePicker->Visible = false;
		this->name_txt->ReadOnly = true;
		this->profession_txt->ReadOnly = true;
		this->email_id_txt->ReadOnly = true;
		this->mobile_no_txt->ReadOnly = true;
		this->address_txt->ReadOnly = true;
		this->profession_selector->Visible = false;
		//this->Refresh();
		//profile_student(transfer_id_student);
		profile_student_Load(sender, e);
		//
		//	FORM NOT RELOADING OVER HERE NEED TO FIX
		//

	}

	void profile_student::fill_data_grid() {

		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT * FROM library_system.borrow_history WHERE student_id = " + this->student_id_txt->Text + " AND borrow_status = 'BORROWED';", conDataBase);
		MySqlDataReader^ myReader;
		//student_id,student_name,student_mobile, student_profession, student_no_book_stat 
		try {
			MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
			sda->SelectCommand = cmdDataBase;
			DataTable^ dbdataset = gcnew DataTable();
			sda->Fill(dbdataset);
			BindingSource^ bSource = gcnew BindingSource();
			bSource->DataSource = dbdataset;
			dataGridView1->DataSource = bSource;
			sda->Update(dbdataset);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}

	}

	System::Void profile_student::back_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}

}