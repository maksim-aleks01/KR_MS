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

   //���������� ���������� ����������� � ��������
AnsiString s1= "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=";
AnsiString s2 = ";Persist Security Info=False";
AnsiString ConStr;

//----------------------------------[�������� �������]--------------------------  
void __fastcall TForm1::Button2Click(TObject *Sender)
{
   if (ADOTable1->Active==true) ADOTable1->Active=false;
        if (ComboBox1->Text!="")
        {
         ADOTable1->TableName=ComboBox1->Text;
         ADOTable1->Active=true;

         if (ListBox1->Items != 0) ListBox1->Items->Clear();//��� �� �� ������������ ListBox1

         StatusBar1->Panels->Items[1]->Text = "�����: " + FloatToStr(ADOTable1->RecordCount); //����� ���-�� ������� � �����
         StatusBar1->Panels->Items[2]->Text = "��������: " + FloatToStr(ADOTable1->FieldCount);

         for (int i=1;i<ADOTable1->FieldCount;i++)   //��������� ������� ������ "��������"
              {ListBox1->Items->Append(ADOTable1->FieldList->Strings[i]);}
        }
        else
        {ShowMessage("������� �� �������!");}
}

//------------------[������ ������� ��]-----------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 OpenDialog1->Execute();
 if (ADOTable1->Active) ADOTable1->Active=false;
 if (ADOConnection1->Connected==true) ADOConnection1->Connected=false;
 if (ListBox1->Items != 0) ListBox1->Items->Clear();
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

  /////////////////////////���������� ����� �������/////////////////////////////
      StringGrid1->Cells[1][0] = "Mu";
      StringGrid1->Cells[2][0] = "Alpha";
      StringGrid1->Cells[3][0] = "Mu+";
      StringGrid1->Cells[4][0] = "Mu-";
      StringGrid1->Cells[5][0] = "Alpha+";
      StringGrid1->Cells[6][0] = "Alpha-";
  //////////////////////////////////////////////////////////////////////////////
  }
}

//------------------------------[DragOver]--------------------------------------
void __fastcall TForm1::ListBox2DragOver(TObject *Sender, TObject *Source,
      int X, int Y, TDragState State, bool &Accept)
{
 TListBox *mSrc =(TListBox *)Source;//������� ��������� �� ����� TListBox ��������

 //���� � ��������� ������ 0 ��������� � ������ ���� �� 1 - ��������� �������
 if (mSrc->Count>0 && mSrc->SelCount>0) Accept = true;
 else Accept = false;
}

//------------------------[DragDrop]--------------------------------------------
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

//------------------------------------------------------------------------------
void __fastcall TForm1::Exit1Click(TObject *Sender)
{
   exit(0);
}

//------------------------[������ ����->������� ��]-----------------------------
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
 StatusBar1->Panels->Items[1]->Text = "�����: " + FloatToStr(ADOTable1->RecordCount);
 StatusBar1->Panels->Items[2]->Text = "��������: " + FloatToStr(ADOTable1->FieldCount);

 for (int i=1;i<ADOTable1->FieldCount;i++) //���������� ������ ��������� (���������)
  {
    ListBox1->Items->Append(ADOTable1->FieldList->Strings[i]);
  }

    /////////////////////���������� ����� �������///////////////////////////////
      StringGrid1->Cells[1][0] = "Mu";
      StringGrid1->Cells[2][0] = "Alpha";
      StringGrid1->Cells[3][0] = "Mu+";
      StringGrid1->Cells[4][0] = "Mu-";
      StringGrid1->Cells[5][0] = "Alpha+";
      StringGrid1->Cells[6][0] = "Alpha-";
    ////////////////////////////////////////////////////////////////////////////
}

//----------------------[������ ����->������ ��]--------------------------------
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

 for (int i = 0; i < StringGrid1->ColCount; i++) //������� ������� ��������
   { for (int j = 0; j < StringGrid1->RowCount; j++)
       { StringGrid1->Cells[i][j] = "";}
   }
   StringGrid2->RowCount= 0;
   StringGrid2->ColCount = 0;

   for (int i = 0; i < StringGrid2->ColCount; i++) //������� ������� 2-�� ������
   { for (int j = 0; j < StringGrid2->RowCount; j++)
       { StringGrid2->Cells[i][j] = "";}
   }
   Button7->Enabled = True;//������ ������ "��������� �������"
   StringGrid2->RowCount= 0;
   StringGrid2->ColCount = 0;
}

