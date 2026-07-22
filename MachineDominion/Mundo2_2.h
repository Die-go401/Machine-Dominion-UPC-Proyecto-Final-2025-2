#pragma once
#include "Controlador2_2.h"
#include "Historia2_Parte4.h"
#include "Nombre.h"
namespace MachineDominion {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de Mundo2_2
	/// </summary>
	public ref class Mundo2_2 : public System::Windows::Forms::Form
	{
	private:
		Nombre^ nom;
		AxWMPLib::AxWindowsMediaPlayer^ SonidoExplosion;
		AxWMPLib::AxWindowsMediaPlayer^ SonidoNormal;

		controlador2_2* control2_2;
		Bitmap^ spritejugador;
		Bitmap^ coco;
		Bitmap^ arania;
		Rectangle limite1;
		Rectangle limite2;
		SoundPlayer^ reproductor;
		Bitmap^ b2;
		Bitmap^ b3;
		Bitmap^ b4;
		int contador;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label10;


		   Bitmap^ Explocion;
	public:
		Mundo2_2(Nombre^h)
		{
			InitializeComponent();
			nom = h;
			this->KeyPreview = true;
			SonidoExplosion = gcnew AxWMPLib::AxWindowsMediaPlayer();
			SonidoExplosion->CreateControl();
			SonidoExplosion->URL = "audio/SonidoExplosion.wav";
			SonidoExplosion->Ctlcontrols->stop();

			SonidoNormal = gcnew AxWMPLib::AxWindowsMediaPlayer();
			SonidoNormal->CreateControl();
			SonidoNormal->URL = "audio/SonidoNormalCoco.mp3";
			SonidoNormal->Ctlcontrols->stop();


			control2_2 = new controlador2_2();
			spritejugador = gcnew Bitmap("Imagenes/Principal.png");
			coco = gcnew Bitmap("Imagenes/Cocos.png");
			arania = gcnew Bitmap("Imagenes/AraniaHorizontal.png");
			limite1 = Rectangle(panel2->Location, panel2->Size);
			limite2 = Rectangle(panel3->Location, panel3->Size);
			Explocion = gcnew Bitmap("Imagenes/explocion.png");
			contador = 0;
			b2 = gcnew Bitmap("Imagenes/AraniaHorizontal3.png");
			b3 = gcnew Bitmap("Imagenes/AraniaHorizontal2.png");
			b4 = gcnew Bitmap("Imagenes/AraniaHorizontal4.png");

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Mundo2_2()
		{
			if (components)
			{
				delete components;
			}
			delete control2_2;
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
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
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Mundo2_2::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->panel6);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1000, 935);
			this->panel1->TabIndex = 0;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel6->Controls->Add(this->label8);
			this->panel6->Controls->Add(this->pictureBox5);
			this->panel6->Controls->Add(this->pictureBox6);
			this->panel6->Controls->Add(this->button6);
			this->panel6->Controls->Add(this->label7);
			this->panel6->Controls->Add(this->label10);
			this->panel6->Location = System::Drawing::Point(139, 284);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(723, 366);
			this->panel6->TabIndex = 24;
			this->panel6->Visible = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Yellow;
			this->label8->Location = System::Drawing::Point(423, 182);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(267, 32);
			this->label8->TabIndex = 24;
			this->label8->Text = L"DISPARAR COCOS";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(41, 126);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(204, 223);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox5->TabIndex = 23;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(285, 126);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(132, 125);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox6->TabIndex = 22;
			this->pictureBox6->TabStop = false;
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
			this->button6->Click += gcnew System::EventHandler(this, &Mundo2_2::button6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Yellow;
			this->label7->Location = System::Drawing::Point(52, 85);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(193, 32);
			this->label7->TabIndex = 18;
			this->label7->Text = L"MOVIMIENTO\r\n";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::Yellow;
			this->label10->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label10->Location = System::Drawing::Point(200, 18);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(325, 54);
			this->label10->TabIndex = 19;
			this->label10->Text = L"CONTROLES";
			this->label10->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Transparent;
			this->panel3->Location = System::Drawing::Point(0, 702);
			this->panel3->Margin = System::Windows::Forms::Padding(4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1000, 220);
			this->panel3->TabIndex = 1;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1000, 233);
			this->panel2->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Mundo2_2::timer1_Tick);
			// 
			// panel4
			// 
			this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel4.BackgroundImage")));
			this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Location = System::Drawing::Point(1001, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(319, 935);
			this->panel4->TabIndex = 2;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel5->Controls->Add(this->label6);
			this->panel5->Controls->Add(this->label5);
			this->panel5->Controls->Add(this->label3);
			this->panel5->Controls->Add(this->label2);
			this->panel5->Controls->Add(this->label1);
			this->panel5->Location = System::Drawing::Point(12, 12);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(289, 442);
			this->panel5->TabIndex = 2;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label6->Location = System::Drawing::Point(3, 156);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(223, 25);
			this->label6->TabIndex = 5;
			this->label6->Text = L"TIEMPO RESTANTE:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label5->Location = System::Drawing::Point(3, 238);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(231, 175);
			this->label5->TabIndex = 4;
			this->label5->Text = L"OBJETIVO:\r\n\r\nEVITA QUE LAS \r\nARAÑAS SE \r\nACERQUEN A LA \r\nCASA DE \r\nLEONARDO DA VI"
				L"NCI";
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
			this->label1->Location = System::Drawing::Point(38, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(205, 38);
			this->label1->TabIndex = 0;
			this->label1->Text = L"MUNDO 2.2";
			// 
			// Mundo2_2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1312, 937);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Mundo2_2";
			this->Text = L"Mundo2_2";
			this->Load += gcnew System::EventHandler(this, &Mundo2_2::Mundo2_2_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Mundo2_2::Mundo2_2_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Mundo2_2::Mundo2_2_KeyUp);
			this->panel1->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			this->panel4->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Mundo2_2_Load(System::Object^ sender, System::EventArgs^ e) {
		panel6->Visible = true;
		panel6->BackColor = Color::FromArgb(160, 0, 0, 0);
		panel5->BackColor = Color::FromArgb(160, 0, 0, 0);
		String^ ruta = System::IO::Path::Combine(Application::StartupPath, "AUDIOS", "Loonboon.wav");
		reproductor = gcnew SoundPlayer(ruta);
		reproductor->Play(); 
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = panel1->CreateGraphics();
		BufferedGraphicsContext^ intervalo = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = intervalo->Allocate(g, panel1->ClientRectangle);
		//Borrar
		buffer->Graphics->DrawImage(panel1->BackgroundImage, panel1->ClientRectangle);
		//estadisticas
		label2->Text = "NOMBRE: " + nom->getName();
		label3->Text = "VIDAS: " + control2_2->getJugador()->getVida();

		label6->Text = "TIEMPO RESTANTE: \n" + contador / 1000 + "/" + "100";
		/*label4->Text = ;
		label6->Text = ;*/
		//Mover y dibujar
		control2_2->AgregarAranias();
		control2_2->ControlAranias(buffer->Graphics, arania, b2,b3,b4);
		control2_2->ControlCocos(buffer->Graphics,coco, Explocion);
		control2_2->ControlJugador(buffer->Graphics,spritejugador);
		control2_2->colisionLimites(limite1, limite2);

		//Sonidos x-x
		if (control2_2->getExplosivo())
		{
			SonidoExplosion->Ctlcontrols->stop();
			SonidoExplosion->Ctlcontrols->play();

			control2_2->setExplosion(false);
		}
		if (control2_2->getNormal())
		{
			SonidoNormal->Ctlcontrols->stop();
			SonidoNormal->Ctlcontrols->play();

			control2_2->setNormal(false);
		}
		

		if (control2_2->getDerrota() == true) {
			reproductor->Stop();
			timer1->Enabled = false;
			this->Close();
		}
		if (contador >= 100000) {
			reproductor->Stop();
			timer1->Enabled = false;
			Historia2_Parte4^ c2 = gcnew Historia2_Parte4(nom);
			this->Hide();
			c2->ShowDialog();
			this->Close();
		}
		//Intervalo de 100 milisegundos
		contador += timer1->Interval;
		buffer->Render(g);
		delete buffer;
		delete intervalo;
		delete g;
	}





	private: System::Void Mundo2_2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Up: {
			control2_2->getJugador()->setDireccion(Arriba);
			break;

		}
		case Keys::Down: {
			control2_2->getJugador()->setDireccion(Abajo);
			break;

		}
		case Keys::Q: {
			//Cuando disparamos un coco cambia el iteraY a derecha
			control2_2->getJugador()->setDireccion(Derecha);
			control2_2->AgregarCocos();
			break;

		}
		
		}


	}
private: System::Void Mundo2_2_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	control2_2->getJugador()->setDireccion(Ninguna);

}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	panel6->Visible = false;
}
};
}
