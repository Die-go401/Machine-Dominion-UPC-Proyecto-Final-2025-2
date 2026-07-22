#pragma once

namespace MachineDominion {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	/// <summary>
	/// Resumen de Derrota3
	/// </summary>
	public ref class Derrota3 : public System::Windows::Forms::Form
	{
	private:
		SoundPlayer^ reproductor;
	public:
		Derrota3(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Derrota3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:

	private:
		/// <summary>
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Derrota3::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Stencil", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(622, 500);
			this->button1->Name = L"button1";
			this->button1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button1->Size = System::Drawing::Size(150, 39);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Salir";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Derrota3::button1_Click);
			// 
			// Derrota3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(784, 551);
			this->Controls->Add(this->button1);
			this->Name = L"Derrota3";
			this->Load += gcnew System::EventHandler(this, &Derrota3::Derrota3_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Derrota3_Load(System::Object^ sender, System::EventArgs^ e) {
		String^ ruta = System::IO::Path::Combine(Application::StartupPath, "AUDIOS", "derrota.wav");
		reproductor = gcnew SoundPlayer(ruta);
		reproductor->PlayLooping(); 
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		reproductor->Stop();
		this->Close();
	}
	};
}
