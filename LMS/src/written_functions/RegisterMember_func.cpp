#include "pch.h"
#include "RegisterMember_func.h"
#include "connection_sql_func.h"

int LMS::dbInteract::RegisterMember_func(String^ Name, String^ DOB, String^ Address, String^ EmailId, \
	String^ MobileNo, String^ Profession, String^ Gender, String^ Password)
{
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

	MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand("INSERT INTO library_system_db.member_data (member_name, \
			member_dob, member_address, member_email, \
			member_mobile, member_profession, member_gender) \
			VALUES('" + Name + "',\
			'" + DOB + "',\
			'" + Address + "',\
			'" + EmailId + "',\
			" + MobileNo + ",\
			'" + Profession + "',\
			'" + Gender + "')	;", conDataBase);

	MySqlCommand^ cmdDataBase2 = gcnew MySqlCommand("USE library_system_db;INSERT INTO user_pass (member_id, user_password) \
			VALUES((SELECT member_id FROM member_data WHERE member_email = '" + EmailId + "'), \
			'" + Password + "');", conDataBase);

	MySqlCommand^ cmdDataBase3 = gcnew MySqlCommand("SELECT * FROM library_system_db.member_data \
			WHERE member_email = '" + EmailId + "';", conDataBase);

	MySqlDataReader^ myReader;
	conDataBase->Open();

	cmdDataBase1->ExecuteNonQuery();
	cmdDataBase2->ExecuteNonQuery();
	int memberId;

	myReader = cmdDataBase3->ExecuteReader();

	if (myReader->Read())
	{
		memberId = myReader->GetInt32("member_id");
	}
	myReader->Close();
	conDataBase->Close();
	return memberId;
}

