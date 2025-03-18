import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.font_manager as fm
# 设置字体为 SimHei 以支持中文
plt.rcParams['font.sans-serif'] = ['SimHei']  # 使用黑体
plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示问题
# 1. 读取数据并合并
data1 = pd.read_csv('数据1.csv', sep='|', encoding='gbk')
data2 = pd.read_excel('数据2.xlsx')
combined_data = pd.concat([data1, data2], ignore_index=True)
print(combined_data.head())

# 2. 筛选国籍为中国的女篮运动员数据
chinese_women_basketball_players = combined_data[(combined_data['国籍'] == '中国') & (combined_data['性别'] == '女') & (combined_data['项目'].str.contains('篮球'))].copy()

# 3. 数据清理
# 3.1 删除重复行
chinese_women_basketball_players.drop_duplicates(inplace=True)

# 3.2 异常值处理 - 处理身高列
chinese_women_basketball_players['身高'] = chinese_women_basketball_players['身高'].str.replace('厘米', '').str.replace('米', '').str.replace('cm', '')
chinese_women_basketball_players['身高'] = pd.to_numeric(chinese_women_basketball_players['身高'], errors='coerce')
height_mean = chinese_women_basketball_players['身高'].mean()
chinese_women_basketball_players['身高/cm'] = chinese_women_basketball_players['身高'].fillna(height_mean).round(1)
chinese_women_basketball_players.drop('身高', axis=1, inplace=True)

# 3.3 处理体重列，移除'kg'和'千克'等单位
chinese_women_basketball_players['体重'] = chinese_women_basketball_players['体重'].str.replace('kg', '').str.replace('千克', '').astype(float)
chinese_women_basketball_players['体重'] = chinese_women_basketball_players['体重'].fillna(chinese_women_basketball_players['体重'].mean())

# 3.4 省份列
chinese_women_basketball_players['省份'] = chinese_women_basketball_players['省份'].fillna('未知')
chinese_women_basketball_players.loc[chinese_women_basketball_players['中文名'] == '陈楠', '省份'] = '青岛'
chinese_women_basketball_players.loc[chinese_women_basketball_players['中文名'] == '陈晓佳', '省份'] = '江苏'

# 4. 计算身高数据的统计量并绘图
height_data = chinese_women_basketball_players['身高/cm']
median_height = np.median(height_data)
mode_height = height_data.mode()[0]
std_height = np.std(height_data)
print("中位数:", median_height)
print("众数:", mode_height)
print("标准差:", std_height)

# 找出身高在前25%的运动员
top_25_percent_height = height_data.quantile(0.75)
top_25_percent_players = chinese_women_basketball_players[height_data >= top_25_percent_height]['中文名']
with open('top_25_percent_players.txt', 'w') as f:
    for name in top_25_percent_players:
        f.write(name + '\n')

# 绘制箱型图和直方图
fig, (ax_box, ax_hist) = plt.subplots(1, 2, sharey=True, figsize=(10, 5))
ax_box.boxplot(height_data)
ax_hist.hist(height_data, bins=10)
ax_box.set_title('箱型图')
ax_hist.set_title('直方图')
plt.show()

# 5. 统计txt文件行数和字数
with open('top_25_percent_players.txt', 'r') as f:
    content = f.read()
    line_count = content.count('\n') + 1
    word_count = len(content.replace('\n','').split(' '))
print("行数:", line_count)
print("字数:", word_count)
