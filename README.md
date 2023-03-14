# Final Project SDEV2320 C++

This final project demonstrates your competency in skills learned in this course. You must complete this exercise on your own, without any help from an instructor or another student. If you get stuck, go back through the relevant sections in the book and previous assignments -- everything you need to do in this exercise has been covered in this course.

This project encrypts data using transposition, substitution, and reversal -- substituting one letter for another using a key value, transposing letters into separate strings, and reversing strings. It then decrypts those results and checks if that decrypted string matches the original string.

You will use skills you've learned throughout this course, but in particular, you might want to review Ch 18's project about reversing stacks, the Module 4 competency project about palindromes which also uses a stack, and the Ch 13 project about combining files.

Create a project that reads a text file that contains a string. In the example here, that string was 

   abc de fghi jkl mn opq rstuv wx yz ab

It can be any string you want, but this one is short enough to be manageable, and because of the order of the letters, easy to check to see if the manipulations are working correctly. This string has an odd number of characters in it; you also want to test a string that has an even number of characters in it (stop the string after the "z"). You must use files to hold the original string and the encrypted strings. Use NotePad++ to create a simple text file with the original string in it. Put that text file in your project files in the same folder with the ReadMe.txt file.

Once you have read in the original text, you need to substitute each character by adding a key value to it. Next, split the substituted string into 2 strings, one for characters in even positions in the original string, and one for characters in odd positions in the original string. Then reverse each of those strings using a stack. The results -- 2 strings that have been substituted, transformed, and reversed -- go into 2 output files. Display the original string and the contents of the even and odd strings.

Decrypt the data by reversing the process. Begin by reading the data from the 2 files created during the encryption process -- do not use the string variables used in that encryption process, make sure you read the data from files. Check the resulting decrypted string against the original string and verify that they are the same.

Here is an example, using 3 as the key to add to a character's ASCII value to get a new character. The first image shows correct results, the second image shows the decryption didn't work correctly. You may find it very useful to include a lot of debugging output to check interim results.

![2320 Final Clean](https://github.com/bell-kevin/finalProject2320cPlusPlus/blob/main/match.PNG)      

Your project should have functions to (a) read a file, (b) substitute characters using a key value, (c) split one string into two strings, (d) merge two strings into one, interleaving them together, (e) reverse a string using a stack. These functions must work for both encrypting and decrypting processes. For example, the substitution function can add the key value to a character to encrypt, and can also add a negative version of the key value, thus subtracting that key value to decrypt. The key value must be in a variable, not hard-coded in the substitution function.

The transformation takes a string and splits it into 2 strings, based on the position of each character in the string. If the string had 5 characters, they are in positions 0, 1, 2, 3, and 4. Those characters in even positions (0, 2, and 4) go into the "even" string, and those characters in odd positions (1 and 3) go into the "odd" string. When decrypting, merging those files together needs to interleave the characters -- take one from the even string, then one from the odd string, then one from the even string, and so on. That should produce the same sequence of characters as the original string.

Do not close the files for the 2 output files after writing the even and odd strings to them. Use the same files in the decrypting portion of the program, reading in the data in the file to the program.

You may use your own data for the original string, as long as it is at least 20 characters long. Run the program twice, once with a string that has an even number of characters, and once with a string that has an uneven number of characters. Take screenshots of both.

![2320 Final Bad](https://github.com/bell-kevin/finalProject2320cPlusPlus/blob/main/NOTmatch.PNG)

Submission: screenshots and the root folder of the project in a zipped folder

== We're Using GitHub Under Protest ==

This project is currently hosted on GitHub.  This is not ideal; GitHub is a
proprietary, trade-secret system that is not Free and Open Souce Software
(FOSS).  We are deeply concerned about using a proprietary system like GitHub
to develop our FOSS project. I have a [website](https://bellKevin.me) where the
project contributors are actively discussing how we can move away from GitHub
in the long term.  We urge you to read about the [Give up GitHub](https://GiveUpGitHub.org) campaign 
from [the Software Freedom Conservancy](https://sfconservancy.org) to understand some of the reasons why GitHub is not 
a good place to host FOSS projects.

If you are a contributor who personally has already quit using GitHub, please
email me at **bellKevin@pm.me** for how to send us contributions without
using GitHub directly.

Any use of this project's code by GitHub Copilot, past or present, is done
without our permission.  We do not consent to GitHub's use of this project's
code in Copilot.

![Logo of the GiveUpGitHub campaign](https://sfconservancy.org/img/GiveUpGitHub.png)
