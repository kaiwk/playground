#!/usr/bin/env python
# -*- coding: utf-8 -*-

def calculate_bid(player, scotch_pos, first_moves, second_moves):
    if player == 1:
        if first_moves:
            opponet_costed = sum(second_moves)
            opponet_costed_left = 100 - opponet_costed
            my_costed = sum(first_moves)
            my_left = 100 - my_costed

            diff = my_left - opponet_costed_left
            diff = 8 if diff >=8 else diff
            if first_moves[-1] < second_moves[-1]:
                if my_left >= first_moves[-1]+ diff:
                    return first_moves[-1] + diff
                else:
                    return int(0.5 * my_left)
            else:
                if my_left < 5:
                    return my_left
                else:
                    return int(0.2 * my_left)
        else:
            return 2
    else:
        if second_moves:
            opponet_costed = sum(first_moves)
            opponet_costed_left = 100 - opponet_costed

            my_costed = sum(second_moves)
            my_left = 100 - my_costed
            diff = my_left - opponet_costed_left
            diff = 8 if diff >=8 else diff
            if second_moves[-1] < first_moves[-1]:
                if my_left >= second_moves[-1] + diff:
                    return second_moves[-1] + diff
                else:
                    return int(0.5 * my_left)
            else:
                if my_left < 5:
                    return my_left
                else:
                    return int(0.2 * my_left)
        else:
            return 3


#gets the id of the player
player = int(input())

scotch_pos = int(input())         #current position of the scotch

first_moves = list(map(int, input().split()))
second_moves = list(map(int, input().split()))
bid = calculate_bid(player,scotch_pos,first_moves,second_moves)
print(bid)
