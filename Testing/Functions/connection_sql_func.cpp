#include "pch.h"
#include "fine_function.h"
#include "connection_sql_func.h"

///	SQL function definitions to connect to database and to hash password

namespace sql_connection_func {

	bool is_xml_file_exist()
	{
		bool return_val = false;
		String^ fileName = "LMS.xml";
		try
		{
			StreamReader^ din = File::OpenText(fileName);
			return_val = true;
		}
		catch (Exception^ e)
		{
			return_val = false;
		}
		return return_val;
	}

	void create_xml(String^ username_in, String^ password_in)
	{
		XmlTextWriter^ write_xml_file;
		String^ txtFilename = "LMS.xml";
		write_xml_file = gcnew XmlTextWriter(txtFilename, System::Text::Encoding::UTF8);
		write_xml_file->WriteStartDocument(true);
		write_xml_file->WriteWhitespace("\n");
		write_xml_file->WriteStartElement("Data");
		write_xml_file->WriteWhitespace("\n");
		write_xml_file->WriteElementString("A", username_in);
		write_xml_file->WriteWhitespace("\n");
		write_xml_file->WriteStartElement("B");
		write_xml_file->WriteString(password_in);
		write_xml_file->WriteEndElement();
		write_xml_file->WriteWhitespace("\n");
		write_xml_file->WriteEndElement();
		write_xml_file->WriteEndDocument();
		write_xml_file->Close();
	}

	String^ read_xml_return_constring()
	{
		String^ filename = "LMS.xml";
		String^ username;
		String^ password;
		XmlTextReader^ xreader = gcnew XmlTextReader(filename);
		int count = 0;
		while (xreader->Read())
		{
			switch (xreader->NodeType)
			{
			case XmlNodeType::Text:
				if (count == 1)
				{
					password = xreader->Value;
				}
				if (count == 0)
				{
					username = xreader->Value;
					count++;
				}
			}

		}
		xreader->Close();

		String^ constring = L"datasource=localhost;port=3306;username=" + username + "; password =" + password + "; SslMode = Required";

		return constring;
	}


	//
	//	FUNCTION FOR SETTING USERNAME PASSWORD TO ESTABLISH CONNECTION TO MYSQL SERVER
	//
	String^ sql_user_pass_string()
	{
		////String^ constring = L"datasource=localhost;port=3306;username=root;password=lovebcmm**,02";
		////String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234; SslMode=Required";
		//String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL; SslMode=Required";
		//return constring;
		return Global::constring;
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


	void InitializeConstring() //initializeConstring()
	{
		if (!is_xml_file_exist())
		{
			String^ UserAnswer = Microsoft::VisualBasic::Interaction::InputBox("Enter Username ", "MySql connection user credentials", "", 12, 50);
			String^ passAnswer = Microsoft::VisualBasic::Interaction::InputBox("Enter Password ", "MySql connection user credentials", "", 12, 50);

			create_xml(UserAnswer, passAnswer);
		}

		Global::constring = read_xml_return_constring();
	}
}


