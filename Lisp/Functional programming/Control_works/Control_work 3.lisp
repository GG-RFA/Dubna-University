;;Проверка работы программ производилась в онлайн-компиляторе
;;Контрольная работа №3. Вариант 3
;;Задание 1
(defun task1 (list1 list2)
  (mapcar (lambda (x y) (setf (get x 'property) y)) list1 list2))
 
(print (task1 '(a b c d) '(1 2 3 4)))
;;Задание 2
(defun task2 (List)
	   (cond
	     ((null List) nil)
	     ((atom (car List)) (cons (car List) (task2 (cdr List))))
	     (t (append (task2 (car List)) (task2 (cdr List))))))

(print (task2 '((((1)2)3))))
;;Задание 3
(defun task3 (list)
  (cond ((< (length list) 2) list)
        (t (cons (car list) (task3 (cddr list))))))
 
(print (task3 '(1 2 3 4 5 6 7 8 9 10)))
;;Задание 4
;;Не до конца реализована задача
(defmacro task4 (list)
   (cond ((null list) t)
        ((numberp (car list)) (task4 (cdr list)))
        (t nil)))  

(print (task4 '(1 2 3)))