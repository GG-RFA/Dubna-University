
(defun mapcar_m (x L)
(cond
((null L) nil)
    (t (cons (eval `(,x (car (quote ,L))))
(mapcar_m x (cdr L))))))


(print(mapcar_m 'sin '(1 2 3 4 5)))


(defun mapcar_mm (x L)
(cond
((null L) nil)
(t (cons (funcall x (car L)) (mapcar_mm x (cdr L))))))

(print(mapcar_mm 'sqrt '(1 2 3 4 5)))

(defun mapcar_dekart (a L)
(mapcar_mm (lambda (x) (mapcar_mm (lambda (y) (list x y)) L)) a))

(print (mapcar_dekart '(1 2) '(3 4 5)))
