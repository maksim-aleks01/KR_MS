object Form1: TForm1
  Left = 245
  Top = 144
  Width = 1061
  Height = 570
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 1033
    Height = 497
    ActivePage = TabSheet1
    TabIndex = 0
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'TabSheet1'
      object Label1: TLabel
        Left = 8
        Top = 56
        Width = 48
        Height = 13
        Caption = #1058#1072#1073#1083#1080#1094#1099':'
      end
      object Image1: TImage
        Left = 672
        Top = 100
        Width = 305
        Height = 201
        Center = True
        Stretch = True
      end
      object Button1: TButton
        Left = 8
        Top = 8
        Width = 75
        Height = 25
        Caption = #1054#1090#1082#1088#1099#1090#1100' '#1041#1044
        TabOrder = 0
        OnClick = Button1Click
      end
      object Edit1: TEdit
        Left = 96
        Top = 8
        Width = 121
        Height = 21
        TabOrder = 1
      end
      object ComboBox1: TComboBox
        Left = 72
        Top = 48
        Width = 145
        Height = 21
        ItemHeight = 13
        TabOrder = 2
        OnChange = ComboBox1Change
      end
      object Button2: TButton
        Left = 248
        Top = 48
        Width = 153
        Height = 25
        Caption = #1055#1086#1082#1072#1079#1072#1090#1100' '#1090#1072#1073#1083#1080#1094#1091
        TabOrder = 3
        OnClick = Button2Click
      end
      object StatusBar1: TStatusBar
        Left = 0
        Top = 450
        Width = 1025
        Height = 19
        Panels = <
          item
            Text = #1055#1091#1090#1100': '
            Width = 50
          end
          item
            BiDiMode = bdLeftToRight
            ParentBiDiMode = False
            Text = #1057#1090#1088#1086#1082': 0'
            Width = 70
          end
          item
            Text = #1057#1090#1086#1083#1073#1094#1086#1074': 0'
            Width = 80
          end>
        SimplePanel = False
      end
      object DBGrid1: TDBGrid
        Left = 24
        Top = 100
        Width = 641
        Height = 345
        DataSource = DataSource1
        TabOrder = 5
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
      object Memo1: TMemo
        Left = 672
        Top = 308
        Width = 185
        Height = 89
        Lines.Strings = (
          'Memo1'
          '')
        TabOrder = 6
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'TabSheet2'
      ImageIndex = 1
      object Label2: TLabel
        Left = 137
        Top = 8
        Width = 32
        Height = 13
        Caption = 'Label2'
      end
      object Label3: TLabel
        Left = 137
        Top = 24
        Width = 32
        Height = 13
        Caption = 'Label3'
        DragMode = dmAutomatic
      end
      object ListBox2: TListBox
        Left = 200
        Top = 64
        Width = 201
        Height = 273
        DragMode = dmAutomatic
        ItemHeight = 13
        MultiSelect = True
        TabOrder = 0
        OnDragDrop = ListBox2DragDrop
        OnDragOver = ListBox2DragOver
      end
      object StaticText2: TStaticText
        Left = 200
        Top = 48
        Width = 118
        Height = 17
        Caption = #1055#1088#1080#1085#1080#1084#1072#1102#1097#1080#1081' '#1089#1087#1080#1089#1086#1082
        TabOrder = 1
      end
      object ListBox1: TListBox
        Left = 8
        Top = 64
        Width = 177
        Height = 273
        DragMode = dmAutomatic
        ItemHeight = 13
        MultiSelect = True
        TabOrder = 2
        OnDragDrop = ListBox2DragDrop
        OnDragOver = ListBox2DragOver
      end
      object StaticText1: TStaticText
        Left = 8
        Top = 48
        Width = 86
        Height = 17
        Caption = #1057#1087#1080#1089#1086#1082' '#1057#1090#1072#1085#1094#1080#1081
        TabOrder = 3
      end
      object Button3: TButton
        Left = 8
        Top = 12
        Width = 113
        Height = 25
        Caption = #1079#1072#1087#1086#1083#1085#1103#1077#1084' '#1084#1072#1089#1089#1080#1074
        TabOrder = 4
        OnClick = Button3Click
      end
    end
  end
  object ADOConnection1: TADOConnection
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 264
    Top = 224
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 296
    Top = 224
  end
  object ADOTable1: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'XX'
    Left = 328
    Top = 224
  end
  object MainMenu1: TMainMenu
    Images = ImageList1
    Left = 736
    Top = 80
    object Menu1: TMenuItem
      Caption = 'Menu'
      object Open1: TMenuItem
        Caption = 'Action1'
      end
      object CloseDB1: TMenuItem
        Caption = 'Close '
        ImageIndex = 0
      end
      object Exit1: TMenuItem
        Caption = 'Exit'
      end
    end
    object About1: TMenuItem
      Caption = 'About'
      object N1: TMenuItem
        Caption = #1050#1072#1083#1103#1082#1072' '#1084#1072#1083#1103#1082#1072
        ImageIndex = 2
      end
    end
  end
  object ActionList1: TActionList
    Left = 776
    Top = 80
  end
  object ImageList1: TImageList
    Left = 816
    Top = 80
    Bitmap = {
      494C010103000400040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000001000000001002000000000000010
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000FFFAFAFAFFF4F4F4FFEDED
      EDFFE6E6E6FFE0E0E0FFDCDCDCFFDADADAFFDADADAFFDEDEDEFFE3E3E3FFEAEA
      EAFFF1F1F1FFF7F7F7FFFDFDFDFF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000848484006B6B6B00636363005A5A5A005A5A5A006B6B6B007B7B7B00A5A5
      A500848484000000000000000000000000000000000000000000000000000000
      0000848484006B6B6B00636363005A5A5A005A5A5A006B6B6B007B7B7B00A5A5
      A50084848400000000000000000000000000000000FF000000FFFEFEFEFFFBFB
      FBFFF8F8F8FFD3C6B7FFCA8636FFEB8105FFDF8216FFBC976CFFF7F6F5FFF9F9
      F9FFFCFCFCFF000000FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000006363
      63009C9C9C005A5A5A00636363008C8C8C00ADADAD00BDBDBD00BDBDBD008C8C
      8C00848484008484840000000000000000000000000000000000000000006363
      63009C9C9C005A5A5A00636363008C8C8C00ADADAD00BDBDBD00BDBDBD008C8C
      8C0084848400848484000000000000000000000000FF000000FF000000FFFBEB
      D8FFEC8000FFEC8307FFEE8D1BFFEF9427FFEE9123FFED8811FFEC8000FFEF9A
      35FF000000FF000000FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000006B6B
      6B00DEDEDE00636363006363630094949400A5A5A500CECECE00D6D6D600B5B5
      B500ADADAD00B5B5B50000000000000000000000000000000000000000006B6B
      6B00DEDEDE00636363006363630094949400A5A5A500CECECE00D6D6D600B5B5
      B500ADADAD00B5B5B5000000000000000000000000FF000000FFF7D9B7FFE77D
      00FFE97E00FFDC7C0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEC8307FFEC80
      00FFEC8307FF000000FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000006B6B
      6B00D6D6D60063636300636363008C8C8C00A5A5A500C6C6C600D6D6D600B5B5
      B500ADADAD00B5B5B50000000000000000000000000000000000000000006B6B
      6B00D6D6D60063636300636363008C8C8C00A5A5A500C6C6C600D6D6D600B5B5
      B500ADADAD00B5B5B5000000000000000000000000FFFEFDFDFFE07800FFE279
      00FFE37A00FFE07700FFD16D00FFFFFFFFFFFFFFFFFFDB7400FFEB7F00FFEC80
      00FFEC8000FFF09B37FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000006B6B
      6B00C6C6C6005A5A5A00525252005A5A5A005A5A5A006B6B6B007B7B7B009494
      940000520000005A0000005A0000000000000000000000000000000000006B6B
      6B00C6C6C6005A5A5A00525252005A5A5A005A5A5A006B6B6B007B7B7B009494
      94009C9C9C00086B08000000000000000000000000FFDF8827FFDB7400FFDD75
      00FFDE7600FFDF7700FFD46F00FFFFFFFFFFFFFFFFFFE57B00FFE77C00FFE87D
      00FFE97E00FFEB7F00FFFEFEFEFF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000005A5A
      5A00A5A5A5005A5A5A005A5A5A008C8C8C00A5A5A500BDBDBD00BDBDBD000063
      080000730800007B0800006B0800005200000000000000000000000000005A5A
      5A00A5A5A5005A5A5A005A5A5A008C8C8C00A5A5A500BDBDBD00BDBDBD008C8C
      8C00005A000031C65A00086B080000000000000000FFD47000FFD67100FFD772
      00FFD97300FFDA7400FFCF6D00FFFFFFFFFFFFFFFFFFE07800FFE17900FFE37A
      00FFE47A00FFE57B00FFF1B876FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000006B6B
      6300E7DED60063635A00635A63008C948C00A5A5A500005A0000006B08000084
      0800005A0000B5B5B50000000000000000000000000000000000000000006B6B
      6300E7DED60063635A00635A63008C948C00A5A5A500CECECE00D6D6D6001894
      310042E77B0029C65200109C2100005A0000000000FFCF6C00FFD16D00FFD26E
      00FFD36F00FFD57000FFCC6A00FFFFFFFFFFFFFFFFFFDB7400FFDC7500FFDD76
      00FFDF7700FFE07800FFE48619FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000006B73
      7300D6D6D6005A635A0063636B008C8C8C00A5A5A500005A000000840800006B
      0800ADADAD00B5B5B50000000000000000000000000000000000000000006B73
      7300D6D6D6005A635A0063636B008C8C8C00A5A5A500CECECE00005A0000189C
      310021AD420021B5420018AD3100109C2100000000FFCA6900FFCC6B01FFD177
      14FFD27916FFCA7110FFFFFFFFFFFFFFFFFFFFFFFFFFD97D16FFDA7E16FFDC7F
      16FFDB7A0CFFDB7400FFDC7806FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000006B63
      6300CECECE00525263005A5A5A005A5A5A005A5A5A00005A000010A52100005A
      00009C9C9C00B5B5B50000000000000000000000000000000000000000006B63
      6300CECECE00525263005A5A5A005A5A5A005A5A5A006B6B6B00848484009494
      9400005A000010A52100005A000000000000000000FFC76E0EFFD0822EFFD283
      2EFFD3832EFFD0802AFFCA7922FFCB7A22FFCC7B22FFD9872EFFDA882EFFDB89
      2EFFDC8A2EFFDD8B2DFFE0943EFF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000006B63
      6300A5A5A5005A63520063636300005A0000005A0000005A000018AD3100005A
      0000005A0000005A000000000000000000000000000000000000000000006B63
      6300A5A5A5005A635200636363008C8C8C00A5A5A500C6C6C600CECECE009C9C
      9C00005A000000941000005A000000000000000000FFBE6100FFD28D45FFD38E
      45FFD48F45FFD59045FFD38C40FFE5C3A1FFD59A5DFFD99245FFDA9345FFDB94
      45FFDC9545FFDA8C36FFF4DCC3FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000006B63
      6300E7DED6005A635A0063635A00848C8C00005A0000109C210029C6520042E7
      7B0018943100ADADAD0000000000000000000000000000000000000000006B63
      6300E7DED6005A635A0063635A00848C8C009C9C9C00C6C6C600CECECE00005A
      000000840800006B0800005A000000000000000000FFE4C29FFFCE8B46FFD59A
      5DFFD69B5DFFD79B5DFFF4E6D9FFFFFFFFFFFFFFFFFFD18F4AFFDB9F5DFFDC9F
      5DFFDDA05DFFCB6A00FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000006B63
      6300E7DED6005A5A630063635A00848C8C009C9C9C0021AD420042DE7300189C
      310000520000ADADAD0000000000000000000000000000000000000000006B63
      6300E7DED6005A5A630063635A00848C8C009C9C9C00C6C6C600CECECE000084
      080000941000005200000000000000000000000000FF000000FFB9640EFFD7A4
      70FFD9A875FFDAA875FFEDDAC6FFFFFFFFFFFFFFFFFFD59D63FFDEAB75FFDFAB
      75FFCA761BFFF6E7D8FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000006363
      6B00A5A5A5005A52630052525200635A6300636363006B6B6B00086B08008484
      840084848400ADADAD0000000000000000000000000000000000000000006363
      6B00A5A5A5005A52630052525200635A630063636300005A0000005A00000052
      000084848400ADADAD000000000000000000000000FF000000FF000000FFB562
      0EFFCE955BFFDEB68DFFDEB58BFFDBB289FFD6A471FFE1B78DFFE1B78CFFC068
      0CFFECD2B7FF000000FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000006B73
      6B00ADADB500949494009CA59400ADADAD00A5A5A500ADADAD00ADADAD009C9C
      9C008C8C8C009C9C9C0000000000000000000000000000000000000000006B73
      6B00ADADB500949494009CA59400ADADAD00A5A5A500ADADAD00ADADAD009C9C
      9C008C8C8C009C9C9C000000000000000000000000FF000000FF000000FF0000
      00FFE0BF9EFFAF5700FFBA6D1FFFC78646FFC47F39FFB55D02FFC07426FFFEFD
      FDFF000000FF000000FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000FF000000FF000000FF0000
      00FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF0000
      00FF000000FF000000FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000100000000100010000000000800000000000000000000000
      000000000000000000000000FFFFFF00FFFFFFFF80010000F007F007C0070000
      E003E003E00F0000E003E003C0070000E003E00380030000E001E00380010000
      E000E00180010000E003E00080010000E003E00080010000E003E00180010000
      E003E00180010000E003E00180030000E003E003C0030000E003E003E0070000
      E003E003F00F0000FFFFFFFFFFFF000000000000000000000000000000000000
      000000000000}
  end
  object OpenDialog1: TOpenDialog
    Filter = 'Microsoft Access|*.mdb'
    Left = 584
    Top = 88
  end
end