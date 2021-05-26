#include "pch.h"
#include "profile_student.h"

namespace CppCLR_WinformsProjekt1 {

	///Constructor calls for functions to Initialize all the components of the form
	///@see InitializeComponent()
	profile_student::profile_student(void)
	{
		InitializeComponent();
	}

	/// <summary>
	///Constructor calls for functions to Initialize all the components of the form
	/// </summary>
	/// @see transfer_id, is_librarian, InitializeComponent()
	profile_student::profile_student(String^ input_id_transfer, bool is_librarian_input)
	{
		InitializeComponent();
		transfer_id = input_id_transfer;
		is_librarian = is_librarian_input;
	}

	profile_student::~profile_student()
	{
		if (components)
		{
			delete components;
		}
	}

	/// <summary>
	/// It loads the Form in full screen mode and fills all the textboxes and fill the Data Grid
	/// </summary>
	System::Void profile_student::profile_student_Load(System::Object^ sender, System::EventArgs^ e)
	{
		CenterToScreen();
		//FormBorderStyle = Windows::Forms::FormBorderStyle::None;
		WindowState = FormWindowState::Maximized;

		if (is_librarian == false)
		{
			this->delete_profile_button->Visible = false;
		}
		else
		{
			this->delete_profile_button->Visible = true;
		}

		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT * FROM library_system.student_data\
		WHERE student_id = " + transfer_id + ";", conDataBase);
		MySqlDataReader^ myReader;
		try {
			conDataBase->Open();
			myReader = cmdDataBase->ExecuteReader();

			String^ printing_name;
			String^ printing_id;
			String^ printing_profession;
			String^ printing_email;
			String^ printing_mobile;
			String^ printing_address;
			//String^ printing_dob;
			String^ printing_member_stat;
			while (myReader->Read())
			{
				
				printing_id = myReader->GetString("student_id");
				printing_name = myReader->GetString("student_name");
				printing_profession = myReader->GetString("student_profession");
				printing_email = myReader->GetString("student_email");
				printing_mobile = myReader->GetString("student_mobile");
				printing_address = myReader->GetString("student_address");
				printing_member_stat = myReader->GetString("membership_stat");
				user_no_book_stat = myReader->GetInt32("student_no_book_stat");

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
				this->member_stat_text->Text = printing_member_stat;
			}
			fill_data_grid();

		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
		conDataBase->Close();
	}

	/// <summary>
	/// Button OnClick To Switch into Update Mode and make some Read-Only Fields as Re-Writable
	/// </summary>
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

	/// <summary>
	/// Button OnClick To Deactivate the Membership of the User, upon passing through checks if the User as returned all the books
	/// </summary>
	System::Void profile_student::delete_profile_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (user_no_book_stat > 0)
		{
			MessageBox::Show("Cannot delete since he/she hasn't returned all the books borrowed.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		MessageBox::Show("Delete Profile");
		if (MessageBox::Show("The profile will be deleted. Do you want to contiue?", "Warning", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK)
		{
			MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
			//MySqlCommand^ cmdDataBase = gcnew MySqlCommand("DELETE FROM library_system.student_data WHERE student_id = " + this->student_id_txt->Text + ";", conDataBase);
			MySqlCommand^ update_member_stat_cmdDataBase = gcnew MySqlCommand("UPDATE library_system.student_data set student_id = " + this->student_id_txt->Text + ", membership_stat = 'DEACTIVATED' WHERE student_id = " + this->student_id_txt->Text + ";", conDataBase);
			MySqlCommand^ delete_user_pass_cmdDataBase = gcnew MySqlCommand("DELETE FROM library_system.user_pass WHERE student_id = " + this->student_id_txt->Text + ";", conDataBase);

			try {
				conDataBase->Open();
				update_member_stat_cmdDataBase->ExecuteNonQuery();
				delete_user_pass_cmdDataBase->ExecuteNonQuery();
				MessageBox::Show("Profile is deleted");
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
			conDataBase->Close();
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
		else
		{
			//Do nothing
		}

	}

	/// <summary>
	/// Button OnClick function to switch back into Read-Only Mode and updating the profile of the User and changing it in the databse as well
	/// </summary>
	System::Void profile_student::confirm_change_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		MessageBox::Show("Changes made");


		this->profession_txt->Text = this->profession_selector->Text;
		this->dob_student_txt->Text = this->dateTimePicker->Text;


		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("UPDATE library_system.student_data set student_id = \
		" + this->student_id_txt->Text + ",student_name = '" + this->name_txt->Text + "',student_dob = '" + this->dob_student_txt->Text + "', student_profession = '" + this->profession_txt->Text + "', student_email='" + this->email_id_txt->Text + "', student_mobile=" + this->mobile_no_txt->Text + ", student_address = '" + this->address_txt->Text + "'WHERE student_id = " + this->student_id_txt->Text + ";", conDataBase);

		try {
			conDataBase->Open();
			cmdDataBase->ExecuteNonQuery();
			MessageBox::Show("Profile is updated");
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
		//profile_student(transfer_id);
		profile_student_Load(sender, e);

		conDataBase->Close();
	}

	/// <summary>
	/// Function to fill the Data Grid with the list of the books the User has Borrowed with some general details
	/// </summary>
	void profile_student::fill_data_grid()
	{

		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		//MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT * FROM library_system.borrow_history WHERE student_id = " + this->student_id_txt->Text + " AND borrow_status = 'BORROWED';", conDataBase);
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT * FROM library_system.borrow_history WHERE student_id = " + this->student_id_txt->Text + ";", conDataBase);
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
		conDataBase->Close();
	}

	/// <summary>
	/// Function for Back Button which goes back to the previous Form by closing the current form
	/// </summary>
	System::Void profile_student::back_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}

	/// <summary>
	/// Button OnClick function to Open Profile of Book Borrowed and Book Borrower along with their details
	/// </summary>
	System::Void profile_student::dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
	{
		if (e->ColumnIndex == 0)
		{
			int row_num = e->RowIndex;
			int col_num = e->ColumnIndex + 1;
			String^ str = this->dataGridView1->Rows[row_num]->Cells[col_num]->Value->ToString();
			MessageBox::Show("Your id is " + str);
			CppCLR_WinformsProjekt1::profile_order^ profile_order_f = gcnew CppCLR_WinformsProjekt1::profile_order(str);
			this->Hide();

			if (profile_order_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				this->Show();
			}

		}
	}

}