//---------------------------------------------------------------------------

#include <vcl.h>
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

void __fastcall TForm1::Button2Click(TObject *Sender)
{
   ADOTable1->TableName=ComboBox1->Text;
   ADOTable1->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
  ComboBox1->Text = ADOTable1->TableName;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
AnsiString ConStr,Path;
ConStr="Provider=Microsoft.Jet.OLEDB.4.0; User ID=Admin; Data Source=";
if (!OpenDialog1->Execute()) return;
Path=OpenDialog1->FileName;
ConStr=ConStr+Path;
StatusBar1->Panels->Items[0]->Text=Path;
ADOConnection1->ConnectionString=ConStr;
ADOConnection1->Connected=true;
ADOConnection1->GetTableNames(ComboBox1->Items);
ADOTable1->Active=true;
Edit1->Text=Path;
AnsiString Put="input.bmp";
Image1->Picture->LoadFromFile(Put);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
  int n(0), m(0);//n-����������� �����, m- ��������
  n = ADOTable1->RecordCount;
  m = ADOTable1->FieldCount;
  Label2->Caption = n;
  Label3->Caption = m;
  StatusBar1->Panels->Items[1]->Text = n;
  StatusBar1->Panels->Items[2]->Text = m;
  ADOTable1->First();//�������������� �� 1 ������ ����� ������ ����������

  //����������� ������� � ������ �� ����
 int **array = new int* [n];
  for (int i=0; i<n; i++)
  {     array[i] = new int [m];
        for (int j = 0; j < m; j++)
        {
            //array[i][j] = StrToInt(DBGrid1->SelectedField->AsString);
           //ShowMessage(DBGrid1->SelectedField->AsString)  ;
           ADOTable1->Next();
        }
  }
  //Memo1->Text = IntToStr(array[10][10]);
  for (int i=0; i<n; i++) //����������� ������
  delete [] array [m];

  //job for ListBox


  for (int i=1;i<m;i++){
  ListBox1->Items->Append(ADOTable1->FieldList->Strings[i]);
  };
}
   
void __fastcall TForm1::ListBox2DragOver(TObject *Sender, TObject *Source,
      int X, int Y, TDragState State, bool &Accept)
{
 TListBox *mSrc =(TListBox *)Source;//������� ��������� �� ����� TListBox ��������

 //���� � ��������� ������ 0 ��������� � ������ ���� �� 1 - ��������� �������
 if (mSrc->Count>0 && mSrc->SelCount>0) Accept = true;
 else Accept = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox2DragDrop(TObject *Sender, TObject *Source,
      int X, int Y)
{
 TListBox *mSrc =(TListBox *)Source;  //������� ��������� �� ����� TListBox ��������
 TListBox *mDest=(TListBox *)Sender;  //������� ��������� �� ����� ���������� (TListBox)
 TPoint p; //��������� ����� ��� ����������� ��������� ����
 p = Point(X,Y);//��������� ������� ����
 int k = mDest ->ItemAtPos(p, true); //����������� ������� �������� ������ ����������, �� ������� ��������� ������ ����

 //��������� ������������ �������� � ������ ����������
 //��������� ������������� �������� ����� ����������� ���������� ������� ����
 for (int i=0; i<mSrc->Count; i++)//������ �� ���� ��������� ������ ���������
   {
     if (mSrc->Selected[i] == true)//���� ������� ������� �������
     mDest->Items->Insert(k, mSrc->Items->Strings[i]);//��������� ������� ������� ���������� �� ����� � ������� k
    }

    //������� ���������� �������� �� ������ ���������
 for (int i=0; i<mSrc->Count; i++)//������ �� ���� ��������� ������ ���������
   {
    if (mSrc->Selected[i] == true)//���� ������� ������� �������
     {
       mSrc->Items->Delete(i);// ������� ������� �� ������ ���������
       i--; //��������� ������ �.�. ������� ���������
     }
   }
}
//---------------------------------------------------------------------------








void __fastcall TForm1::Exit1Click(TObject *Sender)
{
        exit(0);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Open1Click(TObject *Sender)
{
AnsiString ConStr,Path;
ConStr="Provider=Microsoft.Jet.OLEDB.4.0; User ID=Admin; Data Source=";
if (!OpenDialog1->Execute()) return;
Path=OpenDialog1->FileName;
ConStr=ConStr+Path;
StatusBar1->Panels->Items[0]->Text=Path;
ADOConnection1->ConnectionString=ConStr;
ADOConnection1->Connected=true;
ADOConnection1->GetTableNames(ComboBox1->Items);
ADOTable1->Active=true;
Edit1->Text=Path;
AnsiString Put="input.bmp";
Image1->Picture->LoadFromFile(Put);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CloseDB1Click(TObject *Sender)
{
  //Main_menu->Close
ADOConnection1->Connected=false;
ADOTable1->Active=false;

Edit1->Clear();

Image1->Picture->Bitmap = NULL;  //������� Image1

for (int i=0; i < StatusBar1->Panels->Count; i++)//������ StatusBar
    {
      StatusBar1->Panels->Items[i]->Text = "";
    }

ListBox1->Items->Clear();//������ 2�� ������ drag&drop
ListBox2->Items->Clear();
}
//---------------------------------------------------------------------------



