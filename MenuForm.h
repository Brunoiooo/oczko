#pragma once

namespace oczko {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MenuForm : public System::Windows::Forms::Form
	{
		//Constructors
	public:
		MenuForm(void)
		{
			InitializeComponent();
			WindowState = System::Windows::Forms::FormWindowState::Maximized;
		}

		//Destructor
	protected:
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}

		//Handlers
	private: 
		System::Void StartButton_Click(System::Object^ sender, System::EventArgs^ e);

		//Componenst
	private: 
		System::Windows::Forms::Button^ StartButton;
		System::Windows::Forms::TextBox^ StartMoneyTextBox;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->StartButton = (gcnew System::Windows::Forms::Button());
			this->StartMoneyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// StartButton
			// 
			this->StartButton->Location = System::Drawing::Point(723, 577);
			this->StartButton->Name = L"StartButton";
			this->StartButton->Size = System::Drawing::Size(240, 101);
			this->StartButton->TabIndex = 0;
			this->StartButton->Text = L"Start";
			this->StartButton->UseVisualStyleBackColor = true;
			this->StartButton->Click += gcnew System::EventHandler(this, &MenuForm::StartButton_Click);
			// 
			// StartMoneyTextBox
			// 
			this->StartMoneyTextBox->Location = System::Drawing::Point(723, 209);
			this->StartMoneyTextBox->Name = L"StartMoneyTextBox";
			this->StartMoneyTextBox->Size = System::Drawing::Size(216, 22);
			this->StartMoneyTextBox->TabIndex = 1;
			this->StartMoneyTextBox->Text = L"1000";
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1742, 833);
			this->Controls->Add(StartMoneyTextBox);
			this->Controls->Add(StartButton);
			this->Name = L"MenuForm";
			this->Text = L"MenuForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
