'!*script
' �}�[�N�G���g���̂��ׂĂ̏������Ԃɕ\������

' �f�B���N�g�����
MsgBox	"ScriptFullName:" & PPx.ScriptFullName & vbCrLf & _
	"ScriptName:" & PPx.ScriptName & vbCrLf & _
	"WindowIDName:" & PPx.WindowIDName & vbCrLf & _
	"WindowDirection:" & PPx.WindowDirection & vbCrLf & _
	"EntryIndex:" & PPx.EntryIndex & vbCrLf & _
	"EntryDisplayTop:" & PPx.EntryDisplayTop & vbCrLf & _
	"EntryDisplayX:" & PPx.EntryDisplayX & vbCrLf & _
	"EntryDisplayY:" & PPx.EntryDisplayY & vbCrLf & _
	"EntryMarkSize:" & PPx.EntryMarkSize & vbCrLf & _
	"DriveVolumeLabel:" & PPx.DriveVolumeLabel & vbCrLf & _
	"DriveTotalSize:" & PPx.DriveTotalSize & vbCrLf & _
	"DriveFreeSize:" & PPx.DriveFreeSize

' �J�[�\���𓮂�����
If PPx.EntryFirstMark = 0 Then
  MsgBox "�}�[�N�͂���܂���"
Else
  Do
    MsgBox	"EntryIndex:" & PPx.EntryIndex & vbCrLf & _
		"EntryName:" & PPx.EntryName & vbCrLf & _
		"EntryComment:" & PPx.EntryComment & vbCrLf & _
		"EntryAttributes:" & hex(PPx.EntryAttributes) & vbCrLf & _
		"EntrySize:" & PPx.EntrySize & vbCrLf & _
		"EntryMark:" & PPx.EntryMark
    If PPx.EntryNextMark = 0 then exit do
  Loop
End If

' �J�[�\���𓮂������ƂȂ��\�������
' �}�[�N���Ȃ��Ƃ��̓J�[�\����̃G���g����ΏۂƂ���
' �}�[�N�̗L���𔻒肷��Ƃ��� PPx.EntryMarkCount �� 0 �ł��邩�Ŕ��肷��B
For Each item in PPx.Entry
  MsgBox	"Index:" & item.Index & vbCrLf & _
		"Name:" & item.Name & vbCrLf & _
		"ShortName:" & item.ShortName & vbCrLf & _
		"Attributes:" & hex(item.Attributes) & vbCrLf & _
		"Size:" & item.Size & vbCrLf & _
		"Created:" & item.DateCreated & vbCrLf & _
		"LastModified:" & item.DateLastModified & vbCrLf & _
		"LastAccessed:" & item.DateLastAccessed & vbCrLf & _
		"State:" & item.State & vbCrLf & _
		"Color:" & item.ExtColor & vbCrLf & _
		"Comment:" & item.Comment

Next
