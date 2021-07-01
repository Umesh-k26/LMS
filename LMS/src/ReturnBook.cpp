#include "pch.h"
#include "ReturnBook.h"

/// <summary>
///Constructor calls for functions to Initialize all the components of the form
///@see InitializeComponent()
/// </summary>
LMS::ReturnBook::ReturnBook(void)
{
	InitializeComponent();
}

LMS::ReturnBook :: ~ReturnBook()
{
	if (components)
	{
		delete components;
	}
}


/// <summary>
/// It loads the Form in full screen mode 
/// </summary>
System::Void LMS::ReturnBook::ReturnBook_Load(System::Object^ sender, System::EventArgs^ e)
{
	CenterToScreen();
	WindowState = FormWindowState::Maximized;
}


/// <summary>
/// Function to return Book by checking order_id and borrow_Status of Book
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>

System::Void LMS::ReturnBook::return_button_Click(System::Object^ sender, System::EventArgs^ e)
{

	try
	{
		int Order_id = Convert::ToInt32(this->order_id_txt->Text);

		if (Return_book_functions::check_Order_Id(Order_id) == true)
		{

			if (Return_book_functions::Get_Borrow_status(Order_id) == "BORROWED")
			{

				int Book_Id = Return_book_functions::Get_Book_Id(Order_id);

				int Member_ID = Return_book_functions::Get_Member_Id(Order_id);

				String^ profession = Return_book_functions::Get_Profession(Member_ID);

				Return_book_functions::Update_Book_data(Book_Id);

				Return_book_functions::Updata_Borrow_history_data(Order_id);

				int fine = fine_func::calculate_fine(Order_id, Member_ID, profession);

				Return_book_functions::Update_Borrow_history_fine(Order_id, fine);

				Return_book_functions::Update_Member_data(Member_ID);

				Return_book_functions::Message_Return_Successfully(Order_id, Book_Id, Member_ID);

			}

			else if (Return_book_functions::Get_Borrow_status(Order_id) == "RETURNED")
			{
				MessageBox::Show("Book with given Order Id is already returned.");
			}

			else if (Return_book_functions::Get_Borrow_status(Order_id) == "LOST")
			{
				MessageBox::Show("Book with given Order Id is Lost.");
			}
		}

		else
		{
			MessageBox::Show("Order with given Order Id Not found.");
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);
	}
}


/// <summary>
/// Function for Back Button which goes back to the previous Form by closing the current form
/// </summary>
System::Void LMS::ReturnBook::Back_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}
