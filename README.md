

# `Push Swap`

<p align="center"><a href="https://www.42sp.org.br/" target="_blank"><img src="https://img.shields.io/static/v1?label=&message=SP&color=000&style=for-the-badge&logo=42""></a></p>

<!-- <p align="center"><img src="https://game.42sp.org.br/static/assets/achievements/push_swapn.png" alt="So Long"> </p> -->
<p align="center"><img src="https://i2.wp.com/www.aponia-dental-center.com/fachzahnarztliche-praxis/wp-content/uploads/2014/01/work-in-progress.png?fit=286%2C253" alt="So Long"> </p>



<!-- https://hits.dwyl.com/ -->
<!-- [![HitCount](https://hits.dwyl.com/rlinsdev/42-Push-swap.svg?style=flat)](http://hits.dwyl.com/rlinsdev/42-Push-swap) -->
[![HitCount](https://hits.dwyl.com/rlinsdev/42-Push-swap.svg?style=flat&show=unique)](http://hits.dwyl.com/rlinsdev/42-Push-swap)

<!-- [![HitCount](https://hits.dwyl.com/rlinsdev/42-Push-swap.svg?style=flat&show=unique)](http://hits.dwyl.com/rlinsdev/42-Push-swap) -->

# What is Push Swap?

•Lorm spum Lorm spum Lorm spum Lorm spum Lorm spum Lorm spum Lorm spum Lorm spum Lorm spum


## How to run - Samples


```sh
# Will generate a executable in bin folder
	$> make run
# Execute valgrind. Will check memory leaks
	$> make leak
# will run norminette inside de .c files (src folder)
	$> make norma
# Check leaks
	$> make valgrind
```






## `More information`


• Libft allowed.

• Folder structure apply (managed by Makefile).

• No leaks are allowed.

• Norma must be run.

• Linked List

•  Algorithm that sorts by index and position.

### `Operations - Description`

- sa : swap a - Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
- sb : swap b - Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
- ss : sa and sb at the same time.
- pa : push a - take the first element at the top of b and put it at the top of a. Do - nothing if B is empty.
- pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if A is empty.
- ra : rotate a - shift up all elements of stack A by 1. The first element becomes the last one.
- rb : rotate b - shift up all elements of stack B by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra : reverse rotate a - shift down all elements of stack A by 1. The last element becomes the first one.
- rrb : reverse rotate b - shift down all elements of stack B by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.

### `Operations - Images`
<p align="center"><img src="https://miro.medium.com/max/700/1*rXKk8juFHQaLzI-uJyEVog.png" alt="PushSwap1"> </p>
<p align="center"><img src="https://miro.medium.com/max/700/1*dAHbFo-fEko25X-C8CVeKw.png" alt="Swap"> </p>
<p align="center"><img src="https://miro.medium.com/max/700/1*Iji-cUJbgJ1BRmLjT9Qqkw.png" alt="Rotation"> </p>
<p align="center"><img src="https://miro.medium.com/max/700/1*v8rjNThxCvEIkbDNjomCZg.png" alt="R-Rotation"> </p>
<p align="center"><img src="https://miro.medium.com/max/700/1*kE_2S1E4IoJxRF4eVt6TAQ.png" alt="Push"> </p>


## `Validations, tips and tricks`

```sh
########################
#Don't run in ZSH
########################
#Allow access to checker (provided by 42)
	$> chmod 700 checker_linux
#Simple execution
	$> ./bin/push_swap 1 -147 2 89 23 30
#Print nothing
	$> ./bin/push_swap 1 5 6 8
#Print Error
	$> ./bin/push_swap 1 5 2147483657 8
#500 Numbers between 0 and 1000
	$> (shuf -i 0-1000 -n 500)
#Validation-1:
	$>ARG="2 1 0"; ./bin/push_swap $ARG | ./checker_linux $ARG
	$>ARG="2 1 0"; ./bin/push_swap $ARG | wc -l
	$>ARG="2 1 0"; ./bin/push_swap $ARG
#Validation-2:
	$>ARG="1 5 2 4 3"; ./bin/push_swap $ARG | ./checker_linux $ARG
	$>ARG="1 5 2 4 3"; ./bin/push_swap $ARG | wc -l
	$>ARG="1 5 2 4 3"; ./bin/push_swap $ARG
#Validation-3:
	$>ARG="$(shuf -i 0-10 -n 5)"; ./bin/push_swap $ARG | ./checker_linux $ARG
	$>ARG="$(shuf -i 0-10 -n 5)"; ./bin/push_swap $ARG | wc -l
	$>ARG="$(shuf -i 0-10 -n 5)"; ./bin/push_swap $ARG
#Validation-4:
	$>ARG="$(shuf -i 0-1000 -n 100)"; ./bin/push_swap $ARG | ./checker_linux $ARG
	$>ARG="$(shuf -i 0-1000 -n 100)"; ./bin/push_swap $ARG | wc -l
	$>ARG="$(shuf -i 0-1000 -n 100)"; ./bin/push_swap $ARG
#Validation-5:
	$>ARG="$(shuf -i 0-2000 -n 500)"; ./bin/push_swap $ARG | ./checker_linux $ARG
	$>ARG="$(shuf -i 0-2000 -n 500)"; ./bin/push_swap $ARG | wc -l
	$>ARG="$(shuf -i 0-2000 -n 500)"; ./bin/push_swap $ARG
```

# `Videos`
• Linked List:

https://www.youtube.com/watch?v=7bAPics2a5o&list=PL3ZslI15yo2r-gHJtjORRMRKMSNRpf7u5&index=48

https://www.youtube.com/watch?v=VOpjAHCee7c

• Sort Algorithms
https://www.youtube.com/watch?v=ZZuD6iUe3Pc

• Game
https://phemsi-a.itch.io/push-swap


• Visualization of 24 Sorting Algorithms

https://www.youtube.com/watch?v=BeoCbJPuvSE&t=5s

https://www.youtube.com/watch?v=ZZuD6iUe3Pc

https://www.youtube.com/watch?v=ZYPFQ3kMmdU


# `GUI:`
https://github.com/elijahkash/push_swap_gui

# `Article:`
• https://www.freecodecamp.org/portuguese/news/algoritmos-de-ordenacao-explicados-com-exemplos-em-python-java-e-c/

• https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a



# `Tests:`
• checker_linux:

https://github.com/laisarena/push_swap_tester.git
