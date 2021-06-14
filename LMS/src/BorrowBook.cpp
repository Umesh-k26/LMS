#include "pch.h"
#include "BorrowBook.h"

/// <summary>
/// Constructor calls for functions to Initialize all the components of the form
///@see InitializeComponent()
/// </summary>
LMS::BorrowBook::BorrowBook(void)
{
	InitializeComponent();
}



LMS::BorrowBook :: ~BorrowBook()
{
	if (components)
	{
		delete components;
	}
}

/// <summary>
/// It loads the Form in full screen mode 
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
System::Void LMS::BorrowBook::BorrowBook_Load(System::Object^ sender, System::EventArgs^ e)
{
	CenterToScreen();
	WindowState = FormWindowState::Maximized;
}


/// <summary>
/// It checks 
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
System::Void LMS::BorrowBook::borrow_button_Click(System::Object^ sender, System::EventArgs^ e)
{

	String^ Book_status;
	String^ Book_name;
	String^ Book_author;
	String^ Book_publisher;
	int Book_edition_no;
	int copies_available;

	String^ connect_database = sql_connection_func::sql_user_pass_string();
	MySqlConnection^ conDataBase = gcnew MySqlConnection(connect_database);

	MySqlCommand^ member_data = gcnew MySqlCommand("SELECT * FROM library_system_db.member_data \
		WHERE member_id = '" + this->member_id_txt->Text + \
		"';", conDataBase);


	MySqlDataReader^ myReader;


	try {
		conDataBase->Open();
		myReader = member_data->ExecuteReader();

		String^ membership_status;

		int count1 = 0, count2 = 0;
		while (myReader->Read())
		{
			count1 += 1;
			membership_status = myReader->GetString("membership_stat");
		}
		if (count1 == 0)
		{
			MessageBox::Show("Member not found with given Member id .");
		}
		else if (count1 == 1)
		{

			if (membership_status == "ACTIVATED")
			{
				MySqlCommand^ book_data = gcnew MySqlCommand("SELECT * FROM library_system_db.book_data \
                WHERE book_id = '" + this->book_id_txt->Text + \
					"';", conDataBase);

				myReader->Close();
				myReader = book_data->ExecuteReader();

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

						MySqlCommand^ Update_book_data_borrow_status = gcnew MySqlCommand("UPDATE  library_system_db.book_data set\
                     book_borrow_status = 'BORROWED' WHERE \
                     book_id ='" + this->book_id_txt->Text + "'\
                      ;", conDataBase);


						MySqlCommand^ Update_member_data = gcnew MySqlCommand("UPDATE library_system_db.member_data set\
                     member_no_book_stat = member_no_book_stat +1 WHERE \
                     member_id ='" + this->member_id_txt->Text + "' ;", conDataBase);


						MySqlCommand^ Insert_borrow_history = gcnew MySqlCommand("INSERT INTO library_system_db.borrow_history \
	                 (book_id, member_id,date_issue) \
	                 VALUES('" + this->book_id_txt->Text + "',\
	                 '" + this->member_id_txt->Text + "',\
	                 CURDATE());", conDataBase);



						MySqlCommand^ borrow_history_data = gcnew MySqlCommand("SELECT * FROM  library_system_db.borrow_history \
	                 WHERE  book_id ='" + this->book_id_txt->Text + "'\
                     AND member_id = '" + this->member_id_txt->Text + "'\
	                 AND date_issue = CURDATE()\
	                 ; ", conDataBase);

						//Below query updates borrow_status(coloumn) in book data (table) and in member_data(table) updates no_borrowed_books (coloumn)
						Update_book_data_borrow_status->ExecuteNonQuery();

						//Below Query updates member_data ,increases no_copies _borrowed by 1
						Update_member_data->ExecuteNonQuery();


						//Below query updates borrow_history(table) inserts new row for this order.
						Insert_borrow_history->ExecuteNonQuery();

						MySqlCommand^ Update_book_data_copies_available = gcnew MySqlCommand("UPDATE  library_system_db.book_data set copies_available = copies_available -1 WHERE book_name ='" + Book_name + "'\
                             AND book_author ='" + Book_author + "' \
                             AND book_publisher ='" + Book_publisher + "'\
                             AND book_edition_no ='" + Book_edition_no + "' \
                             ;", conDataBase);

						Update_book_data_copies_available->ExecuteNonQuery(); // updates copies__available(coloumn) in book data (table)

						myReader = borrow_history_data->ExecuteReader();

						int orderid;

						while (myReader->Read())
						{
							orderid = myReader->GetInt32("order_id");
						}
						MessageBox::Show("Borrowed book successfully! \nBook_id = " + this->book_id_txt->Text + " \nMember_id = " + this->member_id_txt->Text + " \nOrder_id = " + orderid);
						myReader->Close();


					}


					else if (Book_status == "BORROWED")
					{
						if (copies_available > 0)
							MessageBox::Show("Same Book is available , but with different book id");
						else if (copies_available == 0)
							MessageBox::Show("Book is Not available ");

					}

					else if (Book_status == "LOST")
					{
						if (copies_available > 0)
							MessageBox::Show("Same Book is available , but with different book id");
						else if (copies_available == 0)
							MessageBox::Show("Book is Not available ");

					}
				}

				else if (count2 > 1)
				{
					MessageBox::Show("Duplicate ID's of same book_id detected. Please resolve before updating.");
				}

			}

			else if (membership_status == "DEACTIVATED")
			{
				MessageBox::Show("MemberShip of member with given member_id is Deactivated");
			}

		}
		else if (count1 > 1)
		MessageBox::Show("Duplicate ID's of same member_id detected. Please resolve before updating.");
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);

	}

}

/// <summary>
/// Function for Back Button which goes back to the previous Form by closing the current form
/// </summary>
System::Void LMS::BorrowBook::Back_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}
