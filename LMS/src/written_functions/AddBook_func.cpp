#include "pch.h"
#include "AddBook_func.h"
#include "../connection_sql_func.h"
#include <thread>
#include <chrono>


int LMS::dbInteract::AddBook_func(String^ Name, String^ Author, String^ Publisher, \
	String^ Category, const int EditionNo, const int NoOfCopies, const int Price)
{
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

	MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand("INSERT INTO library_system_db.book_data \
		(book_name, book_author, book_publisher, book_price,book_edition_no,category) \
		VALUES('" + Name + "',\
		'" + Author + "',\
		'" + Publisher + "',\
		'" + Price + "',\
		'" + EditionNo + "',\
		'" + Category + "');", conDataBase);

	MySqlCommand^ cmdDataBase2 = gcnew MySqlCommand("SELECT * FROM library_system_db.book_data WHERE (book_name = '" + Name + "' \
		AND book_edition_no = " + EditionNo + ");", conDataBase);

	MySqlDataReader^ myReader;
	int firstBookId;
	conDataBase->Open();

	int copies_no = System::Convert::ToInt32(NoOfCopies);
	for (int i = 0; i < copies_no; i++)
		cmdDataBase1->ExecuteNonQuery();

	//std::this_thread::sleep_for(std::chrono::seconds(20));
	myReader = cmdDataBase2->ExecuteReader();
	if (myReader->Read())
	{
		firstBookId = myReader->GetInt32("book_id");
	}
	myReader->Close();
	conDataBase->Close();

	return firstBookId;
}
