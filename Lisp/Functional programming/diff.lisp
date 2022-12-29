( setf ( get '+ 'proizvod ) 'diff+)
( setf ( get '* 'proizvod ) 'diff*)
( setf ( get '/  'proizvod ) 'diff/)
( setf ( get '^  'proizvod ) 'diff^)
( setf ( get '- 'proizvod ) 'diff-)
( setf ( get  'sin 'proizvod ) 'diffsin )
( setf ( get 'cos 'proizvod ) 'diffcos )
( setf ( get 'tan 'proizvod ) 'difftan )
( setf ( get 'log 'proizvod ) 'difflog )

(defun diff (L x)
  (cond
    ((atom L) (if (eq L x) 1 0))
    (t (funcall (get (first L) 'proizvod) (cdr L) x))))

(defun diff+ (L x)
  (list '+ (diff (first L) x) (diff (second L) x)))

(defun diff- (L x)
  (list '- (diff (first L) x) (diff (second L) x)))

(defun diff* (L x)
  (list '+ (list '* (diff (first L) x) (second L))
	(list '* (diff (second L) x) (first L))))

(defun diff/ (L x)
  (list '/
	(list '- (list '* (diff (first L) x) (second L))
	      (list '* (diff (second L) x) (first L)))
	(list '* (second L) (second L))))

(defun difflog (L x)
  (list '/ (diff (first L) x) L))

(defun diffsin(L x)
  (list '* (diff (first L) x) (list 'cos (first L))))

(defun diffcos(L x)
  (list '* -1 (list '* (diff (first L) x) (list 'sin (first L)))))

(defun difftan(L x)
  (list '/
	(diff (first L) x )
	(list '* (list 'cos (first L)) (list 'cos (first L)))))