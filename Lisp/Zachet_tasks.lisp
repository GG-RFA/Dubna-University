;;Зачет по дисциплине "Функциональное программирование"
;;Задание 1
(defmacro zachet1 (&rest args)
 (if args
  (if (eval (caar args))
   (cons 'progn (cdar args))
   (cons 'zachet1 (cdr args)))))
;;Задание 2
(defmacro zachet2 (condition &rest body)
  `(if ,condition (progn ,@body)))
;;Задание 3
(defun zachet3 (l m)
   (if (null l) ()
       (append (mapcar #'(lambda (x)
              (list (car l) x)) m)
              (zachet3 (cdr l) m))))

(zachet3 '(a b c) '(1 2 3))
;;Задание 4
(defun zachet4 (a)
   (if a (append (mapcar #'(lambda (x)
         (list (car a) x)) (cdr a))
                   (zachet4 (cdr a))) ))

(zachet4 '(1 2 3 4))
;;Задание 5
(defun zachet5 (list1)
  (if list1
      (apply 'concatenate 'list
         (mapcar (lambda (x)
               (mapcar (lambda (ys)
                 (cons x ys))
                   (zachet5 (remove x list1))))
             list1))
      '(nil)))

(zachet5 '(1 2 3 4))
