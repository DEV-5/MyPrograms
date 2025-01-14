#! /usr/bin/ python3
#import utils from email.utils
from email import utils as utils

if __name__ == "__main__":
    print("happy")
    emailstring = input("please enter your user name and email id as shown uname myid@mail.com :")
    #mail = utils.parseaddr("now <now@mail.com>")
    mail = utils.parseaddr(emailstring)
    amail = utils.formataddr(mail)
    print(mail)
    print(amail)
