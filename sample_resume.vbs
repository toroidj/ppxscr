'!*script
' ppbw /c *script :10001,sample_resume.vbs,arg1,arg2 %: *script :10002,sample_resume.vbs,arg1,arg2 %: *script :10003,sample_resume.vbs,arg1,arg2 %: *linemessage %*script(":10002,fire",arg1,arg2) %: *vbs ":10002","exvalue = 12345" %: *script ":10002","",arg1,arg2

CRLF = chr(13) + chr(10)
exvalue = 0

PPx.report "* sample_resume.vbs (" + PPx.ScriptEngineName + " " + PPx.ScriptEngineVersion + ") StayMode = " + CStr(PPx.StayMode) + CRLF

if PPx.StayMode < 2 Then PPx.StayMode = 2

Function ppx_resume(a, b)
	PPx.report "function ppx_resume(): StayMode = " + CStr(PPx.StayMode) + "   Count = " + CStr(Count) + "  exvalue = " + CStr(exvalue) + CRLF
	Count = Count + 1
	if Count = 2 Then PPx.StayMode = 0 ' ‚Q‰ñ–ÚŽÀs‚ÌŽž‚Íí’“‰ðœ
End Function

Function ppx_finally
	PPx.Echo "function ppx_finally() instance = " + CStr(PPx.StayMode) + "  exvalue = " + CStr(exvalue)
End Function

Function fire(a, b)
	PPx.report "function fire(" + a + ", " + b + ") instance = " + CStr(PPx.StayMode) + "  exvalue = " + CStr(exvalue)  + CRLF
	Count = Count + 1
	fire = "** fire() = " + CStr(Count) + " **" + CRLF
End Function
