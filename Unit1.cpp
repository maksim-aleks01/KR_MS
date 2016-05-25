//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
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

AnsiString s1= "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=";
AnsiString s2 = ";Persist Security Info=False";
AnsiString ConStr;

//���������� ���������� ����������� � ��������


//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
   if (ADOTable1->Active==true) ADOTable1->Active=false;
        if (ComboBox1->Text!="")
        {
         ADOTable1->TableName=ComboBox1->Text;
         ADOTable1->Active=true;
        }
  // ADOTable1->TableName=ComboBox1->Text;
  // ADOTable1->Active=true;

}
//------------------[������ ������� ��]---------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
OpenDialog1->Execute();
if (ADOTable1->Active) ADOTable1->Active=false;
if (ADOConnection1->Connected==true) ADOConnection1->Connected=false;
ComboBox1->Clear();

if (OpenDialog1->FileName!="")
  {
  Edit1->Text=OpenDialog1->FileName;
  ConStr=s1+Edit1->Text+s2;
  ADOConnection1->ConnectionString=ConStr;
  ADOConnection1->Connected=true;
  ADOConnection1->GetTableNames(ComboBox1->Items);
  AnsiString Put="input.bmp";
  Image1->Picture->LoadFromFile(Put);
  AnsiString Path=OpenDialog1->FileName;
  StatusBar1->Panels->Items[0]->Text="����" + Path;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        if (ADOTable1->Active==false) {return; ShowMessage("�� �� �������!"); Button3->Visible = false;}
  int n(0), m(0);//n-����������� �����, m- ��������
  n = ADOTable1->RecordCount;
  m = ADOTable1->FieldCount;
  Label2->Caption = "�����: " + FloatToStr(n);
  Label3->Caption = "��������: " + FloatToStr(m - 1);
  StatusBar1->Panels->Items[1]->Text = "�����: " + FloatToStr(n);
  StatusBar1->Panels->Items[2]->Text = "��������: " + FloatToStr(m - 1);
  ADOTable1->First();//�������������� �� 1 ������ ����� ������ ����������


  //����������� ������� � ������ �� ����
 //int **array = new int* [n];
 // for (int i=0; i<n; i++)
  //{     array[i] = new int [m];
        //for (int j = 0; j < m; j++)
      //  {
        
      //  }
   //     ADOTable1->Next();
 // }

 // for (int i=0; i<n; i++) //����������� ������
 // delete [] array [m];

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
   if (mSrc->ItemIndex == mDest->ItemIndex && mSrc->Name == mDest->Name ) return; //�������� �� ���������� ������ ���� � �����
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
//------------------------[������ ����->������� ��]--------------------------------

void __fastcall TForm1::Open1Click(TObject *Sender)
{
AnsiString ConStr,Path;
ConStr="Provider=Microsoft.Jet.OLEDB.4.0; User ID=Admin; Data Source=";
if (!OpenDialog1->Execute()) return;
Path=OpenDialog1->FileName;
ConStr=ConStr+Path;
StatusBar1->Panels->Items[0]->Text="����" + Path;
ADOConnection1->ConnectionString=ConStr;
ADOConnection1->Connected=true;
ADOConnection1->GetTableNames(ComboBox1->Items);
ADOTable1->Active=true;
Edit1->Text=Path;
AnsiString Put="input.bmp";
Image1->Picture->LoadFromFile(Put);
}
//----------------------[������ ����->������ ��]------------------------------------

void __fastcall TForm1::CloseDB1Click(TObject *Sender)
{
  //Main_menu->Close
ADOConnection1->Connected=false;
ADOTable1->Active=false;
ComboBox1->Clear();
Edit1->Clear();

Image1->Picture->Bitmap = NULL;  //������� Image1

for (int i=0; i < StatusBar1->Panels->Count; i++)//������ StatusBar
    {
      StatusBar1->Panels->Items[i]->Text = "";
    }

ListBox1->Items->Clear();//������ 2�� ������ drag&drop
ListBox2->Items->Clear();
}
//-----------------------[������ ���������� ������]----------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{        
/////////////////////////���������� ����� �������///////////////////////////////
      StringGrid1->Cells[1][0] = "Mu";
      StringGrid1->Cells[2][0] = "Alpha";
////////////////////////////////////////////////////////////////////////////////
     int g=1;
     ADOTable1->First();
     while (!ADOTable1->Eof)
     {
      for (int j = 0; j < ADOTable1->FieldCount; j++)
         StringGrid1->Cells[0][g] = ADOTable1->Fields->Fields[0]->AsFloat;
       ADOTable1->Next();
       g++;
     };
////////////////////////////////////////////////////////////////////////////////

  double Mu=0;    //�����=arccos(k/Q); k = ������(h0)*������(hi), Q = sqrt(Mu0*Mi).
  int i=1;
  ADOTable1->First();
  double *MuArray = new double [ADOTable1->RecordCount]; //������ �������� ��
  while (!ADOTable1->Eof)
  {
        Mu =0;
        for (int j = 1; j < ADOTable1->FieldCount; j++)
        {              ////////������ ��  ////////
          Mu += pow((ADOTable1->Fields->Fields[j]->AsFloat),2);//����� ��������� ������
        }
         Mu = sqrt(Mu);//��������� �� �� ��� ����� �����
         MuArray[i-1] = Mu;
         StringGrid1->Cells[1][i] = Mu; //����� �� � �������
         ADOTable1->Next();
         i++;
  };



  double k=0; // Al=0, Q=0;//�����=arccos(k/Q); k = (h0)*(hi), Q = (Mu0*Mi)^2.

////////���������� ������������ ������, �������� 1-� ������ ADOTable1///////////
  double *MoArray = new double [ADOTable1->FieldCount]; //������ �� ��������
  ADOTable1->First();
  for (int i=1; i<ADOTable1->FieldCount; i++)
    {
       MoArray[i-1] = ADOTable1->Fields->Fields[i]->AsFloat;
    }
////////////////////////////////////////////////////////////////////////////////

////k = (h0)*(hi); �������� 1�������� ������ �� ������ ADOTable1////
  int f=0;
  double *AlArray = new double [ADOTable1->RecordCount]; //������ �������� �����
  ADOTable1->First();
  while (!ADOTable1->Eof)
  {
    k=0;
       for (int j=1; j<ADOTable1->FieldCount; j++)
       {
          k += MoArray[j-1] * ADOTable1->Fields->Fields[j]->AsFloat;
       }
      AlArray[f] = k;
      StringGrid1->Cells[2][f+1] = FloatToStr(acos(k/(MuArray[0]*MuArray[f])));
      //StringGrid1->Cells[2][f+1] = FloatToStr(acos(k/(StrToFloat(StringGrid1->Cells[1][1])*StrToFloat(StringGrid1->Cells[1][f+1]))));
      ADOTable1->Next();
      f++;
  };
////////////////////////////////////////////////////////////////////////////////
     /////////////////////////����������� ������///////////////////////////////////
   delete [] MoArray;
   delete [] MuArray;
   delete [] AlArray;
   //delete [] Qarray;
}

