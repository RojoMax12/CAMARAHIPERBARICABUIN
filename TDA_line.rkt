#lang racket

(require "TDA_section.rkt")
(require "TDA_station.rkt")

;GETTER

(define (get-id-line line)
  (car line))

(define(get-station-line line)
  (cdr(cdr(cdr line))))

;OTRAS FUNCIONES

(define count 3)

(define (list-section-equal list1 list2)
  (cond [(or (null? list1) (null? list2))
         '()]
        [(equal? (car list1) (car list2))
         (cons (car list1) (list-section-equal (cdr list1) (cdr list2)))]
        [else
         (list-section-equal (cdr list1) (cdr list2))]))


(define (name-equal-section1 list-sections search-name-init)
  (cond [(or (string=? (get-name-station (get-point1 (car list-sections))) search-name-init) 
             (null? list-sections))
         list-sections]
        [else
         (name-equal-section1 (cdr list-sections) search-name-init)]))


(define (name-equal-section2 list-sections search-name-finish)
  (cond [(or (string=? (get-name-station(get-point2(car list-sections))) search-name-finish) 
             (null? list-sections))
         (cons (car list-sections) '())]
        [else
         (cons (car list-sections)(name-equal-section2 (cdr list-sections) search-name-finish))]))
       


;Name: line
;Dom : id (int) X name (string) X rail-type (string) X section* (* señala que se pueden agregar 0 o más tramos)
;Rec : line

(define (line id name rail-type . seccion)
  (if (not (null? seccion))
      (cons id
            (cons name
                  (cons rail-type seccion)))
      (cons id
            (cons name
                  (cons rail-type '())))))


;Name: line-length
;Dom : line (line)
;Rec : positive-number

(define (line-length line)
  (cond ((equal? line null)
         0)
        (else (apply + (map get-distance-section (get-station-line line))))))

  
;Name: line-section-length
;Dom: line (line) X station1-name (String) X station2-name (String)
;Rec: positive-number

(define (line-section-length line station1-name station2-name)
  (apply +(map get-distance-section(list-section-equal(name-equal-section1(get-station-line line)station1-name)(name-equal-section2(get-station-line line)station2-name)))))
  
  
;Name: line-cost
;Dom: line (line)
;Rec: positive-number U {0}

(define (line-cost line)
  (cond [(null? line)
         0]
        (else
         (+ (get-cost-section(car line)(line-cost(cdr line)))))))
        
         
;1. acotar la lista para que quede la sub lista
;2. poner las condiciones de parada
;3. calcular el costo total de la linea
(define (get-sublist lst start)
  (if (<= start 0)
      lst
      (get-sublist (cdr lst) (- start 1))))


(provide (all-defined-out))

