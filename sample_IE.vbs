'!*script
Dim IE

url = PPx.Extract("%"+chr(34)+"URL���w�肵�Ă�������"+chr(34)+"%E")

Set IE = PPx.CreateObject("InternetExplorer.Application")
IE.Visible = True
IE.Navigate(url)
