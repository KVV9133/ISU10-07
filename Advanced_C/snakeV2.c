#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses/ncurses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>
#define CONTROLS 2
#define PLAYERS 2
#define MIN_Y  2
int g_snakeColors[PLAYERS] = {1, 1}; // цвет змей, зеленый
int g_foodColor = 4; // цвет зерен
double DELAY=0.1;
enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=3, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10, SEED_NUMBER = 3};

int g_gameMode = 1;    // 1 или 2 игрока
int g_difficulty = 2;  // 1 - Easy, 2 - Normal, 3 - Hard
int g_snakeColor = 1;  // 1 - Green, 2 - Red, 3 - Yellow

// Здесь храним коды управления змейкой
struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
}control_buttons;

//                                                  //
struct control_buttons default_controls[CONTROLS] = {{KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT},{'S','W','A','D'}}; 

/*
 Голова змейки содержит в себе
 x,y - координаты текущей позиции
 direction - направление движения
 tsize - размер хвоста
 *tail -  ссылка на хвост
 */
typedef struct snake_t
{
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail_t *tail;
    struct control_buttons controls;
    int color;
    int score;
} snake_t;

/*
 Хвост это массив состоящий из координат x,y
 */
typedef struct tail_t
{
    int x;
    int y;
} tail_t;

void initTail(struct tail_t t[], size_t size)
{
    struct tail_t init_t={0,0};
    for(size_t i=0; i<size; i++)
    {
        t[i]=init_t;
    }
}

struct food
{
    int x;
    int y;
    time_t put_time;
    char point;
    uint8_t enable;
} food[MAX_FOOD_SIZE];

void initFood(struct food f[], size_t size)
{
    struct food init = {0, 0, 0, 0, 0};
    for (size_t i = 0; i < size; i++)
    {
        f[i] = init;
    }
}


void putFoodSeed(struct food *fp)
{
    int max_x = 0, max_y = 0;
    char spoint[2] = {0};
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(fp->y, fp->x, " ");
    fp->x = rand() % (max_x - 1);
    fp->y = rand() % (max_y - 2) + 1; 
    fp->put_time = time(NULL);
    fp->point = '$';
    fp->enable = 1;
    spoint[0] = fp->point;
    mvprintw(fp->y, fp->x, "%s", spoint);
    attron(COLOR_PAIR(g_foodColor));
    mvprintw(fp->y, fp->x, "%s", spoint);
    attroff(COLOR_PAIR(g_foodColor));
}

void putFood(struct food f[], size_t number_seeds)
{
    for (size_t i = 0; i < number_seeds; i++)
    {
        putFoodSeed(&f[i]);
    }
}

void refreshFood(struct food f[], int nfood)
{
    for (size_t i = 0; i < nfood; i++)
    {
        if (f[i].put_time)
        {
            if (!f[i].enable || (time(NULL) - f[i].put_time) > FOOD_EXPIRE_SECONDS)
            {
                putFoodSeed(&f[i]);
            }
        }
    }
}

void initHead(struct snake_t *head, int x, int y)
{
    head->x = x;
    head->y = y;
    head->direction = RIGHT;
}

void initSnake(snake_t *head[], size_t size, int x, int y,int i)
{
    head[i] = (snake_t*)malloc(sizeof(snake_t));
    tail_t* tail = (tail_t*)malloc(MAX_TAIL_SIZE * sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head[i], x, y);
    head[i]->tail = tail; 
    head[i]->tsize = size + 1;
    // Пример: назначаем разное управление для первой и второй змейки
    if (i == 0)
        head[i]->controls = default_controls[0];
    else
        head[i]->controls = default_controls[1];
    head[i]->color = g_snakeColors[i];
    head[i]->score = 0;
}

/*

 Движение головы с учетом текущего направления движения
 */
