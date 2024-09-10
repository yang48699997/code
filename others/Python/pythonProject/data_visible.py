from pyecharts.charts import Line

line = Line()
line.add_xaxis(["中国", "美国", "英国"])
line.add_yaxis("GDP", [100, 200, 900])
line.render()