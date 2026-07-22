#pragma once
#include "Historia2_parte1.h"
#include "Derrota1.h"
#include "Nombre.h"
namespace MachineDominion {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Historia1_parte2
	/// </summary>
	public ref class Historia1_parte2 : public System::Windows::Forms::Form
	{
	public:
		Historia1_parte2(Nombre^h)
		{
			InitializeComponent();
			//
			nom = h;
			Click = gcnew AxWMPLib::AxWindowsMediaPlayer();
			Click->CreateControl();
			Click->URL = "audio/CLICK.wav";
			Click->Ctlcontrols->stop();

			Narrador = gcnew AxWMPLib::AxWindowsMediaPlayer();
			Narrador->CreateControl();
			Narrador->URL = "audio/NarradorMundo1_3.mp3";
			Narrador->Ctlcontrols->play();

			imagenesIntro = gcnew cli::array<Image^>(3);
			imagenesIntro[0] = Image::FromFile("Imagenes/Gif9.gif");
			imagenesIntro[1] = Image::FromFile("Imagenes/Gif10.gif");
			imagenesIntro[2] = Image::FromFile("Imagenes/Gif11.gif");


			// al inicio usamos las imágenes de la intro
			imagenesActuales = imagenesIntro;

			indiceImagen = 0;
			pictureBox1->Image = imagenesActuales[indiceImagen];

			timerImagenes->Start();
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Historia1_parte2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private:
		/// <summary>
		Nombre^ nom;
		AxWMPLib::AxWindowsMediaPlayer^ Narrador;
		AxWMPLib::AxWindowsMediaPlayer^ Click;
		// --PARA EL TEXTO--
		String^ textoCompleto;
		int indice;

		// --PARA LAS IMAGENES--
		cli::array<Image^>^ imagenesIntro;
		cli::array<Image^>^ imagenesCap1;
		cli::array<Image^>^ imagenesActuales;
		int indiceImagen;
	private: System::Windows::Forms::Timer^ timerTexto;
	private: System::Windows::Forms::Timer^ timerImagenes;

	private: System::ComponentModel::IContainer^ components;
		   /// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		void imprimir_lento(String^ texto)
		{
			textoCompleto = texto;
			indice = 0;
			label1->Text = "";   // limpiar el texto
			timerTexto->Start();     // usar el timer del diseñador
		}
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Historia1_parte2::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timerTexto = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerImagenes = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(73, 79);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(684, 376);
			this->panel1->TabIndex = 17;
			this->panel1->Visible = false;
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(17, 292);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(646, 60);
			this->button4->TabIndex = 3;
			this->button4->Text = L"La IA debería encargarse de todo lo posible, porque confiar en ella es más eficie"
				L"nte que seguir dependiendo de las limitaciones humanas.";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Historia1_parte2::button4_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(17, 211);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(646, 60);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Depender demasiado de la IA destruye nuestra autonomía y nos convierte en seres i"
				L"ncapaces de generar ideas propias.";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Historia1_parte2::button3_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(17, 130);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(646, 60);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Aunque la IA facilita muchas tareas, debemos usarla con equilibrio para no perder"
				L" nuestra capacidad de razonar y decidir de forma independiente.\n";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Historia1_parte2::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(13, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(578, 40);
			this->label2->TabIndex = 0;
			this->label2->Text = L"¿Hasta qué punto la comodidad que ofrece la IA justifica renunciar \r\na nuestra au"
				L"tonomía y pensamiento crítico\?";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(685, 566);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 27);
			this->button1->TabIndex = 16;
			this->button1->Text = L"siguiente";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Historia1_parte2::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(41, 471);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 15;
			this->label1->Text = L"label1";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(1, 445);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(814, 173);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 14;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(1, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(814, 618);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			// 
			// timerTexto
			// 
			this->timerTexto->Interval = 20;
			this->timerTexto->Tick += gcnew System::EventHandler(this, &Historia1_parte2::timerTexto_Tick);
			// 
			// timerImagenes
			// 
			this->timerImagenes->Interval = 10000;
			this->timerImagenes->Tick += gcnew System::EventHandler(this, &Historia1_parte2::timerImagenes_Tick);
			// 
			// Historia1_parte2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(816, 618);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Historia1_parte2";
			this->Text = L"Historia1_parte2";
			this->Load += gcnew System::EventHandler(this, &Historia1_parte2::Historia1_parte2_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Historia1_parte2_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		pictureBox2->Visible = false;
		label1->Visible = false;

		pictureBox2->Parent = pictureBox1;
		pictureBox2->BackColor = Color::Transparent;
		imprimir_lento("Tras reunir los ocho chips, el protagonista logra abrir la puerta del laboratorio. Allí encuentra el Reloj del Tiempo, el\n único artefacto capaz de cambiar el destino del mundo. Pero los robots ya lo han rastreado.Sus pasos metálicos se\n acercan, implacables. Sin otra opción, toma el reloj con desesperación : es su única vía para escapar… y quizá\n para reescribir el futuro antes de que lo alcancen.");
	}
private: System::Void timerTexto_Tick(System::Object^ sender, System::EventArgs^ e) 
{
	if (indice < textoCompleto->Length)
	{
		label1->Text += textoCompleto[indice];
		indice++;
	}
	else
	{
		timerTexto->Stop();
	}
}
private: System::Void timerImagenes_Tick(System::Object^ sender, System::EventArgs^ e) 
{
	indiceImagen++;

	// Si ya llegamos al final del array, detener el timer
	if (indiceImagen >= imagenesActuales->Length) {
		timerImagenes->Stop();  // Detiene la rotación
		indiceImagen = imagenesActuales->Length - 1; // Mantener la última imagen
		return;
	}

	pictureBox1->Image = imagenesActuales[indiceImagen];
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Click->Ctlcontrols->stop();
	Click->Ctlcontrols->play();

	Narrador->Ctlcontrols->stop();
	// Paramos el timer de nuevo
	timerImagenes->Stop();
	// Cambiamos el backgroundimage del form y desactivamos el picturebox de los gif para la transparencia del panel
	this->BackgroundImage = Image::FromFile("Imagenes/PreguntaMundo1.png");
	//Activamos el panel
	panel1->Visible = true;
	panel1->BackColor = Color::FromArgb(160, 255, 255, 255);

	pictureBox2->Visible = false;
	label1->Visible = false;
	button1->Visible = false;
	pictureBox1->Visible = false;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Click->Ctlcontrols->stop();
	Click->Ctlcontrols->play();

	Historia2_parte1^ c2 = gcnew Historia2_parte1(nom);
	this->Hide();
	c2->ShowDialog();
	this->Close();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Click->Ctlcontrols->stop();
	Click->Ctlcontrols->play();
	Derrota1^ c2 = gcnew Derrota1();
	this->Hide();
	c2->ShowDialog();
	this->Close();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Click->Ctlcontrols->stop();
	Click->Ctlcontrols->play();
	Derrota1^ c2 = gcnew Derrota1();
	this->Hide();
	c2->ShowDialog();
	this->Close();
}
};
}
