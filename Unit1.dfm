object Form1: TForm1
  Left = 244
  Top = 132
  Width = 1296
  Height = 612
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  DesignSize = (
    1280
    553)
  PixelsPerInch = 96
  TextHeight = 13
  object StatusBar1: TStatusBar
    Left = 0
    Top = 533
    Width = 1280
    Height = 20
    Panels = <
      item
        Text = #1055#1091#1090#1100': '
        Width = 400
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
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 1273
    Height = 529
    ActivePage = TabSheet1
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabIndex = 0
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = #1041#1072#1079#1072' '#1076#1072#1085#1085#1099#1093
      ParentShowHint = False
      ShowHint = True
      object Label1: TLabel
        Left = 13
        Top = 52
        Width = 46
        Height = 13
        Caption = #1058#1072#1073#1083#1080#1094#1072':'
      end
      object Image1: TImage
        Left = 768
        Top = 124
        Width = 465
        Height = 309
        Center = True
        Stretch = True
      end
      object Label2: TLabel
        Left = 192
        Top = 0
        Width = 66
        Height = 13
        Caption = #1054#1090#1082#1088#1099#1090#1072' '#1041#1044':'
      end
      object Button1: TButton
        Left = 8
        Top = 16
        Width = 75
        Height = 25
        Caption = #1054#1090#1082#1088#1099#1090#1100' '#1041#1044
        TabOrder = 0
        OnClick = Button1Click
      end
      object Edit1: TEdit
        Left = 88
        Top = 18
        Width = 281
        Height = 21
        TabOrder = 1
      end
      object ComboBox1: TComboBox
        Left = 64
        Top = 48
        Width = 145
        Height = 21
        ItemHeight = 13
        TabOrder = 2
      end
      object Button2: TButton
        Left = 216
        Top = 45
        Width = 153
        Height = 25
        Caption = #1055#1086#1082#1072#1079#1072#1090#1100' '#1090#1072#1073#1083#1080#1094#1091
        TabOrder = 3
        OnClick = Button2Click
      end
      object DBGrid1: TDBGrid
        Left = 0
        Top = 84
        Width = 737
        Height = 405
        DataSource = DataSource1
        TabOrder = 4
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
      object Button3: TButton
        Left = 608
        Top = 56
        Width = 129
        Height = 25
        Caption = #1057#1075#1077#1085#1077#1088#1080#1088#1086#1074#1072#1090#1100' '#1079#1072#1087#1080#1089#1100
        TabOrder = 5
        OnClick = Button3Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = '2 '#1091#1088#1086#1074#1077#1085#1100' '#1076#1077#1082#1086#1084#1087#1086#1079#1080#1094#1080#1080
      ImageIndex = 1
      object PageControl2: TPageControl
        Left = 0
        Top = 0
        Width = 1265
        Height = 501
        ActivePage = TabSheet5
        Align = alTop
        MultiLine = True
        Style = tsFlatButtons
        TabIndex = 0
        TabOrder = 0
        object TabSheet5: TTabSheet
          Caption = #1058#1072#1073#1083#1080#1094#1072
          object Label3: TLabel
            Left = 832
            Top = 8
            Width = 104
            Height = 13
            Caption = #1060#1072#1079#1086#1074#1099#1077' '#1074#1077#1083#1080#1095#1080#1085#1099':'
          end
          object StaticText1: TStaticText
            Left = 0
            Top = 8
            Width = 79
            Height = 17
            Caption = #1057#1087#1080#1089#1086#1082' '#1084#1072#1088#1086#1082':'
            TabOrder = 0
          end
          object ListBox1: TListBox
            Left = 0
            Top = 24
            Width = 98
            Height = 273
            DragMode = dmAutomatic
            ItemHeight = 13
            MultiSelect = True
            TabOrder = 1
            OnDragDrop = ListBox2DragDrop
            OnDragOver = ListBox2DragOver
          end
          object ListBox2: TListBox
            Left = 104
            Top = 24
            Width = 98
            Height = 273
            DragMode = dmAutomatic
            ItemHeight = 13
            MultiSelect = True
            TabOrder = 2
            OnDragDrop = ListBox2DragDrop
            OnDragOver = ListBox2DragOver
          end
          object StaticText2: TStaticText
            Left = 104
            Top = 8
            Width = 121
            Height = 17
            Caption = #1055#1088#1080#1085#1080#1084#1072#1102#1097#1080#1081' '#1089#1087#1080#1089#1086#1082':'
            TabOrder = 3
          end
          object BitBtn1: TBitBtn
            Left = 48
            Top = 304
            Width = 50
            Height = 25
            TabOrder = 4
            OnClick = BitBtn1Click
            Glyph.Data = {
              E6040000424DE604000000000000360000002800000014000000140000000100
              180000000000B0040000C40E0000C40E00000000000000000000FFFFFFFDFDFD
              FDFDFDFFFFFFFFFFFFF1F1F1BBBBBB7F7F7F3232320606060606063232327F7F
              7FBBBBBBF1F1F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEFFFFFFFC
              FCFC9090901A1A1A1E1E1E5F5F5F999999CECECECECECE9999995F5F5F1E1E1E
              1A1A1A909090FCFCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1F1F16161612121
              21949494EFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEF94949421
              2121616161F1F1F1FFFFFFFFFFFFFFFFFFFCFCFC616161202020D2D2D2FFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEFFFFFFFFFFFFD2D2D22020
              20616161FCFCFCFFFFFFFFFFFF909090212121D2D2D2FFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFC2C2C2CFCFCFFFFFFFFEFEFEFFFFFFFFFFFFFFFFFFD1D1D1212121
              909090FFFFFFF1F1F1181818949494FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8888
              88000000DDDDDDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF949494181818F1
              F1F1BBBBBB1E1E1EEFEFEFFFFFFFFFFFFFFFFFFFE6E6E66969690000005A5A5A
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEF1E1E1EBBBBBB7E7E
              7E5F5F5FFFFFFFFFFFFFFFFFFFCBCBCB393939000000010101D5D5D5FFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF5F5F5F7F7F7F333333999999
              FFFFFFFFFFFF8D8D8D1717170000000000000707075353534B4B4B4A4A4A4A4A
              4A4A4A4A4A4A4A4747475D5D5DE2E2E29F9F9F323232070707D0D0D0FCFCFC61
              6161000000000000000000000000000000000000000000000000000000000000
              0000000000000F0F0FC7C7C7D6D6D6050505070707D0D0D0FCFCFC6161610000
              0000000000000000000000000000000000000000000000000000000000000000
              00000F0F0FC7C7C7D6D6D6050505333333999999FFFFFFFFFFFF8D8D8D171717
              0000000000000707075353534B4B4B4A4A4A4A4A4A4A4A4A4A4A4A4747475D5D
              5DE2E2E29F9F9F3232327E7E7E5F5F5FFFFFFFFFFFFFFFFFFFCBCBCB39393900
              0000010101D5D5D5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              5F5F5F7F7F7FBCBCBC1F1F1FEFEFEFFFFFFFFFFFFFFFFFFFE6E6E66868680000
              005B5B5BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEF1E1E1EBB
              BBBBF1F1F1191919949494FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF888888000000
              DDDDDDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF949494181818F1F1F1FFFF
              FF909090212121D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC2C2C2CFCFCFFF
              FFFFFDFDFDFDFDFDFFFFFFFFFFFFD2D2D2212121909090FFFFFFFFFFFFFCFCFC
              6161611F1F1FD3D3D3FFFFFFFFFFFFFFFFFFFEFEFEFFFFFFFFFFFFFEFEFEFDFD
              FDFFFFFFFFFFFFD3D3D3202020616161FDFDFDFFFFFFFFFFFFFFFFFFF1F1F161
              6161212121949494EFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEF
              949494202020616161F1F1F1FFFFFFFDFDFDFFFFFFFFFFFFFFFFFFFCFCFC9090
              901A1A1A1E1E1E5F5F5F999999CECECECECECE9999995F5F5F1E1E1E1A1A1A90
              9090FCFCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1F1F1
              BBBBBB7F7F7F3232320606060606063232327F7F7FBBBBBBF1F1F1FFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFF}
          end
          object BitBtn2: TBitBtn
            Left = 104
            Top = 304
            Width = 50
            Height = 25
            TabOrder = 5
            OnClick = BitBtn2Click
            Glyph.Data = {
              E6040000424DE604000000000000360000002800000014000000140000000100
              180000000000B0040000C40E0000C40E00000000000000000000FFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFF1F1F1BBBBBB7F7F7F3232320606060606063232327F7F
              7FBBBBBBF1F1F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC
              FCFC9090901A1A1A1E1E1E5F5F5F999999CECECECECECE9999995F5F5F1E1E1E
              1A1A1A909090FCFCFCFFFFFFFFFFFFFFFFFFFDFDFDFFFFFFF1F1F16161612020
              20949494EFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEF94949421
              2121616161F1F1F1FFFFFFFFFFFFFFFFFFFDFDFD616161202020D3D3D3FFFFFF
              FFFFFFFDFDFDFEFEFEFFFFFFFFFFFFFEFEFEFFFFFFFFFFFFFFFFFFD3D3D31F1F
              1F616161FCFCFCFFFFFFFFFFFF909090212121D2D2D2FFFFFFFFFFFFFDFDFDFD
              FDFDFFFFFFCFCFCFC2C2C2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD1D1D1212121
              909090FFFFFFF1F1F1181818949494FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFDDDDDD000000888888FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF949494191919F1
              F1F1BBBBBB1E1E1EEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              5B5B5B000000686868E6E6E6FFFFFFFFFFFFFFFFFFEFEFEF1F1F1FBCBCBC7F7F
              7F5F5F5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD5D5D501
              0101000000393939CBCBCBFFFFFFFFFFFFFFFFFF5F5F5F7E7E7E3232329F9F9F
              E2E2E25D5D5D4747474A4A4A4A4A4A4A4A4A4A4A4A4B4B4B5353530707070000
              000000001717178D8D8DFFFFFFFFFFFF999999333333050505D6D6D6C7C7C70F
              0F0F000000000000000000000000000000000000000000000000000000000000
              000000000000616161FCFCFCD0D0D0070707050505D6D6D6C7C7C70F0F0F0000
              0000000000000000000000000000000000000000000000000000000000000000
              0000616161FCFCFCD0D0D00707073232329F9F9FE2E2E25D5D5D4747474A4A4A
              4A4A4A4A4A4A4A4A4A4B4B4B5353530707070000000000001717178D8D8DFFFF
              FFFFFFFF9999993333337F7F7F5F5F5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFD5D5D5010101000000393939CBCBCBFFFFFFFFFFFFFFFFFF
              5F5F5F7E7E7EBBBBBB1E1E1EEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFF5A5A5A000000696969E6E6E6FFFFFFFFFFFFFFFFFFEFEFEF1E1E1EBB
              BBBBF1F1F1181818949494FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDDDDD
              000000888888FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF949494181818F1F1F1FFFF
              FF909090212121D1D1D1FFFFFFFFFFFFFFFFFFFEFEFEFFFFFFCFCFCFC2C2C2FF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFD2D2D2212121909090FFFFFFFFFFFFFCFCFC
              616161202020D2D2D2FFFFFFFFFFFFFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFD2D2D2202020616161FCFCFCFFFFFFFFFFFFFFFFFFF1F1F161
              6161212121949494EFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEF
              949494212121616161F1F1F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCFCFC9090
              901A1A1A1E1E1E5F5F5F999999CECECECECECE9999995F5F5F1E1E1E1A1A1A90
              9090FCFCFCFFFFFFFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1F1F1
              BBBBBB7F7F7F3232320606060606063232327F7F7FBBBBBBF1F1F1FFFFFFFFFF
              FFFDFDFDFDFDFDFFFFFF}
          end
          object Button7: TButton
            Left = 224
            Top = 304
            Width = 113
            Height = 25
            Caption = #1055#1086#1089#1090#1088#1086#1080#1090#1100' '#1090#1072#1073#1083#1080#1094#1091
            TabOrder = 6
            OnClick = Button7Click
          end
          object Button8: TButton
            Left = 408
            Top = 304
            Width = 113
            Height = 25
            Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1090#1072#1073#1083#1080#1094#1091
            TabOrder = 7
            OnClick = Button8Click
          end
          object StringGrid2: TStringGrid
            Left = 224
            Top = 24
            Width = 297
            Height = 273
            ColCount = 2
            RowCount = 2
            TabOrder = 8
            RowHeights = (
              24
              24)
          end
          object StringGrid3: TStringGrid
            Left = 528
            Top = 24
            Width = 721
            Height = 273
            ColCount = 10
            RowCount = 2
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSizing, goColSizing]
            TabOrder = 9
            ColWidths = (
              64
              64
              56
              64
              54
              58
              58
              70
              75
              94)
          end
          object Button4: TButton
            Left = 776
            Top = 304
            Width = 137
            Height = 25
            Caption = #1056#1072#1089#1095#1077#1090' '#1074#1090#1086#1088#1086#1075#1086' '#1091#1088#1074#1086#1085#1103' '
            TabOrder = 10
            OnClick = Button4Click
          end
          object GroupBox2: TGroupBox
            Left = 528
            Top = 304
            Width = 201
            Height = 89
            TabOrder = 11
            object Label6: TLabel
              Left = 39
              Top = 55
              Width = 10
              Height = 13
              Caption = #1040':'
            end
            object Label7: TLabel
              Left = 16
              Top = 30
              Width = 177
              Height = 13
              Caption = 'Epsilon:                                          ('#1084')'
            end
            object Edit2: TEdit
              Left = 56
              Top = 28
              Width = 121
              Height = 21
              TabOrder = 0
              Text = '0,005'
              OnKeyPress = Edit2KeyPress
            end
            object Edit3: TEdit
              Left = 56
              Top = 56
              Width = 121
              Height = 21
              TabOrder = 1
              Text = '0,1'
              OnKeyPress = Edit3KeyPress
            end
          end
        end
        object TabSheet6: TTabSheet
          Caption = #1043#1088#1072#1092#1080#1082
          ImageIndex = 1
          object GroupBox1: TGroupBox
            Left = 0
            Top = 32
            Width = 137
            Height = 105
            Caption = #1043#1088#1072#1092#1080#1082#1080':'
            TabOrder = 0
            object CheckBox1: TCheckBox
              Left = 8
              Top = 32
              Width = 97
              Height = 17
              Caption = 'Mu(Al)'
              TabOrder = 0
              OnClick = CheckBox1Click
            end
            object CheckBox2: TCheckBox
              Left = 8
              Top = 48
              Width = 97
              Height = 17
              Caption = 'Mu+(Al+)'
              TabOrder = 1
              OnClick = CheckBox2Click
            end
            object CheckBox3: TCheckBox
              Left = 8
              Top = 64
              Width = 97
              Height = 17
              Caption = 'Mu-(Al-)'
              TabOrder = 2
              OnClick = CheckBox3Click
            end
            object CheckBox4: TCheckBox
              Left = 8
              Top = 80
              Width = 121
              Height = 17
              Caption = #1055#1088#1086#1075#1085#1086#1079#1085#1099#1077' Mu(Al)'
              TabOrder = 3
              OnClick = CheckBox4Click
            end
          end
          object Chart1: TDBChart
            Left = 144
            Top = 0
            Width = 1001
            Height = 417
            AnimatedZoomSteps = 10
            BackWall.Brush.Color = clWhite
            BackWall.Brush.Style = bsClear
            LeftWall.Brush.Color = clWhite
            Title.Text.Strings = (
              #1043#1088#1072#1092#1080#1082' '#1079#1072#1074#1080#1089#1080#1084#1086#1089#1090#1077#1081':')
            BottomAxis.DateTimeFormat = 'dd.MM.yyyy'
            BottomAxis.RoundFirstLabel = False
            BottomAxis.Title.Caption = 'Mu'
            BottomAxis.Title.Font.Charset = ANSI_CHARSET
            BottomAxis.Title.Font.Color = clBlack
            BottomAxis.Title.Font.Height = -11
            BottomAxis.Title.Font.Name = 'Arial Narrow'
            BottomAxis.Title.Font.Style = []
            DepthAxis.AxisValuesFormat = '#,##0.########'
            LeftAxis.AxisValuesFormat = '#,##0.#######'
            LeftAxis.RoundFirstLabel = False
            LeftAxis.Title.Caption = #1040#1083#1100#1092#1072
            Legend.Alignment = laBottom
            Legend.ColorWidth = 40
            Legend.ResizeChart = False
            Legend.ShadowSize = 0
            Legend.TextStyle = ltsPlain
            Legend.VertMargin = 34
            View3D = False
            BevelOuter = bvNone
            BevelWidth = 0
            TabOrder = 1
            object Series1: TArrowSeries
              Marks.ArrowLength = 0
              Marks.Frame.Visible = False
              Marks.Transparent = True
              Marks.Visible = False
              SeriesColor = clRed
              Title = 'Mu(Al)'
              Pointer.InflateMargins = False
              Pointer.Style = psRectangle
              Pointer.Visible = True
              XValues.DateTime = True
              XValues.Name = 'X'
              XValues.Multiplier = 1
              XValues.Order = loAscending
              YValues.DateTime = False
              YValues.Name = 'Y'
              YValues.Multiplier = 1
              YValues.Order = loNone
              EndXValues.DateTime = True
              EndXValues.Name = 'EndX'
              EndXValues.Multiplier = 1
              EndXValues.Order = loNone
              EndYValues.DateTime = False
              EndYValues.Name = 'EndY'
              EndYValues.Multiplier = 1
              EndYValues.Order = loNone
              StartXValues.DateTime = True
              StartXValues.Name = 'X'
              StartXValues.Multiplier = 1
              StartXValues.Order = loAscending
              StartYValues.DateTime = False
              StartYValues.Name = 'Y'
              StartYValues.Multiplier = 1
              StartYValues.Order = loNone
            end
            object Series2: TArrowSeries
              Marks.ArrowLength = 0
              Marks.Frame.Visible = False
              Marks.Transparent = True
              Marks.Visible = False
              SeriesColor = clLime
              Title = 'Mu+(Al+)'
              Pointer.InflateMargins = False
              Pointer.Style = psRectangle
              Pointer.Visible = True
              XValues.DateTime = True
              XValues.Name = 'X'
              XValues.Multiplier = 1
              XValues.Order = loAscending
              YValues.DateTime = False
              YValues.Name = 'Y'
              YValues.Multiplier = 1
              YValues.Order = loNone
              EndXValues.DateTime = True
              EndXValues.Name = 'EndX'
              EndXValues.Multiplier = 1
              EndXValues.Order = loNone
              EndYValues.DateTime = False
              EndYValues.Name = 'EndY'
              EndYValues.Multiplier = 1
              EndYValues.Order = loNone
              StartXValues.DateTime = True
              StartXValues.Name = 'X'
              StartXValues.Multiplier = 1
              StartXValues.Order = loAscending
              StartYValues.DateTime = False
              StartYValues.Name = 'Y'
              StartYValues.Multiplier = 1
              StartYValues.Order = loNone
            end
            object Series3: TArrowSeries
              Marks.ArrowLength = 0
              Marks.Frame.Visible = False
              Marks.Transparent = True
              Marks.Visible = False
              SeriesColor = clBlue
              Title = 'Mu-(Al-)'
              Pointer.InflateMargins = False
              Pointer.Style = psRectangle
              Pointer.Visible = True
              XValues.DateTime = True
              XValues.Name = 'X'
              XValues.Multiplier = 1
              XValues.Order = loAscending
              YValues.DateTime = False
              YValues.Name = 'Y'
              YValues.Multiplier = 1
              YValues.Order = loNone
              EndXValues.DateTime = True
              EndXValues.Name = 'EndX'
              EndXValues.Multiplier = 1
              EndXValues.Order = loNone
              EndYValues.DateTime = False
              EndYValues.Name = 'EndY'
              EndYValues.Multiplier = 1
              EndYValues.Order = loNone
              StartXValues.DateTime = True
              StartXValues.Name = 'X'
              StartXValues.Multiplier = 1
              StartXValues.Order = loAscending
              StartYValues.DateTime = False
              StartYValues.Name = 'Y'
              StartYValues.Multiplier = 1
              StartYValues.Order = loNone
            end
            object Series4: TArrowSeries
              Marks.ArrowLength = 0
              Marks.Frame.Visible = False
              Marks.Transparent = True
              Marks.Visible = False
              SeriesColor = -1
              Title = #1055#1088#1086#1075#1085#1086#1079' Mu(Al)'
              Pointer.InflateMargins = False
              Pointer.Style = psRectangle
              Pointer.Visible = True
              XValues.DateTime = True
              XValues.Name = 'X'
              XValues.Multiplier = 1
              XValues.Order = loAscending
              YValues.DateTime = False
              YValues.Name = 'Y'
              YValues.Multiplier = 1
              YValues.Order = loNone
              EndXValues.DateTime = True
              EndXValues.Name = 'EndX'
              EndXValues.Multiplier = 1
              EndXValues.Order = loNone
              EndYValues.DateTime = False
              EndYValues.Name = 'EndY'
              EndYValues.Multiplier = 1
              EndYValues.Order = loNone
              StartXValues.DateTime = True
              StartXValues.Name = 'X'
              StartXValues.Multiplier = 1
              StartXValues.Order = loAscending
              StartYValues.DateTime = False
              StartYValues.Name = 'Y'
              StartYValues.Multiplier = 1
              StartYValues.Order = loNone
            end
            object Series5: TPointSeries
              Marks.ArrowLength = 0
              Marks.Visible = False
              SeriesColor = clWhite
              Title = #1058#1086#1095#1082#1080' Mu(Al)'
              Pointer.Brush.Color = clRed
              Pointer.InflateMargins = True
              Pointer.Style = psCircle
              Pointer.Visible = True
              XValues.DateTime = False
              XValues.Name = 'X'
              XValues.Multiplier = 1
              XValues.Order = loAscending
              YValues.DateTime = False
              YValues.Name = 'Y'
              YValues.Multiplier = 1
              YValues.Order = loNone
            end
            object Series7: TPointSeries
              Marks.ArrowLength = 0
              Marks.Visible = False
              SeriesColor = clFuchsia
              Title = #1058#1086#1095#1082#1080' Mu+(Al+)'
              Pointer.Brush.Color = clLime
              Pointer.InflateMargins = True
              Pointer.Style = psCircle
              Pointer.Visible = True
              XValues.DateTime = False
              XValues.Name = 'X'
              XValues.Multiplier = 1
              XValues.Order = loAscending
              YValues.DateTime = False
              YValues.Name = 'Y'
              YValues.Multiplier = 1
              YValues.Order = loNone
            end
            object Series6: TPointSeries
              Marks.ArrowLength = 0
              Marks.Visible = False
              SeriesColor = clGray
              Title = #1058#1086#1095#1082'a Mu-(Al-)'
              Pointer.Brush.Color = clBlue
              Pointer.InflateMargins = True
              Pointer.Style = psCircle
              Pointer.Visible = True
              XValues.DateTime = False
              XValues.Name = 'X'
              XValues.Multiplier = 1
              XValues.Order = loAscending
              YValues.DateTime = False
              YValues.Name = 'Y'
              YValues.Multiplier = 1
              YValues.Order = loNone
            end
            object Series8: TPointSeries
              Marks.ArrowLength = 0
              Marks.Visible = False
              SeriesColor = clTeal
              Title = #1055#1088#1086#1075#1085#1086#1079#1085#1072#1103' '#1090#1086#1095#1082#1072' Mu(Al)'
              Pointer.Brush.Color = -1
              Pointer.InflateMargins = True
              Pointer.Style = psCircle
              Pointer.Visible = True
              XValues.DateTime = False
              XValues.Name = 'X'
              XValues.Multiplier = 1
              XValues.Order = loAscending
              YValues.DateTime = False
              YValues.Name = 'Y'
              YValues.Multiplier = 1
              YValues.Order = loNone
            end
          end
        end
      end
    end
    object TabSheet4: TTabSheet
      Caption = '4 '#1091#1088#1086#1074#1077#1085#1100' '#1076#1077#1082#1086#1084#1087#1086#1079#1080#1094#1080#1080
      ImageIndex = 3
      ParentShowHint = False
      ShowHint = False
      object Chart2: TChart
        Left = 152
        Top = 8
        Width = 953
        Height = 489
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        LeftWall.Brush.Color = clWhite
        LeftWall.Color = clRed
        Title.Text.Strings = (
          #1043#1088#1072#1092#1080#1082' '#1079#1072#1074#1080#1089#1080#1084#1086#1089#1090#1080' '#1080#1079#1084#1077#1085#1077#1085#1080#1103' '#1084#1072#1088#1086#1082' '#1086#1090' '#1074#1088#1077#1084#1077#1075#1080)
        BottomAxis.DateTimeFormat = 'dd.MM.yyyy'
        BottomAxis.LabelStyle = talValue
        BottomAxis.Title.Caption = #1069#1087#1086#1093#1080
        LeftAxis.Axis.Width = 1
        LeftAxis.Title.Caption = #1047#1085#1072#1095#1077#1085#1080#1077' '#1084#1072#1088#1082#1080' ('#1084')'
        Legend.Visible = False
        View3D = False
        BevelOuter = bvNone
        TabOrder = 0
        object Series9: TArrowSeries
          Marks.ArrowLength = 0
          Marks.Frame.Visible = False
          Marks.Transparent = True
          Marks.Visible = False
          SeriesColor = clRed
          Pointer.InflateMargins = False
          Pointer.Style = psRectangle
          Pointer.Visible = True
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
          EndXValues.DateTime = True
          EndXValues.Name = 'EndX'
          EndXValues.Multiplier = 1
          EndXValues.Order = loNone
          EndYValues.DateTime = False
          EndYValues.Name = 'EndY'
          EndYValues.Multiplier = 1
          EndYValues.Order = loNone
          StartXValues.DateTime = False
          StartXValues.Name = 'X'
          StartXValues.Multiplier = 1
          StartXValues.Order = loAscending
          StartYValues.DateTime = False
          StartYValues.Name = 'Y'
          StartYValues.Multiplier = 1
          StartYValues.Order = loNone
        end
        object Series10: TPointSeries
          Marks.ArrowLength = 0
          Marks.Visible = False
          SeriesColor = clGreen
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = True
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
      end
      object ComboBox2: TComboBox
        Left = 0
        Top = 8
        Width = 145
        Height = 21
        ItemHeight = 13
        TabOrder = 1
        OnKeyPress = ComboBox2KeyPress
      end
      object Button5: TButton
        Left = 8
        Top = 32
        Width = 121
        Height = 25
        Caption = #1055#1086#1089#1090#1088#1086#1080#1090#1100' '#1075#1088#1072#1092#1080#1082
        TabOrder = 2
        OnClick = Button5Click
      end
    end
  end
  object ADOConnection1: TADOConnection
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'MSDAOSP'
    Left = 64
    Top = 488
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 96
    Top = 488
  end
  object ADOTable1: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'XX'
    Left = 128
    Top = 488
  end
  object MainMenu1: TMainMenu
    Images = ImageList1
    Left = 952
    Top = 480
    object Menu1: TMenuItem
      Caption = 'Menu'
      object Open1: TMenuItem
        Caption = 'Open'
        ImageIndex = 0
        ShortCut = 16463
        OnClick = Open1Click
      end
      object CloseDB1: TMenuItem
        Caption = 'Close '
        ImageIndex = 1
        ShortCut = 16453
        OnClick = CloseDB1Click
      end
      object Exit1: TMenuItem
        Caption = 'Exit'
        ImageIndex = 3
        OnClick = Exit1Click
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
    Left = 992
    Top = 480
  end
  object ImageList1: TImageList
    Left = 1032
    Top = 480
    Bitmap = {
      494C010104000900040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000003000000001002000000000000030
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000FFFAFAFAFFF4F4F4FFEDED
      EDFFE6E6E6FFE0E0E0FFDCDCDCFFDADADAFFDADADAFFDEDEDEFFE3E3E3FFEAEA
      EAFFF1F1F1FFF7F7F7FFFDFDFDFF000000FF00000000FEFEFE00000000000000
      00000000000000000000FEFEFE00FEFEFE000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000848484006B6B6B00636363005A5A5A005A5A5A006B6B6B007B7B7B00A5A5
      A500848484000000000000000000000000000000000000000000000000000000
      0000848484006B6B6B00636363005A5A5A005A5A5A006B6B6B007B7B7B00A5A5
      A50084848400000000000000000000000000000000FF000000FFFEFEFEFFFBFB
      FBFFF8F8F8FFD3C6B7FFCA8636FFEB8105FFDF8216FFBC976CFFF7F6F5FFF9F9
      F9FFFCFCFCFF000000FF000000FF000000FF000000000000000000000000FEFE
      FE00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000006363
      63009C9C9C005A5A5A00636363008C8C8C00ADADAD00BDBDBD00BDBDBD008C8C
      8C00848484008484840000000000000000000000000000000000000000006363
      63009C9C9C005A5A5A00636363008C8C8C00ADADAD00BDBDBD00BDBDBD008C8C
      8C0084848400848484000000000000000000000000FF000000FF000000FFFBEB
      D8FFEC8000FFEC8307FFEE8D1BFFEF9427FFEE9123FFED8811FFEC8000FFEF9A
      35FF000000FF000000FF000000FF000000FF000000000000000000000000FEFE
      FE00FEFEFE00FEFEFE00FEFEFE00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000006B6B
      6B00DEDEDE00636363006363630094949400A5A5A500CECECE00D6D6D600B5B5
      B500ADADAD00B5B5B50000000000000000000000000000000000000000006B6B
      6B00DEDEDE00636363006363630094949400A5A5A500CECECE00D6D6D600B5B5
      B500ADADAD00B5B5B5000000000000000000000000FF000000FFF7D9B7FFE77D
      00FFE97E00FFDC7C0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEC8307FFEC80
      00FFEC8307FF000000FF000000FF000000FF00000000FEFEFE00000000000000
      00000202020002020200010101000202020003030300E3E3E300000000000000
      00000000000000000000FEFEFE00000000000000000000000000000000006B6B
      6B00D6D6D60063636300636363008C8C8C00A5A5A500C6C6C600D6D6D600B5B5
      B500ADADAD00B5B5B50000000000000000000000000000000000000000006B6B
      6B00D6D6D60063636300636363008C8C8C00A5A5A500C6C6C600D6D6D600B5B5
      B500ADADAD00B5B5B5000000000000000000000000FFFEFDFDFFE07800FFE279
      00FFE37A00FFE07700FFD16D00FFFFFFFFFFFFFFFFFFDB7400FFEB7F00FFEC80
      00FFEC8000FFF09B37FF000000FF000000FF0000000000000000000000000000
      000000000000000000000000000000000000D5D5D500E5E5E500ECECEC000000
      0000000000000000000000000000000000000000000000000000000000006B6B
      6B00C6C6C6005A5A5A00525252005A5A5A005A5A5A006B6B6B007B7B7B009494
      940000520000005A0000005A0000000000000000000000000000000000006B6B
      6B00C6C6C6005A5A5A00525252005A5A5A005A5A5A006B6B6B007B7B7B009494
      94009C9C9C00086B08000000000000000000000000FFDF8827FFDB7400FFDD75
      00FFDE7600FFDF7700FFD46F00FFFFFFFFFFFFFFFFFFE57B00FFE77C00FFE87D
      00FFE97E00FFEB7F00FFFEFEFEFF000000FF0000000000000000000000000000
      000000000000000000000000000000000000FEFEFE00FEFEFE000D0D0D001313
      1300000000000000000000000000000000000000000000000000000000005A5A
      5A00A5A5A5005A5A5A005A5A5A008C8C8C00A5A5A500BDBDBD00BDBDBD000063
      080000730800007B0800006B0800005200000000000000000000000000005A5A
      5A00A5A5A5005A5A5A005A5A5A008C8C8C00A5A5A500BDBDBD00BDBDBD008C8C
      8C00005A000031C65A00086B080000000000000000FFD47000FFD67100FFD772
      00FFD97300FFDA7400FFCF6D00FFFFFFFFFFFFFFFFFFE07800FFE17900FFE37A
      00FFE47A00FFE57B00FFF1B876FF000000FF0000000000000000000000000000
      000000000000FCFCFC0000000000000000000000000000000000000000000000
      0000181818000000000000000000000000000000000000000000000000006B6B
      6300E7DED60063635A00635A63008C948C00A5A5A500005A0000006B08000084
      0800005A0000B5B5B50000000000000000000000000000000000000000006B6B
      6300E7DED60063635A00635A63008C948C00A5A5A500CECECE00D6D6D6001894
      310042E77B0029C65200109C2100005A0000000000FFCF6C00FFD16D00FFD26E
      00FFD36F00FFD57000FFCC6A00FFFFFFFFFFFFFFFFFFDB7400FFDC7500FFDD76
      00FFDF7700FFE07800FFE48619FF000000FF00000000FEFEFE00FEFEFE000000
      000000000000FCFCFC0000000000000000000000000000000000000000000000
      0000010101000000000000000000000000000000000000000000000000006B73
      7300D6D6D6005A635A0063636B008C8C8C00A5A5A500005A000000840800006B
      0800ADADAD00B5B5B50000000000000000000000000000000000000000006B73
      7300D6D6D6005A635A0063636B008C8C8C00A5A5A500CECECE00005A0000189C
      310021AD420021B5420018AD3100109C2100000000FFCA6900FFCC6B01FFD177
      14FFD27916FFCA7110FFFFFFFFFFFFFFFFFFFFFFFFFFD97D16FFDA7E16FFDC7F
      16FFDB7A0CFFDB7400FFDC7806FF000000FF0000000000000000000000000000
      000000000000FEFEFE00D3D3D300D3D3D300D3D3D300D3D3D300060606000000
      0000000000000000000000000000000000000000000000000000000000006B63
      6300CECECE00525263005A5A5A005A5A5A005A5A5A00005A000010A52100005A
      00009C9C9C00B5B5B50000000000000000000000000000000000000000006B63
      6300CECECE00525263005A5A5A005A5A5A005A5A5A006B6B6B00848484009494
      9400005A000010A52100005A000000000000000000FFC76E0EFFD0822EFFD283
      2EFFD3832EFFD0802AFFCA7922FFCB7A22FFCC7B22FFD9872EFFDA882EFFDB89
      2EFFDC8A2EFFDD8B2DFFE0943EFF000000FF0000000000000000FEFEFE000000
      000000000000000000000000000000000000D6D6D600E2E2E20001010100FEFE
      FE00000000000000000000000000000000000000000000000000000000006B63
      6300A5A5A5005A63520063636300005A0000005A0000005A000018AD3100005A
      0000005A0000005A000000000000000000000000000000000000000000006B63
      6300A5A5A5005A635200636363008C8C8C00A5A5A500C6C6C600CECECE009C9C
      9C00005A000000941000005A000000000000000000FFBE6100FFD28D45FFD38E
      45FFD48F45FFD59045FFD38C40FFE5C3A1FFD59A5DFFD99245FFDA9345FFDB94
      45FFDC9545FFDA8C36FFF4DCC3FF000000FF0000000000000000000000000000
      000000000000000000000000000000000000D5D5D500E3E3E30000000000FEFE
      FE00000000000000000000000000000000000000000000000000000000006B63
      6300E7DED6005A635A0063635A00848C8C00005A0000109C210029C6520042E7
      7B0018943100ADADAD0000000000000000000000000000000000000000006B63
      6300E7DED6005A635A0063635A00848C8C009C9C9C00C6C6C600CECECE00005A
      000000840800006B0800005A000000000000000000FFE4C29FFFCE8B46FFD59A
      5DFFD69B5DFFD79B5DFFF4E6D9FFFFFFFFFFFFFFFFFFD18F4AFFDB9F5DFFDC9F
      5DFFDDA05DFFCB6A00FF000000FF000000FFFEFEFE0000000000000000000000
      0000FEFEFE00000000000000000000000000D5D5D500E3E3E30000000000FEFE
      FE00000000000000000000000000000000000000000000000000000000006B63
      6300E7DED6005A5A630063635A00848C8C009C9C9C0021AD420042DE7300189C
      310000520000ADADAD0000000000000000000000000000000000000000006B63
      6300E7DED6005A5A630063635A00848C8C009C9C9C00C6C6C600CECECE000084
      080000941000005200000000000000000000000000FF000000FFB9640EFFD7A4
      70FFD9A875FFDAA875FFEDDAC6FFFFFFFFFFFFFFFFFFD59D63FFDEAB75FFDFAB
      75FFCA761BFFF6E7D8FF000000FF000000FF0000000000000000000000000000
      00000000000000000000000000000000000001010100E3E3E30000000000FEFE
      FE00000000000000000000000000000000000000000000000000000000006363
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
      FDFF000000FF000000FF000000FF000000FF0000000000000000FEFEFE000000
      000000000000000000000000000000000000000000000000000000000000FEFE
      FE00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000FF000000FF000000FF0000
      00FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF0000
      00FF000000FF000000FF000000FF000000FF0000000000000000FEFEFE000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000300000000100010000000000800100000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FFFFFFFF8001BCFFF007F007C007EFFF
      E003E003E00FE1FFE003E003C007A03DE003E0038003EF1FE001E0038001EF0F
      E000E0018001E807E003E00080018807E003E0008001E80FE003E0018001CF0F
      E003E0018001EF2FE003E0018003672FE003E003C003E02FE003E003E007FFFF
      E003E003F00FDFEFFFFFFFFFFFFFDFFF00000000000000000000000000000000
      000000000000}
  end
  object OpenDialog1: TOpenDialog
    Filter = 'Microsoft Access|*.mdb'
    Left = 800
    Top = 480
  end
end
