#lang racket

(define c "c")
(define r "r")
(define m "m")
(define t "t")

(require "TDA_station.rkt")
(require "TDA_section.rkt")
(require "TDA_line.rkt")
(require "TDA_pcar.rkt")
(require "TDA_train.rkt")


(define e0 (station 1 "USACH" c 10))
(define e1 (station 2 "Estación Central" c 37))
(define e2 (station 3 "ULA" r 31))
(define e3 (station 3 "República" r 21))
(define e4 (station 4 "Los Héroes" c 25))
(define e5 (station 5 "Toesca" r 20))
(define e6 (station 6 "La Moneda" r 60))
(define e7 (station 7 "Cochera" m 33))
(define e8 (station 8 "Parque OHiggins" r 50))
(define e9 (station 9 "San Pablo" t 30))
(define e10 (station 10 "Los Dominicos" t 20))


(define s0 (section e0 e1 2 50))
(define s1 (section e1 e2 2.5 55))
(define s2 (section e2 e3 1.5  30))
(define s3 (section e3 e4 3  45))
(define s4 (section e4 e5 3  45))
(define s5 (section e4 e6 1.4  50))
(define s6 (section e5 e8 2  40))
(define s7 (section e0 e7 3  0))
(define s8 (section e0 e9 7  100))
(define s9 (section e6 e10 15  250))

(define l0 (line 0 "Línea 0" "UIC 60 ASCE"))
(define l1 (line 1 "Línea 1" "100 R.E." s0 s1 s2 s3 s5 s7 s8 s9))


(define pc0 (pcar 0 100 "NS-74" "c"))
(define pc1 (pcar 1 100 "NS-74" "t"))
(define pc2 (pcar 2 150  "NS-74" "t"))
(define pc3 (pcar 3 100 "NS-74" "c"))
(define pc4 (pcar 4 100 "AS-2014" "c"))
(define pc5 (pcar 5 100 "AS-2014" "c"))
(define pc6 (pcar 6 100 "AS-2016" "c"))
(define t1 (train 1 "CAF" "UIC 60 ASCE" 70  2 pc1 pc0 pc3 pc2))


(define m1 '(((1 "USACH" "c" 10) (2 "Estación Central" "c" 37) 2 50)
            ((2 "Estación Central" "c" 37) (3 "ULA" "r" 31) 2.5 55)
            ((3 "ULA" "r" 31) (3 "República" "r" 21) 1.5 30)
            ((3 "República" "r" 21) (4 "Los Héroes" "c" 25) 3 45)
            ((4 "Los Héroes" "c" 25) (6 "La Moneda" "r" 60) 1.4 50)
            ((1 "USACH" "c" 10) (7 "Cochera" "m" 33) 3 0)
            ((1 "USACH" "c" 10) (9 "San Pablo" "t" 30) 7 100)
            ((6 "La Moneda" "r" 60) (10 "Los Dominicos" "t" 20) 15 250)))

;(append (map get-name-station (map get-point1(get-station-line l1))) (map get-name-station (map get-point2(get-station-line l1))))