-- Write your PostgreSQL query statement below
Select Product.product_name, Sales.year, Sales.price From Sales Left Join Product On Sales.product_id = Product.product_id;