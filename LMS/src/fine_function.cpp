#include "pch.h"
#include "fine_function.h"
#include  "connection_sql_func.h"

//
//	FINE FUNCTION DEFINITION
//
namespace fine_func {
	int calculate_fine(int order_id_input, int student_id_input, String^ borrow_proffesion_input)
	{
		int value_fine = 0;
		int num_date_difference = 0;

		int default_student_allowance = 7, default_faculty_allowance = 14, default_alumni_allowance = 10;
		int perday_student = 10, perday_faculty = 20, perday_alumni = 20;

		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand("SELECT DATEDIFF(date_returned, date_issue) AS fine_column FROM library_system.borrow_history WHERE order_id = " + order_id_input + ";", conDataBase);
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

			/*MySqlCommand^ cmdDataBase2 = gcnew MySqlCommand("SELECT student_profession FROM library_system.student_data WHERE student_id = " + student_id_input + ";", conDataBase);
			myReader = cmdDataBase2->ExecuteReader();
			while (myReader->Read())
			{
				borrow_proffesion_input = myReader->GetString("student_profession");
			}
			myReader->Close();*/

			if (borrow_proffesion_input == "Student")
			{
				if (num_date_difference <= default_student_allowance)
				{
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrow_proffesion_input + "\n Fine = " + value_fine);
					return 0;
				}
				else
				{
					num_date_difference = num_date_difference - default_student_allowance;
					value_fine = num_date_difference * perday_student;
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrow_proffesion_input + "\n Fine = " + value_fine);
					return value_fine;
				}
			}
			if (borrow_proffesion_input == "Faculty")
			{
				if (num_date_difference <= default_faculty_allowance)
				{
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrow_proffesion_input + "\n Fine = " + value_fine);
					return 0;
				}
				else
				{
					num_date_difference = num_date_difference - default_faculty_allowance;
					value_fine = num_date_difference * perday_faculty;
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrow_proffesion_input + "\n Fine = " + value_fine);
					return value_fine;
				}
			}
			if (borrow_proffesion_input == "Alumni")
			{
				if (num_date_difference <= default_alumni_allowance)
				{
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrow_proffesion_input + "\n Fine = " + value_fine);
					return 0;
				}
				else
				{
					num_date_difference = num_date_difference - default_alumni_allowance;
					value_fine = num_date_difference * perday_alumni;
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrow_proffesion_input + "\n Fine = " + value_fine);
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