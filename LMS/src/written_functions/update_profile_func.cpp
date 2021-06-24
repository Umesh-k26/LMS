#include "pch.h"
#include "update_profile_func.h"
#include "connection_sql_func.h"


bool update_profile_func::update_member_profile(String^ input_id, String^ profession_input, String^ email_input, String^ mobile_input, String^ address_input)
{
	bool return_val = false;
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
	MySqlCommand^ cmdDataBase = gcnew MySqlCommand("UPDATE library_system_db.member_data set member_id = \
		" + input_id + ", member_profession = '" + profession_input + "', member_email='" + email_input + "', member_mobile=" + mobile_input + ", member_address = '" + address_input + "'WHERE member_id = " + input_id + ";", conDataBase);

	try {
		conDataBase->Open();
		cmdDataBase->ExecuteNonQuery();
		//MessageBox::Show("Profile is updated");
		return_val = true;
	}
	catch (Exception^ ex)
	{
		//MessageBox::Show(ex->Message);
		return_val = false;
	}
	conDataBase->Close();

    return return_val;
}
