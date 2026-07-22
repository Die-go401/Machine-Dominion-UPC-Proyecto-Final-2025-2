#pragma once
#include "Historia3_parte3.h"
#include "Derrota3.h"
namespace MachineDominion {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Historia3_parte2
	/// </summary>
	public ref class Historia3_parte2 : public System::Windows::Forms::Form
	{
	private:
	private:
		/// <summary>
		AxWMPLib::AxWindowsMediaPlayer^ Narrador;
		AxWMPLib::AxWindowsMediaPlayer^ Narrador2;
		AxWMPLib::AxWindowsMediaPlayer^ Click;
		// --PARA EL TEXTO--
		String^ textoCompleto;
		int indice;

		// --PARA LAS IMAGENES--
		cli::array<Image^>^ imagenesIntro;
		cli::array<Image^>^ imagenesCap1;
		cli::array<Image^>^ imagenesActuales;
	private: System::Windows::Forms::Timer^ timerImagenes;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label2;

		int indiceImagen;
	public:
		Historia3_parte2(void)
		{
			InitializeComponent();
			//
			Click = gcnew AxWMPLib::AxWindowsMediaPlayer();
			Click->CreateControl();
			Click->URL = "audio/CLICK.wav";
			Click->Ctlcontrols->stop();

			Narrador = gcnew AxWMPLib::AxWindowsMediaPlayer();
			Narrador->CreateControl();
			Narrador->URL = "audio/Historia3_parte2.mp3";
			Narrador->Ctlcontrols->play();

			imagenesIntro = gcnew cli::array<Image^>(2);
			imagenesIntro[0] = Image::FromFile("Imagenes/Gif25.gif");
			imagenesIntro[1] = Image::FromFile("Imagenes/Gif24.gif");

			// al inicio usamos las imágenes de la intro
			imagenesActuales = imagenesIntro;

			indiceImagen = 0;
			pictureBox1->Image = imagenesActuales[indiceImagen];

			timerImagenes->Start();
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Historia3_parte2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button3;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::ComponentModel::IContainer^ components;

	protected:






	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Historia3_parte2::typeid));
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timerImagenes = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(685, 566);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(86, 27);
			this->button3->TabIndex = 23;
			this->button3->Text = L"siguiente";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &Historia3_parte2::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(821, 324);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(86, 27);
			this->button2->TabIndex = 22;
			this->button2->Text = L"siguiente";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(685, 566);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 27);
			this->button1->TabIndex = 21;
			this->button1->Text = L"siguiente";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Historia3_parte2::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(41, 471);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 20;
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
			this->pictureBox2->TabIndex = 19;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(1, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(814, 618);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 18;
			this->pictureBox1->TabStop = false;
			// 
			// timerImagenes
			// 
			this->timerImagenes->Interval = 10000;
			this->timerImagenes->Tick += gcnew System::EventHandler(this, &Historia3_parte2::timerImagenes_Tick);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button6);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(65, 92);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(684, 376);
			this->panel1->TabIndex = 24;
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
			this->button4->Text = L"Le pido que verifique la fuente y transcriba la informacion de forma humana para "
				L"que parezca propia.";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Historia3_parte2::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(17, 211);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(646, 60);
			this->button5->TabIndex = 2;
			this->button5->Text = L"Me tomo mi tiempo en verificar la confiabilidad de la fuente, para despues coloca"
				L"r mi uso de IA.";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Historia3_parte2::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(17, 111);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(646, 79);
			this->button6->TabIndex = 1;
			this->button6->Text = L"Uso la fuente y confio en que es de confiabilidad,pues la IA investiga por toda i"
				L"nternet.";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Historia3_parte2::button6_Click);
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
			this->label2->Size = System::Drawing::Size(657, 40);
			this->label2->TabIndex = 0;
			this->label2->Text = L"¿Cuando le preguntas a la IA, confías plenamente en la respuesta que te da\?\r\n¿Cóm"
				L"o usarías la IA en un contexto de gran importancia\?";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// Historia3_parte2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(816, 618);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Historia3_parte2";
			this->Text = L"Historia3_parte2";
			this->Load += gcnew System::EventHandler(this, &Historia3_parte2::Historia3_parte2_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timerImagenes_Tick(System::Object^ sender, System::EventArgs^ e) {
		indiceImagen++;

		// Si ya llegamos al final del array, detener el timer
		if (indiceImagen >= imagenesActuales->Length) {
			timerImagenes->Stop();  // Detiene la rotación
			indiceImagen = imagenesActuales->Length - 1; // Mantener la última imagen
			return;
		}

		pictureBox1->Image = imagenesActuales[indiceImagen];
	}
private: System::Void Historia3_parte2_Load(System::Object^ sender, System::EventArgs^ e) {
	pictureBox2->Visible = false;
	label1->Visible = false;

	pictureBox2->Parent = pictureBox1;
	pictureBox2->BackColor = Color::Transparent;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Click->Ctlcontrols->stop();
	Click->Ctlcontrols->play();

	Narrador->Ctlcontrols->stop();
	// Paramos el timer de nuevo
	timerImagenes->Stop();
	// Cambiamos el backgroundimage del form y desactivamos el picturebox de los gif para la transparencia del panel
	this->BackgroundImage = Image::FromFile("Imagenes/PreguntaMundo3.png");
	//Activamos el panel
	panel1->Visible = true;
	panel1->BackColor = Color::FromArgb(160, 255, 255, 255);

	pictureBox2->Visible = false;
	label1->Visible = false;
	button1->Visible = false;
	pictureBox1->Visible = false;
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	Click->Ctlcontrols->stop();
	Click->Ctlcontrols->play();
	Historia3_parte3^ m = gcnew Historia3_parte3();
	this->Hide();
	m->ShowDialog();
	this->Close();

}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	Click->Ctlcontrols->stop();
	Click->Ctlcontrols->play();
	Derrota3^ m = gcnew Derrota3();
	this->Hide();
	m->ShowDialog();
	this->Close();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	Click->Ctlcontrols->stop();
	Click->Ctlcontrols->play();
	Derrota3^ m = gcnew Derrota3();
	this->Hide();
	m->ShowDialog();
	this->Close();
}
};
}
