#lang racket

; GETTER

(define (get-id-station station)
  (car station))

(define (get-name-station station)
  (car(cdr station)))



;Dom : id (int) X name (String)  X type (station-type) X stop-time (positive integer)
;Rec : station
        
(define (station id name type stop-time)
  (if (or (< stop-time 0)
          (not (integer? stop-time))
          (not (exact? stop-time)))
      (error "El tiempo de parada no puede ser negativo o un valor decimal")
      (cons id
            (cons name
                  (cons type
                        (cons stop-time null))))))

(define (exist-station? verification-station id name type stop-time)
  (if (or (equal? (get-id-station verification-station) id)
          (equal? (get-name-station verification-station) name))
      (error "La estación ya existe")
      (station id name type stop-time)))

























(provide (all-defined-out))