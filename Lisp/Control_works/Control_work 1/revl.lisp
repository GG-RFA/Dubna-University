(defun revl (List)
	   (cond
	     ((null (cdr List)) List)
	     (t (cons (revl (cdr List)) (list (car List))))))