//-----------------------[��������� ������]-----------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
 if (StringGrid2->RowCount == 0)
 {
   Series1->LinePen->Width = 1; Series1->SeriesColor = clRed;
   Series1->Clear();

        for( int i = 0; i < ADOTable1->RecordCount; i++)
          {
           Series1->AddXY(StrToFloat(StringGrid1->Cells[1][i+1]), StrToFloat(StringGrid1->Cells[2][i+1]));
          }
 }
  else {ShowMessage("��� �������� �� � �����");}
}

//---------------------[��������� �������]--------------------------------------
  int iSchetchik = 0;//������� ������� �� ������ [��������� �������]
void __fastcall TForm1::Button7Click(TObject *Sender)
{
 if (ComboBox1->Text!="")//�������� �������� ��
 {
  iSchetchik++;;

  //////////////////��������� ������� � �������/////////////////////////////////
   int g=1;
     ADOTable1->First();
     while (!ADOTable1->Eof)
     {
      for (int j = 0; j < ADOTable1->FieldCount; j++) //���������� ����� ������� ��������
         StringGrid2->Cells[0][g] = ADOTable1->Fields->Fields[0]->AsFloat;
       ADOTable1->Next();
       g++;
     };
  //////////////////////////////////////////////////////////////////////////////

                           //������ ���������, ������� � ������
  int iKolField = ListBox2->Items->Count;//�������� ����������� �������� � ����������� ������
  int  iKolRecord =  ADOTable1->RecordCount;//�������� ����������� �����  � ����. �������
  StringGrid2->RowCount = StringGrid2->RowCount+(iKolRecord-1);
  StringGrid2->ColCount = StringGrid2->ColCount+(iKolField-1);

  if ( iSchetchik == 1)
  {Button7->Enabled = False;}

   /////////////////////���������� �������///////////////////////////////
 ADOTable1->First();
 
 //while (!ADOTable1->Eof)     ListBox2->Items->Count   ADOTable1->RecordCount
 for (int j=0; j<ListBox2->Items->Count; j++)
  {  ADOTable1->First();
   for (int i=0; i<ADOTable1->RecordCount; i++)
      {
        StringGrid2->Cells[j+1][0] = ListBox2->Items->Strings[j];
        StringGrid2->Cells[j+1][i+1] = ADOTable1->FieldByName(ListBox2->Items->Strings[j])->AsString;
        ADOTable1->Next();
      }
  }
 }
  else {ShowMessage("�� �� ������� ��� �� ������� �������!");}
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
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Edit2KeyPress(TObject *Sender, char &Key)
{
 if((Key!=VK_BACK)&&(Key<'0'||Key>'9')&&(Key!=','))Key=0;// ���������� ����� �������
}

//-----------------[����������� ��� ������� � ������ ��������]---------------------------------------------------------- 
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
   for(int i=0; i<ListBox2->Items->Count; i++)
 {
  ListBox1->Items->Add(ListBox2->Items->Strings[i]);
 }
  ListBox2->Items->Clear();
}

//---------------[����������� ��� ������� � ������ ��������]--------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
 for(int i=0; i<ListBox1->Items->Count; i++)
 {
  ListBox2->Items->Add(ListBox1->Items->Strings[i]);
 }
 ListBox1->Items->Clear();
}

