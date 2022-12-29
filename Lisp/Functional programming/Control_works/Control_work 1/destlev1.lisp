(defun destlev1 (List)
	   (cond
	     ((null List) nil)
	     ((atom (car List)) (cons (car List) (destlev1 (cdr List))))
	     (t (append (destlev1 (car List)) (destlev1 (cdr List))))))