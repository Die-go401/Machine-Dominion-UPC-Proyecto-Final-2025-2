#pragma once
#include "Controlador1.h"
#include "Derrota1.h"
#include "Historia1_parte2.h"
#include "Nombre.h"
namespace MachineDominion {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Mundo1
	/// </summary>
	public ref class Mundo1 : public System::Windows::Forms::Form
	{
	private:
		Nombre^ nom;
		AxWMPLib::AxWindowsMediaPlayer^ SonidoBala;
		AxWMPLib::AxWindowsMediaPlayer^ SonidoBalaE;
		AxWMPLib::AxWindowsMediaPlayer^ SonidoExplosion;
		AxWMPLib::AxWindowsMediaPlayer^ SonidoChip;
		AxWMPLib::AxWindowsMediaPlayer^ Musica;
		Controlador1* control1;
		Bitmap^ spritePrincipal;
		Bitmap^ spriteSoldados;
		Bitmap^ BalaPrincipal;
		Bitmap^ BalaSoldado;
		Bitmap^ Laboratorio;
		Bitmap^ Explocion;
		Bitmap^ Acechador;
		bool teclaE_Presionada;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

		   Bitmap^ chip;
	public:
		Mundo1(Nombre^h)
		{
			InitializeComponent();
			nom = h;
			this->KeyPreview = true;

			Musica = gcnew AxWMPLib::AxWindowsMediaPlayer();
			Musica->CreateControl();
			Musica->URL = "audio/Mundo1.mp3";
			Musica->Ctlcontrols->play();

			SonidoBala = gcnew AxWMPLib::AxWindowsMediaPlayer();
			SonidoBala->CreateControl();
			SonidoBala->URL = "audio/SonidoBala.mp3";
			SonidoBala->Ctlcontrols->stop();

			SonidoBalaE = gcnew AxWMPLib::AxWindowsMediaPlayer();
			SonidoBalaE->CreateControl();
			SonidoBalaE->URL = "audio/SonidoBalaE.mp3";
			SonidoBalaE->Ctlcontrols->stop();
			
			SonidoExplosion = gcnew AxWMPLib::AxWindowsMediaPlayer();
			SonidoExplosion->CreateControl();
			SonidoExplosion->URL = "audio/SonidoExplosion.wav";
			SonidoExplosion->Ctlcontrols->stop();

			SonidoChip = gcnew AxWMPLib::AxWindowsMediaPlayer();
			SonidoChip->CreateControl();
			SonidoChip->URL = "audio/SonidoChip.wav";
			SonidoChip->Ctlcontrols->stop();

			control1 = new Controlador1();
			spritePrincipal = gcnew Bitmap("Imagenes/Principal.png");
			spriteSoldados = gcnew Bitmap("Imagenes/Robot.png");
			BalaPrincipal = gcnew Bitmap("Imagenes/balaPrincipal.png");
			BalaSoldado = gcnew Bitmap("Imagenes/balaEnemigo.png");
			Laboratorio = gcnew Bitmap("Imagenes/mdo1.png");
			chip = gcnew Bitmap("Imagenes/chips.png");
			Acechador = gcnew Bitmap("Imagenes/acechador.png");
			Explocion = gcnew Bitmap("Imagenes/explocion.png");
			teclaE_Presionada = false;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Mundo1()
		{
			if (components)
			{
				delete components;
			}
			delete control1;
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Mundo1::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Mundo1::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1012, 935);
			this->panel1->TabIndex = 0;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel4->Controls->Add(this->label9);
			this->panel4->Controls->Add(this->label8);
			this->panel4->Controls->Add(this->pictureBox3);
			this->panel4->Controls->Add(this->pictureBox2);
			this->panel4->Controls->Add(this->pictureBox1);
			this->panel4->Controls->Add(this->button6);
			this->panel4->Controls->Add(this->label6);
			this->panel4->Controls->Add(this->label7);
			this->panel4->Location = System::Drawing::Point(228, 165);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(723, 366);
			this->panel4->TabIndex = 22;
			this->panel4->Visible = false;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Yellow;
			this->label9->Location = System::Drawing::Point(428, 126);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(248, 32);
			this->label9->TabIndex = 25;
			this->label9->Text = L"RECOGER CHIPS";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Yellow;
			this->label8->Location = System::Drawing::Point(428, 225);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(157, 32);
			this->label8->TabIndex = 24;
			this->label8->Text = L"DISPARAR";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(41, 126);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(204, 148);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 23;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(308, 205);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(100, 69);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 22;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(308, 114);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 69);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 21;
			this->pictureBox1->TabStop = false;
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(320, 297);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(98, 39);
			this->button6->TabIndex = 20;
			this->button6->Text = L"Cerrar";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Mundo1::button6_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Yellow;
			this->label6->Location = System::Drawing::Point(52, 85);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(193, 32);
			this->label6->TabIndex = 18;
			this->label6->Text = L"MOVIMIENTO\r\n";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Yellow;
			this->label7->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label7->Location = System::Drawing::Point(200, 18);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(325, 54);
			this->label7->TabIndex = 19;
			this->label7->Text = L"CONTROLES";
			this->label7->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Location = System::Drawing::Point(12, 12);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(278, 453);
			this->panel2->TabIndex = 2;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label5->Location = System::Drawing::Point(3, 204);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(234, 50);
			this->label5->TabIndex = 4;
			this->label5->Text = L"OBJETIVO:\r\nRECOLECTA 8 CHIPS";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label4->Location = System::Drawing::Point(3, 153);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(221, 25);
			this->label4->TabIndex = 3;
			this->label4->Text = L"CHIPS RESTANTES:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label3->Location = System::Drawing::Point(3, 109);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(85, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"VIDAS:";
			this->label3->Click += gcnew System::EventHandler(this, &Mundo1::label3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label2->Location = System::Drawing::Point(3, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"NOMBRE:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(51, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(176, 38);
			this->label1->TabIndex = 0;
			this->label1->Text = L"MUNDO 1";
			this->label1->Click += gcnew System::EventHandler(this, &Mundo1::label1_Click);
			// 
			// panel3
			// 
			this->panel3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel3.BackgroundImage")));
			this->panel3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel3->Controls->Add(this->panel2);
			this->panel3->Location = System::Drawing::Point(1010, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(308, 935);
			this->panel3->TabIndex = 0;
			// 
			// Mundo1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1312, 937);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel3);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Mundo1";
			this->Text = L"Mundo1";
			this->Load += gcnew System::EventHandler(this, &Mundo1::Mundo1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Mundo1::Mundo1_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Mundo1::Mundo1_KeyUp);
			this->panel1->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Mundo1_Load(System::Object^ sender, System::EventArgs^ e) {
		panel2->BackColor = Color::FromArgb(160, 0, 0, 0);
		panel4->BackColor = Color::FromArgb(160, 0, 0, 0);
		panel4->Visible = true;

		/*pictureBox1->Parent = panel4;
		pictureBox2->Parent = panel4;
		pictureBox3->Parent = panel4;*/
		
		/*panel2->BringToFront();*/
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = panel1->CreateGraphics();
		BufferedGraphicsContext^ intervalo = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = intervalo->Allocate(g, panel1->ClientRectangle);
		//Borrar
		buffer->Graphics->DrawImage(panel1->BackgroundImage, panel1->ClientRectangle);
		
		//Estadisticas
		label2->Text = "NOMBRE: " + nom->getName();
		label3->Text = "VIDAS: " + control1->getJugador()->getVida(); 
		label4->Text = "CHIPS RESTANTES: " + control1->getChips().size();
		//Mover y dibujar
		control1->dibujarChips(buffer->Graphics, chip);
		control1->AgregarSoldado(buffer->Graphics);
		control1->AgregarAcechador(buffer->Graphics);
		control1->ControlPrincipal(buffer->Graphics, spritePrincipal, BalaPrincipal);
		control1->ControlSoldados(buffer->Graphics, spriteSoldados, BalaSoldado);
		control1->ControlAcechadores(buffer->Graphics, Acechador);
		control1->ControlColisiones(buffer->Graphics,teclaE_Presionada,Explocion);
		//Sonidos x-x
		for (int i = 0; i < control1->getSoldados().size(); i++)
		{
			if(control1->getSoldados()[i]->getsonidosBalaEnemigo())
			{
				SonidoBalaE->Ctlcontrols->stop();
				SonidoBalaE->Ctlcontrols->play();

				control1->getSoldados()[i]->setsonidoBalaEnemigo(false);
			}
		}
		if(control1->getsonidosExplosion())
		{
			SonidoExplosion->Ctlcontrols->stop();
			SonidoExplosion->Ctlcontrols->play();

			control1->setsonidoExplosion(false);
		}
		if (control1->getsonidosChip())
		{
			SonidoChip->Ctlcontrols->stop();
			SonidoChip->Ctlcontrols->play();

			control1->setsonidoChip(false);
		}

		if (control1->getChips().size() == 0) {
			timer1->Stop();
			Musica->Ctlcontrols->stop();
			Historia1_parte2^ c2 = gcnew Historia1_parte2(nom);
			this->Hide();
			c2->ShowDialog();
			this->Close();
		
		}
		if (control1->getJugador()->getVida() <= 0) {
			timer1->Stop();
			Musica->Ctlcontrols->stop();
			Derrota1^ c2 = gcnew Derrota1();
			this->Hide();
			c2->ShowDialog();
			this->Close();
		}


		buffer->Render(g);

		delete buffer;
		delete g;
		delete intervalo;
	}


	private: System::Void Mundo1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Up: {
			control1->getJugador()->setDireccion(Arriba);
			break;

		}
		case Keys::Down: {
			control1->getJugador()->setDireccion(Abajo);
			break;

		}
		case Keys::Left: {
			control1->getJugador()->setDireccion(Izquierda);
			break;

		}
		case Keys::Right: {
			control1->getJugador()->setDireccion(Derecha);
			break;

		}
		case Keys::Q: {
			SonidoBala->Ctlcontrols->stop();
			SonidoBala->Ctlcontrols->play();
			control1->getJugador()->disparar();
			break;
		}
		case Keys::E: {
			teclaE_Presionada = true;
		}
				


		}


	}
	private: System::Void Mundo1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		control1->getJugador()->setDireccion(Ninguna);
		if (e->KeyCode == Keys::E) {
			teclaE_Presionada = false;
		}
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	panel4->Visible = false;
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
