# pipex<img width="1175" alt="Pipex" src="https://user-images.githubusercontent.com/82111543/218945992-d0c25557-92d5-47a3-96f7-0d7eb0a393a3.png">


In this project, we had to write our own version of a pipe in c that should execute as follows
 ./pipex file1 cmd1 cmd2 file2
It must take 4 arguments:
• file1 and file2 are file names.
• cmd1 and cmd2 are shell commands with their parameters.
and should work like the shell command 
$> < file1 cmd1 | cmd2 > file2
I created a parent process and then used fork to create two child processes to deal with the two commands. The parent process must then wait using wait or waitpid.  I used waitpid because we had more than one child process so their id becomes important. When the child processes are done executing the parent can also be done. If the parent ends before any child the leftover child process becomes a zombie and causes problems
I learned how to use perror and strerror when there are error messages to give.
I used dup2 to change fds of the read and write ends of pipes as required.
env is a command that tells many things including paths. Searched them for PATH= and stored them as a 2d array split using: as a delimiter to get all the paths in a 2D array. Checked for and added a slash if not there at the end. Checked if the path exists using access in a loop to tell if that command is usable then used these paths in execve in a loop so it checks by attaching your command at the end of each until one works. Use the access function to check whether the path actually exists and is accessible first. Now you have all paths and can begin executing in each child with execve. An important thing to remember is that though each child process takes a copy of all parent variables they are now independent and any changes they make are limited to their own copies. They never rejoin their parent.
