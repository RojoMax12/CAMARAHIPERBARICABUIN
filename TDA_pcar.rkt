#lang racket

;GETTER

(define (get-type pcar)
  (list-ref pcar 3))

;Nombre : pcar
;Dom : id (int) X capacity (positive integer) X model (string) X type (car-type)
;Rec : pcar

(define (pcar id  capacity  model type)
  (cons id
        (cons capacity
              (cons model
                    (cons type null)))))





(provide (all-defined-out))