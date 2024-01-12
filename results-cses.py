import requests
from bs4 import BeautifulSoup
import pandas as pd
import re

login_data = {
    "nick": "Chusma",
    "pass": "Chusma1234",
}

user_codes = [3226, 119041, 7901, 14702]


def parsear(lista):
    nueva_lista = []
    for x in lista:
        # print(x)
        if len(x) < 3:
            nueva_lista.append("NS")
        elif x[2] == "full":
            nueva_lista.append("AC")
        else:
            nueva_lista.append("WA")

    return nueva_lista


df_all = pd.DataFrame()

with requests.Session() as s:
    url = "https://cses.fi/login"
    r = s.get(url)
    soup = BeautifulSoup(r.content)
    login_data["csrf_token"] = soup.find("input", attrs={"name": "csrf_token"})["value"]
    r = s.post(url, data=login_data)

    for user in user_codes:
        url2 = f"https://cses.fi/problemset/user/{user}/"
        r2 = s.get(url=url2)
        with open("html.txt", "w+") as file:
            file.write(r2.text)
        soup = BeautifulSoup(r2.text, "html.parser")
        table = soup.find("table", class_="course-user-solved")
        print(soup.find("h2").text)
        pattern = re.compile(r"Statistics for ([\w-]+)")
        match = pattern.search(soup.find("h2").text)
        user_text = match.group(1)

        parsed_data = []
        all_responses = []

        for row in table.find_all("tr"):
            titles = [a["title"] for a in row.find_all("a", class_="task-score")]
            solved = [a["class"] for a in row.find_all("a", class_="task-score")]
            aux = parsear(solved)
            all_responses = all_responses + parsear(solved)
            parsed_data = parsed_data + titles

        df = pd.DataFrame({user_text: all_responses}, index=parsed_data)
        df_all = pd.concat([df_all, df], axis=1)


df_all.loc["Total"] = df_all.apply(lambda x: x.value_counts()["AC"])
df_all = df_all.loc[["Total"] + df.index.to_list()[:-1]]
df_all.to_excel("Resultados_CSES.xlsx")

print(df_all)
