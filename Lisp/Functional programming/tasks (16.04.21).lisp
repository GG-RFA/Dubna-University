;;левая половина
(defun division_left (a L)
	   (cond
	     ((null L) nil)
	     ((<(car L) a)(cons (car L) (division_left a (cdr L))))
	   (t (devision_left a (cdr L)))))

;;правая половина
(defun division_right (a L)
	   (cond
	     ((null L) nil)
	     ((>=(car L) a)(cons (car L) (division_right a (cdr L))))
	   (t (division_right a (cdr L)))))

;;сортировка Хоара
(defun quick_sort (L)
(cond
((null L) nil)
(t (append
    (quick_sort (division_left (car L) (cdr L)))
    (list (car L))
    (quick_sort (division_right (car L) (cdr L)))))))

;;задача с деревом

(defun tree-make (m n)
	   (if (<= n 0)
	       (list (random m) nil nil)
	       (list (random m)
		     (tree-make m (- n (random m)))
                     (tree-make m (- n (random m))))))

;;подсчет узлов дерева

(defun peak_count (L)
 (cond
   ((and (null (second L)) (null (third L))) 1)
   (t (+ 1 
       (peak_count (second L))
       (peak_count (third L))))))

;;подсчет листьев дерева

(defun leaves_count (L)
 (cond
   ((and (null (second L)) (null (third L))) 1)
   (t (+
       (leaves_count (second L))
       (leaves_count (third L))))))

;;ДЗ
;;leaves-list
;;story-tree     
;;member-tree