//-------------------------[������ ������]--------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
 if (ComboBox1->Text!="")//�������� �������� ��
 {
     int g=1;
     ADOTable1->First();
     while (!ADOTable1->Eof)
     {
      for (int j = 0; j < ADOTable1->FieldCount; j++) //���������� ����� ������� ��������
         StringGrid1->Cells[0][g] = ADOTable1->Fields->Fields[0]->AsFloat;
       ADOTable1->Next();
       g++;
     };
  //////////////////////////////////////////////////////////////////////////////
                //������ ��
  double Mu=0;
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
  }
               ///END ��///

   //������ �����
  double k=0; //�����=arccos(k/Q); k = (h0)*(hi), Q = (Mu0*Mi)^2.

  //////���������� ������������ ������, �������� 1-� ������ ADOTable1///////////
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
      AlArray[f] = acos(k/(MuArray[0]*MuArray[f]));
      StringGrid1->Cells[2][f+1] = FloatToStr(acos(k/(MuArray[0]*MuArray[f])));
      //StringGrid1->Cells[3][f+1] = k; //FloatToStr(acos(k/(StrToFloat(StringGrid1->Cells[1][1])*StrToFloat(StringGrid1->Cells[1][f+1]))));
      //StringGrid1->Cells[4][f+1] =(MuArray[0]*MuArray[f]);
      ADOTable1->Next();
      f++;
  }
    ///END �����///
     
    //////////////////////Epsilon///////////////////////////////////////////////
 double E=0.005;
 if(Edit2->Text!="")
 E=StrToFloat(Edit2->Text);
 else E=0,005;
     /////////////////////////Mu+///////////////////////////////////////////////
 for(int i=0; i<ADOTable1->RecordCount; i++)
   {
    StringGrid1->Cells[3][i+1] = MuArray[i] + E; //Mu+
    StringGrid1->Cells[4][i+1] = MuArray[i] - E; //Mu-
    StringGrid1->Cells[5][i+1] = AlArray[i] + E; //Alpha+
    StringGrid1->Cells[6][i+1] = AlArray[i] - E; //Alpha-
   }

  /////////////////////����������� ������///////////////////////////////////////
   delete [] MoArray;
   delete [] MuArray;
   delete [] AlArray;
 }
   else
        {ShowMessage("�� �� �������!");}
}

//-------------------------2-�� ������� [������]-----------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
if (ComboBox1->Text!="")//�������� �������� ��
 {
 /////////////////���������� ���� ������� �������� 2-�� ������/////////////////
     int g=1;
     ADOTable1->First();
     while (!ADOTable1->Eof)
     {
      for (int j = 0; j < ADOTable1->FieldCount; j++)
         StringGrid3->Cells[0][g] = ADOTable1->Fields->Fields[0]->AsFloat;
       ADOTable1->Next();
       g++;
     };
////////////////////////////////////////////////////////////////////////////////

  StringGrid3->RowCount = StringGrid2->RowCount;  //������ ���������, ������
  StringGrid3->Cells[1][0] = "Mu";
  StringGrid3->Cells[2][0] = "Alpha";
  StringGrid3->Cells[3][0] = "Mu+";
  StringGrid3->Cells[4][0] = "Mu-";
  StringGrid3->Cells[5][0] = "Alpha+";
  StringGrid3->Cells[6][0] = "Alpha-";

            //������ ��
  double Mu=0;
  double *MuArray = new double [StringGrid2->RowCount-1]; //������ �������� ��
  for (int i=1; i < StringGrid2->RowCount-1; i++)
  {
        Mu =0;
        for (int j = 1; j < StringGrid2->ColCount-1; j++)
        {              ////////������ ��  ////////
          Mu += pow(StrToFloat(StringGrid2->Cells[j][i]),2);//����� ��������� ������
        }
         Mu = sqrt(Mu);//��������� �� �� ��� ����� �����
         MuArray[i-1] = Mu;
         StringGrid3->Cells[1][i] = Mu; //����� �� � �������
  }
   ////////////////END ��/////////////////

                 //������ �����
  //�����=arccos(k/Q); k = (h0)*(hi), Q = (Mu0*Mi)^2.

  //////���������� ������������ ������, �������� 1-� ������ StringGrid2///////////
  double *MoArray = new double [StringGrid2->ColCount-1]; //������ �� ��������
  for (int i=1; i<StringGrid2->ColCount-1; i++)
    {
       MoArray[i-1] = StrToFloat(StringGrid2->Cells[1][i]);
    }
////////////////////////////////////////////////////////////////////////////////

     ////k = (h0)*(hi); �������� 1�������� ������ �� ������ ADOTable1////
  double k=0;
  double *AlArray = new double [StringGrid2->ColCount-1]; //������ �������� �����
  for(int f=0; f<StringGrid2->RowCount-1; f++)
  {
    k=0;
       for (int j=1; j<StringGrid2->ColCount-1; j++)
       {
          k += MoArray[j-1] * StrToFloat(StringGrid2->Cells[j][f+1]);
       }
      AlArray[f] = acos(k/(MuArray[0]*MuArray[f]));
      StringGrid3->Cells[2][f+1] = FloatToStr(acos(k/(MuArray[0]*MuArray[f])));//����� ALpha � �������
  }
    ///END �����///


 }
   else
        {ShowMessage("�� �� �������!");}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
  Edit3->Text = StringGrid2->RowCount;
}
//---------------------------------------------------------------------------

