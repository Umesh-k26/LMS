#include "pch.h"
#include "profile_book.h"
#include "written_functions/delete_profile_func.h"
#include "written_functions/update_profile_func.h"
#include "fine_function.h"
/// <summary>
///Constructor calls for functions to Initialize all the components of the form
/// </summary>
///@see InitializeComponent()
LMS::profile_book::profile_book(void)
{
	InitializeComponent();
}

/// <summary>
///Constructor calls for functions to Initialize all the components of the form and make buttons visible based on the User being a librarian or not
/// </summary>
/// @see transfer_id_book, transfer_isLibrarian, InitializeComponent()
LMS::profile_book::profile_book(String^ label_book_id, bool isLibrarian)
{
	InitializeComponent();
	transfer_id_book = label_book_id;
	transfer_isLibrarian = isLibrarian;
	if (transfer_isLibrarian == false)
	{
		this->update_profile_button->Visible = false;
		this->delete_profile_button->Visible = false;
	}
	//fill_data_grid();
}

LMS::profile_book::~profile_book()
{
	if (components)
	{
		delete components;
	}
}

/// <summary>
/// It loads the Form in full screen mode and fills all the textboxes and fill the Data Grid
/// </summary>
/// @see filling_datagrid::fill_datagrid_book_profile()
System::Void LMS::profile_book::profile_book_Load(System::Object^ sender, System::EventArgs^ e)
{
	CenterToScreen();
	WindowState = FormWindowState::Maximized;

	//Creating a connection to database
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

	//This command returns details of Book of that Book ID
	MySqlCommand^ fill_data_cmdDataBase = gcnew MySqlCommand("SELECT * FROM library_system_db.book_data\
		WHERE book_id = " + transfer_id_book + ";", conDataBase);
	MySqlDataReader^ myReader;

	try {
		//Opens the Database connection
		conDataBase->Open();
		myReader = fill_data_cmdDataBase->ExecuteReader();

		String^ printing_name;
		String^ printing_id;
		String^ printing_author;
		String^ printing_publisher;
		String^ printing_price;
		String^ printing_edition_no;
		String^ printing_book_borrow_stat;
		String^ printing_category;
		//String^ printing_copies_avilable;
		//String^ printing_lost_stat;
		while (myReader->Read())
		{
			printing_id = myReader->GetString("book_id");
			printing_name = myReader->GetString("book_name");
			printing_author = myReader->GetString("book_author");
			printing_publisher = myReader->GetString("book_publisher");
			printing_price = myReader->GetString("book_price");
			printing_edition_no = myReader->GetString("book_edition_no");
			printing_book_borrow_stat = myReader->GetString("book_borrow_status");
			printing_category = myReader->GetString("category");
			//printing_copies_avilable = myReader->GetString("copies_available");
			//printing_lost_stat = myReader->GetString("book_lost");
			this->bookname_txt->Text = printing_name;
			this->book_id_txt->Text = printing_id;
			this->author_txt->Text = printing_author;
			this->publisher_txt->Text = printing_publisher;
			this->price_txt->Text = printing_price;
			this->edition_no_txt->Text = printing_edition_no;
			this->borrow_stat_txt->Text = printing_book_borrow_stat;
			this->category_txt->Text = printing_category;
			//this->copies_available_txt->Text = printing_copies_avilable;
			//this->book_lost_stat_text->Text = printing_lost_stat;
			//listBox1->Items->Add(printing_names);

		}
		//fill_data_grid();

		//Calls the function to fill datagrid with IDs of the copies of the book
		filling_datagrid::fill_datagrid_book_profile(this->bookname_txt->Text, book_copies_dataGridView, this->edition_no_txt->Text);


		int num_row = this->book_copies_dataGridView->RowCount;
		this->no_copies_txt->Text = num_row.ToString();

	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);
	}

	//Close the connection to DataBase
	conDataBase->Close();

	this->numeric_updown_no_copies->Value = 0;
}

/// <summary>
/// Button OnClick To Switch into Update Mode and make some Read-Only Fields as Re-Writable
/// </summary>
System::Void LMS::profile_book::update_profile_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Update Profile");
	this->numeric_updown_no_copies->Visible = true;
	this->confirm_change_button->Visible = true;
	this->update_profile_button->Visible = false;
}

