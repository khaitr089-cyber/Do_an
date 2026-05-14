import math

def pt_bac2():
    a = float(input("Nhập a: "))
    b = float(input("Nhập b: "))
    c = float(input("Nhập c: "))

    if a == 0:
        if b == 0:
            print("Phương trình vô nghiệm")
        else:
            print("Nghiệm:", -c / b)
    else:
        delta = b**2 - 4*a*c
        if delta < 0:
            print("Vô nghiệm")
        elif delta == 0:
            print("Nghiệm kép:", -b / (2*a))
        else:
            x1 = (-b + math.sqrt(delta)) / (2*a)
            x2 = (-b - math.sqrt(delta)) / (2*a)
            print("2 nghiệm:", x1, x2)


def bang_cuu_chuong():
    for i in range(2, 10):
        print(f"\nBảng {i}:")
        for j in range(1, 11):
            print(f"{i} x {j} = {i*j}")


def tong_chan():
    tong = sum(i for i in range(2, 101, 2))
    print("Tổng chẵn:", tong)


def so_nguyen_to():
    n = int(input("Nhập số: "))
    if n < 2:
        print("Không phải SNT")
        return
    
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            print("Không phải SNT")
            return
    print("Là SNT")


def tam_giac():
    n = int(input("Nhập chiều cao: "))
    for i in range(1, n + 1):
        print("*" * i)


def ucln_bcnn():
    a = int(input("Nhập a: "))
    b = int(input("Nhập b: "))

    x, y = a, b
    while y != 0:
        x, y = y, x % y

    ucln = x
    bcnn = (a * b) // ucln

    print("ƯCLN:", ucln)
    print("BCNN:", bcnn)


def dem_chu_so():
    n = int(input("Nhập số: "))
    n = abs(n)

    if n == 0:
        print("Có 1 chữ số")
        return

    count = 0
    while n > 0:
        count += 1
        n //= 10

    print("Số chữ số:", count)


# ===== MENU =====
while True:
    print("\n===== MENU =====")
    print("1. Giải PT bậc 2")
    print("2. Bảng cửu chương")
    print("3. Tổng số chẵn 1-100")
    print("4. Kiểm tra số nguyên tố")
    print("5. In tam giác")
    print("6. ƯCLN & BCNN")
    print("7. Đếm chữ số")
    print("0. Thoát")

    chon = input("Chọn chức năng: ")

    if chon == "1":
        pt_bac2()
    elif chon == "2":
        bang_cuu_chuong()
    elif chon == "3":
        tong_chan()
    elif chon == "4":
        so_nguyen_to()
    elif chon == "5":
        tam_giac()
    elif chon == "6":
        ucln_bcnn()
    elif chon == "7":
        dem_chu_so()
    elif chon == "0":
        print("Thoát chương trình")
        break
    else:
        print("Chọn sai!")


        