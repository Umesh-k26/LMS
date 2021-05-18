#include "pch.h"
#include "AddBook.h"

namespace CppCLR_WinformsProjekt1 {
	AddBook::AddBook(void)
	{
		InitializeComponent();
	}
	AddBook::~AddBook()
	{
		if (components)
		{
			delete components;
		}
	}

	System::Void AddBook::AddBook_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		WindowState = FormWindowState::Maximized;
	}

	System::Void AddBook::AddBook_Click(System::Object^ sender, System::EventArgs^ e) {
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

		MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand("INSERT INTO library_system.book_data \
		(book_name, book_author, book_publisher, book_price,book_edition_no,no_of_copies, category, copies_available) \
		VALUES('" + this->bookname_txt->Text + "',\
		'" + this->author_txt->Text + "',\
		'" + this->publisher_txt->Text + "',\
		'" + this->price_txt->Text + "',\
		'" + this->edition_no_txt->Text + "',\
		'" + this->no_of_copies_txt->Text + "',\
		'" + this->category_txt->Text + "',\
		'" + this->no_of_copies_txt->Text + "'	);", conDataBase);

		MySqlCommand^ cmdDataBase2 = gcnew MySqlCommand("SELECT * FROM library_system.book_data WHERE (book_name = '" + this->bookname_txt->Text + "' \
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

	System::Void AddBook::BackButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
}
