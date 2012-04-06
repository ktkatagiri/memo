;; (require rnrs/control-6)

;;; this imprementation of queue is MzScheme specific.
(define (make-queue)
  (cons '() '()))

(define (enqueue! queue obj)
  (let ((lobj (cons obj '())))
    (if (null? (car queue))
	(begin
	  (set-car! queue lobj)
	  (set-cdr! queue lobj))
	(begin
	  (set-cdr! (cdr queue) lobj)
	  (set-cdr! queue lobj)))
    (car queue)))

(define (dequeue! queue)
  (let ((obj (car (car queue))))
    (set-car! queue (cdr (car queue)))
    obj))


;;; coroutine   
(define process-queue (make-queue))
(define coroutine
  (lambda (thunk)
    (enqueue! process-queue thunk)))
(define start
  (lambda ()
    ((dequeue! process-queue))))
(define yield
  (lambda ()
    (call/cc
     (lambda (k)
       (coroutine (lambda () (k)))
       (start)))))

;;; example
(coroutine (lambda ()
	     (let loop ((i 0)) 
	       (when (< i 10)
		     (display (+ 1 i)) 
		     (display " ") 
		     (yield) 
		     (loop (+ 1 i))))))

(coroutine (lambda ()
	     (let loop ((i 0)) 
	       (when (< i 10)
		     (display (integer->char (+ i 97)))
		     (display " ")
		     (yield) 
		     (loop (+ 1 i))))))

(start)


