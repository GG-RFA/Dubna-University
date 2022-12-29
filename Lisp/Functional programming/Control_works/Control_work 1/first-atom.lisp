(defun first-atom (List)
	   (cond
	     ((null List) nil)
	     ((atom (car List)) (car List))
	     (t (first-atom (cdr List)))))