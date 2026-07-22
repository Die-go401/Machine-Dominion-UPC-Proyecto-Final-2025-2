#pragma once
#include <iostream>
#include "Creditos.h"
#include "Mundo1.h"
#include "Mundo2.h"
#include "Mundo2_2.h"
#include "Historia1_parte1.h"
#include "Historia2_parte3.h"
#include "Historia2_parte4.h"
#include "Historia3_parte1.h"
#include "Historia3_parte2.h"
#include "Historia3_parte3.h"
#include "Ranking.h"
#include "Nombre.h"
#include "Principal.h"
namespace MachineDominion {

	using namespace System::Media;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MENU
	/// </summary>
	public ref class MENU : public System::Windows::Forms::Form
	{
	public:
		MENU(void)
		{
			InitializeComponent();
			//
			// 
			
			AudioCh1 = gcnew AxWMPLib::AxWindowsMediaPlayer();
			AudioCh1->CreateControl();
			AudioCh1->URL = "audio/MusicaMenu.flac";
			AudioCh1->Ctlcontrols->play();
			
		}
		
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MENU()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_PLAY;
	protected:
	private: System::Windows::Forms::Button^ button_CREDIT;
	private: System::Windows::Forms::PictureBox^ pictureBox_LOGO_UPC;
	private: System::Windows::Forms::Button^ button_EXIT;



	private:
		/// <summary>
		AxWMPLib::AxWindowsMediaPlayer^ AudioCh1;
	private: System::Windows::Forms::Button^ button1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MENU::typeid));
			this->button_PLAY = (gcnew System::Windows::Forms::Button());
			this->button_CREDIT = (gcnew System::Windows::Forms::Button());
			this->button_EXIT = (gcnew System::Windows::Forms::Button());
			this->pictureBox_LOGO_UPC = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_LOGO_UPC))->BeginInit();
			this->SuspendLayout();
			// 
			// button_PLAY
			// 
			this->button_PLAY->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_PLAY.BackgroundImage")));
			this->button_PLAY->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button_PLAY->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_PLAY->Location = System::Drawing::Point(270, 361);
			this->button_PLAY->Margin = System::Windows::Forms::Padding(2);
			this->button_PLAY->Name = L"button_PLAY";
			this->button_PLAY->Size = System::Drawing::Size(179, 50);
			this->button_PLAY->TabIndex = 0;
			this->button_PLAY->UseVisualStyleBackColor = true;
			this->button_PLAY->Click += gcnew System::EventHandler(this, &MENU::button_PLAY_Click);
			this->button_PLAY->MouseEnter += gcnew System::EventHandler(this, &MENU::button_PLAY_MouseEnter);
			this->button_PLAY->MouseLeave += gcnew System::EventHandler(this, &MENU::button_PLAY_MouseLeave);
			// 
			// button_CREDIT
			// 
			this->button_CREDIT->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_CREDIT.BackgroundImage")));
			this->button_CREDIT->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button_CREDIT->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_CREDIT->Location = System::Drawing::Point(270, 424);
			this->button_CREDIT->Margin = System::Windows::Forms::Padding(2);
			this->button_CREDIT->Name = L"button_CREDIT";
			this->button_CREDIT->Size = System::Drawing::Size(179, 50);
			this->button_CREDIT->TabIndex = 1;
			this->button_CREDIT->UseVisualStyleBackColor = true;
			this->button_CREDIT->Click += gcnew System::EventHandler(this, &MENU::button_CREDIT_Click);
			this->button_CREDIT->MouseEnter += gcnew System::EventHandler(this, &MENU::button_CREDIT_MouseEnter);
			this->button_CREDIT->MouseLeave += gcnew System::EventHandler(this, &MENU::button_CREDIT_MouseLeave);
			// 
			// button_EXIT
			// 
			this->button_EXIT->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_EXIT.BackgroundImage")));
			this->button_EXIT->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button_EXIT->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_EXIT->Location = System::Drawing::Point(270, 548);
			this->button_EXIT->Margin = System::Windows::Forms::Padding(2);
			this->button_EXIT->Name = L"button_EXIT";
			this->button_EXIT->Size = System::Drawing::Size(179, 47);
			this->button_EXIT->TabIndex = 2;
			this->button_EXIT->UseVisualStyleBackColor = true;
			this->button_EXIT->Click += gcnew System::EventHandler(this, &MENU::button_EXIT_Click);
			this->button_EXIT->MouseEnter += gcnew System::EventHandler(this, &MENU::button_EXIT_MouseEnter);
			this->button_EXIT->MouseLeave += gcnew System::EventHandler(this, &MENU::button_EXIT_MouseLeave);
			// 
			// pictureBox_LOGO_UPC
			// 
			this->pictureBox_LOGO_UPC->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox_LOGO_UPC->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_LOGO_UPC.Image")));
			this->pictureBox_LOGO_UPC->Location = System::Drawing::Point(630, 548);
			this->pictureBox_LOGO_UPC->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox_LOGO_UPC->Name = L"pictureBox_LOGO_UPC";
			this->pictureBox_LOGO_UPC->Size = System::Drawing::Size(94, 76);
			this->pictureBox_LOGO_UPC->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox_LOGO_UPC->TabIndex = 3;
			this->pictureBox_LOGO_UPC->TabStop = false;
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Location = System::Drawing::Point(270, 488);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(179, 47);
			this->button1->TabIndex = 4;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MENU::button1_Click);
			this->button1->MouseEnter += gcnew System::EventHandler(this, &MENU::button1_MouseEnter);
			this->button1->MouseLeave += gcnew System::EventHandler(this, &MENU::button1_MouseLeave);
			// 
			// MENU
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(723, 634);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox_LOGO_UPC);
			this->Controls->Add(this->button_EXIT);
			this->Controls->Add(this->button_CREDIT);
			this->Controls->Add(this->button_PLAY);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MENU";
			this->Text = L"MENU";
			this->Load += gcnew System::EventHandler(this, &MENU::MENU_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_LOGO_UPC))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MENU_Load(System::Object^ sender, System::EventArgs^ e) 
	{
	}
	private: System::Void button_PLAY_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		AudioCh1->Ctlcontrols->stop();
		String^ ruta = System::IO::Path::Combine(Application::StartupPath, "AUDIOS", "CLICK_CONFIRM.wav");
		ReproducirSonido(ruta);
		
		Nombre^ a = gcnew Nombre();
		a->ShowDialog();

		//primero->getNombre()
		Historia1_parte1^ m = gcnew Historia1_parte1(a);
		//Mundo3^ m = gcnew Mundo3(a);
		m->ShowDialog();
	}
