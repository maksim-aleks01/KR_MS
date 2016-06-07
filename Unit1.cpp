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

         if (ListBox1->Items != 0) ListBox1->Items->Clear(); ListBox2->Items->Clear();//��� �� �� ������������ ListBox1

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

   StringGrid3->RowCount= 0;
   StringGrid3->ColCount = 0;

   Edit2->Text = 0.005; //��������� ��������� �������
}

//-----------------------[��������� ������]-----------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
 if (StringGrid3->RowCount > 2)
 {
  // Series1->LinePen->Width = 1; Series1->SeriesColor = clRed; Series1->Clear();
        Series1->Clear();
        Series2->Clear();
        Series3->Clear();
        Series4->Clear();
        Series5->Clear();
        Series6->Clear();
        Series7->Clear();
        Series8->Clear();

        for( int i = 0; i < ADOTable1->RecordCount-1; i++)
          {
          //����������� ������ ��(�����)
           double MuX = StrToFloat(StringGrid3->Cells[1][i+1]);
           double AlY = StrToFloat(StringGrid3->Cells[2][i+1]);
           double MuX1 = StrToFloat(StringGrid3->Cells[1][i+2]);
           double AlY1 = StrToFloat(StringGrid3->Cells[2][i+2]);
           Series1->AddArrow(MuX, AlY, MuX1, AlY1, StringGrid3->Cells[1][i+1], clRed); //Mu(Al)
           Series5->AddXY(MuX, AlY, "Fuck" , clWhite);

          //����������� ������ ��-(�����-)
           double MuMinX = StrToFloat(StringGrid3->Cells[4][i+1]);
           double AlMinY = StrToFloat(StringGrid3->Cells[6][i+1]);
           double MuMinX1 = StrToFloat(StringGrid3->Cells[4][i+2]);
           double AlMinY1 = StrToFloat(StringGrid3->Cells[6][i+2]);
           Series2->AddArrow(MuMinX, AlMinY, MuMinX1, AlMinY1, "", clBlue); //StringGrid3->Cells[4][i+1]
           Series6->AddXY(MuMinX, AlMinY, "Fuck" , clRed);

            //����������� ������ ��+(�����+)
           double MuMaxX = StrToFloat(StringGrid3->Cells[3][i+1]);
           double AlMaxY = StrToFloat(StringGrid3->Cells[5][i+1]);
           double MuMaxX1 = StrToFloat(StringGrid3->Cells[3][i+2]);
           double AlMaxY1 = StrToFloat(StringGrid3->Cells[5][i+2]);
           Series3->AddArrow(MuMaxX, AlMaxY, MuMaxX1, AlMaxY1, "", clGreen);
           Series7->AddXY(MuMaxX, AlMaxY, "Fuck" , clBlack);


            //����������� ������ ��-����������(�����-����������)
           double MuPrX = StrToFloat(StringGrid3->Cells[7][i+1]);
           double AlPrY = StrToFloat(StringGrid3->Cells[8][i+1]);
           double MuPrX1 = StrToFloat(StringGrid3->Cells[7][i+2]);
           double AlPrY1 = StrToFloat(StringGrid3->Cells[8][i+2]);
           Series4->AddArrow(MuPrX, AlPrY, MuPrX1, AlPrY1, "", clYellow);
           Series8->AddXY(MuPrX, AlPrY, "Fuck" , clLime);

          // Series2->AddArrow(StrToFloat(StringGrid3->Cells[3][i]), StrToFloat(StringGrid3->Cells[5][i])); //Mu+(Al+)
         //  Series3->AddArrow(StrToFloat(StringGrid3->Cells[4][i]), StrToFloat(StringGrid3->Cells[6][i]));  //Mu-(Al-)
          }
 }
  else {ShowMessage("��� ��������!");}
}

//---------------------[��������� �������]--------------------------------------
  int iSchetchik = 0;//������� ������� �� ������ [��������� �������]
