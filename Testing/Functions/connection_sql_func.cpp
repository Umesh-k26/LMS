#include "pch.h"
#include "fine_function.h"
#include "connection_sql_func.h"

///	SQL function definitions to connect to database and to hash password

namespace sql_connection_func {

	//
	//	FUNCTION FOR SETTING USERNAME PASSWORD TO ESTABLISH CONNECTION TO MYSQL SERVER
	//
	String^ sql_user_pass_string()
	{
		//String^ constring = L"datasource=localhost;port=3306;username=root;password=lovebcmm**,02";
		String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234; SslMode=Required";
		//String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL; SslMode=Required";
		return constring;
	}

	
	/// <summary>
	/// This function hashes the password of the user and also salts it with ID of the user before being hashed
	/// </summary>
	/// The function converts the salted string into byte array then it applies MD5 Hashing method and then converts the byte array back into String
	String^ password_hasher(String^ input_id, String^ input_pass)
	{
		//Salting the required password string with username
		String^ final_password_for_hash = input_pass + input_id;

		//Converting the String into Byte Array Form
		array<Byte>^ byte_array_password = System::Text::Encoding::ASCII->GetBytes(final_password_for_hash);

		//Hashing the byte Array using MD5 
		System::Security::Cryptography::MD5CryptoServiceProvider^ md5_hash_gen = gcnew System::Security::Cryptography::MD5CryptoServiceProvider();
		array<Byte>^ byte_array_hash = md5_hash_gen->ComputeHash(byte_array_password);

		//Convert the Byte Array into String
		return BitConverter::ToString(byte_array_hash);
		
	}

	


}


