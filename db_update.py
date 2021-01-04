#更新
import pymysql
db=pymysql.connect("localhost","user","test1","TESTDB")#打开数据库连接
cursor=db.cursor()#创建游标对象
sql="UPDATE RESIDENTS SET AGE = AGE + 1 WHERE SEX = '%c'" % ('M')
try:
    cursor.execute(sql)
    db.commit()
except:
    import traceback
    traceback.print_exc()
db.close()