void __fastcall TForm1::Button7Click(TObject *Sender)
{
 if (ComboBox1->Text!="" && ADOTable1->Active==true)//�������� �������� ��
 {
  iSchetchik++;
  if ( iSchetchik == 1)
  {Button7->Enabled = False;}//�������� ������ ����� �������

                             //������ ���������, ������� � ������
  StringGrid2->RowCount = ADOTable1->RecordCount+1; //�������� ����������� �����  � ����. �������
  StringGrid2->ColCount = ListBox2->Items->Count+1; //�������� ����������� �������� � ����������� ������

  //////////////////��������� ������� � �������/////////////////////////////////
   int g=1;
     ADOTable1->First();
     while (!ADOTable1->Eof)
     {
      for (int j = 0; j < ADOTable1->FieldCount; j++)
         StringGrid2->Cells[0][g] = ADOTable1->Fields->Fields[0]->AsFloat;
       ADOTable1->Next();
       g++;
     };
  //////////////////////////////////////////////////////////////////////////////

   /////////////////////���������� ������� �������///////////////////////////////
 StringGrid2->Cells[0][0] = ADOTable1->FieldList->Strings[0];//��� ������� ������
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
  else
  {
    if (ADOTable1->Active==false && ComboBox1->Text=="") ShowMessage("�� �� �������, �� ������� �������!");
    if (ADOTable1->Active==true && ComboBox1->Text!="") ShowMessage("�� ������� �������!");
    if (ADOTable1->Active==false && ComboBox1->Text!="") ShowMessage("�� �� �������!");
  }
}

//---------------------------------[������� �������]------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
   for (int i = 0; i < StringGrid2->ColCount; i++)    //������� ������ ������������
   {
    for (int j = 0; j < StringGrid2->RowCount; j++)
       {
        StringGrid2->Cells[i][j] = "";
        iSchetchik = 0;
        Button7->Enabled = True;
       }
   }


   for (int i = 0; i < StringGrid3->ColCount; i++) // ������� ������� ��������
   {
    for (int j = 0; j < StringGrid3->RowCount; j++)
       {
        StringGrid3->Cells[i][j] = "";
       }
   }

   Edit2->Text = 0.005; //��������� ��������� �������
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

     /////////////////////////Min\Max ������� �������///////////////////////////
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
if (ComboBox1->Text!="" && StringGrid2->RowCount > 2 && StringGrid2->ColCount >= 2)//�������� �������� ��
 {
 StringGrid3->RowCount = StringGrid2->RowCount+1; //������ ���������, ������
 StringGrid3->Cells[0][0] = StringGrid2->Cells[0][0]; //��� ������� ������

///////////////////���������� ���� ������� �������� 2-�� ������/////////////////
 int g=1; ADOTable1->First();
     while (!ADOTable1->Eof)
     {
      for (int j = 0; j < ADOTable1->FieldCount; j++)
         StringGrid3->Cells[0][g] = ADOTable1->Fields->Fields[0]->AsFloat;
         ADOTable1->Next();
         g++;
     }
////////////////////////////////////////////////////////////////////////////////

  StringGrid3->Cells[1][0] = "Mu";
  StringGrid3->Cells[2][0] = "Alpha";
  StringGrid3->Cells[3][0] = "Mu+";
  StringGrid3->Cells[4][0] = "Mu-";
  StringGrid3->Cells[5][0] = "Alpha+";
  StringGrid3->Cells[6][0] = "Alpha-";
  StringGrid3->Cells[7][0] = "������� ��";
  StringGrid3->Cells[8][0] = "������� Alpha";
      //////////////////////Epsilon///////////////////////////////////////////////
 double E=0.005;
 if(Edit2->Text!="")
 E=StrToFloat(Edit2->Text);
 else E=0,005;

    //////////////////////���������� �///////////////////////////////////////////////
 double A=0.1;
 if(Edit3->Text!="" && Edit3->Text <=1 )
 A=StrToFloat(Edit3->Text);
 else A=0,1;
             ////////������ ��, MuMax, MuMin////////
  double Mu(0), MuMax(0), MuMin(0), SumMu(0);
  //double *MuArray = new double [ADOTable1->RecordCount]; //������ �������� ��
  double MuArray [100]; double MaxMuArray [100]; double MinMuArray [100];

  for (int i=0; i<100; i++)//��������� ��������
   {
     MuArray[i] = 0;
     MaxMuArray[i] = 0;
     MinMuArray[i] = 0;
   }


  for (int i=1; i<ADOTable1->RecordCount+1; i++)
  {
        Mu =0; MuMax =0; MuMin =0;
        for (int j = 1; j < StringGrid2->ColCount; j++)
        {
          Mu += pow(StrToFloat(StringGrid2->Cells[j][i]),2);//����� ��������� ������
          MuMax += pow((StrToFloat(StringGrid2->Cells[j][i]))+E,2);
          MuMin += pow((StrToFloat(StringGrid2->Cells[j][i]))-E,2);
        }
         Mu = sqrt(Mu);//��������� �� �� ��� ����� �����
         MuMax = sqrt(MuMax);
         MuMin = sqrt(MuMin);

         SumMu += Mu; //����� ��

         StringGrid3->Cells[1][i] = Mu; //����� �� � �������
         StringGrid3->Cells[3][i] = MuMax; //"Mu+"
         StringGrid3->Cells[4][i] = MuMin; //"Mu-"

         MuArray[i-1] = Mu;//������� �������� � ������
         MaxMuArray[i-1] = MuMax;
         MinMuArray[i-1] = MuMin;
  }
   ////////////////END ��/////////////////

               //������ �����, MaxAlpha+, MinAlpha-
  //�����=arccos(k/Q); k = (h0)*(hi), Q = (MuArray[0]*MuArray[f])
  //////���������� ������������ ������, �������� 1-� ������ StringGrid2///////////
  //double *Str0Array = new double [StringGrid2->ColCount-1]; //������ ������� ������
  double Str0Array [100];
  double MaxStr0Array [100];
  double MinStr0Array [100];
  double SumAl=0;

  for (int i=0; i<100; i++) //��������� ��������
  {
   Str0Array[i] = 0;
   MaxStr0Array[i] = 0;
   MinStr0Array[i] = 0;
  }

  for (int i=1; i<StringGrid2->ColCount; i++)  //������
    {
       Str0Array[i-1] = StrToFloat(StringGrid2->Cells[i][1]);
       MaxStr0Array[i-1] = (StrToFloat(StringGrid2->Cells[i][1]))+E;
       MinStr0Array[i-1] = (StrToFloat(StringGrid2->Cells[i][1]))-E;
    }
////////////////////////////////////////////////////////////////////////////////

     ////k = (h0)*(hi); �������� 1�������� ������ �� ������ ADOTable1////
  double k=0; double kMax=0; double kMin=0;

  //double *AlArray = new double [StringGrid2->ColCount-1]; //������ �������� �����
  double AlArray [100]; double MaxAlArray [100]; double MinAlArray [100];

  //for (int i=0; i<StringGrid2->ColCount-1; i++) AlArray[i] = 0; // �������� ������
  for (int i=0; i<100; i++)
  {
   AlArray[i] = 0;
   MaxAlArray[i] = 0;
   MinAlArray[i] = 0;// �������� ������
  }

  for(int f=0; f<StringGrid2->RowCount-1; f++)
  {
    k=0; kMax=0; kMin=0;
       for (int j=1; j<StringGrid2->ColCount; j++)
       {
          k += Str0Array[j-1] * StrToFloat(StringGrid2->Cells[j][f+1]);
          kMax += MaxStr0Array[j-1] * ((StrToFloat(StringGrid2->Cells[j][f+1]))+E);
          kMin += MinStr0Array[j-1] * ((StrToFloat(StringGrid2->Cells[j][f+1]))-E);
       }

      double dProverka = k/(MuArray[0]*MuArray[f]);
      double MaXdProverka = kMax/(MaxMuArray[0]*MaxMuArray[f]);
      double MiNdProverka = kMin/(MinMuArray[0]*MinMuArray[f]);
      if (dProverka > 1 || MaXdProverka > 1 || MiNdProverka > 1)
       {
        dProverka = 1;
        MaXdProverka = 1;
        MiNdProverka = 1;

        AlArray[f] = acos(dProverka);
        MaxAlArray[f] = acos(MaXdProverka);
        MinAlArray[f] = acos(MiNdProverka);
       }
      else
       {
         AlArray[f] = acos(dProverka);
         MaxAlArray[f] = acos(MaXdProverka);
         MinAlArray[f] = acos(MiNdProverka);
       }

      SumAl += AlArray[f];
      StringGrid3->Cells[2][f+1] = FloatToStr(AlArray[f]);//����� ALpha � �������
      StringGrid3->Cells[5][f+1] = FloatToStr(MaxAlArray[f]);//����� ALpha+ � �������
      StringGrid3->Cells[6][f+1] = FloatToStr(MinAlArray[f]);//����� ALpha- � �������

  }
    ///END �����///


    //////������ ����������� �������� �� //////
     double MuPr0 = MuArray[0] * A +(1-A) * (SumMu/StrToFloat(ADOTable1->RecordCount)); //������ 0-�� ����������� �������� ��
     StringGrid3->Cells[7][1] = MuPr0;
     //Edit4->Text = MuPr0;
     double MuPrArray[100];
     for (int i=0; i<ADOTable1->RecordCount; i++)
        {
          MuPrArray[i] = MuArray[i+1] * A +(1-A) * MuPr0;
          StringGrid3->Cells[7][i+2] = MuPrArray[i];//����� ����������� �� � �������
        }
     double MuPrB = (SumMu/StrToFloat(ADOTable1->RecordCount)) * A +(1-A) * MuPrArray[ADOTable1->RecordCount]; //�� ���������
     StringGrid3->Cells[7][ADOTable1->RecordCount+1] = MuPrB;
     //////END Mu-pr//////

     //////������ ����������� �������� �����-pr//////
     double AlPr0 = AlArray[0] * A +(1-A) * (SumAl/StrToFloat(ADOTable1->RecordCount)); //������ 0-�� ����������� �������� ��
     StringGrid3->Cells[8][1] = AlPr0;

     double AlPrArray[100];
     for (int i=0; i<ADOTable1->RecordCount; i++)
        {
          AlPrArray[i] = AlArray[i+1] * A +(1-A) * AlPr0;
          StringGrid3->Cells[8][i+2] = AlPrArray[i];//����� ����������� ����� � �������
        }                             
     double AlPrB = (SumAl/StrToFloat(ADOTable1->RecordCount)) * A +(1-A) * AlPrArray[ADOTable1->RecordCount]; //����� ���������
     StringGrid3->Cells[8][ADOTable1->RecordCount] = AlPrB;
     //////END �����-pr//////


    /////////////////////����������� ������///////////////////////////////////////
   delete [] MuArray;
   delete [] Str0Array;
   delete [] AlArray;
 }
   else {
    if (StringGrid2->RowCount <= 2 || StringGrid2->ColCount <= 2){ShowMessage("������� �� �������!");}
    if (ComboBox1->Text==""){ShowMessage("�� �� �������!");}
   }

}
//---------------------------------------------------------------------------






