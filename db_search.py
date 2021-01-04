#查询
import pymysql
db=pymysql.connect("localhost","user","test1","TESTDB")#打开数据库连接
cursor=db.cursor()#创建游标对象
sql="SELECT * FROM RESIDENTS \
       WHERE AGE > '%d'" % (30)
try:
    cursor.excute(sql)
    results=cursor.fetchall()
    for row in results:
        name=row[0]
        age=row[1]
        sex=row[2]
        tel=row[3]
        add=row[4]
        print("name=%s,age=%d,sex=%s,tel=%s,add=%s \ (name,age,sex,tel,add)")
except:
    print("ERROR")
db.close()