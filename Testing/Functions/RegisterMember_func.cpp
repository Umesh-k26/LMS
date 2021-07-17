#include "pch.h"
#include "RegisterMember_func.h"
#include "connection_sql_func.h"

int LMS::dbInteract::RegisterMember_func(String^ Name, String^ DOB, String^ Address, String^ EmailId, \
	String^ MobileNo, String^ Profession, String^ Gender, String^ Password)
{
	int memberId;
	String^ hashedPassword;
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

	MySqlCommand^ MemberDataInsertQuery = gcnew MySqlCommand("INSERT INTO library_system_db.member_data (member_name, \
			member_dob, member_address, member_email, \
			member_mobile, member_profession, member_gender) \
			VALUES('" + Name + "',\
			'" + DOB + "',\
			'" + Address + "',\
			'" + EmailId + "',\
			" + MobileNo + ",\
			'" + Profession + "',\
			'" + Gender + "')	;", conDataBase);

	MySqlCommand^ GetIdSelectQuery = gcnew MySqlCommand("SELECT * FROM library_system_db.member_data \
			WHERE member_email = '" + EmailId + "';", conDataBase);

	MySqlDataReader^ myReader;
	conDataBase->Open();

	MemberDataInsertQuery->ExecuteNonQuery();

	myReader = GetIdSelectQuery->ExecuteReader();

	if (myReader->Read())
	{
		memberId = myReader->GetInt32("member_id");
	}
	myReader->Close();
	hashedPassword = sql_connection_func::password_hasher(memberId.ToString(), Password);

	MySqlCommand^ UserPassInsertQuery = gcnew MySqlCommand("USE library_system_db;INSERT INTO user_pass (member_id, user_password) \
			VALUES((SELECT member_id FROM member_data WHERE member_email = '" + EmailId + "'), '" + hashedPassword + "');", conDataBase);

	UserPassInsertQuery->ExecuteNonQuery();
	conDataBase->Close();
	return memberId;
}

