#pragma once
#include <math.h>
#include <complex>
namespace Лаб33Калькулятор {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void) {
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ X2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ X3;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Label^ a;
	private: System::Windows::Forms::TextBox^ X1;
	private: System::Windows::Forms::TextBox^ Y1;
	private: System::Windows::Forms::TextBox^ Y2;
	private: System::Windows::Forms::TextBox^ Y3;
	private: System::Windows::Forms::Label^ i1;
	private: System::Windows::Forms::Label^ plus1;
	private: System::Windows::Forms::Label^ plus3;
	private: System::Windows::Forms::Label^ plus2;
	private: System::Windows::Forms::Label^ i3;
	private: System::Windows::Forms::Label^ i2;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ b;
	private: System::Windows::Forms::Label^ c;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::Label^ yravnenie;
	private: System::Windows::Forms::Panel^ panel2;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->X2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->X3 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->a = (gcnew System::Windows::Forms::Label());
			this->X1 = (gcnew System::Windows::Forms::TextBox());
			this->Y1 = (gcnew System::Windows::Forms::TextBox());
			this->Y2 = (gcnew System::Windows::Forms::TextBox());
			this->Y3 = (gcnew System::Windows::Forms::TextBox());
			this->i1 = (gcnew System::Windows::Forms::Label());
			this->plus1 = (gcnew System::Windows::Forms::Label());
			this->plus3 = (gcnew System::Windows::Forms::Label());
			this->plus2 = (gcnew System::Windows::Forms::Label());
			this->i3 = (gcnew System::Windows::Forms::Label());
			this->i2 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->b = (gcnew System::Windows::Forms::Label());
			this->c = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->yravnenie = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// X2
			// 
			this->X2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->X2->Cursor = System::Windows::Forms::Cursors::Default;
			this->X2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->X2->Location = System::Drawing::Point(59, 115);
			this->X2->Name = L"X2";
			this->X2->Size = System::Drawing::Size(66, 29);
			this->X2->TabIndex = 2;
			this->X2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->X2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Cursor = System::Windows::Forms::Cursors::Default;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(12, 189);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(114, 30);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Решить";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(135, 189);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(120, 30);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Очистить";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// X3
			// 
			this->X3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->X3->Cursor = System::Windows::Forms::Cursors::Default;
			this->X3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->X3->Location = System::Drawing::Point(59, 147);
			this->X3->Name = L"X3";
			this->X3->Size = System::Drawing::Size(66, 29);
			this->X3->TabIndex = 22;
			this->X3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox1->Location = System::Drawing::Point(12, 12);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(171, 25);
			this->checkBox1->TabIndex = 25;
			this->checkBox1->Text = L"Комплексные числа";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// a
			// 
			this->a->AutoSize = true;
			this->a->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->a->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->a->Location = System::Drawing::Point(3, 1);
			this->a->Name = L"a";
			this->a->Size = System::Drawing::Size(37, 21);
			this->a->TabIndex = 26;
			this->a->Text = L"a = ";
			this->a->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// X1
			// 
			this->X1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->X1->Cursor = System::Windows::Forms::Cursors::Default;
			this->X1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->X1->Location = System::Drawing::Point(59, 83);
			this->X1->Name = L"X1";
			this->X1->Size = System::Drawing::Size(66, 29);
			this->X1->TabIndex = 0;
			this->X1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->X1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// Y1
			// 
			this->Y1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Y1->Cursor = System::Windows::Forms::Cursors::Default;
			this->Y1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Y1->Location = System::Drawing::Point(156, 83);
			this->Y1->Name = L"Y1";
			this->Y1->Size = System::Drawing::Size(63, 29);
			this->Y1->TabIndex = 32;
			this->Y1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->Y1->Visible = false;
			this->Y1->TextChanged += gcnew System::EventHandler(this, &MyForm::Y1_TextChanged);
			// 
			// Y2
			// 
			this->Y2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Y2->Cursor = System::Windows::Forms::Cursors::Default;
			this->Y2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Y2->Location = System::Drawing::Point(156, 115);
			this->Y2->Name = L"Y2";
			this->Y2->Size = System::Drawing::Size(63, 29);
			this->Y2->TabIndex = 33;
			this->Y2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->Y2->Visible = false;
			// 
			// Y3
			// 
			this->Y3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Y3->Cursor = System::Windows::Forms::Cursors::Default;
			this->Y3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Y3->Location = System::Drawing::Point(156, 147);
			this->Y3->Name = L"Y3";
			this->Y3->Size = System::Drawing::Size(63, 29);
			this->Y3->TabIndex = 34;
			this->Y3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->Y3->Visible = false;
			// 
			// i1
			// 
			this->i1->AutoSize = true;
			this->i1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->i1->Location = System::Drawing::Point(3, 0);
			this->i1->Name = L"i1";
			this->i1->Size = System::Drawing::Size(21, 21);
			this->i1->TabIndex = 35;
			this->i1->Text = L"*i";
			// 
			// plus1
			// 
			this->plus1->AutoSize = true;
			this->plus1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->plus1->Location = System::Drawing::Point(131, 85);
			this->plus1->Name = L"plus1";
			this->plus1->Size = System::Drawing::Size(21, 21);
			this->plus1->TabIndex = 37;
			this->plus1->Text = L"+";
			this->plus1->Visible = false;
			// 
			// plus3
			// 
			this->plus3->AutoSize = true;
			this->plus3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->plus3->Location = System::Drawing::Point(131, 149);
			this->plus3->Name = L"plus3";
			this->plus3->Size = System::Drawing::Size(21, 21);
			this->plus3->TabIndex = 38;
			this->plus3->Text = L"+";
			this->plus3->Visible = false;
			// 
			// plus2
			// 
			this->plus2->AutoSize = true;
			this->plus2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->plus2->Location = System::Drawing::Point(131, 117);
			this->plus2->Name = L"plus2";
			this->plus2->Size = System::Drawing::Size(21, 21);
			this->plus2->TabIndex = 39;
			this->plus2->Text = L"+";
			this->plus2->Visible = false;
			// 
			// i3
			// 
			this->i3->AutoSize = true;
			this->i3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->i3->Location = System::Drawing::Point(3, 64);
			this->i3->Name = L"i3";
			this->i3->Size = System::Drawing::Size(21, 21);
			this->i3->TabIndex = 40;
			this->i3->Text = L"*i";
			// 
			// i2
			// 
			this->i2->AutoSize = true;
			this->i2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->i2->Location = System::Drawing::Point(3, 32);
			this->i2->Name = L"i2";
			this->i2->Size = System::Drawing::Size(21, 21);
			this->i2->TabIndex = 41;
			this->i2->Text = L"*i";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label17->Location = System::Drawing::Point(3, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(0, 21);
			this->label17->TabIndex = 25;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->Location = System::Drawing::Point(3, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(0, 21);
			this->label16->TabIndex = 26;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->label17);
			this->panel1->Location = System::Drawing::Point(12, 257);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(243, 26);
			this->panel1->TabIndex = 17;
			// 
			// b
			// 
			this->b->AutoSize = true;
			this->b->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->b->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b->Location = System::Drawing::Point(3, 33);
			this->b->Name = L"b";
			this->b->Size = System::Drawing::Size(38, 21);
			this->b->TabIndex = 45;
			this->b->Text = L"b = ";
			// 
			// c
			// 
			this->c->AutoSize = true;
			this->c->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->c->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->c->Location = System::Drawing::Point(3, 65);
			this->c->Name = L"c";
			this->c->Size = System::Drawing::Size(36, 21);
			this->c->TabIndex = 46;
			this->c->Text = L"c = ";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->c);
			this->panel3->Controls->Add(this->a);
			this->panel3->Controls->Add(this->b);
			this->panel3->Location = System::Drawing::Point(12, 83);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(43, 93);
			this->panel3->TabIndex = 47;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Controls->Add(this->i3);
			this->panel4->Controls->Add(this->i2);
			this->panel4->Controls->Add(this->i1);
			this->panel4->Location = System::Drawing::Point(225, 84);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(30, 92);
			this->panel4->TabIndex = 48;
			this->panel4->Visible = false;
			// 
			// panel9
			// 
			this->panel9->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel9->Controls->Add(this->label16);
			this->panel9->Location = System::Drawing::Point(12, 225);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(243, 26);
			this->panel9->TabIndex = 18;
			// 
			// yravnenie
			// 
			this->yravnenie->AutoSize = true;
			this->yravnenie->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->yravnenie->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->yravnenie->Location = System::Drawing::Point(24, 3);
			this->yravnenie->Name = L"yravnenie";
			this->yravnenie->Size = System::Drawing::Size(198, 25);
			this->yravnenie->TabIndex = 42;
			this->yravnenie->Text = L"a * x^2 + b * x + c = 0";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->yravnenie);
			this->panel2->Location = System::Drawing::Point(12, 43);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(243, 33);
			this->panel2->TabIndex = 44;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(268, 291);
			this->Controls->Add(this->panel9);
			this->Controls->Add(this->plus2);
			this->Controls->Add(this->plus3);
			this->Controls->Add(this->plus1);
			this->Controls->Add(this->Y3);
			this->Controls->Add(this->Y2);
			this->Controls->Add(this->Y1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->X3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->X2);
			this->Controls->Add(this->X1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel4);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->MaximumSize = System::Drawing::Size(284, 330);
			this->MinimumSize = System::Drawing::Size(284, 330);
			this->Name = L"MyForm";
			this->Text = L"Решение кв. уравнений";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public:bool Protect_K()
		{
			if ((X1->Text->Length == 0) || (X2->Text->Length == 0) || (X3->Text->Length == 0) || (Y1->Text->Length == 0) || (Y2->Text->Length == 0)
				|| (Y3->Text->Length == 0))
			{
				return false;
			}
			for (int i = 0; i < X1->Text->Length; i++)
			{
				if ((X1->Text[i] >= '0') && (X1->Text[i] <= '9') || (X1->Text[i] == ',') || (X1->Text[i] == '-')) {}
				else { return false; }
			}
			for (int i = 0; i < X2->Text->Length; i++)
			{
				if ((X2->Text[i] >= '0') && (X2->Text[i] <= '9') || (X2->Text[i] == ',') || (X2->Text[i] == '-')) {}
				else { return false; }
			}
			for (int i = 0; i < Y1->Text->Length; i++)
			{
				if ((Y1->Text[i] >= '0') && (Y1->Text[i] <= '9') || (Y1->Text[i] == ',') || (Y1->Text[i] == '-')) {}
				else { return false; }
			}
			for (int i = 0; i < Y2->Text->Length; i++)
			{
				if ((Y2->Text[i] >= '0') && (Y2->Text[i] <= '9') || (Y2->Text[i] == ',') || (Y2->Text[i] == '-')) {}
				else { return false; }
			}
			for (int i = 0; i < X3->Text->Length; i++)
			{
				if ((X3->Text[i] >= '0') && (X3->Text[i] <= '9') || (X3->Text[i] == ',') || (X3->Text[i] == '-')) {}
				else { return false; }
			}
			for (int i = 0; i < Y3->Text->Length; i++)
			{
				if ((Y3->Text[i] >= '0') && (Y3->Text[i] <= '9') || (Y3->Text[i] == ',') || (Y3->Text[i] == '-')) {}
				else { return false; }
			}
			return true;
		}
		public:bool Protect_D()
		{
			if ((X1->Text->Length == 0) || (X2->Text->Length == 0) || (X3->Text->Length == 0))
			{
				return false;
			}
			for (int i = 0; i < X1->Text->Length; i++)
			{
				if ((X1->Text[i] >= '0') && (X1->Text[i] <= '9') || (X1->Text[i] == ',') || (X1->Text[i] == '-')) {}
				else { return false; }
			}
			for (int i = 0; i < X2->Text->Length; i++)
			{
				if ((X2->Text[i] >= '0') && (X2->Text[i] <= '9') || (X2->Text[i] == ',') || (X2->Text[i] == '-')) {}
				else { return false; }
			}
			for (int i = 0; i < X3->Text->Length; i++)
			{
				if ((X3->Text[i] >= '0') && (X3->Text[i] <= '9') || (X3->Text[i] == ',') || (X3->Text[i] == '-')) {}
				else { return false; }
			}
			return true;
		}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox1->Checked)
	{
		if (Protect_K()) {
			panel1->Visible = true;
			double x1 = Convert::ToDouble(X1->Text);
			double y1 = Convert::ToDouble(Y1->Text);
			double x2 = Convert::ToDouble(X2->Text);
			double y2 = Convert::ToDouble(Y2->Text);
			double x3 = Convert::ToDouble(X3->Text);
			double y3 = Convert::ToDouble(Y3->Text);
			complex <double> A(x1, y1);
			complex <double> B(x2, y2);
			complex <double> C(x3, y3);
			complex <double> D = B * B - 4.0 * A * C;
			D = sqrt(D);
			complex <double> Z1 = (-B + D) / (2.0 * A);
			complex <double> Z2 = (-B - D) / (2.0 * A);
			double k11 = Z1.real(); double k21 = Z2.real();
			double k12 = Z1.imag(); double k22 = Z2.imag();

			if (k12 > 0) {
				label16->Text = "z1 = " + Math::Round(k11, 3).ToString() + " + "
					+ Math::Round(k12, 3).ToString() + "* i";
			}
			else {
				k12 = k12 * (-1);
				label16->Text = "z1 = " + Math::Round(k11, 3).ToString() + " - "
					+ Math::Round(k12, 3).ToString() + "* i";
			}
			if (k22 > 0) {
				label17->Text = "z2 = " + Math::Round(k21, 3).ToString() + " + "
					+ Math::Round(k22, 3).ToString() + "* i";
			}
			else {
				k22 = k22 * (-1);
				label17->Text = "z2 = " + Math::Round(k21, 3).ToString() + " - "
					+ Math::Round(k22, 3).ToString() + "* i";
			}
		}
		else {
			MessageBox::Show("Ошибка! Проверьте введенные данные.");
		}
	}
	else
	{
		if (Protect_D()) {
			double a = System::Convert::ToDouble(X1->Text);
			double b = System::Convert::ToDouble(X2->Text);
			double c = System::Convert::ToDouble(X3->Text);
			double d = b * b - 4 * a * c;
			if (a == 0) {
				if (b == 0) {
					MessageBox::Show("Уравнение несовместимо");
					label16->Text = "";
					label17->Text = "";
					return;
				}
			}
			if (a == 0) {
				double x = -c / b;
				panel1->Visible = false;
				label16->Text = "x = " + Math::Round(x, 3).ToString();
				label17->Text = "";
				return;
			}
			if (b != 0) {
				if (c == 0) {
					panel1->Visible = true;
					double x1 = 0;
					double x2 = -b / a;
					label16->Text = "x1 = " + System::Convert::ToString(x1);
					label17->Text = "x2 = " + Math::Round(x2, 3).ToString();
					return;
				}
			}
			if (b == 0) {
				panel1->Visible = true;
				double x1 = sqrt(c);
				double x2 = -sqrt(c);
				label16->Text = "x1 = " + System::Convert::ToString(x1);
				label17->Text = "x2 = " + Math::Round(x2, 3).ToString();
				return;
			}
			if (d < 0)
			{
				MessageBox::Show("Уравнение не имеет действительных корней. Найдены комплексные корни");
				double z1 = (-b / 2);
				double z2 = (sqrt(abs(d))) / (2);
				double z3 = (-b / 2);
				double z4 = -(sqrt(abs(d))) / (2);
				panel1->Visible = true;
				if (z2 > 0) {
					label16->Text = "z1 = " + System::Convert::ToString(z1) +
						" + " + Math::Round(z2, 3).ToString() + "*i";
				}
				else {
					z2 = z2 * (-1);
					label16->Text = "z1 = " + System::Convert::ToString(z1) +
						" - " + Math::Round(z2, 3).ToString() + "*i";
				}
				if (z4 > 0)
					label17->Text = "z2 = " + System::Convert::ToString(z3) +
					" + " + Math::Round(z4, 3).ToString() + "*i";
				else {
					z4 = z4 * (-1);
					label17->Text = "z2 = " + System::Convert::ToString(z3) +
						" - " + Math::Round(z4, 3).ToString() + "*i";
				}
				return;
			}
			if (d == 0)
			{
				double x = (-b / 2 * a);
				label16->Text = "x = " + System::Convert::ToString(x);
				label17->Text = "";
				panel1->Visible = false;
				return;
			}
			if (d > 0)
			{
				double x1 = (-1 * b + sqrt(d)) / (2 * a);
				double x2 = (-1 * b - sqrt(d)) / (2 * a);
				panel1->Visible = true;
				label16->Text = "x1 = " + Math::Round(x1, 3).ToString();
				label17->Text = "x2 = " + Math::Round(x2, 3).ToString();
				return;
			}
		}
		else {
			MessageBox::Show("Ошибка! Проверьте введенные данные.");
		}
	}
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox1->Checked) {
		yravnenie->Text = "a * z^2 + b * z + c = 0";
		Y1->Visible = true;
		Y2->Visible = true;
		Y3->Visible = true;
		panel4->Visible = true;
		plus1->Visible = true;
		plus2->Visible = true;
		plus3->Visible = true;
	}
	else {
		yravnenie->Text = "a * x^2 + b * x + c = 0";
		panel4->Visible = false;
		Y1->Visible = false;
		Y2->Visible = false;
		Y3->Visible = false;
		plus1->Visible = false;
		plus2->Visible = false;
		plus3->Visible = false;
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	X1->Text = ""; X2->Text = ""; X3->Text = "";
	Y1->Text = ""; Y2->Text = ""; Y3->Text = "";
	label16->Text = "";
	label17->Text = "";
}
private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Y1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
