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
	public:
		MenuForm(void)
		{
			InitializeComponent();
			WindowState = System::Windows::Forms::FormWindowState::Maximized;
		}

	protected:
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: 
		System::Void StartButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Windows::Forms::Button^ StartButton;
		System::Windows::Forms::TextBox^ StartMoneyTextBox;
	private: System::Windows::Forms::Label^ start_money_label;

		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuForm::typeid));
			this->StartButton = (gcnew System::Windows::Forms::Button());
			this->StartMoneyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->start_money_label = (gcnew System::Windows::Forms::Label());
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
			// start_money_label
			// 
			this->start_money_label->AutoSize = true;
			this->start_money_label->Location = System::Drawing::Point(720, 190);
			this->start_money_label->Name = L"start_money_label";
			this->start_money_label->Size = System::Drawing::Size(78, 16);
			this->start_money_label->TabIndex = 2;
			this->start_money_label->Text = L"Start money";
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1742, 833);
			this->Controls->Add(this->start_money_label);
			this->Controls->Add(this->StartMoneyTextBox);
			this->Controls->Add(this->StartButton);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MenuForm";
			this->Text = L"MenuForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