/// <summary>
/// Button OnClick To Switch the particular copy to Lost and removed from showing in the list
/// </summary>
/// @see delete_profile_func::delete_book_profile(), fine_func::calculate_fine_lost_book()
System::Void LMS::profile_book::delete_profile_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Delete Profile");
	if (MessageBox::Show("The profile will be deleted. Do you want to contiue?", "Warning", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK)
	{
		//MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		//MySqlCommand^ update_lost_cmdDataBase = gcnew MySqlCommand("UPDATE library_system_db.book_data SET book_borrow_status = 'LOST' WHERE book_id = " + this->book_id_txt->Text + ";", conDataBase);

		//MySqlCommand^ update_no_copies_cmdDataBase = gcnew MySqlCommand("UPDATE library_system_db.book_data set copies_available = copies_available - 1, no_of_copies= no_of_copies-1 WHERE \
		//						book_name = '" + this->bookname_txt->Text + "'\
		//						AND book_author = '" + this->author_txt->Text + "'\
		//						AND book_publisher = '" + this->publisher_txt->Text + "'\
		//						AND book_edition_no = " + this->edition_no_txt->Text + ";", conDataBase);
		//try {
		//	conDataBase->Open();
		//	update_lost_cmdDataBase->ExecuteNonQuery();
		//	update_no_copies_cmdDataBase->ExecuteNonQuery();
		//	MessageBox::Show("Profile is deleted");
		//}
		//catch (Exception^ ex)
		//{
		//	MessageBox::Show(ex->Message);
		//}
		//conDataBase->Close();

		//Initializes the fine as price of book
		int total_fine = Int32::Parse(this->price_txt->Text);

		//Calculates the total fine to be paid by calling the function
		int fine_paid_lost_book = fine_func::calculate_fine_lost_book(total_fine);

		//IF block which checks that if the delete book profile function returns true then it shows message to pay the fine
		//ELSE it shows an error message
		if (delete_profile_func::delete_book_profile(this->book_id_txt->Text, this->borrow_stat_txt->Text, System::Convert::ToString(fine_paid_lost_book)) == true)
		{
			MessageBox::Show("Profile is deleted");
			MessageBox::Show("Pay Fine for the book: Rs " + System::Convert::ToString(fine_paid_lost_book));
		}
		else
		{
			MessageBox::Show("SOME ERROR HAS OCCURED IN DELETING BOOK PROFILE", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		//Closes the form and goes back to previous page
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	else
	{
		//do nothing
	}
}

/// <summary>
/// Button OnClick function to switch back into Read-Only Mode and updating the profile of the Book and changing it in the databse as well
/// </summary>
/// @see update_profile_func::update_book_profile()
System::Void LMS::profile_book::confirm_change_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->numeric_updown_no_copies->Visible = false;
	this->confirm_change_button->Visible = false;
	this->update_profile_button->Visible = true;

	//updating_no_of_copies((int)this->numeric_updown_no_copies->Value);
	//IF the number of books to be added is less than or equal to 0 then it shows message and nothing else
	if ((int)this->numeric_updown_no_copies->Value <= 0)
	{
		MessageBox::Show("" + (int)this->numeric_updown_no_copies->Value + "");
	}
	else
	{
		MessageBox::Show("" + (int)this->numeric_updown_no_copies->Value + "");
		//if (update_profile_func::update_book_profile(this->book_id_txt->Text, (int)this->numeric_updown_no_copies->Value, this->bookname_txt->Text, this->edition_no_txt->Text) == true)
		//IF the update profile book successfully updates the profile of the book then it shows message of success
		//ELSE it shows Error
		if (update_profile_func::update_book_profile(this->book_id_txt->Text, (int)this->numeric_updown_no_copies->Value) == true)
		{
			MessageBox::Show("New copies are added");
		}
		else
		{
			MessageBox::Show("SOME ERROR HAS OCCURED IN UPDATING BOOK PROFILE", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	//Reload the form to show new additions if there are any
	profile_book_Load(sender, e);
}

///// <summary>
///// Function to fill the Data Grid with the list of copies of the same book with general details
///// </summary>
//void LMS::profile_book::fill_data_grid()
//{
//
//	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
//	MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT book_id AS 'Book ID', book_name AS 'Name', book_author AS 'Author', book_edition_no AS 'Edition No', book_publisher AS 'Publisher', book_borrow_status AS 'Borrow Status' FROM library_system_db.book_data \
//			WHERE book_name = '" + this->bookname_txt->Text + "' AND book_edition_no = " + this->edition_no_txt->Text + " AND NOT book_borrow_status = 'LOST';", conDataBase);
//	try {
//		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
//		sda->SelectCommand = cmdDataBase;
//		DataTable^ dbdataset = gcnew DataTable();
//		sda->Fill(dbdataset);
//		BindingSource^ bSource = gcnew BindingSource();
//		bSource->DataSource = dbdataset;
//		book_copies_dataGridView->DataSource = bSource;
//		sda->Update(dbdataset);
//	}
//	catch (Exception^ ex)
//	{
//		MessageBox::Show(ex->Message);
//	}
//	conDataBase->Close();
//}

/// <summary>
/// Button OnClick function to Open Profile of other copy of the book with more details
/// </summary>
System::Void LMS::profile_book::book_copies_dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	//if the cell selected is the first cell of the row then it carries out the following process
	if (e->ColumnIndex == 0)
	{
		//=======================================================
		//This section converts the ID from the second column to String form to open profile

		int row_num = e->RowIndex;
		int col_num = e->ColumnIndex + 1;
		String^ str = this->book_copies_dataGridView->Rows[row_num]->Cells[col_num]->Value->ToString();

		//=======================================================

		MessageBox::Show("Your id is " + str);

		//Constructing profile form by passing the Book ID along with it as well as if the user is librarian or not
		LMS::profile_book^ profile_book_f = gcnew LMS::profile_book(str, transfer_isLibrarian);
		this->Hide();
		//profile_book_f->ShowDialog();

		//Hiding the current Form and opening the profile form and waits till the time the user clicks on back button
		if (profile_book_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			//When user clicks the back button in the Profile Form it closes that and then shows this form again and fills loads the form
			this->Show();
			filling_datagrid::fill_datagrid_book_profile(this->bookname_txt->Text, book_copies_dataGridView, this->edition_no_txt->Text);
		}

	}
}

/// <summary>
/// Function for Back Button which goes back to the previous Form by closing the current form
/// </summary>
System::Void LMS::profile_book::back_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}

///// <summary>
///// Function to be run after the Librarian wants to add more copies of the same book to the database
///// </summary>
//
//void LMS::profile_book::updating_no_of_copies(int num_new_copies)
//{
//	if (num_new_copies <= 0)
//	{
//		MessageBox::Show("" + num_new_copies + "");
//		return;
//	}
//	else
//	{
//		MessageBox::Show("" + num_new_copies + "");
//
//		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
//
//		MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand("INSERT INTO library_system_db.book_data \
//				(book_name, book_author, book_publisher, book_price,book_edition_no,no_of_copies, category) \
//				VALUES('" + this->bookname_txt->Text + "',\
//				'" + this->author_txt->Text + "',\
//				'" + this->publisher_txt->Text + "',\
//				'" + this->price_txt->Text + "',\
//				'" + this->edition_no_txt->Text + "',\
//				'" + this->no_copies_txt->Text + "',\
//				'" + this->category_txt->Text + "');", conDataBase);
//
//		MySqlCommand^ cmdDataBase2 = gcnew MySqlCommand("UPDATE library_system_db.book_data SET \
//				no_of_copies = no_of_copies + '" + num_new_copies + "'\
//				WHERE book_name = '" + this->bookname_txt->Text + "' AND \
//				book_edition_no = '" + this->edition_no_txt->Text + "';", conDataBase);
//
//		try {
//			conDataBase->Open();
//			for (int i = 0; i < num_new_copies; i++)
//				cmdDataBase1->ExecuteNonQuery();
//
//			MessageBox::Show("cmdb1 executed");
//			cmdDataBase2->ExecuteNonQuery();
//			MessageBox::Show("cmdb2 executed");
//			conDataBase->Close();
//		}
//		catch (Exception^ ex)
//		{
//			MessageBox::Show(ex->Message);
//		}
//		conDataBase->Close();
//	}
//}
