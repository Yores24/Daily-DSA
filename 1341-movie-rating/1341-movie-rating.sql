with abc as (select  mr.user_id,u.name,mr.movie_id from Movierating as mr left join users as u on u.user_id=mr.user_id),
abc2 as (select mr.movie_id,m.title,mr.rating,mr.created_at from movierating as mr left join movies as m on m.movie_id=mr.movie_id where mr.created_at>='2020-02-01' and mr.created_at<'2020-03-01')
(select  name as results from abc group by user_id order by count(user_id) desc,name limit 1) union all
(select title as results from abc2 group by movie_id order by avg(rating) desc,title limit 1)