void go(struct snake_t *head)
{
    char ch = '@';
    int max_x = 0, max_y = 0;
    getmaxyx(stdscr, max_y, max_x);  // macro - размер терминала
    mvprintw(head->y, head->x, " "); // очищаем один символ
    switch (head->direction)
    {
    case LEFT:
        if (head->x <= 0) // Циклическое движение, чтобы не уходить за пределы экрана
            head->x = max_x;
        mvprintw(head->y, --(head->x), "%c", ch);
        break;
    case RIGHT:
        if (head->x >= max_x)
            head->x = 0;
        mvprintw(head->y, ++(head->x), "%c", ch);
        break;
    case UP:
        if (head->y <= 0)
            head->y = max_y;
        mvprintw(--(head->y), head->x, "%c", ch);
        break;
    case DOWN:
        if (head->y >= max_y)
            head->y = 0;
        mvprintw(++(head->y), head->x, "%c", ch);
        break;
    default:
        break;
    }
    attron(COLOR_PAIR(head->color));
    mvprintw(head->y, head->x, "%c", ch);
    attroff(COLOR_PAIR(head->color));
    refresh();
}

int upper(int ch) 
{
    if (ch >= 'a' && ch <= 'z')
        return ch - ('a' - 'A');
    return ch;
}


void changeDirection(snake_t *snake, const int32_t key) 
{
    if ((key == snake->controls.down || upper(key) == snake->controls.down) && snake->direction != UP)
        snake->direction = DOWN;
    else if ((key == snake->controls.up || upper(key) == snake->controls.up) && snake->direction != DOWN)
        snake->direction = UP;
    else if ((key == snake->controls.right || upper(key) == snake->controls.right) && snake->direction != LEFT)
        snake->direction = RIGHT;
    else if ((key == snake->controls.left || upper(key) == snake->controls.left) && snake->direction != RIGHT)
        snake->direction = LEFT;
}
//void changeDirection(struct snake_t* snake, const int32_t key)
//{
    //if (key == snake->controls.down)
        //snake->direction = DOWN;
    //else if (key == snake->controls.up)
        //snake->direction = UP;
    //else if (key == snake->controls.right)
        //snake->direction = RIGHT;
    //else if (key == snake->controls.left)
        //snake->direction = LEFT;
//}

//int checkDirection(snake_t* snake, int32_t key) {
    //if (snake->direction == RIGHT && key == snake->controls.left)
        //return 0;
    //if (snake->direction == LEFT && key == snake->controls.right)
        //return 0;
    //if (snake->direction == UP && key == snake->controls.down)
        //return 0;
    //if (snake->direction == DOWN && key == snake->controls.up)
        //return 0;
    //return 1;
//}
/*
 Движение хвоста с учетом движения головы
 */
void goTail(struct snake_t *head)
{
    char ch = '*';
    mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x, " ");
    for(size_t i = head->tsize-1; i>0; i--)
    {
        head->tail[i] = head->tail[i-1];
        attron(COLOR_PAIR(head->color));
        if( head->tail[i].y || head->tail[i].x)
        {
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
            attroff(COLOR_PAIR(head->color));
         }
    }
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
}
//
 _Bool haveEat(struct snake_t *head, struct food f[])
{
	for(size_t i=0; i<MAX_FOOD_SIZE; i++)
	{
		if(head->x == f[i].x && head->y == f[i].y)
		{	
			f[i].enable = 0; 
			return 1;
		}	
	}
	return 0;
}

void addTail(struct snake_t *head)
{
    head->tail[head->tsize].x = head->tail[head->tsize - 1].x;
    head->tail[head->tsize].y = head->tail[head->tsize - 1].y;
    head->tsize++;
}

int isCrush(snake_t* snake) 
{

    for (size_t i = 1; i < snake->tsize; i++) {
        if (snake->x == snake->tail[i].x && snake->y == snake->tail[i].y) 
        {	
			mvprintw(0, 0, "Collision!");
			refresh();

            return 1;  
        }
    }
    return 0;
}
int checkDirection(snake_t* snake, int32_t key)
{
    return 1;
}

void reapirSeed(struct food f[],size_t nfood, struct snake_t *head)
{
	for(size_t i=0;i<head->tsize;i++)
	{
		for(size_t j=0;j<nfood;j++)
		{
		if (f[j].enable && (head->tail[i].x == f[j].x) && (head->tail[i].y == f[j].y)) 
			putFoodSeed(&f[j]);
		}
	}
	for(size_t i=0;i<nfood;i++)
	{
		for(size_t j=0;j<nfood;j++)
		{
		if (i != j && f[i].enable && f[j].enable &&
                (f[i].x == f[j].x) && (f[i].y == f[j].y))
                putFoodSeed(&f[j]);
		}
	}
	
}

