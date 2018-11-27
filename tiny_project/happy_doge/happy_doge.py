import pygame
import time
import random

GAME_NAME = 'Happy Doge, Yeah!'

# FONT = 'freesansbold.ttf'
FONT = 'monaco.ttf'
ALERT_FONT_SIZE = 50

display_width = 800
display_height = 600

# RGB
black = (0, 0, 0)
white = (255, 255, 255)
red = (200, 0, 0)
green = (0, 200, 0)
block_color = black

bright_red = (255, 0, 0)
bright_green = (0, 255, 0)

pygame.init()

gameDisplay = pygame.display.set_mode((display_width, display_height)) # 这个对象控制Pygame所有元素的显示
pygame.display.set_caption(GAME_NAME) # 设置标题
clock = pygame.time.Clock()     # 游戏时钟，用来设置 游戏 的 fps, 会影响 update 的频率。实际的fps要更加复杂，也取决其他因素

# 加载图片
dogeImg = pygame.image.load('doge.png')
dogeImg = pygame.transform.scale(dogeImg, (100, 100))
doge_width = 100

shitImg = pygame.image.load('shit.png')
shitImg = pygame.transform.scale(shitImg, (100, 100))

def doge(x, y):
    """ blit 方法会预备显示这个图片，等待 update 刷新
    :param x: doge左上角的横坐标
    :param y: doge左上角的纵坐标
    :returns:
    :rtype:
    """
    gameDisplay.blit(dogeImg, (x, y))

def shit(x, y):
    gameDisplay.blit(shitImg, (x, y))

def score_board(count):
    """ 计分板，仍然要调用 blit 方法，等待 update 刷新
    :param count: 当前分数
    :returns:
    :rtype:
    """
    font = pygame.font.SysFont(None, 25)
    text = font.render('Dodged: ' + str(count), True, black)
    gameDisplay.blit(text, (0, 0))
    if count > 5:
        win()

def text_objects(text, font):
    """ 生成文本对象，
    :param text: 文字
    :param font: 文字的字体
    :returns: 返回文字和摆放文字的矩形，之所以返回这两个参数是因为 blit 函数需要这两个参数
    :rtype:
    """
    textSurface = font.render(text, True, black)
    return textSurface, textSurface.get_rect()

def quitgame():
    pygame.quit()
    quit()


def message_display(text):
    largeText = pygame.font.Font(FONT, ALERT_FONT_SIZE)
    TextSurf, TextRect = text_objects(text, largeText)
    TextRect.center = (display_width/2, display_height/2)
    gameDisplay.blit(TextSurf, TextRect) # blit 函数 参数为 文字 和 摆放 文字的矩形
    pygame.display.update()
    time.sleep(2)


def crash():
    message_display('So sad, oops!')
    time.sleep(2)
    game_intro()

def win():
    message_display('So happy, yeah!')
    time.sleep(2)
    game_intro()

def button(msg, x, y, w, h, ic, ac, action=None):
    """ 游戏中出现的按钮，写这个函数的原因是，提取了公共代码，利于复用
    :param msg: 按钮上的内容
    :param x: 按钮左上角的横坐标
    :param y: 按钮左上角的纵坐标
    :param w: 按钮的宽度
    :param h: 按钮的高度
    :param ic: 按钮颜色
    :param ac: 鼠标放在按钮上，显示的颜色
    :param action: 响应事件，即点击这个按钮会调用的函数
    :returns:
    :rtype:

    """
    mouse = pygame.mouse.get_pos()
    click = pygame.mouse.get_pressed()


    if x+w > mouse[0] > x and y+h > mouse[1] > y:
        pygame.draw.rect(gameDisplay, ac, (x, y, w, h))

        if click[0] == 1 and action != None:
            action()
    else:
        pygame.draw.rect(gameDisplay, ic, (x, y, w, h))

    # button text
    smallText = pygame.font.Font(FONT, 20)
    textSurf, textRect = text_objects(msg, smallText)
    textRect.center = ((x + (w/2)), (y+(h/2)))

    # display
    gameDisplay.blit(textSurf, textRect)



def game_intro():
    """ 游戏开始界面
    :returns:
    :rtype:
    """
    intro = True
    while intro:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                quitgame()

        gameDisplay.fill(white) # 填充背景为白色
        largeText = pygame.font.Font(FONT, ALERT_FONT_SIZE)
        TextSurf, TextRect = text_objects(GAME_NAME, largeText)
        TextRect.center = (display_width/2, display_height/2)
        gameDisplay.blit(TextSurf, TextRect)

        button('Go', 150, 450, 100, 50, green, bright_green, game_loop)
        button('Quit', 550, 450, 100, 50, red, bright_red, quitgame)

        gameDisplay.blit(TextSurf, TextRect)

        pygame.display.update() # 所有的 blit 函数，在 update 后生效，发生更新，包括一些函数内调用的，比如 button 函数，因为 gameDisplay 是全局的
        clock.tick(100)         # 每秒100帧



def game_loop():
    """ 游戏主循环

    :returns:
    :rtype:

    """
    x = (display_width * 0.45)
    y = (display_height * 0.8)

    shit_startx = random.randrange(0, display_width-100)
    shit_starty = -600
    shit_speed = 10
    shit_width = 100
    shit_height = 100

    dodged = 0

    deltX = 0

    while True:

        # quit loop
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                quitgame()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    deltX = -10
                if event.key == pygame.K_RIGHT:
                    deltX = 10

            if event.type == pygame.KEYUP:
                if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                    deltX = 0

        # logic loop
        x += deltX
        gameDisplay.fill(white)

        shit(shit_startx, shit_starty)
        shit_starty += shit_speed

        doge(x, y)
        score_board(dodged)

        # boundary
        if x > display_width - doge_width or x < 0:
            crash()

        if shit_starty > display_height:
            shit_starty = 0 - shit_height
            shit_startx = random.randrange(0, display_width-100)
            dodged += 1
            shit_speed += 1
            shit_width += (dodged * 1.2)

        if y < shit_starty + shit_height:
            if x + doge_width > shit_startx and x < shit_startx + shit_width:
                crash()

        pygame.display.update()
        clock.tick(100)

if __name__ == '__main__':
    game_intro()
    game_loop()
