# Lottery_Scheduling

Project Title: Lottery Scheduling

Language: C++

Description: The purpose of this project is to demonstrate random scheduling. Using C++ code, I implemented a process class and a scheduler class as per assignment requirements. Using srand(), rand(), and time() function, I ensure that the winning process is random. This is because of the time component. With the ticket number, the more tickets a process has the more likely it is to win. This is similar to a priority-based queue but not similar in the randomness as per assignment requirements. I also tried implementing a first come, first serve approach, but that only ensures the first added process wins, so I commented on the FCFS scheduling implementation. 

When you download the project, you can run it on basically any IDE. Many popular ones are Visual Studio, Visual Studio code, Online IDE, and Online GDB. When the code is running, it will randomly pick a winning process. You can fiddle with the code in the add_proccess part in main. It looks like this: "scheduler.add_process(process(1, 33));" The 33/the right-hand side, is the number of tickets. Changing the number of tickets changes the priority. The more tickets, the more likely the process wins the lottery. 
