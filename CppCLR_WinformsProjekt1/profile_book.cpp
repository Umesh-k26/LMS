#include "pch.h"
#include "profile_book.h"

namespace CppCLR_WinformsProjekt1 {

	profile_book::profile_book(void)
	{
		InitializeComponent();
		//
		//TODO: Add the constructor code here
		//
		//fill_data_grid();
	}

	profile_book::profile_book(String^ label_book_id)
	{
		InitializeComponent();
		//
		//TODO: Add the constructor code here
		//
		transfer_id_book = label_book_id;
		//fill_data_grid();
	}

	profile_book::~profile_book()
	{
		if (components)
		{
			delete components;
		}
	}

	System::Void profile_book::profile_book_Load(System::Object^ sender, System::EventArgs^ e)
	{
		CenterToScreen();
		//FormBorderStyle = Windows::Forms::FormBorderStyle::None;
		WindowState = FormWindowState::Maximized;

		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		//MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from test.student_data WHERE username='" + this->username_txt->Text + "' and password = '" + this->password_txt->Text + "' ;", conDataBase);

		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT * FROM library_system.book_data\
		WHERE book_id = " + transfer_id_book + ";", conDataBase);
		MySqlDataReader^ myReader;

		try {
			conDataBase->Open();
			myReader = cmdDataBase->ExecuteReader();

			while (myReader->Read())
			{
				String^ printing_name;
				String^ printing_id;
				String^ printing_author;
				String^ printing_publisher;
				String^ printing_price;
				String^ printing_edition_no;
				String^ printing_book_borrow_stat;
				String^ printing_category;
				String^ printing_copies_avilable;
				printing_id = myReader->GetString("book_id");
				printing_name = myReader->GetString("book_name");
				printing_author = myReader->GetString("book_author");
				printing_publisher = myReader->GetString("book_publisher");
				printing_price = myReader->GetString("book_price");
				printing_edition_no = myReader->GetString("book_edition_no");
				printing_book_borrow_stat = myReader->GetString("book_borrow_status");
				printing_category = myReader->GetString("category");
				printing_copies_avilable = myReader->GetString("copies_available");
				this->bookname_txt->Text = printing_name;
				this->book_id_txt->Text = printing_id;
				this->author_txt->Text = printing_author;
				this->publisher_txt->Text = printing_publisher;
				this->price_txt->Text = printing_price;
				this->edition_no_txt->Text = printing_edition_no;
				this->borrow_stat_txt->Text = printing_book_borrow_stat;
				this->category_txt->Text = printing_category;
				this->copies_available_txt->Text = printing_copies_avilable;
				//listBox1->Items->Add(printing_names);

			}
			fill_data_grid();
			int num_row = this->dataGridView1->RowCount;
			this->no_copies_txt->Text = num_row.ToString();

		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
	}

	System::Void profile_book::update_profile_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		MessageBox::Show("Update Profile");
		this->numeric_updown_no_copies->Visible = true;
		this->confirm_change_button->Visible = true;
		this->update_profile_button->Visible = false;
	}

	System::Void profile_book::delete_profile_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		MessageBox::Show("Delete Profile");
		if (MessageBox::Show("The profile will be deleted. Do you want to contiue?", "Warning", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK)
		{
			MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
			MySqlCommand^ cmdDataBase = gcnew MySqlCommand("DELETE FROM library_system.book_data WHERE book_id = " + this->book_id_txt->Text + ";", conDataBase);
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
			//do nothing
		}
	}

	System::Void profile_book::confirm_change_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->numeric_updown_no_copies->Visible = false;
		this->confirm_change_button->Visible = false;
		this->update_profile_button->Visible = true;

		updating_no_of_copies((int)this->numeric_updown_no_copies->Value);
		profile_book_Load(sender, e);
	}

	void profile_book::fill_data_grid()
	{

		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT book_id, book_name, book_author, book_edition_no, book_publisher, book_borrow_status FROM library_system.book_data WHERE book_name = '" + this->bookname_txt->Text + "' AND book_edition_no = " + this->edition_no_txt->Text + ";", conDataBase);
		MySqlDataReader^ myReader;
		//
		//
		//	THIS PART IS NOT FILLING THE DATA PROPERLY IN DATAGRIDVIEW NEED TO CHECK
		//


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

	System::Void profile_book::dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) 
	{
		if (e->ColumnIndex == 0)
		{
			int row_num = e->RowIndex;
			int col_num = e->ColumnIndex + 1;
			String^ str = this->dataGridView1->Rows[row_num]->Cells[col_num]->Value->ToString();
			MessageBox::Show("Your id is " + str);
			CppCLR_WinformsProjekt1::profile_book^ profile_book_f = gcnew CppCLR_WinformsProjekt1::profile_book(str);
			this->Hide();
			//profile_book_f->ShowDialog();

			if (profile_book_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				this->Show();
			}

		}
	}

	System::Void profile_book::back_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}

	void profile_book::updating_no_of_copies(int num_new_copies)
	{
		if (num_new_copies <= 0)
		{
			MessageBox::Show("" + num_new_copies + "");
			return;
		}
		else
		{
			MessageBox::Show("" + num_new_copies + "");

			MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

			MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand("INSERT INTO library_system.book_data \
			(book_name, book_author, book_publisher, book_price,book_edition_no,no_of_copies, category) \
			VALUES('" + this->bookname_txt->Text + "',\
			'" + this->author_txt->Text + "',\
			'" + this->publisher_txt->Text + "',\
			'" + this->price_txt->Text + "',\
			'" + this->edition_no_txt->Text + "',\
			'" + this->no_copies_txt->Text + "',\
			'" + this->category_txt->Text + "');", conDataBase);

			MySqlCommand^ cmdDataBase2 = gcnew MySqlCommand("UPDATE library_system.book_data SET \
			no_of_copies = no_of_copies + '" + num_new_copies + "' WHERE book_name = '" + this->bookname_txt->Text + "' AND \
			book_edition_no = '" + this->edition_no_txt->Text + "';", conDataBase);

			try {
				conDataBase->Open();
				for (int i = 0; i < num_new_copies; i++)
					cmdDataBase1->ExecuteNonQuery();

				MessageBox::Show("cmdb1 executed");
				cmdDataBase2->ExecuteNonQuery();
				MessageBox::Show("cmdb2 executed");
				conDataBase->Close();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}
	}

}

