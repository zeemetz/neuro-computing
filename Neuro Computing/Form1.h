#include<fann.h>
#pragma once

namespace NeuroComputing {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected: 
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private:
		// variable global
		Bitmap ^bitmap;
		Bitmap ^grayScaleBitmap; // buat tampung hasil convert
		array<double, 2> ^myInputData;
		array<double, 2> ^myOutputData;
		int countData; // buat hitung data ke-berapa

		// pakai include fann.h
		fann *ann;
		fann_train_data *data;
	private: System::Windows::Forms::Button^  button7;

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

// Form Commponent
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button7 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(38, 24);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 114);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(300, 24);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(100, 114);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(38, 159);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Browse";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(38, 205);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Free Processing";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(177, 24);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Train";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Facebook", L"Twitter", L"RSS"});
			this->comboBox1->Location = System::Drawing::Point(159, 69);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 4;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(300, 159);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"browse";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(300, 205);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(100, 23);
			this->button5->TabIndex = 6;
			this->button5->Text = L"Free Processing";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(436, 23);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 7;
			this->button6->Text = L"Recognize";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(433, 69);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Result";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(436, 115);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 9;
			this->button7->Text = L"save";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(534, 273);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


// ubah gambar kedalam bentuk gray scale
private: System::Drawing::Bitmap ^convertToGrayScale(Bitmap ^bmp){
			
			 // ambil semua pixel
			 for(int x = 0 ; x < bmp->Width ; x++)
			 {
				 for(int y = 0 ; y < bmp->Height ; y++)
				 {
					 // ambil warna
					 Color colorPixel = bmp->GetPixel(x,y);
					 // algoritma gray scale, caranya tambahin RGB/3
					 int tempColor = (colorPixel.R + colorPixel.G + colorPixel.B)/3;
					 // bikin color baru
					 Color newColor = Color::FromArgb(tempColor, tempColor, tempColor); // jadiin 1 warna
					 // set color
					 bmp->SetPixel(x,y,newColor);
				 }
			 }
			 return bmp;
		 }


// Form Load
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

				 // inisialisasi input output

				 myInputData = gcnew array<double, 2>(5, 49);
				 myOutputData = gcnew array<double, 2>(5,3);
				 countData = 0;

				 //load dari file
				 ann = fann_create_from_file("../Neuro Computing/otak.net");
				 
			 }

//load gambar kedalam pictureBox1
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 if( openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK ) // ini buat browse gambar
				 {
					 bitmap = gcnew Bitmap(openFileDialog1->FileName);
					 pictureBox1->Image = bitmap;
				 }

			 }
// free processing
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

			 //pictureBox1->Image = convertToGrayScale(bitmap); // tes gray scale

			 // kecilin pixel biar sama, cari lagi ??
			 Bitmap ^old = gcnew Bitmap(7,7); // semakin kecil gambar semakin jelek, kuasnya
			 Graphics ^grap = Graphics::FromImage(old); // buat Graphics dari si-old
			 grap->DrawImage(bitmap,0,0,7,7); // dari 0,0 sampai sebanyak 7,7

			 //buat grayscale image
			 grayScaleBitmap = convertToGrayScale(old);
			 pictureBox1->Image = grayScaleBitmap; // pakai gray scale dari old-nya

			 

		 }

		 


