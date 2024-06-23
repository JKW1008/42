#!/bin/bash

# random_generator 프로그램을 실행하여 랜덤 숫자 생성
RANDOM_NUMS=$(./random_generator)

# push_swap 프로그램을 랜덤 숫자와 함께 실행
./push_swap $RANDOM_NUMS