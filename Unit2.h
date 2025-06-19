//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *QuestionLabel1;
	TRadioButton *Answer1RadioButton1;
	TRadioButton *Answer2RadioButton2;
	TRadioButton *Answer3RadioButton3;
	TRadioButton *Answer4RadioButton4;
	TLabel *Points;
	TLabel *PointLabel3;
	TButton *ConfirmButton1;
	void __fastcall Answer1RadioButton1Change(TObject *Sender);
	void __fastcall Answer2RadioButton2Change(TObject *Sender);
	void __fastcall Answer3RadioButton3Change(TObject *Sender);
	void __fastcall Answer4RadioButton4Change(TObject *Sender);
	void __fastcall ConfirmButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
