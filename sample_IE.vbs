'!*script
Dim IE

url = PPx.Extract("%"+chr(34)+"URLを指定してください"+chr(34)+"%E")

Set IE = PPx.CreateObject("InternetExplorer.Application")
IE.Visible = True
IE.Navigate(url)
