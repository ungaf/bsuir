//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

double factorial(int number) {
        double result = 1;
        for (int i = 1; i <= number; i++) {
                result *= i;
        }
        return result;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Memo1->Clear();
        double  a = StrToFloat(Edit1->Text),
                b = StrToFloat(Edit2->Text),
                h = StrToFloat(Edit3->Text);

        int     n = StrToInt(Edit4->Text);

        for (double x = a; x <= b; x += h) {
                double s = 0, y;
                for (int k = 0; k <= n; k++)
                        s += pow(x, 2*k)/factorial(2*k);

                y = (pow(M_E, x) + pow(M_E, -x))/2.;

                Memo1->Lines->Add("S("+(String)x+")="+s);
                Memo1->Lines->Add("Y("+(String)x+")="+y);
                Memo1->Lines->Add("|Y("+(String)x+")-S("+(String)x+")|="+(String)fabs(y-s));
        }
}
//---------------------------------------------------------------------------

