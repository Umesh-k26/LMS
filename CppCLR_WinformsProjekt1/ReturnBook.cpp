#include "pch.h"
#include "ReturnBook.h"

namespace CppCLR_WinformsProjekt1 {
	ReturnBook::ReturnBook(void)
	{
		InitializeComponent();
	}
	ReturnBook::ReturnBook(String^ input_transfer_id, bool is_librarian_input)
	{
		InitializeComponent();
		transfer_id = input_transfer_id;
		is_librarian = is_librarian_input;
	}
	ReturnBook::~ReturnBook()
	{
		if (components)
		{
			delete components;
		}
	}

	System::Void ReturnBook::ReturnBook_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		WindowState = FormWindowState::Maximized;
	}
	System::Void ReturnBook::return_button_Click(System::Object^ sender, System::EventArgs^ e) {

		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand("SELECT * FROM library_system.borrow_history WHERE order_id = '" + this->order_id_txt->Text + "';", conDataBase);

		MySqlDataReader^ myReader;

		int Book_id;
		int Student_id;
		String^ Book_name;
		String^ Book_author;
		String^ Book_publisher;
		int Book_edition_no;

		try {
			conDataBase->Open();
			myReader = cmdDataBase1->ExecuteReader();

			int count = 0;
			String^ Borrow_status;

			while (myReader->Read())
			{
				count += 1;
				Borrow_status = myReader->GetString("borrow_status");
				Book_id = myReader->GetInt32("book_id");
				Student_id = myReader->GetInt32("student_id");
			}
			myReader->Close();
			if (count == 0)
			{
				MessageBox::Show("Order not found with given Order id .");
			}
			else if (count == 1)
			{
				if (Borrow_status == "RETURNED")
					MessageBox::Show("Book with given Order id is already Returned! .Please resolve if any before updating");

				else if (Borrow_status = "BORROWED")
				{
					MySqlCommand^ cmdDataBase2 = gcnew MySqlCommand("SELECT * FROM library_system.book_data WHERE book_id ='" + Book_id + "';", conDataBase);

					int count1 = 0;
					myReader = cmdDataBase2->ExecuteReader();
					while (myReader->Read())
					{
						count1 += 1;
						Book_name = myReader->GetString("book_name");
						Book_author = myReader->GetString("book_author");
						Book_publisher = myReader->GetString("book_publisher");
						Book_edition_no = myReader->GetInt32("book_edition_no");
					}
					myReader->Close();
					if (count1 == 0)
						MessageBox::Show("Book id of Borrowed book with given order_id is not found. Please resolve before updating.");
					else if (count1 == 1)
					{

						myReader->Close();
						MySqlCommand^ cmdDataBase3 = gcnew MySqlCommand("SELECT * FROM library_system.student_data \
                       WHERE student_id ='" + Student_id + "';", conDataBase);
						myReader = cmdDataBase3->ExecuteReader();

						int count2 = 0;
						String^ profession;
						while (myReader->Read())
						{
							count2 += 1;
							profession = myReader->GetString("student_profession");
						}
						myReader->Close();
						if (count2 == 0)
						{
							MessageBox::Show("student who borrowed  book with given order_id is not found. Please resolve before updating.");
						}

						else if (count2 == 1)
						{
							MySqlCommand^ cmdDataBase4 = gcnew MySqlCommand("UPDATE library_system.borrow_history set \
                       date_returned = CURDATE(),borrow_status = 'RETURNED'\
		               WHERE order_id = '" + this->order_id_txt->Text + "';", conDataBase);


							//Below Query Updates Borrow_history (Table) except fine coloumn
							cmdDataBase4->ExecuteNonQuery();

							int order_id = Convert::ToInt32(this->order_id_txt->Text);
							int fine = extra_func::calculate_fine(order_id, Student_id, profession);

							MySqlCommand^ cmdDataBase5 = gcnew MySqlCommand("UPDATE library_system.book_data set copies_available = copies_available +1 WHERE \
                       book_name = '" + Book_name + "'\
                       AND book_author = '" + Book_author + "'\
                       AND book_publisher = '" + Book_publisher + "'\
                       AND book_edition_no = " + Book_edition_no + "\
                       ; UPDATE library_system.book_data set book_borrow_status = 'AVAILABLE' WHERE book_id = " + Book_id + " ;", conDataBase);

							MySqlCommand^ cmdDataBase6 = gcnew MySqlCommand("UPDATE  library_system.student_data\
                       set student_no_book_stat = student_no_book_stat - 1,student_fine = student_fine + '" + fine + "' \
                       WHERE student_id ='" + Student_id + "';", conDataBase);

							MySqlCommand^ cmdDataBase7 = gcnew MySqlCommand("UPDATE library_system.borrow_history set \
                       borrow_fine= '" + fine + "'\
		               WHERE order_id = '" + this->order_id_txt->Text + "';", conDataBase);


							//Below Query Updates Book_data (Table) {increases copies_available by 1 for all copies and book_borrow_Status = AVAILABLE for partciular book id}
							cmdDataBase5->ExecuteNonQuery();

							//Below Query Updates student_data(Table)
							cmdDataBase6->ExecuteNonQuery();

							//Below Query Updates fine coloumn in borrow_history by using fine function
							cmdDataBase7->ExecuteNonQuery();

							MessageBox::Show("Returned book successfully! \n book_id = " + Book_id + ",student_id = " + Student_id + ",order_id = " + this->order_id_txt->Text + " ");
						}
					}
					else if (count1 > 1)
						MessageBox::Show("Duplicate ID's of same book_id detected. Please resolve before updating.");

				}
				else
					MessageBox::Show("borrow_status is neither 'BORROWED' nor 'RETURNED' of given order_id, detected. Please resolve before updating.");
			}
			else if (count > 1)
				MessageBox::Show("Duplicate ID's of same order_id detected. Please resolve before updating.");
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
	}

	System::Void ReturnBook::BackButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
}

