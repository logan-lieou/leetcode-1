;; Tree datastructure as a nested list
(defvar lst (list '(1 2 (3 4))))
(write lst)
(defvar tre (copy-tree lst))
(format t "~a~%" tre)
