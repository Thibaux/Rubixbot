# Test script to test ToKociemba
##	Description	##
# At first we adress the file to an fileobject to extract the lines out of the file.
# The same happens for the output file. Secondly we store the correct lines in a variable.
# Then we run ToKociemba with the input, and store the output of ToKociemba in a variable.
# The unnecessary characters and whitespaces get extracted from the string.
# Finaly the variables get checked, if they are equal to each other the test was successful.

# Importing the necessary libraries
import sys
import os
import subprocess
import re

# Assign the file to an fileobject and assign the lines in the file to lines
# NOTE: The 'with open' function reads a file as a binary so the first line is 0 instead of 1
with open("Test_cases.txt") as test_cases:
    lines = test_cases.readlines()

# Assign the new file to an fileobject and give the parrameter 'a' to be able to write to the file
output = open("Test_output.txt", "w")

###		ToKociemba		###

##	CORRECT DATA ##
# Read the specific lines from the file and assign them to varibles
# CASE 1
case_1_color_correct = lines[11].rstrip()
# CASE 2
case_2_color_correct = lines[18].rstrip()
# CASE 3
case_3_color_correct = lines[25].rstrip()
# CASE 4
case_4_color_correct = lines[32].rstrip()
# CASE 5
case_5_color_correct = lines[39].rstrip()


##	TEST DATA ##
# CASE 1
case_1_kociemba_out = subprocess.check_output(
    r"D:\Thibaux\Documents\School\Windesheim\Jaar3\IUT\Project\Rubik'sCubeAlgo\ToKociemba WWOWOWWOGGGRRWBBBYOOGGRWBBYOGGGRRWBBBYOOYYRYRYYR; exit 0",
    shell=True
)
chars = ["a-z", "'", r" \ "]
case_1_kociemba_out_a = case_1_kociemba_out.decode('ASCII')
for i in chars:
    case_1_kociemba_out_a = case_1_kociemba_out_a.replace(i, "")
case_1_kociemba_out_b = case_1_kociemba_out_a.rstrip()

# CASE 2
case_2_kociemba_out_a = subprocess.check_output(
    r"D:\Thibaux\Documents\School\Windesheim\Jaar3\IUT\Project\Rubik'sCubeAlgo\ToKociemba WWRWRWWRGGGRRYBBBWOOGGRYBBWOGGGRRYBBBWOOYYOYOYYO; exit 0",
    shell=True
)
chars = ["a-z", "'", r" \ "]
case_2_kociemba_out_a = case_2_kociemba_out_a.decode('ASCII')
for i in chars:
    case_2_kociemba_out_a = case_2_kociemba_out_a.replace(i, "")
case_2_kociemba_out_b = case_2_kociemba_out_a.rstrip()

# CASE 3
case_3_kociemba_out_a = subprocess.check_output(
    r"D:\Thibaux\Documents\School\Windesheim\Jaar3\IUT\Project\Rubik'sCubeAlgo\ToKociemba BWWOWOBROGGWRGYBBOOYOGWGYBOYWWWBRGYRRBBGRGORYRYY; exit 0",
    shell=True
)
chars = ["a-z", "'", r" \ "]
case_3_kociemba_out_a = case_3_kociemba_out_a.decode('ASCII')
for i in chars:
    case_3_kociemba_out_a = case_3_kociemba_out_a.replace(i, "")
case_3_kociemba_out_b = case_3_kociemba_out_a.rstrip()

# CASE 4
case_4_kociemba_out_a = subprocess.check_output(
    r"D:\Thibaux\Documents\School\Windesheim\Jaar3\IUT\Project\Rubik'sCubeAlgo\ToKociemba RRBYBROBWGWGBRYYYOGBGRYWRYOWYWYOBBWWWGGRGROBOGOO; exit 0",
    shell=True
)
chars = ["a-z", "'", r" \ "]
case_4_kociemba_out_a = case_4_kociemba_out_a.decode('ASCII')
for i in chars:
    case_4_kociemba_out_a = case_4_kociemba_out_a.replace(i, "")
case_4_kociemba_out_b = case_4_kociemba_out_a.rstrip()

# CASE 5
case_5_kociemba_out_a = subprocess.check_output(
    r"D:\Thibaux\Documents\School\Windesheim\Jaar3\IUT\Project\Rubik'sCubeAlgo\ToKociemba RRBYBROBWGWGBRYYYOGBGRYWRYOWYWYOBBWWWGGRGROBOGOO; exit 0",
    shell=True
)
chars = ["a-z", "'", r" \ "]
case_5_kociemba_out_a = case_5_kociemba_out_a.decode('ASCII')
for i in chars:
    case_5_kociemba_out_a = case_5_kociemba_out_a.replace(i, "")
case_5_kociemba_out_b = case_5_kociemba_out_a.rstrip()

# Write to the output file
print("Kociemba test" + "\n")

# CASE 1
if case_1_color_correct == case_1_kociemba_out_b:
    print("Test case 1 was succesful!")
elif case_1_color_correct != case_1_kociemba_out_b:
    print("Test case 1 was not successful.")
else:
    print("Something went wrong.")

# CASE 2
if case_2_color_correct == case_2_kociemba_out_b:
    print("Test case 2 was succesful!")
elif case_2_color_correct != case_2_kociemba_out_b:
    print("Test case 2 was not successful.")
else:
    print("Something went wrong.")

# CASE 3
if case_3_color_correct == case_3_kociemba_out_b:
    print("Test case 3 was succesful!")
elif case_3_color_correct != case_3_kociemba_out_b:
    print("Test case 3 was not successful.")
else:
    print("Something went wrong.")

# CASE 4
if case_4_color_correct == case_4_kociemba_out_b:
    print("Test case 4 was succesful!")
elif case_4_color_correct != case_4_kociemba_out_b:
    print("Test case 4 was not successful.")
else:
    print("Something went wrong.")

# CASE 5
if case_5_color_correct == case_5_kociemba_out_b:
    print("Test case 5 was succesful!")
elif case_5_color_correct != case_5_kociemba_out_b:
    print("Test case 4 was not successful.")
else:
    print("Something went wrong.")


# Close the fileobject
output.close()