void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
  if (OpenDialog1->FileName!="" && ComboBox1->Text!="" && ComboBox2->Text!="")
  {
        ADOTable1->First();
        double M[100];

        for (int i=0; i<ADOTable1->RecordCount; i++)
           {
             M[i]=ADOTable1->FieldByName(ComboBox2->Text)->AsFloat;
             ADOTable1->Next();
           }

        Series9->Clear();
        Series10->Clear();
        for (int i=1; i<ADOTable1->RecordCount; i++)
            {
                Series9->AddArrow(i-1,M[i-1],i,M[i]);
                Series10->AddXY(i-1,M[i-1],i,M[i]);
             }
        Chart2->Refresh();
  }

 else
     {
        if (OpenDialog1->FileName=="" && ComboBox1->Text=="")
        {  ShowMessage("������� ����� ���������� ��!");      }

        if (ComboBox2->Text=="")
        {          return;     }
     }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit3KeyPress(TObject *Sender, char &Key)
{
 if((Key!=VK_BACK)&&(Key<'0'||Key>'9')&&(Key!=','))Key=0;// ���������� ����� A        
}
//---------------------------------------------------------------------------



void __fastcall TForm1::CheckBox4Click(TObject *Sender)
{
          if (CheckBox4->Checked == true)
           {
            Series4->Clear(); Series8->Clear();
            for( int i = 0; i < ADOTable1->RecordCount-1; i++)
                   {
                    //����������� ������ ��-����������(�����-����������)
                        double MuPrX = StrToFloat(StringGrid3->Cells[7][i+1]);
                        double AlPrY = StrToFloat(StringGrid3->Cells[8][i+1]);
                        double MuPrX1 = StrToFloat(StringGrid3->Cells[7][i+2]);
                        double AlPrY1 = StrToFloat(StringGrid3->Cells[8][i+2]);
                        Series4->AddArrow(MuPrX, AlPrY, MuPrX1, AlPrY1, "", clYellow);
                        Series8->AddXY(MuPrX, AlPrY, "Fuck" , clLime);
                   }
           }
          else {Series4->Clear(); Series8->Clear();}  }
//---------------------------------------------------------------------------

