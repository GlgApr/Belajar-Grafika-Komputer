Public Class Form1

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        If TextBox1.Text = "" Then
            MsgBox("Bilangan masih kosong")
        ElseIf TextBox1.Text = "A" Then
            MsgBox("Maaf karakter yang dimasukkan salah")
        ElseIf TextBox1.Text = "B" Then
            MsgBox("Maaf karakter yang dimasukkan salah")
        ElseIf TextBox1.Text = "C" Then
            MsgBox("Maaf karakter yang dimasukkan salah")
        ElseIf TextBox1.Text = "D" Then
            MsgBox("Maaf karakter yang dimasukkan salah")
        ElseIf TextBox1.Text = "E" Then
            MsgBox("Maaf karakter yang dimasukkan salah")
        ElseIf TextBox1.Text = "F" Then
            MsgBox("Maaf karakter yang dimasukkan salah")
        ElseIf TextBox1.Text = "G" Then
            MsgBox("Maaf karakter yang dimasukkan salah")
        Else
            If TextBox1.Text Mod 2 = 0 Then
                Label1.Text = TextBox1.Text + " Adalah Bilangan Genap"
            Else
                Label1.Text = TextBox1.Text + " Adalah Bilangan Ganjil"
            End If
        End If
    End Sub
End Class
