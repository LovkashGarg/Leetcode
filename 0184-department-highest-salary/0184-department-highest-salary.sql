# Write your MySQL query statement below

select Department.name as Department, Employee.name as Employee , salary from Department Left Join Employee  on Employee.departmentId = Department.id where Employee.salary=(select max(salary) from Employee d where Employee.departmentId= d.departmentId );
