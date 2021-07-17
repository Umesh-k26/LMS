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
}