#include "pch.h"
#include "RegisterLibrarian_func.h"
#include <connection_sql_func.h>

bool LMS::Presenter::RegisterLibrarian_func(String^ username, String^ password, String^ Name, \
						String^ DOB, String^ Address, String^ Email, String^ Mobile, String^ Gender)
{
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
	MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand("INSERT INTO library_system_db.library_user_pass \
		VALUES('" + username + "',\
		'" + password + "',\
		'" + Name + "',\
		'" + DOB + "',\
		'" + Address + "',\
		'" + Email + "',\
		'" + Mobile + "',\
		'" + Gender + "')	;", conDataBase);

	conDataBase->Open();
	cmdDataBase1->ExecuteNonQuery();
	conDataBase->Close();
	return true;
}