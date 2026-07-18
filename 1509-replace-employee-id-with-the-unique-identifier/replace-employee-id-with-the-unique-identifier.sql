-- Write your PostgreSQL query statement below
SELECT EmployeeUNI.unique_id, Employees.name from Employees left join EmployeeUNI ON EmployeeUNI.id = Employees.id;