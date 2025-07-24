![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Unix](https://img.shields.io/badge/Unix-3E4348?style=for-the-badge&logo=linux&logoColor=white)
![Makefile](https://img.shields.io/badge/Makefile-1f425f?style=for-the-badge&logo=makefile&logoColor=white)
![Threads](https://img.shields.io/badge/Threads-blue?style=for-the-badge) 
![Mutex](https://img.shields.io/badge/Mutex-red?style=for-the-badge)
![Philosophers](https://img.shields.io/badge/Philosophers-Completed-e68e3a?style=for-the-badge)

# Philosophers

![philosophers_demo](assets/philosophers_demo.gif) ## Project Description

This repository contains **Philosophers**, a classic synchronization problem from the 42 curriculum. The goal is to simulate a group of philosophers dining around a table, addressing the challenges of resource allocation and preventing deadlocks using threads and mutexes.

### Core Concepts

* **Concurrency**: The project simulates multiple philosophers (threads) running concurrently.
* **Synchronization**: It uses **mutexes** to protect shared resources (forks and potentially other critical sections) and ensure that only one philosopher can pick up a specific fork at a time.
* **Deadlock Prevention**: The primary objective is to implement a solution that prevents deadlocks, where philosophers might indefinitely wait for resources that other philosophers hold. A common approach involves establishing a hierarchy for picking up forks or ensuring that not all philosophers try to pick up their left fork simultaneously.
* **Liveness (Starvation)**: The solution also aims to prevent starvation, where a philosopher might endlessly wait to eat while others continue to dine.

### Rules and Behavior

* **Philosophers**: Each philosopher is represented by a thread.
* **Forks**: Forks are shared resources, and there's one fork between each pair of adjacent philosophers.
* **Life Cycle**: Philosophers cycle through three states:
    * **Thinking**: When not eating, a philosopher thinks.
    * **Eating**: To eat, a philosopher must acquire two forks (one to their left and one to their right).
    * **Sleeping**: After eating, a philosopher sleeps for a defined period before thinking again.
* **Monitoring**: The simulation tracks key events, such as a philosopher taking a fork, eating, sleeping, or dying.
* **Termination**: The simulation ends if a philosopher dies (doesn't eat within a specified `time_to_die`) or if all philosophers have eaten a specified number of times (if `number_of_times_each_philosopher_must_eat` is provided).

## How to Use

1.  Clone the repository and compile the program with `make`:
    ```bash
    git clone [https://github.com/leonel-carrizo/Philosophers.git](https://github.com/leonel-carrizo/Philosophers.git)
    cd Philosophers
    make
    ```
2.  Run the simulation by providing command-line arguments:
    ```bash
    ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
    ```
    * `<number_of_philosophers>`: The number of philosophers (and forks).
    * `<time_to_die>`: The time (in milliseconds) after which a philosopher dies if they don't eat.
    * `<time_to_eat>`: The time (in milliseconds) it takes for a philosopher to eat.
    * `<time_to_sleep>`: The time (in milliseconds) a philosopher sleeps.
    * `[number_of_times_each_philosopher_must_eat]` (optional): If specified, the simulation stops once all philosophers have eaten at least this many times.

    **Example:**
    ```bash
    ./philo 5 800 200 200
    ```
    This simulates 5 philosophers, where a philosopher dies if they don't eat within 800ms, eating takes 200ms, and sleeping takes 200ms.

## Contact

* **GitHub**: [leonel-carrizo](https://github.com/leonel-carrizo)

Feel free to explore the code or reach out with any questions.
