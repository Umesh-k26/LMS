#include "pch.h"
#include "BorrowBook.h"

namespace CppCLR_WinformsProjekt1 {
	BorrowBook::BorrowBook(void)
	{
		InitializeComponent();
	}
	BorrowBook::BorrowBook(String^ input_transfer_id, bool is_librarian_input)
	{
		InitializeComponent();
		transfer_id = input_transfer_id;
		is_librarian = is_librarian_input;
	}
	BorrowBook::~BorrowBook()
	{
		if (components)
		{
			delete components;
		}
	}

	System::Void BorrowBook::BorrowBook_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		WindowState = FormWindowState::Maximized;
	}

	System::Void BorrowBook::borrow_button_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ Book_status;
		String^ Book_name;
		String^ Book_author;
		String^ Book_publisher;
		int Book_edition_no;
		int copies_available;

		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

		MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand("SELECT * FROM library_system.student_data WHERE student_id = '" + this->stud_id_txt->Text + "';", conDataBase);
		MySqlCommand^ cmdDataBase2 = gcnew MySqlCommand("SELECT * FROM library_system.book_data WHERE book_id = '" + this->book_id_txt->Text + "';", conDataBase);
		MySqlCommand^ cmdDataBase3 = gcnew MySqlCommand("UPDATE  library_system.book_data set\
     book_borrow_status = 'BORROWED' WHERE \
     book_id ='" + this->book_id_txt->Text + "' ; \
     UPDATE library_system.student_data set\
     student_no_book_stat = student_no_book_stat +1 WHERE \
     student_id ='" + this->stud_id_txt->Text + "' ", conDataBase);

		MySqlCommand^ cmdDataBase5 = gcnew MySqlCommand("INSERT INTO library_system.borrow_history \
		(book_id, student_id,date_issue) \
		VALUES('" + this->book_id_txt->Text + "',\
		'" + this->stud_id_txt->Text + "',\
		CURDATE());", conDataBase);

		MySqlCommand^ cmdDataBase6 = gcnew MySqlCommand("SELECT * FROM  library_system.borrow_history \
			WHERE  book_id ='" + this->book_id_txt->Text + "'\
            AND student_id = '" + this->stud_id_txt->Text + "'\
			AND date_issue = CURDATE()\
			; ", conDataBase);

		MySqlDataReader^ myReader;


		try {
			conDataBase->Open();
			myReader = cmdDataBase1->ExecuteReader();

			int count1 = 0, count2 = 0;
			while (myReader->Read())
			{
				count1 += 1;
			}
			if (count1 == 0)
			{
				MessageBox::Show("Student not found with given student id .");
			}
			else if (count1 == 1)
			{
				myReader->Close();
				myReader = cmdDataBase2->ExecuteReader();

				while (myReader->Read())
				{
					count2 += 1;
					Book_status = myReader->GetString("book_borrow_status");
					Book_name = myReader->GetString("book_name");
					Book_author = myReader->GetString("book_author");
					Book_publisher = myReader->GetString("book_publisher");
					Book_edition_no = myReader->GetInt32("book_edition_no");
					copies_available = myReader->GetInt32("copies_available");
				}
				if (count2 == 0)
				{
					MessageBox::Show("Book not found with given book id .");
				}
				else if (count2 == 1)
				{
					if (Book_status == "AVAILABLE")
					{

						myReader->Close();

						//Below query updates borrow_status(coloumn) in book data (table) and in student_data(table) updates no_borrowed_books (coloumn)
						cmdDataBase3->ExecuteNonQuery();

						//Below query updates borrow_history(table) inserts new row for this order.
						cmdDataBase5->ExecuteNonQuery();

						MySqlCommand^ cmdDataBase4 = gcnew MySqlCommand("UPDATE  library_system.book_data set copies_available = copies_available -1 WHERE book_name ='" + Book_name + "'\
                             AND book_author ='" + Book_author + "' \
                             AND book_publisher ='" + Book_publisher + "'\
                             AND book_edition_no ='" + Book_edition_no + "' \
                             ;", conDataBase);

						cmdDataBase4->ExecuteNonQuery(); // updates copies__available(coloumn) in book data (table)

						myReader = cmdDataBase6->ExecuteReader();

						int orderid;

						while (myReader->Read())
						{
							orderid = myReader->GetInt32("order_id");
						}
						MessageBox::Show("Borrowed book successfully! \n book_id = '" + this->book_id_txt->Text + "',student_id = '" + this->stud_id_txt->Text + "',order_id = " + orderid);
						myReader->Close();


					}


					else if (Book_status == "BORROWED")
					{
						if (copies_available > 0)
							MessageBox::Show("Same Book is available , but with different book id");
						else if (copies_available == 0)
							MessageBox::Show("Book is Not available ");

					}

				}

				else if (count2 > 1)
					MessageBox::Show("Duplicate ID's of same book_id detected. Please resolve before updating.");

			}
			else if (count1 > 1)
				MessageBox::Show("Duplicate ID's of same student_id detected. Please resolve before updating.");
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	System::Void BorrowBook::BackButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}

}