//---------------------�����------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{



///////////////////�������� �����///////////////////////////////////////////////
          // for (int i=0; i<ADOTable1->RecordCount; i++)
           {
           // StringGrid1->Cells[2][i+1] = acos(karray[i]/Qarray[i]);
           }
////////////////////////////////////////////////////////////////////////////////



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
   Series1->LinePen->Width = 5; Series1->SeriesColor = clRed;
   Series1->Clear();

        for( int i = 0; i < ADOTable1->RecordCount; i++)
          {
           // Series1->AddXY(StrToFloat(StringGrid1->Cells[1][i]), StrToFloat(StringGrid1->Cells[2][i]));
          }

}
//---------------------------------------------------------------------------




  int iSchetchik = 0;//������� ������� �� ������ [��������� �������]
void __fastcall TForm1::Button7Click(TObject *Sender)
{
  iSchetchik++;
                           //������ ���������, ������� � ������
  int iKolRecord = ListBox2->Items->Count;//�������� ����������� ����� � ����������� ������
  int iKolField =  ADOTable1->FieldCount;//�������� ����������� �������� � ����. �������
  StringGrid2->RowCount=StringGrid2->RowCount+(iKolRecord-1);
  StringGrid2->ColCount = StringGrid2->ColCount+(iKolField-2);

  if ( iSchetchik == 1)
  {
    Button7->Enabled = False;
  }
    int iAR = ADOTable1->RecordCount; //����������� ����� � ADOTable1


    for (int i=0; i<iAR; i++)
    {   int j=0;
     //Edit2->Text = ListBox2->Items->Strings[ListBox2->ItemIndex[i]];
         //while (ListBox2->Items->Strings[ListBox2->ItemIndex] == ADOTable1->Fields->Fields[i])
        {
         //   StringGrid1->Cells[i][j] = ADOTable1->Fields[0][iAR]
        }
        j++;
    }
  //
   //for (int j=0; j<iKolRecord; j++)
   {
   // if (ListBox2->Items[i] == ADOTable1->Fields[0][iAR])
     {
    //StringGrid1->Cells[i][j] = ADOTable1->Fields[0][iAR];
     }

   }




}
//---------------------------------[������� �������]------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
   for (int i = 0; i < StringGrid2->ColCount; i++)
   {
    for (int j = 0; j < StringGrid2->RowCount; j++)
    {
      StringGrid2->Cells[i][j] = "";
      iSchetchik = 0;
      Button7->Enabled = True;
    }
   }
   StringGrid2->RowCount= 0;
   StringGrid2->ColCount = 0;
}
//---------------------------------------------------------------------------
