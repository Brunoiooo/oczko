#pragma once

#include "Core.hpp"

namespace oczko {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace std;

	public ref class GameForm : public System::Windows::Forms::Form
	{
	private:
		Core::Core* core;
		void UpdateComponents();
		void UpdateStartBetButton();
		void UpdateStartBetLabel();
		void UpdateStartBetTextbox();

	public:
		GameForm(float money)
		{
			core = new Core::Core(money);

			InitializeComponent();

			UpdateComponents();

			WindowState = System::Windows::Forms::FormWindowState::Maximized;
		}

	protected:
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ start_bet_button;
	private: System::Windows::Forms::TextBox^ start_bet_textbox;
	private: System::Windows::Forms::Label^ start_bet_label;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GameForm::typeid));
			this->start_bet_button = (gcnew System::Windows::Forms::Button());
			this->start_bet_textbox = (gcnew System::Windows::Forms::TextBox());
			this->start_bet_label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// start_bet_button
			// 
			this->start_bet_button->Location = System::Drawing::Point(728, 532);
			this->start_bet_button->Name = L"start_bet_button";
			this->start_bet_button->Size = System::Drawing::Size(410, 140);
			this->start_bet_button->TabIndex = 0;
			this->start_bet_button->Text = L"Start next bet";
			this->start_bet_button->UseVisualStyleBackColor = true;
			this->start_bet_button->Click += gcnew System::EventHandler(this, &GameForm::start_bet_button_Click);
			// 
			// start_bet_textbox
			// 
			this->start_bet_textbox->Location = System::Drawing::Point(728, 504);
			this->start_bet_textbox->Name = L"start_bet_textbox";
			this->start_bet_textbox->Size = System::Drawing::Size(410, 22);
			this->start_bet_textbox->TabIndex = 1;
			// 
			// start_bet_label
			// 
			this->start_bet_label->AutoSize = true;
			this->start_bet_label->Location = System::Drawing::Point(725, 485);
			this->start_bet_label->Name = L"start_bet_label";
			this->start_bet_label->Size = System::Drawing::Size(105, 16);
			this->start_bet_label->TabIndex = 2;
			this->start_bet_label->Text = L"Value of next bet";
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1787, 777);
			this->Controls->Add(this->start_bet_label);
			this->Controls->Add(this->start_bet_textbox);
			this->Controls->Add(this->start_bet_button);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"GameForm";
			this->Text = L"GameForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void start_bet_button_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			float money = float::Parse(start_bet_textbox->Text);

			if (money <= 0)
				throw gcnew Exception("Value of bet have to be bigger than 0.");
			if (!core->CanNewBet(money))
				throw gcnew Exception("Player doesn't have enough money to place the bet.");
			
			core->NewBet(money);

			UpdateComponents();
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
		}
	}
	};
}
