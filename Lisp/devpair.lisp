(defun devpair (List)
	   (cond
	     ((null List) nil)
	     (t (cons (list (car List) (cadr List)) (devpair (cddr List))))))