#创建
import pymysql
db=pymysql.connect("localhost","user","test1","TESTDB")#打开数据库连接
cursor=db.cursor()#创建游标对象
cursor.execute("DROP TABLE IF EXISTS DATA")
sql="""CREATE TABLE RESIDENTS(
       NAME CHAR(20) NOT NULL,
       AGE INT,
       SEX CHAR(1),
       TEL CHAR(11),
       ADD CHAR(30))"""
cursor.execute(sql)
db.close