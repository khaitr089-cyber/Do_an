import pandas as pd

data_input={
    "HoTen": [ "an", "binh", "cuong", "dung", "hai"],
    "Tuoi": [ 20, 21, 22, 23, 24],
    "DiemTB": [ 8.5, 7.0, 9.0, 6.5, 8.0],
    "Lop":["23ct1", "23ct2", "23ct3", "23ct4", "23ct5"]
}

df_input = pd.DataFrame(data=data_input)
print(df_input)
#truy xuất cột 
print(df_input.loc[1, "HoTen"])
print()


df_diem_tb_lop = df_input.groupby("Lop")["DiemTB"].mean()
print(df_diem_tb_lop)
print()


