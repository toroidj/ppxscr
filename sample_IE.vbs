'!*script
Dim IE

url = PPx.Extract("%"+chr(34)+"URL‚ðŽw’è‚µ‚Ä‚­‚¾‚³‚¢"+chr(34)+"%E")

Set IE = PPx.CreateObject("InternetExplorer.Application")
IE.Visible = True
IE.Navigate(url)
