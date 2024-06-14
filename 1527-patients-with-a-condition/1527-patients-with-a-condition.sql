# Write your MySQL query statement below
select patient_id, patient_name, conditions from patients where conditions regexp '\\bDIAB1'
-- select substring(conditions,1,5) from patients