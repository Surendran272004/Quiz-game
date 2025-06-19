//---------------------------------------------------------------------------

#include <fmx.h>
#include<queue>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
class Question{
public:
	char* Text;
	char* Answer1;
	char* Answer2;
	char* Answer3;
	char* Answer4;
	int CorrectAnswer;
	Question(){}
	Question(char* text,char* ans1,char* ans2,char* ans3,char* ans4,int correctans){
	Text = text;
	Answer1 = ans1;
	Answer2 = ans2;
	Answer3 = ans3;
    Answer4 = ans4;
    CorrectAnswer = correctans;
	}
};
std::queue<Question> LoadQuestions(){
Question q1 = Question("Which colour does not appear on olympic ring?","Black","White","Green","Orange",4);
Question q2 = Question("Rani Durgavati Tiger Reserve is located in which state?"," Odisha","Madhya Pradesh","Rajasthan","Gujarat",2);
Question q3 = Question("Which day is observed as the International Day of Education every year?","24 January","25 January","26 January","27 January",1);
Question q4 = Question("Which player won the ICC Men’s T20I Cricketer of the Year Award?","Kuldeep Yadav","Rishabh Pant","Suryakumar Yadav","Hardik Pandya",3);
Question q5 = Question("Which country will host the Chess World Cup 2025?","India","Germany","USA","Norway",1);

	std::queue<Question> questions;
	questions.push(q1);
	questions.push(q2);
	questions.push(q3);
	questions.push(q4);
	questions.push(q5);
	return questions;
}
std::queue<Question> questions;
Question currentQuestion;
int selectAnswer;
int points;

TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
questions = LoadQuestions();
currentQuestion = questions.front();

QuestionLabel1     ->Text = currentQuestion.Text ;
Answer1RadioButton1->Text = currentQuestion.Answer1;
Answer2RadioButton2->Text = currentQuestion.Answer2 ;
Answer3RadioButton3->Text = currentQuestion.Answer3 ;
Answer4RadioButton4->Text = currentQuestion.Answer4 ;
questions.pop();
PointLabel3->Text = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Answer1RadioButton1Change(TObject *Sender)
{
	selectAnswer = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Answer2RadioButton2Change(TObject *Sender)
{
	selectAnswer = 2;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Answer3RadioButton3Change(TObject *Sender)
{
   selectAnswer = 3;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Answer4RadioButton4Change(TObject *Sender)
{
    selectAnswer = 4;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ConfirmButton1Click(TObject *Sender)
{
    if(selectAnswer==currentQuestion.CorrectAnswer){
	points++;
	PointLabel3->Text=points;
	}
	if(!questions.empty()){
		currentQuestion = questions.front();
        QuestionLabel1     ->Text = currentQuestion.Text ;
        Answer1RadioButton1->Text = currentQuestion.Answer1;
		Answer2RadioButton2->Text = currentQuestion.Answer2 ;
		Answer3RadioButton3->Text = currentQuestion.Answer3 ;
		Answer4RadioButton4->Text = currentQuestion.Answer4 ;
		questions.pop();

		Answer1RadioButton1->IsChecked = false;
		Answer2RadioButton2->IsChecked = false;
		Answer3RadioButton3->IsChecked = false;
		Answer4RadioButton4->IsChecked = false;
	}
	else{
		ConfirmButton1->Enabled = false;
        ConfirmButton1->Text = "GAME OVER!!";
    }

}
//---------------------------------------------------------------------------
