Due Date: 10/10/2017 at 11:55PM

Submission and Grading: All programs are to be submitted in eLearning.
Projects submitted after the due date are subject to the late penalties described
in the syllabus. Each student is responsible for developing sample test cases to
ensure the program works as expected. Type your name and netID in the comments at
the top of all source files submitted.

What to Submit: Save all project files in a directory named with the following
format: <netID>_Project<number>. This directory should contain all header files,
source code files and any IDE based project file. Zip up the directory into a
standard Zip file. Please do not create a RAR or 7-Zip file, just a .zip file.

Objective: Use pointers to create and access dynamic arrays.

Problem: Jeopardy! is creating a new tournament centered around pop culture and
geek trivia. The producers will launch an online multiple choice test for
contestants to take for entry into the tournament. They need a report generated
for each participant as well as the mean, median and mode for each version of
the exam.

Details:
•This project will utilize dynamic arrays
•All array access must be done with pointer notation (no brackets)
•For each contestant, produce a report
    The report will contain the following:  
        §Contestant’s ID number
        §Score
        §List of questions missed, including the correct answer and contestant answer
•Calculate the overall mean, median and mode of all contestants
•All calculated values should be rounded to 2 decimal places
•Score = # correct questions / total # questions * 100

Input:
•Multiple files will be used for input.
•Correct answers will be in a file named answers.txt.
    o Series of characters separated by white space.
    o Each character represents the correct answer for a multiple choice style question.
    o First character is the answer for the first question, the second character
        for the second question and so forth.
•Contestant answers will be in a file named contestants.txt.
•Each line of the file will contain data for a unique contestant.
•Each line of the file will begin with a contestant ID (a 10-digit number –
    can be treated as a string) followed by the contestant’s answers for the test.
•Each answer will be separated by a space and there will be exactly as many answers
    as there are questions listed in answers.txt

Output:
•All output will be written to a file named report.txt.
•For each contestant, the following information should be written to the file
(each bullet represents a separate line):
    o Contestant ID
    o Score
    o If questions missed
        §Exam questions missed (numeric - separated by spaces)
        §Incorrect answers given by contestant (line up each answer with the
            ones digit of the question number in the previous line)
        §Correct answer (line up each answer with the incorrect answer on the previous line)
    o Blank line
•Create a summary at the end of the report
    o Mean
    o Median
    o Mode
        § If there is more than 1 value for mode
•List all modes separated by a comma and space
