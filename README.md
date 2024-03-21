<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->


<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/othneildrew/Best-README-Template">
    <img src="logo/Redfox_coding.jpg" alt="Logo" width="160" height="160">
  </a>

  <h3 align="center">PUSH_SWAP</h3>



</div>


<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

The Push swap project is a very simple and a highly straightforward algorithm project:
data must be sorted. (with as few moves as possible)

we have a list of action defined by the subject to sort the data, and we have 2 stack to sort it :

-> stack_a (original stack)

-> stack-b

To get the best grades, we need to sort 5 value in less than 8 moves / 100 in under 700 moves / 500 in under 5500 moves.

For this, i use the [turk algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

(!) The program dont return the stack_a correctly sorted, it return the list of moves to correctly sorted the stack.

here the list of actions :
```
-> sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

-> sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

-> ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

-> pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

-> ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

-> rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

-> rr : ra and rb at the same time.

-> rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

-> rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

-> rrr : rra and rrb at the same time.
```
<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- GETTING STARTED -->
## Getting Started

### Prerequisites

This is a C program so you need to have gcc compiler.
  ```sh
  sudo apt-get install gcc -y
  ```

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/Lyyrst/push_swap.git
2. Makefile !
   ```sh
   make && make clean
   ```
<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

To use the program you should use this :
```sh
./push_swap "data"
```
example :
```sh
./push_swap "42 -42 0 -32 32"
```
<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTACT -->
## Contact

[Discord : lyrst](https://discord.com/users/257192704537001984)

kurt.butorp@gmail.com

## Reminder

Please remember that this project is one of the first I did as a computer science learner, it does not reflect my actual skills but through which project I learned programming.