private: System::Void button_EXIT_Click(System::Object^ sender, System::EventArgs^ e) 
{
	String^ ruta = System::IO::Path::Combine(Application::StartupPath, "AUDIOS", "CLICK_CONFIRM.wav");
	ReproducirSonido(ruta);
	_sleep(1000);
	this->Close();
}
private: System::Void button_CREDIT_Click(System::Object^ sender, System::EventArgs^ e) 
{
	/*AudioCh1->Ctlcontrols->stop();*/
	String^ ruta = System::IO::Path::Combine(Application::StartupPath, "AUDIOS", "CLICK_CONFIRM.wav");
	ReproducirSonido(ruta);

	Creditos^ Ventana = gcnew Creditos();
	// Hace que la ventana de créditos aparezca en la misma posición que el formulario actual
	Ventana->StartPosition = FormStartPosition::Manual;
	Ventana->Location = this->Location;

	Ventana->ShowDialog();
}
private: System::Void button_PLAY_MouseEnter(System::Object^ sender, System::EventArgs^ e)
{
	String^ ruta = System::IO::Path::Combine(Application::StartupPath, "AUDIOS", "CLICK.wav");
	ReproducirSonido(ruta);

	String^ ruta1 = System::IO::Path::Combine(Application::StartupPath, "RECURSOS VISUALES", "PLAY_GRIS.png");
	button_PLAY->BackgroundImage = Image::FromFile(ruta1);
}
private: System::Void button_PLAY_MouseLeave(System::Object^ sender, System::EventArgs^ e) 
{
	String^ ruta = System::IO::Path::Combine(Application::StartupPath, "RECURSOS VISUALES", "PLAY.png");
	button_PLAY->BackgroundImage = Image::FromFile(ruta);
}
private: System::Void button_CREDIT_MouseEnter(System::Object^ sender, System::EventArgs^ e) 
{
	String^ ruta = System::IO::Path::Combine(Application::StartupPath, "AUDIOS", "CLICK.wav");
	ReproducirSonido(ruta);

	String^ ruta1 = System::IO::Path::Combine(Application::StartupPath, "RECURSOS VISUALES", "CREDIT_GRIS.png");
	button_CREDIT->BackgroundImage = Image::FromFile(ruta1);
}

private: System::Void button_CREDIT_MouseLeave(System::Object^ sender, System::EventArgs^ e) 
{
	String^ ruta = System::IO::Path::Combine(Application::StartupPath, "RECURSOS VISUALES", "CREDIT.png");
	button_CREDIT->BackgroundImage = Image::FromFile(ruta);
}
private: System::Void button_EXIT_MouseEnter(System::Object^ sender, System::EventArgs^ e) 
{
	String^ ruta = System::IO::Path::Combine(Application::StartupPath, "AUDIOS", "CLICK.wav");
	ReproducirSonido(ruta);

	String^ ruta1 = System::IO::Path::Combine(Application::StartupPath, "RECURSOS VISUALES", "EXIT_GRIS.png");
	button_EXIT->BackgroundImage = Image::FromFile(ruta1);
}
private: System::Void button_EXIT_MouseLeave(System::Object^ sender, System::EventArgs^ e) 
{
	String^ ruta = System::IO::Path::Combine(Application::StartupPath, "RECURSOS VISUALES", "EXIT.png");
	button_EXIT->BackgroundImage = Image::FromFile(ruta);
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ ruta = System::IO::Path::Combine(Application::StartupPath, "AUDIOS", "CLICK_CONFIRM.wav");
	ReproducirSonido(ruta);
	Ranking^ m = gcnew Ranking();
	m->ShowDialog();

}

private: System::Void button1_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	String^ ruta = System::IO::Path::Combine(Application::StartupPath, "AUDIOS", "CLICK.wav");
	ReproducirSonido(ruta);

	String^ ruta1 = System::IO::Path::Combine("Imagenes/Rankingnegro.jpg");
	button1->BackgroundImage = Image::FromFile(ruta1);
}
private: System::Void button1_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	String^ ruta = System::IO::Path::Combine("Imagenes/Ranking.jpg");
	button1->BackgroundImage = Image::FromFile(ruta);

	

}
};
}
