#!/usr/bin/env python
# -*- coding: utf-8 -*-

import random
import math
import os
import copy


# 基因突变几率
mutation_probability = 0.2

# 遗传代数
generations = 100

# 假设总体数量
generation_size = 100

# 参与繁衍的个体数量
sample_size = 10

# 城市集合
city_list = []

class City:
    def __init__ (self, name, x, y, distance_to=None):
        self.name = name
        self.x = self.graph_x = x
        self.y = self.graph_y = y
        city_list.append(self)
        self.distance_to = {self.name: 0.0}

        if distance_to:
            self.distance_to = distance_to

    def calculate_distance (self):
        for city in city_list:
            tmp_dist = self.point_dist(self.x, self.y, city.x, city.y)
            self.distance_to[city.name] = tmp_dist

    def point_dist (self, x1, y1, x2, y2):
        return ((x1-x2)**2 + (y1-y2)**2)**0.5


class Route(object):
    def __init__ (self):
        self.route = sorted(city_list, key=lambda *args: random.random())
        self.recalculate_route_len()

    def recalculate_route_len (self):
        self.length = 0.0
        for city in self.route:
            next_city = self.route[self.route.index(city) - len(self.route) + 1]
            dist_to_next = city.distance_to[next_city.name]
            self.length += dist_to_next

    def print_cities_route (self, print_route=False):
        cities_str = ''
        for city in self.route:
            cities_str += city.name + ','
        cities_str = cities_str[:-1]
        if print_route:
            print('    ' + cities_str)

    def print_coordi_cities_in_route (self):
        cities_str = '|'
        for city in self.route:
            cities_str += str(city.x) + ',' + str(city.y) + '|'
        print(cities_str)

    def is_valid_route (self):
        for city in city_list:
            if self.count_mult(self.route, lambda c: c.name == city.name) > 1:
                return False
        return True

    def count_mult (self, seq, pred):
        return sum(1 for v in seq if pred(v))


class RoutePopulation(object):
    def __init__ (self, size, initialise):
        self.route_population = []
        self.size = size

        if initialise:
            for x in range(0, size):
                new_route = Route()
                self.route_population.append(new_route)
            self.get_fittest()

    def get_fittest (self):
        sorted_list = sorted(self.route_population, key=lambda x: x.length, reverse=False)
        self.fittest = sorted_list[0]
        return self.fittest


class GeneticAlgorithm(object):

    def crossover (self, parent1, parent2):
        child_route = Route()

        child_route.route = [None for _ in range(len(city_list))]

        start_pos = random.randint(0, len(parent1.route))
        end_pos = random.randint(0, len(parent1.route))

        if start_pos < end_pos:
            for i in range(start_pos, end_pos):
                child_route.route[i] = parent1.route[i]
        elif start_pos > end_pos:
            for i in range(end_pos, start_pos):
                child_route.route[i] = parent1.route[i]

        for i in range(len(parent2.route)):
            if not parent2.route[i] in child_route.route:
                for j in range(len(child_route.route)):
                    if child_route.route[j] == None:
                        child_route.route[j] = parent2.route[i]
                        break;

        child_route.recalculate_route_len()
        return child_route


    def mutate (self, route_to_mutate):
        if random.uniform(0.0, 1.0) < mutation_probability:
            mut_pos1 = random.randint(0, len(route_to_mutate.route)-1)
            mut_pos2 = random.randint(0, len(route_to_mutate.route)-1)

            if mut_pos1 == mut_pos2:
                return route_to_mutate

            city1 = route_to_mutate.route[mut_pos1]
            city2 = route_to_mutate.route[mut_pos2]

            # exchange
            route_to_mutate.route[mut_pos2] = city1
            route_to_mutate.route[mut_pos1] = city2

        route_to_mutate.recalculate_route_len()

        return route_to_mutate


    def generation_select (self, poplulation):
        sample_population = RoutePopulation(size=sample_size, initialise=False)

        for i in range(sample_size-1):
            sample_population.route_population.append(random.choice(poplulation.route_population))
        return sample_population.get_fittest()


    def evolve_population (self, init_population):
        descendant_population = RoutePopulation(size=init_population.size, initialise=True)

        for i in range(descendant_population.size):
            tournament_parent1 = self.generation_select(init_population)
            tournament_parent2 = self.generation_select(init_population)

            tournament_child = self.crossover(tournament_parent1, tournament_parent2)

            descendant_population.route_population[i] = tournament_child

        for route in descendant_population.route_population:
            if random.random() < 0.3:
                self.mutate(route)

        descendant_population.get_fittest()

        return descendant_population

def random_cities ():
    c = City('1', 6734, 1453)
    c = City('2', 2233, 10)
    c = City('3', 5530, 1424)
    c = City('4', 401, 841)
    c = City('5', 3082, 1644)
    c = City('6', 7608, 4458)
    c = City('7', 7573, 3716)
    c = City('8', 7265, 1268)
    c = City('9', 6898, 1885)
    c = City('10', 1112, 2049)
    c = City('11', 5468, 2606)
    c = City('12', 5989, 2873)
    c = City('13', 4706, 2674)
    c = City('14', 4612, 2035)
    c = City('15', 6347, 2683)
    c = City('16', 6107, 669)
    c = City('17', 7611, 5184)
    c = City('18', 7462, 3590)
    c = City('19', 7732, 4723)
    c = City('20', 5900, 3561)
    c = City('21', 4483, 3369)
    c = City('22', 6101, 1110)
    c = City('23', 5199, 2182)
    c = City('24', 1633, 2809)
    c = City('25', 4307, 2322)
    c = City('26', 675, 1006)
    c = City('27', 7555, 4819)
    c = City('28', 7541, 3981)
    c = City('29', 3177, 756)
    c = City('30', 7352, 4506)
    c = City('31', 7545, 2801)
    c = City('32', 3245, 3305)
    c = City('33', 6426, 3173)
    c = City('34', 4608, 1198)
    c = City('35', 23, 2216)
    c = City('36', 7248, 3779)
    c = City('37', 7762, 4595)
    c = City('38', 7392, 2244)
    c = City('39', 3484, 2829)
    c = City('40', 6271, 2135)
    c = City('41', 4985, 140)
    c = City('42', 1916, 1569)
    c = City('43', 7280, 4899)
    c = City('44', 7509, 3239)
    c = City('45', 10, 2676)
    c = City('46', 6807, 2993)
    c = City('47', 5185, 3258)
    c = City('48', 3023, 1942)

    for city in city_list:
        city.calculate_distance()


if __name__ == '__main__':
    print("Creates the poplulation.")
    random_cities()
    the_population = RoutePopulation(generation_size, True)
    initial_length = the_population.fittest.length

    print("Finished Creation of the population")

    best_route = Route()

    for i in range(1, generations):
        the_population = GeneticAlgorithm().evolve_population(the_population)
        if the_population.fittest.length < best_route.length:
            best_route = copy.deepcopy(the_population.fittest)

        print('Current fittest has length {0:.2f}'.format(the_population.fittest.length))
        print('And goes via:')
        the_population.fittest.print_cities_route(True)
        print('')

    print('Finished evolving {0} generations.'.format(generations))
    print(' ')
    print('Initial best distance: {0:.2f}'.format(initial_length))
    print('Final best distance:   {0:.2f}'.format(best_route.length))
    print('The best route went via:')
    best_route.print_cities_route(True)
