#include "pch.h"
#include "Return_book_functions.h"
#include "connection_sql_func.h"

namespace Return_book_functions {



	String^ Get_Borrow_status(int Order_Id)
	{
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlDataReader^ myReader;

		String^ Borrow_status;

		try
		{
			conDataBase->Open();

			MySqlCommand^ Order_data = gcnew MySqlCommand("SELECT * FROM library_system_db.borrow_history WHERE\
                     order_id = '" + Order_Id + "';", conDataBase);

			myReader = Order_data->ExecuteReader();

			while (myReader->Read())
			{
				Borrow_status = myReader->GetString("borrow_status");
			}
			myReader->Close();
			conDataBase->Close();

			return Borrow_status;
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}

	}



	bool check_Order_Id(int Order_Id)
	{

		bool return_value = false;

		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlDataReader^ myReader;

		String^ Borrow_status;

		try
		{
			conDataBase->Open();

			MySqlCommand^ Order_data = gcnew MySqlCommand("SELECT * FROM library_system_db.borrow_history WHERE\
                     order_id = '" + Order_Id + "';", conDataBase);

			myReader = Order_data->ExecuteReader();

			while (myReader->Read())
			{
				Borrow_status = myReader->GetString("borrow_status");
			}
			myReader->Close();
			conDataBase->Close();

			if (Borrow_status == "BORROWED" || Borrow_status == "RETURNED" || Borrow_status == "LOST")
			{
				return_value = true;
			}

			return return_value;
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	String^ Get_Profession(int Member_Id)
	{
		String^ Profession;

		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlDataReader^ myReader;


		try
		{
			conDataBase->Open();
			MySqlCommand^ Member_data = gcnew MySqlCommand("SELECT * FROM library_system_db.member_data WHERE\
                          member_id = '" + Member_Id + "';", conDataBase);

			myReader = Member_data->ExecuteReader();

			while (myReader->Read())
			{
				Profession = myReader->GetString("member_profession");
			}
			myReader->Close();
			conDataBase->Close();

			return Profession;
		}

		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}

	}

	int Get_Member_Id(int Order_Id)
	{
		int Member_Id;

		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlDataReader^ myReader;

		try
		{
			conDataBase->Open();
			MySqlCommand^ Order_data = gcnew MySqlCommand("SELECT * FROM library_system_db.borrow_history WHERE\
                          order_id = '" + Order_Id + "';", conDataBase);

			myReader = Order_data->ExecuteReader();

			while (myReader->Read())
			{
				Member_Id = myReader->GetInt32("member_id");
			}
			myReader->Close();
			conDataBase->Close();

			return Member_Id;

		}

		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}

	}

	int Get_Book_Id(int Order_Id)
	{
		int Book_Id;

		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlDataReader^ myReader;

		try
		{
			conDataBase->Open();
			MySqlCommand^ Order_data = gcnew MySqlCommand("SELECT * FROM library_system_db.borrow_history WHERE\
                          order_id = '" + Order_Id + "';", conDataBase);

			myReader = Order_data->ExecuteReader();

			while (myReader->Read())
			{
				Book_Id = myReader->GetInt32("book_id");
			}
			myReader->Close();
			conDataBase->Close();

			return Book_Id;

		}

		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}

	}

	void Updata_Borrow_history_data(int Order_Id)
	{
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

		try
		{
			conDataBase->Open();

			MySqlCommand^ Update_date_Borrow_status = gcnew MySqlCommand("UPDATE library_system_db.borrow_history set \
                       date_returned = CURDATE(),borrow_status = 'RETURNED'\
		               WHERE order_id = '" + Order_Id + "';", conDataBase);

			Update_date_Borrow_status->ExecuteNonQuery();

			conDataBase->Close();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	void Update_Borrow_history_fine(int Order_Id, int fine)
	{
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

		try
		{
			conDataBase->Open();

			MySqlCommand^ Update_borrow_history_fine = gcnew MySqlCommand("UPDATE library_system_db.borrow_history set \
                       borrow_fine= '" + fine + "'\
		               WHERE order_id = '" + Order_Id + "';", conDataBase);


			//Below Query Updates fine coloumn in borrow_history by using fine function
			Update_borrow_history_fine->ExecuteNonQuery();


			conDataBase->Close();

		}

		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}

	}
	void Update_Member_data(int Member_Id)
	{
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

		try
		{
			conDataBase->Open();

			MySqlCommand^ Update_books_borrowed = gcnew MySqlCommand("UPDATE  library_system_db.member_data\
                       set member_no_book_stat = member_no_book_stat - 1\
                       WHERE member_id ='" + Member_Id + "';", conDataBase);


			Update_books_borrowed->ExecuteNonQuery();

			conDataBase->Clone();
		}

		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}
	void Update_Book_data(int Book_Id)
	{
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

		try
		{
			conDataBase->Open();

			MySqlCommand^ Update_book_borrow_status = gcnew MySqlCommand("UPDATE library_system_db.book_data set\
                       book_borrow_status = 'AVAILABLE'\
                       WHERE book_id = " + Book_Id + " ;", conDataBase);

			Update_book_borrow_status->ExecuteNonQuery();

			conDataBase->Close();
		}

		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}


	void Message_Return_Successfully(int Order_id, int Book_Id, int Member_Id)
	{
		try
		{
			MessageBox::Show("Returned book successfully! \nBook_id = " + Book_Id + " \nMember_id = " + Member_Id + " \nOrder_id = " + Order_id + " ");
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}
}