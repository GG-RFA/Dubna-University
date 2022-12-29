(defun devlev1 (List)
	   (cond
	     ((null (cdr List)) List)
	     (t (list (car List) (devlev1 (cdr List))))))