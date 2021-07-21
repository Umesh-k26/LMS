#pragma once


namespace sql_connection_func {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	using namespace System::Security::Cryptography;
	using namespace System::Xml;
	using namespace System::IO;

	/// <summary>
	/// Function for setting username password to establish connection to MySQL server
	/// </summary>
	/// <returns>
	/// String for connection to sql database with username and password to database
	/// </returns>
	String^ sql_user_pass_string();

	/// <summary>
	/// Function to implement for the password to be stored in a hashed format
	/// </summary>
	/// <param name="input_id">
	/// String for ID of the user
	/// </param>
	/// <param name="input_pass">
	/// String for Password that needs to be hashed
	/// </param>
	/// <returns>
	/// Hashed String
	/// </returns>
	String^ password_hasher(String^ input_id, String^ input_pass);
	void InitializeConstring();
	public ref class Global
	{
	public:
		static System::String^ constring;

	};
	bool is_xml_file_exist();
	void create_xml(String^ username_in, String^ password_in);
	String^ read_xml_return_constring();

	public ref class my_encdec {
	public:
		enum class MyEnum
		{
			USER, PASS
		};

		String^ enc_str(String^ str, MyEnum num)
		{
			switch (num)
			{
			case sql_connection_func::my_encdec::MyEnum::USER:
				str = str + "_server_usr";
				break;
			case sql_connection_func::my_encdec::MyEnum::PASS:
				str = str + "&45@";
				break;
			default:
				break;
			}
			return str;
		}

		int enc_num(String^ str, MyEnum num)
		{
			int new_num = str->Length;
			switch (num)
			{
			case sql_connection_func::my_encdec::MyEnum::USER:
				new_num = new_num + 8;
				break;
			case sql_connection_func::my_encdec::MyEnum::PASS:
				new_num = new_num + 12;
				break;
			default:
				break;
			}
			return new_num;
			//return new_num.ToString();
		}

		String^ dec_num(String^ str, MyEnum num)
		{
			int new_num = Int32::Parse(str);
			switch (num)
			{
			case sql_connection_func::my_encdec::MyEnum::USER:
				new_num = new_num - 8;
				break;
			case sql_connection_func::my_encdec::MyEnum::PASS:
				new_num = new_num - 12;
				break;
			default:
				break;
			}
			return new_num.ToString();
		}

		String^ dec_str(String^ str, int length)
		{
			String^ new_str = str;

			new_str = new_str->Remove(length, str->Length - length);

			return new_str;
		}
	};

}