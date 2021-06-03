#pragma once

//
//	FINE FUNCTION HEADER
//
namespace fine_func {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// int function to calculate fine for the borrower
	/// </summary>
	/// <param name="order_id_input">
	/// Input for the order ID
	/// </param>
	/// <param name="member_id_input">
	/// input for the member who has borrowed the book
	/// </param>
	/// <param name="borrow_profession_input">
	/// profession of the borrower
	/// </param>
	/// <returns>
	/// int value of fine
	/// </returns>
	int calculate_fine(int order_id_input, int member_id_input, String^ borrow_profession_input);

}