#pragma once
#include <msclr/marshal_cppstd.h> //converts String^ object used by winsform into normal string variable for VideoList class
#include "VideoList.h"

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace WMPLib;
	using namespace msclr::interop;


	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

		}

	protected:

		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: AxWMPLib::AxWindowsMediaPlayer^ player;
	private:
		VideoList* videoList; //Declare video linked list object
	protected:

	protected:

	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ btn_play;



	private: System::Windows::Forms::Button^ btn_previous;
	private: System::Windows::Forms::Button^ btn_pause;

	private: System::Windows::Forms::Button^ btn_next;
	private: System::Windows::Forms::Button^ btn_stop;


	private: System::Windows::Forms::Button^ btn_open;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ lbl_msg;
	private: System::Windows::Forms::Label^ lbl_volume;
	private: System::Windows::Forms::Label^ lbl_volpercentage;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ lbl_tracker_start;
	private: System::Windows::Forms::Label^ lbl_tracker_end;
	private: System::Windows::Forms::ListBox^ track_list;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;








	private:



#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->player = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->track_list = (gcnew System::Windows::Forms::ListBox());
			this->lbl_volpercentage = (gcnew System::Windows::Forms::Label());
			this->lbl_volume = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->btn_open = (gcnew System::Windows::Forms::Button());
			this->btn_stop = (gcnew System::Windows::Forms::Button());
			this->btn_pause = (gcnew System::Windows::Forms::Button());
			this->btn_next = (gcnew System::Windows::Forms::Button());
			this->btn_play = (gcnew System::Windows::Forms::Button());
			this->btn_previous = (gcnew System::Windows::Forms::Button());
			this->lbl_msg = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->lbl_tracker_start = (gcnew System::Windows::Forms::Label());
			this->lbl_tracker_end = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->player))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// player
			// 
			this->player->Dock = System::Windows::Forms::DockStyle::Fill;
			this->player->Enabled = true;
			this->player->Location = System::Drawing::Point(0, 0);
			this->player->Name = L"player";
			this->player->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"player.OcxState")));
			this->player->Size = System::Drawing::Size(968, 611);
			this->player->TabIndex = 0;
			this->player->Enter += gcnew System::EventHandler(this, &MyForm::track_list_Enter);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Black;
			this->groupBox1->Controls->Add(this->track_list);
			this->groupBox1->Controls->Add(this->lbl_volpercentage);
			this->groupBox1->Controls->Add(this->lbl_volume);
			this->groupBox1->Controls->Add(this->trackBar1);
			this->groupBox1->Controls->Add(this->btn_open);
			this->groupBox1->Controls->Add(this->btn_stop);
			this->groupBox1->Controls->Add(this->btn_pause);
			this->groupBox1->Controls->Add(this->btn_next);
			this->groupBox1->Controls->Add(this->btn_play);
			this->groupBox1->Controls->Add(this->btn_previous);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->ForeColor = System::Drawing::Color::Blue;
			this->groupBox1->Location = System::Drawing::Point(114, 435);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(742, 153);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Controls";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MyForm::groupBox1_Enter);
			// 
			// track_list
			// 
			this->track_list->BackColor = System::Drawing::Color::Gray;
			this->track_list->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->track_list->FormattingEnabled = true;
			this->track_list->ItemHeight = 22;
			this->track_list->Location = System::Drawing::Point(23, 68);
			this->track_list->Name = L"track_list";
			this->track_list->Size = System::Drawing::Size(543, 70);
			this->track_list->TabIndex = 9;
			this->track_list->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::track_list_SelectedIndexChanged);
			// 
			// lbl_volpercentage
			// 
			this->lbl_volpercentage->AutoSize = true;
			this->lbl_volpercentage->BackColor = System::Drawing::Color::Transparent;
			this->lbl_volpercentage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_volpercentage->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->lbl_volpercentage->Location = System::Drawing::Point(644, 65);
			this->lbl_volpercentage->Name = L"lbl_volpercentage";
			this->lbl_volpercentage->Size = System::Drawing::Size(31, 18);
			this->lbl_volpercentage->TabIndex = 8;
			this->lbl_volpercentage->Text = L"0%";
			this->lbl_volpercentage->Click += gcnew System::EventHandler(this, &MyForm::lbl_volpercentage_Click);
			// 
			// lbl_volume
			// 
			this->lbl_volume->AutoSize = true;
			this->lbl_volume->BackColor = System::Drawing::Color::Transparent;
			this->lbl_volume->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_volume->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->lbl_volume->Location = System::Drawing::Point(631, 126);
			this->lbl_volume->Name = L"lbl_volume";
			this->lbl_volume->Size = System::Drawing::Size(64, 18);
			this->lbl_volume->TabIndex = 3;
			this->lbl_volume->Text = L"Volume";
			this->lbl_volume->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(595, 15);
			this->trackBar1->Maximum = 100;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBar1->Size = System::Drawing::Size(56, 133);
			this->trackBar1->TabIndex = 7;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// btn_open
			// 
			this->btn_open->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_open->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_open->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btn_open->Location = System::Drawing::Point(480, 27);
			this->btn_open->Name = L"btn_open";
			this->btn_open->Size = System::Drawing::Size(86, 32);
			this->btn_open->TabIndex = 5;
			this->btn_open->Text = L"open";
			this->btn_open->UseVisualStyleBackColor = true;
			this->btn_open->Click += gcnew System::EventHandler(this, &MyForm::btn_open_Click);
			// 
			// btn_stop
			// 
			this->btn_stop->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_stop->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_stop->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btn_stop->Location = System::Drawing::Point(388, 27);
			this->btn_stop->Name = L"btn_stop";
			this->btn_stop->Size = System::Drawing::Size(86, 32);
			this->btn_stop->TabIndex = 4;
			this->btn_stop->Text = L"stop";
			this->btn_stop->UseVisualStyleBackColor = true;
			this->btn_stop->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// btn_pause
			// 
			this->btn_pause->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_pause->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_pause->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btn_pause->Location = System::Drawing::Point(296, 27);
			this->btn_pause->Name = L"btn_pause";
			this->btn_pause->Size = System::Drawing::Size(86, 32);
			this->btn_pause->TabIndex = 3;
			this->btn_pause->Text = L"pause";
			this->btn_pause->UseVisualStyleBackColor = true;
			this->btn_pause->Click += gcnew System::EventHandler(this, &MyForm::button3_Click_1);
			// 
			// btn_next
			// 
			this->btn_next->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_next->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_next->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btn_next->Location = System::Drawing::Point(204, 27);
			this->btn_next->Name = L"btn_next";
			this->btn_next->Size = System::Drawing::Size(86, 32);
			this->btn_next->TabIndex = 2;
			this->btn_next->Text = L"next";
			this->btn_next->UseVisualStyleBackColor = true;
			this->btn_next->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// btn_play
			// 
			this->btn_play->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_play->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_play->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btn_play->Location = System::Drawing::Point(112, 27);
			this->btn_play->Name = L"btn_play";
			this->btn_play->Size = System::Drawing::Size(86, 32);
			this->btn_play->TabIndex = 1;
			this->btn_play->Text = L"play";
			this->btn_play->UseVisualStyleBackColor = true;
			this->btn_play->Click += gcnew System::EventHandler(this, &MyForm::btn_play_Click);
			// 
			// btn_previous
			// 
			this->btn_previous->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_previous->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_previous->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btn_previous->Location = System::Drawing::Point(20, 27);
			this->btn_previous->Name = L"btn_previous";
			this->btn_previous->Size = System::Drawing::Size(86, 32);
			this->btn_previous->TabIndex = 0;
			this->btn_previous->Text = L"previous";
			this->btn_previous->UseVisualStyleBackColor = true;
			this->btn_previous->Click += gcnew System::EventHandler(this, &MyForm::btn_previous_Click);
			// 
			// lbl_msg
			// 
			this->lbl_msg->AutoSize = true;
			this->lbl_msg->BackColor = System::Drawing::Color::Transparent;
			this->lbl_msg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_msg->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->lbl_msg->Location = System::Drawing::Point(17, 9);
			this->lbl_msg->Name = L"lbl_msg";
			this->lbl_msg->Size = System::Drawing::Size(103, 18);
			this->lbl_msg->TabIndex = 2;
			this->lbl_msg->Text = L"Media player";
			this->lbl_msg->Click += gcnew System::EventHandler(this, &MyForm::lbl_msg_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(180, 421);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(624, 8);
			this->progressBar1->TabIndex = 3;
			this->progressBar1->Click += gcnew System::EventHandler(this, &MyForm::progressBar1_Click);
			// 
			// lbl_tracker_start
			// 
			this->lbl_tracker_start->AutoSize = true;
			this->lbl_tracker_start->BackColor = System::Drawing::Color::Transparent;
			this->lbl_tracker_start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_tracker_start->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->lbl_tracker_start->Location = System::Drawing::Point(122, 414);
			this->lbl_tracker_start->Name = L"lbl_tracker_start";
			this->lbl_tracker_start->Size = System::Drawing::Size(49, 18);
			this->lbl_tracker_start->TabIndex = 9;
			this->lbl_tracker_start->Text = L"00:00";
			this->lbl_tracker_start->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_1);
			// 
			// lbl_tracker_end
			// 
			this->lbl_tracker_end->AutoSize = true;
			this->lbl_tracker_end->BackColor = System::Drawing::Color::Transparent;
			this->lbl_tracker_end->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_tracker_end->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->lbl_tracker_end->Location = System::Drawing::Point(815, 415);
			this->lbl_tracker_end->Name = L"lbl_tracker_end";
			this->lbl_tracker_end->Size = System::Drawing::Size(49, 18);
			this->lbl_tracker_end->TabIndex = 10;
			this->lbl_tracker_end->Text = L"00:00";
			this->lbl_tracker_end->Click += gcnew System::EventHandler(this, &MyForm::lbl_tracker_end_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(968, 611);
			this->Controls->Add(this->lbl_tracker_end);
			this->Controls->Add(this->lbl_tracker_start);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->lbl_msg);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->player);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->player))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { //"Next" button
		if (!videoList->isEmpty()) {
			String^ nextVideo = gcnew String(videoList->nextVideo().c_str()); //Stores the converted managed string representation (WinForms own version/implementation of Strings) returned by nextVideo in the variable nextVideo
			//.c_str() converts the url string returned by nextVide() into a char* to make it compatible with String^ constructor
			//gcnew String() is like a static cast, it switches the string returned into a new managed String ^ (used by WinForms)
			player->URL = nextVideo; //updates the current URL to the one in the nextVideo
			player->Ctlcontrols->play(); //makes it so that the play button plays this video/URL
			lbl_msg->Text = "Playing next video...";

			// update track_list SelectedIndex if it doesn't match Node index
			int nodeIndex = videoList->getCurrentNodeIndex();
			if (nodeIndex < track_list->Items->Count) {
				track_list->SelectedIndex = nodeIndex;
			}
			else {
				track_list->SelectedIndex = 0; // Wrap around
			}
		}
		else {
			lbl_msg->Text = "Playlist is empty.";
		}
	}
	private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) {
		player->Ctlcontrols->pause();
		lbl_msg->Text = "pause";


	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		player->Ctlcontrols->stop();
		lbl_msg->Text = "stop";
	}


	private: System::Void lbl_msg_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}

		   cli::array<String^>^ paths;
		   cli::array<String^>^ files;

	private: System::Void btn_open_Click(System::Object^ sender, System::EventArgs^ e) { //connected it to linked list

		System::Windows::Forms::OpenFileDialog^ ofd = gcnew System::Windows::Forms::OpenFileDialog();
		ofd->Multiselect = true;
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

			files = ofd->SafeFileNames;
			paths = ofd->FileNames;

			for (int x = 0; x < files->Length; x++)
			{
				track_list->Items->Add(files[x]); //for URL display
				videoList->addVideo(marshal_as<std::string>(dynamic_cast<System::String^>(paths[x]))); // Add URL to VideoList;
				Console::WriteLine("Adding video to videoList and track_list: {0}", paths[x]); //DEBUG LINE
			}
		}

	}

	private: System::Void track_list_Enter(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void track_list_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (track_list->SelectedIndex >= 0 && track_list->SelectedIndex < paths->Length && track_list->SelectedIndex < videoList->getSize()) {
			player->URL = paths[track_list->SelectedIndex];
			player->Ctlcontrols->play();
			lbl_msg->Text = "Playing...";
			timer1->Start();
			trackBar1->Value = 50;
			lbl_volpercentage->Text = trackBar1->Value.ToString() + "%";
		}
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) { //"Constructor" of GUI
		videoList = new VideoList(); //Intialize
	}
	private: System::Void btn_play_Click(System::Object^ sender, System::EventArgs^ e) {

		player->Ctlcontrols->play();
		lbl_msg->Text = "playing.....";
	}
	private: System::Void btn_previous_Click(System::Object^ sender, System::EventArgs^ e) { //"previous" button
		if (!videoList->isEmpty()) {
			String^ prevVideo = gcnew String(videoList->prevVideo().c_str());
			player->URL = prevVideo;
			player->Ctlcontrols->play();
			lbl_msg->Text = "Playing previous video...";

			//Make sure track_list SelectedIndex is same as VideoNode index
			int nodeIndex = videoList->getCurrentNodeIndex(); // Ensure the current index is updated
			if (nodeIndex >= 0) {
				track_list->SelectedIndex = nodeIndex;
			}
		}
		else {
			lbl_msg->Text = "Playlist is empty.";
		}
	}
	private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void lbl_tracker_end_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (player->playState == WMPLib::WMPPlayState::wmppsPlaying)
		{
			progressBar1->Maximum = (int)player->Ctlcontrols->currentItem->duration;
			progressBar1->Value = (int)player->Ctlcontrols->currentPosition;
		}
		lbl_tracker_start->Text = player->Ctlcontrols->currentPositionString;
		lbl_tracker_end->Text = player->Ctlcontrols->currentItem->durationString->ToString();
	}
	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
		player->settings->volume = trackBar1->Value;
		lbl_volpercentage->Text = trackBar1->Value.ToString() + "%";



	}
	private: System::Void lbl_volpercentage_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
