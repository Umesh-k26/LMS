#pragma once

namespace delete_profile_func {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Function to delete profile of a member
	/// </summary>
	/// <param name="input_id">
	/// String input for ID of the member whose profile needs to be deleted
	/// </param>
	/// <returns>
	/// Returns true if it is successful in deleting
	/// </returns>
	bool delete_member_profile(String^ input_id);

	/// <summary>
	/// Function to delete profile of a book
	/// </summary>
	/// <param name="input_id">
	/// String input for ID of the book whose profile needs to be deleted
	/// </param>
	/// <param name="book_name_input">
	/// String input for name of the book
	/// </param>
	/// <param name="book_author_input">
	/// String input for author of the book
	/// </param>
	/// <param name="book_pub_input">
	/// String input for publisher of the book
	/// </param>
	/// <param name="book_edition_input">
	/// String input for edition of the book
	/// </param>
	/// <returns>
	/// Returns true if it is successful in deleting
	/// </returns>
	bool delete_book_profile(String^ input_id, String^ book_name_input, String^ book_author_input, String^ book_pub_input, String^ book_edition_input, String^ borrow_status_input, String^ final_fine);

}