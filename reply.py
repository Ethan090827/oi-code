import requests
import time
Url="https://www.zhihu.com/api/v4/messages"
Header={"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/129.0.0.0 Safari/537.36",
        "cookie":"_xsrf=CyejTdP1c9oDrzRKpko9caXzZRrMOg07; _zap=d02e1caa-2f61-46b8-acfd-959d6259da74; __zse_ck=003_b66zc8uSWr959RVSmC4Drs2C1mqSXt3rNJtOc3zFGnl7DoHqw3j9yGUS91DohoL4hraFdCTQbp7NzLIKmUnc5Y9G0aGthYGqxdukQi1J3Gnr; d_c0=APDRqcLZURmPTvfW-XzmDwoq0ozUYrFaiRE=|1727769632; __snaker__id=dqoW6PJCObiNkoUt; Hm_lvt_98beee57fd2ef70ccdd5ca52b9740c49=1727769634,1727848440; captcha_session_v2=2|1:0|10:1727848441|18:captcha_session_v2|88:SkZzdUNUcmxGcmFUeG9lbDRPcjJvTndQNUdVRGNKd3dvKzNFNTlMYWNHQVhsY3JmcGNJcWNtSEU3ODRWQnhRZg==|9779f2ea51b99a8b6c7d752226e21d415c35d7b5885c0f203010b9032ccc010e; gdxidpyhxdE=YoemXTHYnUYYgUJmK0uQMEaRChhchjSoRVlRXczMHywe7NA8TkXtCMVoU699KH4mQpNWYvSPbSM3gHH12drxh0wMdnHKuQOskLvLBucKyvSovrwW6T%5Ctplpw5k8h6sct46eIEZ7fvJa1p2Lf%5Cx7U0zIGZHG%5CqEiUrAUwCrCZtaQaLJT0%3A1727849341686; captcha_ticket_v2=2|1:0|10:1727848457|17:captcha_ticket_v2|728:eyJ2YWxpZGF0ZSI6IkNOMzFfeGxNU3FNRXEuMXU5QTJOUVFMVVIuQypBY1g4cnI1bGxPS2RNM1pVc25aOTg4RUtkaFlfRnFlUXppaGtKWXBlWUZoMGsyOVcyRGxPc1NCQl9BVWJZU0VYenlNTVNNdmlIVjBzY1JDMDBhQjNaUlQuMlZpV1B5Z1JNTDhkZkFSOF9YTGxuWGpJS1g4KklPUlZqaEZFQkxRaXA0bktvbEdMMzR2NlpJZVNNKnlrc2dSOW9wTGhOKnE4V1NoT24wM204U0Fxbmo2Y2VUTnJqanlRUS5pRXFXcTAyLmpndjBmVHZDVmh1eUlhSnI4bG1ia0lId0JaTWJFTjkwZV9tNmVlc0NLczZoWnEzclRWTWhnQXVORVpmUy50eFpKWDNtZ3JGd2FfSm4zcVRVTWFXdDZ3bmVwRE94NEJ5ZFNpKnFLQk8zMnRldmhhbkk4a2xLTGlmOVV0RFVDLl8xcWd5c2h3cGxlRy5rWkhIOGF3TnM1c2s0aFpFUXJDM19KQWhKTGdqa2xNTEExOHEzT19jdWJUS2ZYQTlJZ3dKdDhMRVZaZngyTEVkUFZpUWZBajVHQVJmalRJNHpnNnRRa3lyX2hFWXlaaXdsV0FkVkpHcVJVVkV5dWU4ZXpoUmtZTDQ2STl2MUZWVk9wYVNycXdsaVJ3ZkxwVU4yYVNkU1NLSG1ibEs5NjJrY1g3N192X2lfMSJ9|76df8e9e7f043c892d15679b8c64b6219f996223ba02b711e2d26dbe80d75ac8; z_c0=2|1:0|10:1727848457|4:z_c0|92:Mi4xMElybFV3QUFBQUFBOE5HcHd0bFJHU1lBQUFCZ0FsVk5DUzdxWndETmhtU2pONTBGRHpWdmg3QzlzUmxJMFMzeklR|be63eca68c9aaea4beffe740fda90177331d9148aa18405c9c9aeba35e653600; BEC=32377ec81629ec05d48c98f32428ae46"}
while 1:
    op=input()
    if op=="prev":
        num=int(input())
        res = requests.get(url="https://www.zhihu.com/api/v4/chat?sender_id=8a91877a687398dab6e8f3a623c7ac1d",
                           headers=Header)
        res.encoding='utf-8'
        html = res.text
        #print(html.find("text",0))
        #print(html)
        texts3=0
        for j in range(1,num+1):
            texts = html.find("text",texts3)
            texts1 = html.find("creation_card",texts)
            texts2 = html.find("created_time",texts1)
            texts3 = html.find("content_type",texts2)
            texts4 = html.find("user_type",texts3)
            timee = ""
            for i in range(texts2 + 14, texts3 - 2):
                timee += html[i]
            time1 = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(int(timee)))
            message = ""
            for i in range(texts + 7, texts1 - 3):
                message += html[i]
            if html[texts4 + 12] == 's':
                print(time1 + "   qq:\n" + message)
            else:
                print(time1 + "   me:\n" + message)
    else:
        data = {"content": op,
                "receiver_hash": "8a91877a687398dab6e8f3a623c7ac1d",
                "type": "common"}
        html = requests.post(Url, headers=Header, json=data)
        if html.status_code==200:
            print("Successfully sent")


