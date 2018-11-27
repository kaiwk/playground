import genetic_tsp as gt
import tkinter as tk
import copy

from genetic_tsp import random_cities
from genetic_tsp import city_list, generation_size
from genetic_tsp import RoutePopulation, Route, GeneticAlgorithm


canvas_width = 500
canvas_height = 600

class Drawer:
    def __init__(self, master):
        self.root = master
        self.cv = tk.Canvas(master, width=canvas_width, height=canvas_height)
        self.cv.pack()

        self.label_generation = tk.Label(text='Current Generation: ~')
        self.label_generation.pack(side=tk.BOTTOM)

        self.label_length = tk.Label(text='Current Length: ~')
        self.label_length.pack(side=tk.BOTTOM)
        self.btn = tk.Button(text='next', width=50, command=self._next_generation)
        self.btn.pack(side=tk.BOTTOM)

        self.the_population = RoutePopulation(generation_size, True)
        self.initial_length = self.the_population.fittest.length
        self.generation = 1
        self.route = Route()
        self.label_length.config(text='Current Length: ' + str(self.initial_length))
        self.label_generation.config(text='Current Generation: '+ str(self.generation))

        self.draw_city(city_list)

    def _draw_line (self, x1, y1, x2, y2):
        self.cv.create_line(x1, y1, x2, y2, tags=('path'), fill='red')
        self.cv.pack()
        self.cv.update_idletasks()

    def _draw_point (self, x, y, color):
        self.cv.create_oval(x-3, y-3, x+3, y+3, fill=color)
        self.cv.pack()

    def draw_city (self, cities):
        for city in city_list[1:]:
            self._draw_point(city.graph_x, city.graph_y, 'green')
        self._draw_point(cities[0].graph_x, cities[0].graph_y, 'black')


    def draw_route (self, route):
        self.index_city = 0
        def recursive_draw_line():
            if self.index_city == len(route)-1:
                self._draw_line(route[-1].graph_x, route[-1].graph_y,
                                 route[0].graph_x, route[0].graph_y)
                return
            city = route[self.index_city]
            next_city = route[self.index_city+1]
            self._draw_line(city.graph_x, city.graph_y, next_city.graph_x, next_city.graph_y)
            self.index_city += 1
            self.cv.after(100, recursive_draw_line)
        recursive_draw_line()


    def _next_generation (self):
        self.cv.destroy()
        self.cv = tk.Canvas(self.root, width=canvas_width, height=canvas_height)
        self.cv.pack()

        self.the_population = GeneticAlgorithm().evolve_population(self.the_population)
        self.route = copy.deepcopy(self.the_population.fittest)

        self.draw_city(self.route.route)
        self.draw_route(self.route.route)
        length = self.the_population.fittest.length
        self.generation += 1
        self.label_length.config(text='Current Lenght: ' + str(length))
        self.label_generation.config(text='Current Generation: ' + str(self.generation))

    def start_draw (self):
        self.draw_route(city_list)


def calculate_scale_size ():

    x_list = [city.x for city in city_list]
    y_list = [city.y for city in city_list]

    min_x = min(x_list)
    min_y = min(y_list)
    max_x = max(x_list)
    max_y = max(y_list)

    return (max_x-min_x)/canvas_width + 1, (max_y-min_y)/canvas_height + 1

def scale_city_location (city):
    city.graph_x = city.x / scale_x_size + 10
    city.graph_y = city.y / scale_y_size + 10
    return city

# preprocess
random_cities()
scale_x_size, scale_y_size = calculate_scale_size()
city_list = list(map(scale_city_location, city_list))


if __name__ == '__main__':
    root = tk.Tk()
    drawer = Drawer(root)
    drawer.start_draw()

    tk.mainloop()
