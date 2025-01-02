import requests
import time
import os
Header={"user-agent":"Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/130.0.0.0 Safari/537.36"}
Cookie={"cookie":"__client_id=94944f158bacbc1b7bba1b1ba3b2c5719d72e0ce; _uid=575298"}       
res=requests.get(url="https://www.luogu.com.cn/record/193055941",headers=Header,cookies=Cookie)
res.encoding='utf-8'
print(res.text)