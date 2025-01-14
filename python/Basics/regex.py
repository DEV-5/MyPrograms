#! /usr/bin/python
"""
Date: 11Th August 2020
Author: Vasudev.m
Source: Corey Schafer @ https://www.youtube.com/watch?v=K8L6KVGG-7o
"""
import re

"""
Regex
.   - Any character
\d  - Digit (0-9)
\D  - Not a Digit (0-9)
\w  - Word Character (a-z, A-Z, 0-9, _)
\W  - Not a word Character
\s  - White space (space, tab, newline)
\S  - Not White space (space, tab, newline)

#Anchors(Don't match any characters used in conjunction with other patterns):
\b  - Word Boundary
\B  - Not a Word Boundary
^   - Beginning of a string
$   - END of a string

[]  = Matches Characters in brackets
[^ ]= Matches Characters not in brackets

|   - Either Or
()  - Group

Quantifiers: 
*   - 0 or More
+   - 1 or More
?   - 0 or 1
{2} - exact number
{1,5} - Range of numbers (Minimum, Maximum)
"""
def main():
    """ Main Function"""
    sentence = "This is the 1st string code :1233 bye"
    my_file = open("./wiki.txt", "r")
    buff = my_file.read()
    print("hello")
    emails = """
    vasudev0510@gmail.com
    vasudevvedusav@gmail.com
    vasudev_ind@hotmail.com
    vasudev-0510@mywork.net
    vasudev.m@university.edu
    """
    urls = """
    https://www.google.com
    http://coreyms.com
    https://www.youtube.com
    https://www.nasa.gov
    """
    
    ps = "655 tty7     00:00:15 Xorg"
    pattern = re.compile(r's[0-9]')
    matchdisplay(pattern, ps)

    pattern = re.compile(r'ab')
    matchdisplay(pattern, sentence)
    pattern = re.compile(r'\.')
    matchdisplay(pattern, sentence)
    pattern = re.compile(r'\W')
    matchdisplay(pattern, sentence)
    pattern = re.compile(r'^bye') #search for bye at start of string
    matchdisplay(pattern, sentence)
    pattern = re.compile(r'bye$') #search for bye at end of string
    matchdisplay(pattern, sentence)
    pattern = re.compile(r'$')
    matchdisplay(pattern, sentence)
    pattern = re.compile(r'\d\d\d.\d\d\d.\d\d\d\d') #same as above
    matchdisplay(pattern, buff)
    pattern = re.compile(r'\d\d\d[-.]\d\d\d.\d\d\d\d')
    matchdisplay(pattern, buff)
    pattern = re.compile(r'[89]00.\d\d\d.\d\d\d\d')
    matchdisplay(pattern, buff)
    #pattern = re .compile(r'[^a-zA-z]') # search for all char which are not alphabets
    pattern = re.compile(r'[^b]at') #search for all char not with b but have at
    matchdisplay(pattern, buff)
    pattern = re.compile(r'Mr\.?\s[A-Za-z]\w*') #\.? for one or none of any char \w* 0 or more w
    matchdisplay(pattern, buff)
    pattern = re.compile(r'M(r|s|rs)\.?\s[A-Za-z]\w*')
    matchdisplay(pattern, buff)
    pattern = re.compile(r'[a-zA-Z0-9-._]+@[a-zA-a-.]+\.(com|net|edu)')
    matchdisplay(pattern, emails)
    pattern = re.compile(r'https?://(www\.)?(\w+)(\.\w+)')
    matchdisplay(pattern, urls)
    subbed_url = pattern.sub(r'\2\3', urls) #upon pattern match substitute string with group 2 and 3
    print(subbed_url)
    pattern = re.compile(r'M(r|s|rs)\.?\s[A-Za-z]\w*')
    matches = pattern.findall(buff) # if they are groups it only consider them and ignore rest
    for match in matches:
        print(match)
    pattern = re.compile(r'This')
    #searches beginning of string and returns match found or none if not found
    matches = pattern.match(sentence)
    print(matches)
    pattern = re.compile(r'This')
    #Searches entire string and returns first match found or none if not found
    matches = pattern.search(sentence)
    print(matches)
    pattern = re.compile(r'this', re.IGNORECASE) # using Flag to ignore case of text
    matches = pattern.search(sentence)
    print(matches)


def matchdisplay(patt, astring):
    """
    Search  and display
    @pattern : regex patt to be searched
    """
    print(" ---------------------------------------------- ")
    matches = patt.finditer(astring)
    for match in matches:
        print(match)

if __name__ == '__main__':
    main()
