#include "pch.h"
#include "AddBook.h"
#include "connection_sql_func.h"

namespace LMS {

	///Constructor calls for functions to Initialize all the components of the form
	///@see InitializeComponent(),
	AddBook::AddBook(void)
	{
		InitializeComponent();
	}

	/// <summary>
	///Constructor calls for functions to Initialize all the components of the form
	/// </summary>
	/// @see transfer_id, is_librarian, InitializeComponent()
	AddBook::AddBook(String^ input_transfer_id, bool is_librarian_input)
	{
		InitializeComponent();
		transfer_id = input_transfer_id;
		is_librarian = is_librarian_input;
	}

	AddBook::~AddBook()
	{
		if (components)
		{
			delete components;
		}
	}

	/// <summary>
	/// It loads the Form in full screen mode and displays TextBoxes for user input
	/// </summary>
	System::Void AddBook::AddBook_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		WindowState = FormWindowState::Maximized;
	}

	/// <summary>
	/// Button OnClick to Add Books into Library Database
	/// </summary>
	System::Void AddBook::AddBook_Click(System::Object^ sender, System::EventArgs^ e) {
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

		MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand("INSERT INTO library_system_db.book_data \
		(book_name, book_author, book_publisher, book_price,book_edition_no, category) \
		VALUES('" + this->bookname_txt->Text + "',\
		'" + this->author_txt->Text + "',\
		'" + this->publisher_txt->Text + "',\
		'" + this->price_txt->Text + "',\
		'" + this->edition_no_txt->Text + "',\
		'" + this->category_txt->Text + "');", conDataBase);

		MySqlCommand^ cmdDataBase2 = gcnew MySqlCommand("SELECT * FROM library_system_db.book_data WHERE (book_name = '" + this->bookname_txt->Text + "' \
		AND book_edition_no = " + this->edition_no_txt->Text + ");", conDataBase);
		MySqlDataReader^ myReader;
		try {
			conDataBase->Open();

			int copies_no = System::Convert::ToInt32(this->no_of_copies_txt->Text);
			for (int i = 0; i < copies_no; i++)
				cmdDataBase1->ExecuteNonQuery();

			MessageBox::Show("Book(s) added successfully!");

			int db_count = 0;
			myReader = cmdDataBase2->ExecuteReader();
			while (myReader->Read())
			{
				int book_id = myReader->GetInt32("book_id");
				id_listbox->Items->Add(book_id);
				db_count++;
			}
			id_listbox->Items->Add("No. of books added = " + db_count);
			myReader->Close();
			this->id_listbox->Visible = true;
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
	System::Void AddBook::BackButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
}
