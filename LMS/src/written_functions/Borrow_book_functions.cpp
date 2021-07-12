#include "pch.h"
#include "Borrow_book_functions.h"
#include "connection_sql_func.h"


namespace LMS::dbInteract {


	bool Check_book(String^ Book_Id)
	{
		bool return_value = false;

		//Creating a connection to database
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

		MySqlDataReader^ myReader;

		String^ Book_status;

		try
		{
			conDataBase->Open();

			//This command select Book's Borrow Satus from book_data Table , to check it's availability
			MySqlCommand^ book_data = gcnew MySqlCommand("SELECT book_borrow_status FROM library_system_db.book_data \
                WHERE book_id = '" + Book_Id + "';", conDataBase);

			myReader = book_data->ExecuteReader();

			while (myReader->Read())
			{
				Book_status = myReader->GetString("book_borrow_status");
			}

			myReader->Close();

			//Close the connection to DataBase
			conDataBase->Close();

			if (Book_status == "AVAILABLE")
			{
				return_value = true;
			}

			return return_value;

		}
		catch (Exception^ ex)
		{
			//If any exception occurs then show messagebox
			MessageBox::Show(ex->Message);
		}

	}

	bool Check_Memeber(String^ Member_Id)
	{

		bool return_value = false;

		//Creating a connection to database
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

		MySqlDataReader^ myReader;

		String^ Membership_status;

		try
		{

			conDataBase->Open();

			MySqlCommand^ member_data = gcnew MySqlCommand("SELECT membership_stat FROM library_system_db.member_data \
		         WHERE member_id = '" + Member_Id + \
				"';", conDataBase);

			myReader = member_data->ExecuteReader();

			while (myReader->Read())
			{
				Membership_status = myReader->GetString("membership_stat");
			}

			myReader->Close();

			//Close the connection to DataBase
			conDataBase->Close();


			if (Membership_status == "ACTIVATED")
			{
				return_value = true;
			}

			return return_value;

		}
		catch (Exception^ ex)
		{
			//If any exception occurs then show messagebox
			MessageBox::Show(ex->Message);
		}


	}


	//Updates Book status coloumn  in Book data Table 
	void Update_Book_data(String^ Book_Id)
	{

		//Creating a connection to database
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

		try
		{

			conDataBase->Open();

			MySqlCommand^ Update_book_data_borrow_status = gcnew MySqlCommand("UPDATE  library_system_db.book_data set\
                     book_borrow_status = 'BORROWED' WHERE \
                     book_id ='" + Book_Id + "'\
                      ;", conDataBase);

			Update_book_data_borrow_status->ExecuteNonQuery();

			//Close the connection to DataBase
			conDataBase->Close();
		}

		catch (Exception^ ex)
		{
			//If any exception occurs then show messagebox
			MessageBox::Show(ex->Message);
		}

	}

	Void Update_member_data(String^ Memeber_Id)
	{

		//Creating a connection to database
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());


		try
		{
			conDataBase->Open();


			MySqlCommand^ Update_member_data = gcnew MySqlCommand("UPDATE library_system_db.member_data set\
                     member_no_book_stat = member_no_book_stat +1 WHERE \
                     member_id ='" + Memeber_Id + "' ;", conDataBase);

			Update_member_data->ExecuteNonQuery();

			//Close the connection to DataBase
			conDataBase->Close();

		}
		catch (Exception^ ex)
		{
			//If any exception occurs then show messagebox
			MessageBox::Show(ex->Message);
		}
	}


	//Inserts New row  in Borrow history table
	void Take_New_order(String^ Book_Id, String^ Member_Id)
	{
		//Creating a connection to database
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());


		try
		{
			conDataBase->Open();

			MySqlCommand^ Insert_borrow_history = gcnew MySqlCommand("INSERT INTO library_system_db.borrow_history \
	                 (book_id, member_id,date_issue) \
	                 VALUES('" + Book_Id + "',\
	                 '" + Member_Id + "',\
	                 CURDATE());", conDataBase);

			Insert_borrow_history->ExecuteNonQuery();

			//Close the connection to DataBase
			conDataBase->Close();

		}
		catch (Exception^ ex)
		{
			//If any exception occurs then show messagebox
			MessageBox::Show(ex->Message);
		}
	}

	void Message_Borrowed_succesfully(String^ Book_Id, String^ Member_Id)
	{
		String^ Order_Id;

		//Creating a connection to database
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlDataReader^ myReader;

		try
		{
			conDataBase->Open();

			MySqlCommand^ borrow_history_data = gcnew MySqlCommand("SELECT * FROM  library_system_db.borrow_history \
	                 WHERE  book_id ='" + Book_Id + "'\
                     AND member_id = '" + Member_Id + "'\
	                 AND date_issue = CURDATE()\
	                 ; ", conDataBase);


			myReader = borrow_history_data->ExecuteReader();

			while (myReader->Read())
			{
				Order_Id = myReader->GetString("order_id");
			}

			myReader->Close();

			//Close the connection to DataBase
			conDataBase->Close();

			MessageBox::Show("Borrowed book successfully! \nBook_id = " + Book_Id + " \nMember_id = " + Member_Id + " \nOrder_id = " + Order_Id);

		}
		catch (Exception^ ex)
		{
			//If any exception occurs then show messagebox
			MessageBox::Show(ex->Message);
		}

	}



	void Check_copies_available(String^ Book_Id)
	{

		//Creating a connection to database
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlDataReader^ myReader;


		String^ Book_name;
		String^ Book_author;
		String^ Book_publisher;
		String^ Book_edition_no;
		int Copies_available = 0;

		try
		{
			conDataBase->Open();

			MySqlCommand^ book_data = gcnew MySqlCommand("SELECT * FROM library_system_db.book_data \
                          WHERE book_id = '" + Book_Id + \
				"';", conDataBase);

			myReader = book_data->ExecuteReader();

			while (myReader->Read())
			{

				Book_name = myReader->GetString("book_name");
				Book_author = myReader->GetString("book_author");
				Book_publisher = myReader->GetString("book_publisher");
				Book_edition_no = myReader->GetString("book_edition_no");

			}
			myReader->Close();

			MySqlCommand^ Copies_available_data = gcnew MySqlCommand("SELECT * FROM library_system_db.book_data WHERE book_name ='" + Book_name + "'\
                             AND book_author ='" + Book_author + "' \
                             AND book_publisher ='" + Book_publisher + "'\
                             AND book_edition_no ='" + Book_edition_no + "' \
                             ;", conDataBase);

			myReader = Copies_available_data->ExecuteReader();

			while (myReader->Read())
			{
				Copies_available += 1;
			}

			myReader->Close();

			//Close the connection to DataBase
			conDataBase->Close();

			if (Copies_available > 1)
			{
				MessageBox::Show("Different copy of same Book is available ");
			}

			else
			{
				MessageBox::Show("Book is Not Available with given Book ID");
			}
		}

		catch (Exception^ ex)
		{
			//If any exception occurs then show messagebox
			MessageBox::Show(ex->Message);

		}

	}
}