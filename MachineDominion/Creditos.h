#pragma once
#include <iostream>
namespace MachineDominion {

	using namespace System::Media;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Creditos
	/// </summary>
	public ref class Creditos : public System::Windows::Forms::Form
	{
	public:
		Creditos(void)
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
		~Creditos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_BACK;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		void ReproducirSonido(String^ ruta)
		{
			try
			{
				SoundPlayer^ sp = gcnew SoundPlayer(ruta);
				sp->Play(); // Usa sp->PlaySync() si quieres que espere a que termine
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error al reproducir sonido: " + ex->Message);
			}
		}
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Creditos::typeid));
			this->button_BACK = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button_BACK
			// 
			this->button_BACK->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_BACK.BackgroundImage")));
			this->button_BACK->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button_BACK->Location = System::Drawing::Point(757, 727);
			this->button_BACK->Name = L"button_BACK";
			this->button_BACK->Size = System::Drawing::Size(213, 88);
			this->button_BACK->TabIndex = 0;
			this->button_BACK->UseVisualStyleBackColor = true;
			this->button_BACK->Click += gcnew System::EventHandler(this, &Creditos::button_BACK_Click);
			this->button_BACK->MouseEnter += gcnew System::EventHandler(this, &Creditos::button_BACK_MouseEnter);
			this->button_BACK->MouseLeave += gcnew System::EventHandler(this, &Creditos::button_BACK_MouseLeave);
			// 
			// Creditos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(982, 827);
			this->Controls->Add(this->button_BACK);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Creditos";
			this->Text = L"Creditos";
			this->Load += gcnew System::EventHandler(this, &Creditos::Creditos_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Creditos_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button_BACK_MouseEnter(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ ruta = System::IO::Path::Combine(Application::StartupPath, "AUDIOS", "CLICK.wav");
		ReproducirSonido(ruta);

		String^ ruta1 = System::IO::Path::Combine(Application::StartupPath, "RECURSOS VISUALES", "BACK_GRIS.png");
		button_BACK->BackgroundImage = Image::FromFile(ruta1);
	}
	private: System::Void button_BACK_MouseLeave(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ ruta = System::IO::Path::Combine(Application::StartupPath, "AUDIOS", "CLICK.wav");
		ReproducirSonido(ruta);

		String^ ruta1 = System::IO::Path::Combine(Application::StartupPath, "RECURSOS VISUALES", "BACK.png");
		button_BACK->BackgroundImage = Image::FromFile(ruta1);
	}
	private: System::Void button_BACK_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ ruta = System::IO::Path::Combine(Application::StartupPath, "AUDIOS", "CLICK_CONFIRM.wav");
		ReproducirSonido(ruta);
		_sleep(1000);
		this->Close();
	}
};
}
