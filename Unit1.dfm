object Form1: TForm1
  Left = 667
  Top = 512
  Width = 1270
  Height = 799
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 32
    Top = 80
    Width = 48
    Height = 13
    Caption = #1058#1072#1073#1083#1080#1094#1099':'
  end
  object Image1: TImage
    Left = 648
    Top = 120
    Width = 505
    Height = 321
  end
  object Button1: TButton
    Left = 16
    Top = 24
    Width = 75
    Height = 25
    Caption = #1054#1090#1082#1088#1099#1090#1100' '#1041#1044
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 144
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object ComboBox1: TComboBox
    Left = 96
    Top = 72
    Width = 145
    Height = 21
    ItemHeight = 13
    TabOrder = 2
    OnChange = ComboBox1Change
  end
  object Button2: TButton
    Left = 280
    Top = 72
    Width = 153
    Height = 25
    Caption = #1055#1086#1082#1072#1079#1072#1090#1100' '#1090#1072#1073#1083#1080#1094#1091
    TabOrder = 3
    OnClick = Button2Click
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 741
    Width = 1254
    Height = 19
    Panels = <
      item
        Text = 'Items'
        Width = 50
      end>
    SimplePanel = False
  end
  object DBGrid1: TDBGrid
    Left = 24
    Top = 160
    Width = 545
    Height = 273
    DataSource = DataSource1
    TabOrder = 5
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object OpenDialog1: TOpenDialog
    Left = 528
    Top = 104
  end
  object ADOConnection1: TADOConnection
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 288
    Top = 128
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 320
    Top = 128
  end
  object ADOTable1: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Y'
    Left = 352
    Top = 128
  end
end
