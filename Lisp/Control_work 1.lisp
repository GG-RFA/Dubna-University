
;;Задание 1(подпункт 1 и 2)

((lambda(X) (/ (+(expt x 2) (* 3 x) (expt (sin x) 2)) (+(expt (tan x) 2) 1)))2)

((lambda(X) (exp (exp (cos (+(* x x) (* 3 (sin x))))))) 2)

;;Задание 2

(defun function2 (x y)
(* (asin x) (tan y)))
(function2 (/ 3 10) (/ pi 3))

;;Задание 3

(defun function31(n)
(cond
((= 1 n) 1)
((= 2 n) 1)
(t (sqrt (+ (function31(- n 2)) (function31(- n 1)))))))

(defun function32(f1 f2 n)
(cond
((= 2 n) f2)
(t (function32 f2 (sqrt (+ f1 f2)) (- n 1)))))

(time (function31 '15))

(time (function32 '1 '1 '15))
;;Задание 4

(defun function4 (x L)
(cond
((null L) nil)
(t (cons 
	(append 
		(list (caar L) x)
		(cddar L))
	(function4 x(cdr L))))))

;;Задание 5

(defun function5 (x L)
(cond
((null L) nil)
((= 0 (mod (car L) x)) (cons (car L) (function5 x (cdr L))))
(t (function5 x (cdr L))))) 
