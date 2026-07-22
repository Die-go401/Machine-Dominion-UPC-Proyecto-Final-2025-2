#pragma once

namespace MachineDominion {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Nombre
	/// </summary>
	public ref class Nombre : public System::Windows::Forms::Form
	{
	public:
		Nombre(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		String^ getName()
		{
			return nombre;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Nombre()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;

	private:
		/// <summary>
		String^ nombre;
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(589, 218);
			this->panel1->TabIndex = 13;
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(169, 139);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(192, 50);
			this->button4->TabIndex = 2;
			this->button4->Text = L"ACEPTAR";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Nombre::button4_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(3, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(530, 69);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Ingresa tu nombre";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(15, 72);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(506, 49);
			this->textBox1->TabIndex = 0;
			// 
			// Nombre
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(590, 217);
			this->Controls->Add(this->panel1);
			this->Name = L"Nombre";
			this->Text = L"Nombre";
			this->Load += gcnew System::EventHandler(this, &Nombre::Nombre_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		nombre = textBox1->Text;
		this->Close();
	}
private: System::Void Nombre_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
