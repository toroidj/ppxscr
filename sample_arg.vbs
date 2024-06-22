'!*script
Set arg = PPx.Arguments

MsgBox arg.Count

text = "Žè“®—ñ‹“‚Ì—á" + chr(13) + chr(10)
For i = 0 to arg.Count - 1
   text = text + arg(i) + ", "
Next
PPx.Echo text

text = "Foreach‚Ì—á" + chr(13) + chr(10)
For Each item in arg
   text = text + item + ", "
Next
PPx.Echo text
