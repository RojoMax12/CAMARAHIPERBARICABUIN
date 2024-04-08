#lang racket


;GETTER

(define (get-point1 section)
  (car section))

(define (get-point2 section)
  (car(cdr section)))

(define (get-distance-section section)
  (list-ref section 2))

(define (get-cost-section section)
  (list-ref section 3))

;CODITIONAL

(define (not-is-section? section)
  (cond ((or (null? (get-point1 section)) (null? (get-point2 section)))
         #t)
        ((integer? section)
         #t)
        ((string? section)
         #t)
        (else
         #f)))
       


;Dom : point1 (station)  X point2 (station) X distance (positive-number) X cost (positive-number U {0}).
;Rec : section
  
(define(section point1 point2 distance cost)
  (if(< cost 0)
   (error "El costo es negativo")
   (cons point1
         (cons point2
               (cons distance
                     (cons cost null))))))

(provide (all-defined-out))