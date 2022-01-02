# push_swap

## *Summary*:
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.

## *Period*:
2021.04 ~ 2021.05

## *CMD*:
> *Build*
>
> `$> make`
>
> `$> make bonus`
>
> *Run*
>
> `$> ./push_swap [random numbers]`
>
> *Checker*
>
> `$> ./push_swap [random numbers] | ./checker [random numbers]`

## *Goal*:
- [x] Implementation Stack
- [x] Sorting algorithm

## *Rule*
```
* sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
* sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
* ss : sa and sb at the same time.
* pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
* ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
* rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
* rr : ra and rb at the same time.
* rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
* rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
* rrr : rra and rrb at the same time.
```


## *Usage*:
> ```bash$> ARG=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG```
