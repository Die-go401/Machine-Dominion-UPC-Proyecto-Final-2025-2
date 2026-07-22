#pragma once
#include "Controlador2.h"
#include "Historia2_parte2.h"
#include "Derrota2.h"
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
	/// Resumen de Mundo2
	/// </summary>
	public ref class Mundo2 : public System::Windows::Forms::Form
	{
	private:
		Nombre^ nom;
		Controlador2* control2;
		Bitmap^ jugador;
		Bitmap^ arania;
		Bitmap^ arbolDesidratado;
		Bitmap^ arbolNavidad;
		Rectangle limite1;
		Rectangle limite2;
		Rectangle limite3;
        Rectangle limite4;
		SoundPlayer^ reproductor;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label10;

		   int contador;
	
	public:
		Mundo2(Nombre^h)
		{
			InitializeComponent();
			nom = h;
			this->KeyPreview = true;
			String^ ruta = System::IO::Path::Combine(Application::StartupPath, "AUDIOS", "mundo2_1.wav");
			reproductor = gcnew SoundPlayer(ruta);
			reproductor->PlayLooping(); // o Play()

			control2 = new Controlador2();
			limite1 = Rectangle(pictureBox1->Location, pictureBox1->Size);
			limite2 = Rectangle(pictureBox2->Location, pictureBox2->Size);
			limite3 = Rectangle(pictureBox3->Location, pictureBox3->Size);
			limite4 = Rectangle(pictureBox4->Location, pictureBox4->Size);
			jugador = gcnew Bitmap("Imagenes/Principal.png");
			arania = gcnew Bitmap("Imagenes/AraniaFinal.png");
			arbolDesidratado = gcnew Bitmap("Imagenes/ArbolRegar.png");
			arbolNavidad = gcnew Bitmap("Imagenes/ArbolNavidad.png");
			contador = 0;
	
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Mundo2()
		{
			if (components)
			{
				delete components;
			}
			delete control2;
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Mundo2::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->pictureBox4);
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Controls->Add(this->pictureBox3);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(750, 760);
			this->panel1->TabIndex = 0;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel4->Controls->Add(this->label8);
			this->panel4->Controls->Add(this->pictureBox5);
			this->panel4->Controls->Add(this->pictureBox6);
			this->panel4->Controls->Add(this->button6);
			this->panel4->Controls->Add(this->label7);
			this->panel4->Controls->Add(this->label10);
			this->panel4->Location = System::Drawing::Point(104, 231);
			this->panel4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(542, 297);
			this->panel4->TabIndex = 23;
			this->panel4->Visible = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Yellow;
			this->label8->Location = System::Drawing::Point(317, 148);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(162, 26);
			this->label8->TabIndex = 24;
			this->label8->Text = L"REFORESTAR";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(31, 102);
			this->pictureBox5->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(153, 120);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox5->TabIndex = 23;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(230, 130);
			this->pictureBox6->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(75, 56);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox6->TabIndex = 22;
			this->pictureBox6->TabStop = false;
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(240, 241);
			this->button6->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(74, 32);
			this->button6->TabIndex = 20;
			this->button6->Text = L"Cerrar";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Mundo2::button6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Yellow;
			this->label7->Location = System::Drawing::Point(39, 69);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(152, 26);
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
			this->label10->Location = System::Drawing::Point(150, 15);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(263, 44);
			this->label10->TabIndex = 19;
			this->label10->Text = L"CONTROLES";
			this->label10->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox4->Location = System::Drawing::Point(703, 60);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(47, 700);
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Location = System::Drawing::Point(0, 3);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(50, 700);
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->Location = System::Drawing::Point(0, 695);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(750, 65);
			this->pictureBox3->TabIndex = 1;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(750, 89);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Mundo2::timer1_Tick);
			// 
			// panel3
			// 
			this->panel3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel3.BackgroundImage")));
			this->panel3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel3->Controls->Add(this->panel2);
			this->panel3->Location = System::Drawing::Point(749, 3);
			this->panel3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(235, 760);
			this->panel3->TabIndex = 1;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Location = System::Drawing::Point(9, 10);
			this->panel2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(217, 424);
			this->panel2->TabIndex = 2;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label6->Location = System::Drawing::Point(2, 181);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(178, 20);
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
			this->label5->Location = System::Drawing::Point(2, 279);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(191, 120);
			this->label5->TabIndex = 4;
			this->label5->Text = L"OBJETIVO:\r\n\r\nRECUPERA LOS \r\nARBOLES PERDIDOS\r\nPARA SALVAR AL \r\nBOSQUE\r\n";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label4->Location = System::Drawing::Point(2, 124);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(208, 20);
			this->label4->TabIndex = 3;
			this->label4->Text = L"ARBOLES RESTANTES:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label3->Location = System::Drawing::Point(2, 89);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 20);
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
			this->label2->Location = System::Drawing::Point(2, 54);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 20);
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
			this->label1->Location = System::Drawing::Point(38, 11);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(146, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"MUNDO 2";
			// 
			// Mundo2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 761);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->Name = L"Mundo2";
			this->Text = L"MUNDO 2";
			this->Load += gcnew System::EventHandler(this, &Mundo2::Mundo2_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Mundo2::Mundo2_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Mundo2::Mundo2_KeyUp);
			this->panel1->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		contador += timer1->Interval;
		
		Graphics^ g = panel1->CreateGraphics();
		BufferedGraphicsContext^ intervalo = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = intervalo->Allocate(g, panel1->ClientRectangle);
		//Borrar
		buffer->Graphics->DrawImage(panel1->BackgroundImage, panel1->ClientRectangle);
		//estadisticas
		label2->Text = "NOMBRE: " + nom->getName();
		label3->Text = "VIDAS: " + control2->getJugador()->getVida();
		label4->Text = "ARBOLES RESTANTES: \n" + control2->getPuntos() + "/" + control2->getTotal();
		label6->Text = "TIEMPO RESTANTE: \n" + contador / 1000 + "/" + "60";
		//Mover y dibujar
		control2->ControlMundo2(buffer->Graphics,jugador,limite1, limite2, limite3, limite4,arbolNavidad,arbolDesidratado,arania);
		if (control2->victoria() == true) {
			reproductor->Stop();
			timer1->Stop();
			Historia2_parte2^ c2 = gcnew Historia2_parte2(nom);
			this->Hide();
			c2->ShowDialog();
			this->Close();

		}
		if (contador >= 60000) {
			reproductor->Stop();
			timer1->Stop();
			Derrota2^ c2 = gcnew Derrota2();
			this->Hide();
			c2->ShowDialog();
			this->Close();
		}
		
		
		buffer->Render(g);
		delete buffer;
		delete intervalo;
		delete g;



	}
   
	private: System::Void Mundo2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Up: {
			control2->getJugador()->setDireccion(Arriba);
			break;

		}
		case Keys::Down: {
			control2->getJugador()->setDireccion(Abajo);
			break;

		}
		case Keys::Left: {
			control2->getJugador()->setDireccion(Izquierda);
			break;

		}
		case Keys::Right: {
			control2->getJugador()->setDireccion(Derecha);
			break;
		}
		case Keys::R: {

			for (int i = 0; i < control2->getArboles().size(); i++) {
				if (control2->getArboles()[i]->getTipo() == 1) {
					if (control2->getJugador()->getRectanglePrincipal().IntersectsWith(control2->getArboles()[i]->getRectangleArbol())) {
						control2->getArboles()[i]->setIteraX(control2->getArboles()[i]->getIteraX() + 1);
					}
				}
			}
			break;
		}
		}
	}
	private: System::Void Mundo2_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		control2->getJugador()->setDireccion(Ninguna);
	}
   
    
private: System::Void Mundo2_Load(System::Object^ sender, System::EventArgs^ e) {
	panel2->BackColor = Color::FromArgb(160, 0, 0, 0);
	panel4->BackColor = Color::FromArgb(160, 0, 0, 0);
	panel4->Visible = true;
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	panel4->Visible = false;
}
};
}
