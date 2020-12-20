USE `mydb` ;
DELIMITER |
DROP TRIGGER IF EXISTS Movie_BI|
CREATE TRIGGER Movie_BI BEFORE INSERT ON Movie
FOR EACH ROW
BEGIN
SET NEW.Duration=(SELECT TIMESTAMPDIFF(DAY,NEW.Filming_start,NEW.Filming_end));
END|

DROP TRIGGER IF EXISTS Movie_AU|
CREATE TRIGGER Movie_AU AFTER UPDATE ON Movie
FOR EACH ROW
BEGIN
update Movie set Duration=(SELECT TIMESTAMPDIFF(DAY,Filming_start,Filming_end));
END|


DROP TRIGGER IF EXISTS Acting_job_AI|
CREATE TRIGGER Acting_job_AI AFTER INSERT ON Acting_job
FOR EACH ROW
BEGIN
update Producing p set p.Budget = p.Budget + NEW.Contract
                                  where p.Movie_id_Movie = NEW.Movie_id_Movie;
END|

DROP TRIGGER IF EXISTS Acting_job_AU|
CREATE TRIGGER Acting_job_AU AFTER UPDATE ON Acting_job
FOR EACH ROW
BEGIN
update Producing p set p.Budget = p.Budget + NEW.Contract
                                  where p.Movie_id_Movie = NEW.Movie_id_Movie;
END|

DROP TRIGGER IF EXISTS Acting_job_AD|
CREATE TRIGGER Acting_job_AD AFTER DELETE ON Acting_job
FOR EACH ROW
BEGIN
update Producing p set p.Budget = p.Budget - old.Contract
                                  where p.Movie_id_Movie = old.Movie_id_Movie;
END|
