#include "pch.h"
#include "fine_function.h"
#include  "connection_sql_func.h"

//
//	FINE FUNCTION DEFINITION
//
namespace fine_func {

	/// <summary>
	/// This function calculates the fine that the borrower needs to pay after returning the book depending upon the profession
	/// </summary>
	int calculate_fine(int order_id_input, int member_id_input, String^ borrow_profession_input)
	{
		int value_fine = 0;
		int num_date_difference = 0;

		int default_student_allowance = 7, default_faculty_allowance = 14, default_alumni_allowance = 10;
		int perday_student = 10, perday_faculty = 20, perday_alumni = 20;

		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand("SELECT DATEDIFF(date_returned, date_issue) AS fine_column FROM library_system_db.borrow_history WHERE order_id = " + order_id_input + ";", conDataBase);
		MySqlDataReader^ myReader;
		try {
			conDataBase->Open();
			myReader = cmdDataBase1->ExecuteReader();

			while (myReader->Read())
			{
				num_date_difference = myReader->GetInt16("fine_column");
				//MessageBox::Show(""+num_date_difference);
			}
			myReader->Close();

			/*MySqlCommand^ cmdDataBase2 = gcnew MySqlCommand("SELECT member_profession FROM library_system_db.member_data WHERE member_id = " + member_id_input + ";", conDataBase);
			myReader = cmdDataBase2->ExecuteReader();
			while (myReader->Read())
			{
				borrow_profession_input = myReader->GetString("member_profession");
			}
			myReader->Close();*/

			if (borrow_profession_input == "Student")
			{
				if (num_date_difference <= default_student_allowance)
				{
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrow_profession_input + "\n Fine = " + value_fine);
					return 0;
				}
				else
				{
					num_date_difference = num_date_difference - default_student_allowance;
					value_fine = num_date_difference * perday_student;
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrow_profession_input + "\n Fine = " + value_fine);
					return value_fine;
				}
			}
			if (borrow_profession_input == "Faculty")
			{
				if (num_date_difference <= default_faculty_allowance)
				{
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrow_profession_input + "\n Fine = " + value_fine);
					return 0;
				}
				else
				{
					num_date_difference = num_date_difference - default_faculty_allowance;
					value_fine = num_date_difference * perday_faculty;
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrow_profession_input + "\n Fine = " + value_fine);
					return value_fine;
				}
			}
			if (borrow_profession_input == "Alumni")
			{
				if (num_date_difference <= default_alumni_allowance)
				{
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrow_profession_input + "\n Fine = " + value_fine);
					return 0;
				}
				else
				{
					num_date_difference = num_date_difference - default_alumni_allowance;
					value_fine = num_date_difference * perday_alumni;
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrow_profession_input + "\n Fine = " + value_fine);
					return value_fine;
				}
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}

		conDataBase->Close();
		return 0;
	}
}