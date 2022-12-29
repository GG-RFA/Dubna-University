(defun remsec (List)
	   (cond
	     ((null (cdr List))List)
	     (t (cons (car List) (remsec (cddr List))))))