void update(struct snake_t *head, struct food f[], const int32_t
key){

    changeDirection(head, key);
    go(head);
    if (haveEat(head, f)) 
    {
        addTail(head);
        head->score+=10;
    } 
    else 
    {
        goTail(head);
    }
	 refreshFood(food, SEED_NUMBER);//
	 reapirSeed(food, SEED_NUMBER, head);
	 clock_t begin = clock();
	 while ((double)(clock() - begin)/CLOCKS_PER_SEC<DELAY)
	 {}
}

void startMenu() 
{
    int ch;
    int local_gameMode = 1;
    int local_difficulty = 2;
    double local_delay = 0.1;
    
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
        init_pair(4, COLOR_BLUE, COLOR_BLACK);     
		init_pair(5, COLOR_MAGENTA, COLOR_BLACK);   
		init_pair(6, COLOR_CYAN, COLOR_BLACK); 
    }
    
    clear();
    mvprintw(2, 10, "Welcome to Snake Game!");
    mvprintw(4, 10, "Select game mode:");
    mvprintw(6, 12, "1. 1 Player");
    mvprintw(7, 12, "2. 2 Players");
    mvprintw(9, 10, "Press 1 or 2 to select mode.");
    refresh();
    while ((ch = getch()) == ERR) { }
    local_gameMode = (ch == '2') ? 2 : 1;
    
    clear();
    mvprintw(2, 10, "Select difficulty:");
    mvprintw(4, 12, "1. Easy");
    mvprintw(5, 12, "2. Normal");
    mvprintw(6, 12, "3. Hard");
    mvprintw(8, 10, "Press 1, 2 or 3 to select difficulty.");
    refresh();
    while ((ch = getch()) == ERR) { }
    if (ch == '1') {
        local_difficulty = 1;
        local_delay = 0.2;
    } else if (ch == '3') {
        local_difficulty = 3;
        local_delay = 0.05;
    } else {
        local_difficulty = 2;
        local_delay = 0.1;
    }
    
    if (local_gameMode == 1) {
        // Если один игрок – выбираем один цвет:
        clear();
        mvprintw(2, 10, "Select snake color:");
        mvprintw(4, 12, "1. Green");
        mvprintw(5, 12, "2. Red");
        mvprintw(6, 12, "3. Yellow");
        mvprintw(8, 10, "Press 1, 2 or 3 to select color.");
        refresh();
        int local_snakeColor = 1;
        while ((ch = getch()) == ERR) { }
        if (ch == '2')
            local_snakeColor = 2;
        else if (ch == '3')
            local_snakeColor = 3;
        else
            local_snakeColor = 1;
        g_snakeColors[0] = local_snakeColor;
    } else {
        // Если два игрока – спрашиваем цвета отдельно
        int local_snakeColor1 = 1, local_snakeColor2 = 1;
        clear();
        mvprintw(2, 10, "Select color for Snake 1:");
        mvprintw(4, 12, "1. Green");
        mvprintw(5, 12, "2. Red");
        mvprintw(6, 12, "3. Yellow");
        refresh();
        while ((ch = getch()) == ERR) { }
        if (ch == '2')
            local_snakeColor1 = 2;
        else if (ch == '3')
            local_snakeColor1 = 3;
        else
            local_snakeColor1 = 1;
        
        clear();
        mvprintw(2, 10, "Select color for Snake 2:");
        mvprintw(4, 12, "1. Green");
        mvprintw(5, 12, "2. Red");
        mvprintw(6, 12, "3. Yellow");
        refresh();
        while ((ch = getch()) == ERR) { }
        if (ch == '2')
            local_snakeColor2 = 2;
        else if (ch == '3')
            local_snakeColor2 = 3;
        else
            local_snakeColor2 = 1;
        
        g_snakeColors[0] = local_snakeColor1;
        g_snakeColors[1] = local_snakeColor2;
    }
    
    clear();
    mvprintw(2, 10, "Select food color:");
    mvprintw(4, 12, "4. Blue");
    mvprintw(5, 12, "5. Magenta");
    mvprintw(6, 12, "6. Cyan");
    mvprintw(8, 10, "Press 4, 5, or 6 to select color.");
    refresh();
    while ((ch = getch()) == ERR) { }
    if (ch == '4')
        g_foodColor = 4;
    else if (ch == '5')
        g_foodColor = 5;
    else
        g_foodColor = 6;

    // Сохраняем выбранные настройки
    g_gameMode = local_gameMode;
    g_difficulty = local_difficulty;
    DELAY = local_delay;
    
    // Выводим итог
    clear();
    mvprintw(2, 10, "Game Mode: %s", (g_gameMode == 1) ? "1 Player" : "2 Players");
    if (g_difficulty == 1)
        mvprintw(3, 10, "Difficulty: Easy");
    else if (g_difficulty == 2)
        mvprintw(3, 10, "Difficulty: Normal");
    else
        mvprintw(3, 10, "Difficulty: Hard");
    
    if (g_gameMode == 1) {
        // Вывод цвета змейки
        mvprintw(4, 10, "Snake Color: %s",
            (g_snakeColors[0] == 1) ? "Green" : 
            (g_snakeColors[0] == 2) ? "Red" : "Yellow"
        );
    } else {
        mvprintw(4, 10, "Snake 1 Color: %s", 
            (g_snakeColors[0] == 1) ? "Green" :
            (g_snakeColors[0] == 2) ? "Red" : "Yellow"
        );
        mvprintw(5, 10, "Snake 2 Color: %s", 
            (g_snakeColors[1] == 1) ? "Green" :
            (g_snakeColors[1] == 2) ? "Red" : "Yellow"
        );
    }
    
    // Вывод цвета еды
    const char* foodName = (g_foodColor == 4) ? "Blue" :
                           (g_foodColor == 5) ? "Magenta" : "Cyan";
    mvprintw(7, 10, "Food Color: %s", foodName);
    
    mvprintw(9, 10, "Press any key to start the game...");
    refresh();
    getch();
    clear();
    refresh();
}
int main()
{	

	int game_over=0;
    //initSnake(snake,START_TAIL_SIZE,10,10);
    initscr();
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    raw();                // Откдючаем line buffering
    noecho();            // Отключаем echo() режим при вызове getch
    curs_set(FALSE);    //Отключаем курсор
    startMenu();
    snake_t* snake[PLAYERS];
	for (int i = 0; i < PLAYERS; i++)
        initSnake(snake, START_TAIL_SIZE, 10 + i * 10, 10 + i * 10, i);
    int players = g_gameMode;
    mvprintw(0, 0," Use arrows for control. Press 'F10' for EXIT");
    timeout(0);    //Отключаем таймаут после нажатия клавиши в цикле
    initFood(food,MAX_FOOD_SIZE);
    putFood(food,SEED_NUMBER);
    int key_pressed=0;
    while( key_pressed != STOP_GAME )
    {
        key_pressed = getch(); // Считываем клавишу
        for(int i=0;i<players;i++)
        {
			update(snake[i],food,key_pressed);
			//go(snake);
			//goTail(snake);
			//timeout(100); // Задержка при отрисовке
			//if (haveEat(snake[i],food))
			//{
				//addTail(snake[i]);
			//}
			if (isCrush(snake[i])) 
			{
				game_over = 1;
				break;
			}
			//changeDirection(snake[i], key_pressed);
		}
		if(game_over)
			break;
		 if (players == 1) 
				mvprintw(LINES - 1, 0, "Score: %d  ", snake[0]->score);
		 else 
			mvprintw(LINES - 1, 0, "Score P1: %d   Score P2: %d  ", snake[0]->score, snake[1]->score);
    
	}
		if (game_over) 
		{
		clear(); 
		mvprintw(LINES / 2, (COLS - 9) / 2, "Game Over!");
		refresh();       
		sleep(10);    
	}
    for (int i = 0; i < players; i++) 
    {
        free(snake[i]->tail);
        free(snake[i]);
    }
    endwin(); // Завершаем режим curses mod
    return 0;
}
