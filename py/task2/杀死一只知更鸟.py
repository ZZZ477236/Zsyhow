import requests
import re
from lxml import etree
from charset_normalizer import detect

url="https://www.youduzw.com/book/6736/495647.html"
HEADERS = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0'
}

response = requests.get(url, headers=HEADERS)
if response.status_code == 200:
    res_encoding=detect(response.content)['encoding']
    content=response.content.decode(res_encoding)
    text=etree.HTML(content)
else:
    print("请求失败")
ts=''
p_list = text.xpath("//div[@id='TextContent' and contains(@class, 'read-content')]//p/text()")
for p in p_list:
    if p:
        ts+=p.strip()+'\n'
utf8_text = ts.encode('utf-8', errors='replace').decode('utf-8')

with open('D:\code\py/task2/杀死一只知更鸟.txt','w',encoding='utf-8') as f:
    f.write(utf8_text)
