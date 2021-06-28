#include "pch.h"
#include "ReturnBook.h"

/// <summary>
///Constructor calls for functions to Initialize all the components of the form
///@see InitializeComponent()
/// </summary>
LMS::ReturnBook::ReturnBook(void)
{
	InitializeComponent();
}

LMS::ReturnBook :: ~ReturnBook()
{
	if (components)
	{
		delete components;
	}
}


/// <summary>
/// It loads the Form in full screen mode 
/// </summary>
System::Void LMS::ReturnBook::ReturnBook_Load(System::Object^ sender, System::EventArgs^ e)
{
	CenterToScreen();
	WindowState = FormWindowState::Maximized;
}


/// <summary>
/// Function to return Book by checking order_id and borrow_Status of Book
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>

System::Void LMS::ReturnBook::return_button_Click(System::Object^ sender, System::EventArgs^ e)
{

	String^ connect_database = sql_connection_func::sql_user_pass_string();
	MySqlConnection^ conDataBase = gcnew MySqlConnection(connect_database);

	MySqlCommand^ Order_data = gcnew MySqlCommand("SELECT * FROM library_system_db.borrow_history WHERE\
     order_id = '" + this->order_id_txt->Text + "';", conDataBase);

	MySqlDataReader^ myReader;

	int Book_id;
	int Member_id;
	String^ Book_name;
	String^ Book_author;
	String^ Book_publisher;
	int Book_edition_no;

	try {
		conDataBase->Open();
		myReader = Order_data->ExecuteReader();

		int count = 0;
		String^ Borrow_status;

		while (myReader->Read())
		{
			count += 1;
			Borrow_status = myReader->GetString("borrow_status");
			Book_id = myReader->GetInt32("book_id");
			Member_id = myReader->GetInt32("member_id");
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
				MySqlCommand^ Book_data = gcnew MySqlCommand("SELECT * FROM library_system_db.book_data WHERE book_id ='" + Book_id + "';", conDataBase);

				int count1 = 0;
				myReader = Book_data->ExecuteReader();
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

					MySqlCommand^ Member_data = gcnew MySqlCommand("SELECT * FROM library_system_db.member_data \
                    WHERE member_id ='" + Member_id + "';", conDataBase);


					myReader = Member_data->ExecuteReader();


					int count2 = 0;
					String^ profession;
					while (myReader->Read())
					{
						count2 += 1;
						profession = myReader->GetString("member_profession");
					}
					myReader->Close();
					if (count2 == 0)
					{
						MessageBox::Show("student who borrowed  book with given order_id is not found. Please resolve before updating.");
					}

					else if (count2 == 1)
					{
						MySqlCommand^ Update_borrow_history_data = gcnew MySqlCommand("UPDATE library_system_db.borrow_history set \
                       date_returned = CURDATE(),borrow_status = 'RETURNED'\
		               WHERE order_id = '" + this->order_id_txt->Text + "';", conDataBase);


						//Below Query Updates Borrow_history (Table) except fine coloumn
						Update_borrow_history_data->ExecuteNonQuery();

						int order_id = Convert::ToInt32(this->order_id_txt->Text);
						int fine = fine_func::calculate_fine(order_id, Member_id, profession);

						MySqlCommand^ Update_book_data = gcnew MySqlCommand("UPDATE library_system_db.book_data \
                       set book_borrow_status = 'AVAILABLE' \
                       WHERE book_id = " + Book_id + " ;", conDataBase);

						MySqlCommand^ Update_member_data = gcnew MySqlCommand("UPDATE  library_system_db.member_data\
                       set member_no_book_stat = member_no_book_stat - 1,\
					   member_fine = member_fine + '" + fine + "' \
                       WHERE member_id ='" + Member_id + "';", conDataBase);

						MySqlCommand^ Update_borrow_history_fine = gcnew MySqlCommand("UPDATE library_system_db.borrow_history set \
                       borrow_fine= '" + fine + "'\
		               WHERE order_id = '" + this->order_id_txt->Text + "';", conDataBase);


						//Below Query Updates Book_data (Table) {increases copies_available by 1 for all copies and book_borrow_Status = AVAILABLE for partciular book id}
						Update_book_data->ExecuteNonQuery();

						//Below Query Updates member_data(Table)
						Update_member_data->ExecuteNonQuery();

						//Below Query Updates fine coloumn in borrow_history by using fine function
						Update_borrow_history_fine->ExecuteNonQuery();

						MessageBox::Show("Returned book successfully! \nBook_id = " + Book_id + " \nMember_id = " + Member_id + " \nOrder_id = " + this->order_id_txt->Text + " ");
					}
				}
			}
			else
				MessageBox::Show("borrow_status is neither 'BORROWED' nor 'RETURNED' of given order_id, detected. Please resolve before updating.");
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);

	}
}


/// <summary>
/// Function for Back Button which goes back to the previous Form by closing the current form
/// </summary>
System::Void LMS::ReturnBook::Back_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}
