#pragma once

namespace oczko {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AboutMeFormh
	/// </summary>
	public ref class AboutMeForm : public System::Windows::Forms::Form
	{
	public:
		AboutMeForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AboutMeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox;
	private: System::Windows::Forms::Label^ name_label;
	private: System::Windows::Forms::Label^ direction_label;
	private: System::Windows::Forms::Label^ semestr_label;
	private: System::Windows::Forms::Label^ group_label;
	private: System::Windows::Forms::Label^ year_label;
	private: System::Windows::Forms::Label^ place_label;
	private: System::Windows::Forms::Label^ close_label;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutMeForm::typeid));
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->name_label = (gcnew System::Windows::Forms::Label());
			this->direction_label = (gcnew System::Windows::Forms::Label());
			this->semestr_label = (gcnew System::Windows::Forms::Label());
			this->group_label = (gcnew System::Windows::Forms::Label());
			this->year_label = (gcnew System::Windows::Forms::Label());
			this->place_label = (gcnew System::Windows::Forms::Label());
			this->close_label = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox
			// 
			this->pictureBox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox.BackgroundImage")));
			this->pictureBox->Location = System::Drawing::Point(12, 12);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(547, 166);
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;
			// 
			// name_label
			// 
			this->name_label->AutoSize = true;
			this->name_label->Location = System::Drawing::Point(12, 181);
			this->name_label->Name = L"name_label";
			this->name_label->Size = System::Drawing::Size(100, 16);
			this->name_label->TabIndex = 1;
			this->name_label->Text = L"B³a¿ej Gonczar";
			// 
			// direction_label
			// 
			this->direction_label->AutoSize = true;
			this->direction_label->Location = System::Drawing::Point(12, 197);
			this->direction_label->Name = L"direction_label";
			this->direction_label->Size = System::Drawing::Size(167, 16);
			this->direction_label->TabIndex = 2;
			this->direction_label->Text = L"Informatyka niestacjonarna";
			// 
			// semestr_label
			// 
			this->semestr_label->AutoSize = true;
			this->semestr_label->Location = System::Drawing::Point(12, 213);
			this->semestr_label->Name = L"semestr_label";
			this->semestr_label->Size = System::Drawing::Size(67, 16);
			this->semestr_label->TabIndex = 3;
			this->semestr_label->Text = L"Semestr 3";
			// 
			// group_label
			// 
			this->group_label->AutoSize = true;
			this->group_label->Location = System::Drawing::Point(85, 213);
			this->group_label->Name = L"group_label";
			this->group_label->Size = System::Drawing::Size(54, 16);
			this->group_label->TabIndex = 4;
			this->group_label->Text = L"Grupa 1";
			// 
			// year_label
			// 
			this->year_label->AutoSize = true;
			this->year_label->Location = System::Drawing::Point(12, 229);
			this->year_label->Name = L"year_label";
			this->year_label->Size = System::Drawing::Size(42, 16);
			this->year_label->TabIndex = 5;
			this->year_label->Text = L"Rok 2";
			// 
			// place_label
			// 
			this->place_label->AutoSize = true;
			this->place_label->Location = System::Drawing::Point(12, 245);
			this->place_label->Name = L"place_label";
			this->place_label->Size = System::Drawing::Size(155, 16);
			this->place_label->TabIndex = 6;
			this->place_label->Text = L"Politechnika Koszaliñska";
			// 
			// close_label
			// 
			this->close_label->AutoSize = true;
			this->close_label->Location = System::Drawing::Point(404, 373);
			this->close_label->Name = L"close_label";
			this->close_label->Size = System::Drawing::Size(129, 16);
			this->close_label->TabIndex = 7;
			this->close_label->Text = L"Click Space to close";
			// 
			// AboutMeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(571, 398);
			this->Controls->Add(this->close_label);
			this->Controls->Add(this->place_label);
			this->Controls->Add(this->year_label);
			this->Controls->Add(this->group_label);
			this->Controls->Add(this->semestr_label);
			this->Controls->Add(this->direction_label);
			this->Controls->Add(this->name_label);
			this->Controls->Add(this->pictureBox);
			this->Name = L"AboutMeForm";
			this->Text = L"AboutMeFormh";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AboutMeForm::AboutMeForm_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void AboutMeForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
};
}
