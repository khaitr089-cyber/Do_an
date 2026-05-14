from bs4 import BeautifulSoup
import requests

URL = 'https://books.toscrape.com/'

reponse = requests.get(URL)
text_reponse = reponse.text
print(text_reponse)
soup = BeautifulSoup(text_reponse, 'html.parser')

book_products = soup.find_all("article", class_="product_pod")
print(book_products)
for i__book in book_products:
    print(i__book)

    name = i__book.h3.a['title']
    print(name)



 