#插入
import pymysql
db=pymysql.connect("localhost","user","test1","TESTDB")#打开数据库连接
cursor=db.cursor()#创建游标对象
sql="""INSERT INTO RESIDENTS(NAME,
       AGE,SEX,TEL,ADD)
       VALUEs('张三','28','男','12345678900','5号楼555')"""
try:
    cursor.execute(sql)
    db.commit()
except:
    import traceback
    traceback.print_exc()
db.close()