//train
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

			 int tempCount = 0; //buat dapat data colom
			 // grayScaleBitmap
			 // masukkin gray scale sebagai data input
			 for(int x = 0 ; x < grayScaleBitmap->Width ; x++)
			 {
				 for(int y = 0 ; y < grayScaleBitmap->Height ; y++)
				 {
					 // ambil pixel
					 Color colorPixel = grayScaleBitmap->GetPixel(x,y);

					 myInputData[countData, tempCount] = (double)colorPixel.R/255;
					 tempCount++;
				 }
			 }

			 // output
			 // harus tau gambar
			 // inisialisasi
			 for(int i = 0 ; i < 3 ; i++)
			 {
				 myOutputData[countData, i] = 0;
			 }

			 myOutputData[countData, comboBox1->SelectedIndex] = 1;
			
			 // tes hasil output
			 String ^temp;
			 for(int i = 0 ; i < 3 ; i++) temp+=myOutputData[countData, i] + " ";
			 MessageBox::Show(temp); 
			 
			 // buat datanya
			 countData++;

			 // pakai Fann
			 ann = fann_create_standard(3,49,100,3); // bikin networknya, tiga layer (input = ada 49, hidden = bebas->banyak = lelet = bagus, output = 3)
			 // activation
			 fann_set_activation_function_layer(ann, FANN_SIGMOID, 0); // nentuin metode training otak
			 fann_set_activation_function_hidden(ann, FANN_SIGMOID );
			 fann_set_activation_function_output(ann, FANN_SIGMOID );

			 // train datanya

			 data = (fann_train_data*)malloc( sizeof (fann_train_data));
			 data->num_data = countData;
			 data->num_input = 49;
			 data->num_output = 3;
			 
			 // masukkin array yang my input kedalam struct ini
			 data->input = (fann_type**) calloc(data->num_data, sizeof(fann_type) );
			 data->output = (fann_type**) calloc(data->num_data, sizeof(fann_type) );

			 // kasi array dimensi ke-duanya
			 for(int i = 0 ; i < data->num_data ; i++)
			 {
				 data->input[i] = (fann_type*)calloc(data->num_input, sizeof (fann_type));
				 data->output[i] = (fann_type*)calloc(data->num_output, sizeof (fann_type));
			 }

			 // isi data
			 for(int i = 0 ; i < data->num_data ; i++)
			 {
				 for(int j = 0 ; j < data->num_input ;j++)
				 {
					 data->input[i][j] = myInputData[i,j]; // pindahin kedalam struct data
				 }

				 for(int j = 0 ; j < data->num_output ;j++)
				 {
					 data->output[i][j] = myOutputData[i,j]; // pindahin kedalam struct data
				 }
			 }

			 // kasi fann, training
			 fann_train_on_data(ann, data, 500000, 0, 0.00001); // training sebanyak 500rb kali, 2 param terakhir adalah jumlah error yang muncul

			 MessageBox::Show("Training Success");
		 }




// load gambar pictureBox2
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

			 if(openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
			 {
				 bitmap = gcnew Bitmap(openFileDialog1->FileName);
				 pictureBox2->Image = bitmap;
			 }

		 }
// GrayScale
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {

			 Bitmap ^old = gcnew Bitmap(7,7);
			 Graphics ^grap = Graphics::FromImage(old);
			 grap->DrawImage(bitmap,0,0,7,7);

			 grayScaleBitmap = convertToGrayScale(old);
			 pictureBox2->Image = grayScaleBitmap;

		 }

//recognize
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {

			 if(ann)
			 {
				 // INPUT
				 // bandingin dengan datanya
				 fann_type *input = (fann_type*)calloc(49,sizeof(fann_type));
				 int tempCount = 0;

				 // ambil data pixelnya
				 for(int x = 0 ; x < grayScaleBitmap->Width; x++)
				 {
					 for(int y = 0 ; y < grayScaleBitmap->Height ; y++ )
					 {
						 Color colorPixel = grayScaleBitmap->GetPixel(x,y);

						 input[tempCount] = (double)colorPixel.R/255;
						 tempCount++;
					 }
				 }

				 //OUTPUT
				 fann_type *output = fann_run(ann,input); // fungsi dari training tadi

				 // hasil run dari kotak kita
				 String ^temp ;
				 for(int i = 0 ; i < 3 ; i ++) temp += output[i] + " ";
				 MessageBox::Show(temp);

				 // tentukan hasil pada label
				 double max = output[0];
				 int index = 0 ;

				 for(int i = 1 ; i < 3 ; i++)
				 {
					 if(output[i]>max)
					 {
						 max = output[i];
						 index = i;
					 }
				 }

				 label1->Text = comboBox1->Items[index] + "";

			 }

		 }

// Save to File
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {

			 fann_save(ann,"../Neuro Computing/otak.net");
		 }
};
}

