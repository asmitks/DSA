
aynamron's avatar
aynamron
467
Last Edit: March 22, 2021 11:44 PM

31.5K VIEWS

I was asked in the interview of linkedIn, writing it directly can be extremely complicated, for there are many special cases we have to deal with, and the code I wrote was messy. Then I failed to pass the interview.

Here's a clear solution. With DFA we can easily get our idea into shape and then debug, and the source code is clear and simple.

class Solution(object):
  def isNumber(self, s):
      """
      :type s: str
      :rtype: bool
      """
      #define a DFA
      state = [{}, 
              {'blank': 1, 'sign': 2, 'digit':3, '.':4}, 
              {'digit':3, '.':4},
              {'digit':3, '.':5, 'e':6, 'blank':9},
              {'digit':5},
              {'digit':5, 'e':6, 'blank':9},
              {'sign':7, 'digit':8},
              {'digit':8},
              {'digit':8, 'blank':9},
              {'blank':9}]
      currentState = 1
      for c in s:
          if c >= '0' and c <= '9':
              c = 'digit'
          if c == ' ':
              c = 'blank'
          if c in ['+', '-']:
              c = 'sign'
          if c not in state[currentState].keys():
              return False
          currentState = state[currentState][c]
      if currentState not in [3,5,8,9]:
          return False
      return True
