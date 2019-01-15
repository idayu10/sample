Option Explicit

Private Sub openFile()
    Application.ScreenUpdating = False
    
    Dim i As Long
    Dim folder As String
    Dim fileName As String
    Dim n As Integer
    Dim buf As String
    Dim strs As Variant
    
    folder = ThisWorkbook.Path & "\作業フォルダ\"
    fileName = Dir(folder & "*.csv")
    
    Do While fileName <> ""
        Worksheets.Add
        ActiveSheet.Name = fileName
        n = 0
        Open folder & fileName For Input As #1
        Do Until EOF(1)
            Line Input #1, buf
            n = n + 1
            strs = Split(buf, ",")
            Call copyToSheet(strs, n)
        Loop
        Close #1
        fileName = Dir()
    Loop
    
    MsgBox "完了しました"
    
End Sub

Private Sub copyToSheet(strs As Variant, n As Integer)
    Application.ScreenUpdating = False
    Dim i As Integer
    
    For i = 0 To UBound(strs)
        With ActiveSheet.Cells(n, i + 1)
            .NumberFormat = "@"
            .Value = strs(i)
        End With
    Next i
End Sub
