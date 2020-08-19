import sys

if len(sys.argv) > 1:

    origional_message = sys.argv[1]
    print('Your text: {}'.format(origional_message))

    reversed_text = ''
    i = len(origional_message) - 1

    while i >= 0:
        reversed_text += origional_message[i]
        i -= 1

    print('Reversed text: {}'.format(reversed_text))
else:
    print('Please pass text as argument to reverse. Pass the same reversed text to get origional text.')
