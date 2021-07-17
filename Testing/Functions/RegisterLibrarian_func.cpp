#include "pch.h"
#include "RegisterLibrarian_func.h"
#include "connection_sql_func.h"

bool LMS::dbInteract::RegisterLibrarian_func(String^ username, String^ password, String^ Name, \
	String^ DOB, String^ Address, String^ Email, String^ Mobile, String^ Gender)
{
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

	password = sql_connection_func::password_hasher(username, password);
	MySqlCommand^ LibraryUserPassInsertQuery = gcnew MySqlCommand("INSERT INTO library_system_db.library_user_pass \
		VALUES('" + username + "',\
		'" + password + "',\
		'" + Name + "',\
		'" + DOB + "',\
		'" + Address + "',\
		'" + Email + "',\
		'" + Mobile + "',\
		'" + Gender + "')	;", conDataBase);
	conDataBase->Open();

	LibraryUserPassInsertQuery->ExecuteNonQuery();
	conDataBase->Close();
	return true;
}
