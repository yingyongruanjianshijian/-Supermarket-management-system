#删除
import pymysql
db=pymysql.connect("localhost","user","test1","TESTDB")#打开数据库连接
cursor=db.cursor()#创建游标对象
sql="DELETE FROM RESIDENTS WHERE AGE>'%d'" % (30)
try:
    cursor.execute(sql)
    db.commit()
except:
    import traceback
    traceback.print_exc()
db.close()