#pragma once
#include <Glut.h>
#include <iostream>
#include<vector>
#include <string>
using namespace std;
const int maxSIZE = 10;
const int newmatrixSIZE = 50;
const int newmatrixSIZEmin = 2;

template <class T>
class Graph {
public:
	vector<T> vertList;
	int Matrix[maxSIZE][maxSIZE];
	vector<int> labelList;//расстояния

public:
	Graph();
	~Graph();
	void Print();
	bool isEmpty();
	bool isFull();
	int GetVertPos(const T& vertex);
	int GetAmountVerts() { return this->vertList.size(); }//кол-во вершин
	int GetAmountEdges();
	int GetWeight(const T& vertex1, const T& vertex2);
	vector<T> GetNbrs(const T& vertex);
	void addVertex(const T&);
	void addEdge(const T& vertex1, const T& vertex2, int weight);
	void addEdgeIn();
	void FiilLabels(T& startVertex);
	int Dijkstra(T& startVert);
	bool allVisit(bool* mass);
	void drawGraph(int argc, char** argv);
	void Salesman();
};
struct ContextStruct {
	Graph<char> graph;
};
ContextStruct context;
struct point {
	int x, y;
	point(int x1, int y1) {
		x = x1;
		y = y1;
	}
};
vector<point> coords;



template<class T>
Graph<T>::Graph() { //конструктор, который инициализирует значения объектов класса Graph
//перебор строк и столбцов матрицы смежности и заполнение её нулями
	for (int i = 0; i < maxSIZE; ++i) {
		for (int j = 0; j < maxSIZE; ++j) {
			this->Matrix[i][j] = 0;
		}
	}
}

template<class T>
Graph<T>::~Graph() {

}

template<class T>
void Graph<T>::Print() {
	if (!this->isEmpty()) {
		cout << "Матрица смежности графа: " << endl;
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i) {
			cout << this->vertList[i] << " ";
			for (int j = 0; j < vertListSize; ++j) {
				cout << " " << this->Matrix[i][j] << "\t";
			}
			cout << endl;
		}
	}
	else {
		cout << "Граф пуст " << endl;
	}
}

template <class T>
int Graph<T>::GetVertPos(const T& vertex) {
	for (int i = 0; i < this->vertList.size(); ++i) {
		if (this->vertList[i] == vertex)
			return i;
	}
	return -1;
}
template<class T>
bool Graph<T>::isEmpty() {
	if (this->vertList.size() != 0)
		return false;
	else
		return true;
}
template<class T>
bool Graph<T>::isFull() {
	return (vertList.size() == maxSIZE);
}

template<class T>
int Graph<T>::GetAmountEdges() {
	int amount = 0; // обнуляем счетчик
	if (!this->IsEmpty()) { // проверяем, что граф не пуст
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i) {
			for (int j = 0; j < vertListSize; ++j) {
				if (this->adjMatrix[i][j] != 0) // находим рёбра////////////////////////////////////////изменить если что ==1
					amount += 1; // считаем количество рёбер
			}
		}
		return amount; // возвращаем количество рёбер
	}
	else
		return 0; // если граф пуст, возвращаем 0
}

template<class T>
int Graph<T>::GetWeight(const T& vertex1, const T& vertex2) {
	if (!this->isEmpty()) {
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		return Matrix[vertPos1][vertPos2];
	}
	return 0;
}

template<class T>
vector<T> Graph<T>::GetNbrs(const T& vertex) {
	std::vector<T> nbrsList; // создание списка соседей
	int pos = this->GetVertPos(vertex); /* вычисление позиции vertex в матрице смежности */
	if (pos != (-1)) { /* проверка, что vertex есть в матрице смежности */
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i) {
			if (this->Matrix[pos][i] != 0) /* вычисление соседей*/
				nbrsList.push_back(this->vertList[i]); /* запись соседей в вектор */
		}
	}
	return nbrsList; // возврат списка соседей
}

template<class T>
void Graph<T>::addVertex(const T& vertex) {
	if (!this->isFull()) {
		this->vertList.push_back(vertex);
	}
	else {
		cout << "Граф уже заполнен. Невозможно добавить новую вершину " << endl;
		return;
	}
}

template<class T>
void Graph<T>::addEdge(const T& vertex1, const T& vertex2, int weight) {
	if (this->GetVertPos(vertex1) != (-1) && this->GetVertPos(vertex2) != (-1)) {
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		if (this->Matrix[vertPos1][vertPos2] != 0) {
			cout << "Ребро между этими вершинами уже существует" << endl;
			return;
		}
		else {
			this->Matrix[vertPos1][vertPos2] = weight;
			for (int i = 0; i < vertList.size(); i++)
			{
				Matrix[i][i] = -444;
			}
		}
	}
	else {
		cout << "Обеих вершин (или одной из них) нет в графе " << endl;
		return;
	}
}
template<class T>
void Graph<T>::addEdgeIn() {
	char a, b;
	int s;
	for (int i = 1; i <= vertList.size(); i++) {
		a = i + '0';
		for (int j = 1; j <= vertList.size(); j++) {
			if (j != i) {
				if (i > j) {
					cout << " Введите расстояние между вершиной " << i << " и вершиной " << j << ": ";
					cin >> s;
					b = j + '0';
					addEdge(a, b, s); addEdge(b, a, s);
				}
			}
		}
	}
}

template<class T>
void Graph<T>::FiilLabels(T& startVertex) {
	int size = this->vertList.size();
	for (int i = 0; i < size; ++i) {
		labelList.push_back(1000000);
	}
	int p = GetVertPos(startVertex);
	labelList[p] = 0;
}

template<class T>
int Graph<T>::Dijkstra(T& startVert) {

	if (GetVertPos(startVert) != -1) {

		FiilLabels(startVert);
		int p = vertList.size();
		bool* visitVert = new bool[p];

		for (int i = 0; i < vertList.size(); i++) {
			visitVert[i] = false;
		}

		T temp = startVert;
		while (!allVisit(visitVert)) {

			int cnt = 0;
			int min = 1000000;
			vector<T> sosedi = GetNbrs(temp);

			for (int i = 0; i < sosedi.size(); i++) {
				int start = labelList[GetVertPos(temp)];//значение стартовой вершины
				int w = GetWeight(temp, sosedi[i]);//значение ребра
				int v = labelList[GetVertPos(sosedi[i])];//значение соседа
				if (start + w < v) {
					labelList[GetVertPos(sosedi[i])] = start + w;
				}
				if (labelList[GetVertPos(sosedi[i])] < min && !visitVert[GetVertPos(sosedi[i])]) {
					min = labelList[GetVertPos(sosedi[i])];
				}
				cnt++;
			}
			if (cnt == sosedi.size()) {
				visitVert[GetVertPos(temp)] = true;
			}
			for (int i = 0; i < sosedi.size(); i++) {
				if (labelList[GetVertPos(sosedi[i])] == min) {
					temp = sosedi[i];
				}
			}
		}
		for (int i = 0; i < vertList.size(); i++) {
			if (vertList[i] != startVert) {
				cout << "Кратчайшие расстояние от вершины " << startVert << " до вершины " << vertList[i] << " равно " << labelList[i] << endl;
			}
		}
		return 0;
	}
}

template<class T>
void Graph<T>::Salesman()
{
	int kp[newmatrixSIZE]; int msh[newmatrixSIZE][newmatrixSIZE];
	int evstr[newmatrixSIZE][newmatrixSIZE]; int evstb[newmatrixSIZE][newmatrixSIZE];
	int d[newmatrixSIZE][newmatrixSIZEmin]; int c[newmatrixSIZE];
	int NewMatrix_1[newmatrixSIZE][newmatrixSIZEmin];
	int NewMatrix_2[newmatrixSIZE][newmatrixSIZE];
	int minstr[newmatrixSIZE]; int minstlb[newmatrixSIZE];
	int NewMatrix_3[newmatrixSIZE][newmatrixSIZEmin]; int NewMatrix_4[newmatrixSIZE][newmatrixSIZEmin];
	for (int j = 0; j <= (vertList.size() - 1); j++) {
		NewMatrix_1[j][0] = j + 1;
		NewMatrix_1[j][1] = j + 1;
	}
	//Присвоение основной матрицы в дополнительную
	for (int i = 0; i <= (vertList.size() - 1); i++) {
		for (int j = 0; j <= (vertList.size() - 1); j++) {
			NewMatrix_2[i][j] = Matrix[i][j];
		}
	}
	for (int j = 0; j <= (vertList.size() - 2); j++) {
		NewMatrix_4[j][0] = 0;
		NewMatrix_4[j][1] = 0;
	}
	//Цикл задачи
	for (int h = 1; h <= 3; h++) {
		//Вычисление мин элементов строк
		cout << endl << " Шаг цикла № " << h << endl;
		for (int i = 0; i <= (vertList.size() - h); i++) {
			for (int j = 0; j <= (vertList.size() - h); j++) {
				if (NewMatrix_2[i][j] != -444) { 
					minstr[i] = NewMatrix_2[i][j]; 
					break; 
				}
			}
		}
		for (int i = 0; i <= (vertList.size() - h); i++) {
			for (int j = 0; j <= (vertList.size() - h); j++) {
				if (NewMatrix_2[i][j] != -444) {
					if (minstr[i] > NewMatrix_2[i][j])
						minstr[i] = NewMatrix_2[i][j];
				}
			}
		}
		cout << " Минимальные элементы в строках: ";
		for (int i = 0; i <= (vertList.size() - h); i++)
		{
			cout << minstr[i] << " ";
		}
		cout << endl;
		//Вычитание мин эл из строк
		for (int i = 0; i <= (vertList.size() - h); i++) {
			for (int j = 0; j <= (vertList.size() - h); j++) {
				if (NewMatrix_2[i][j] != -444)
					NewMatrix_2[i][j] = NewMatrix_2[i][j] - minstr[i];
			}
		}
		//Вычисление мин эл в столбцах
		for (int j = 0; j <= (vertList.size() - h); j++) {
			for (int i = 0; i <= (vertList.size() - h); i++) {
				if (NewMatrix_2[i][j] != -444) { 
					minstlb[j] = NewMatrix_2[i][j]; 
					break; 
				}
			}
		}
		for (int j = 0; j <= (vertList.size() - h); j++) {
			for (int i = 0; i <= (vertList.size() - h); i++) {
				if (NewMatrix_2[i][j] != -444) {
					if (minstlb[j] > NewMatrix_2[i][j])
						minstlb[j] = NewMatrix_2[i][j];
				}
			}
		}
		cout << " Минимальные элементы в столбцах: ";
		for (int i = 0; i <= (vertList.size() - h); i++)
		{
			cout << minstlb[i] << " ";
		}
		cout << endl;
		for (int j = 0; j <= (vertList.size() - h); j++) {
			for (int i = 0; i <= (vertList.size() - h); i++) {
				if (NewMatrix_2[i][j] != -444)
					NewMatrix_2[i][j] = NewMatrix_2[i][j] - minstlb[j];
			}
		}
		//Вывод матрицы после вычитания
		cout << " Матрица, после вычитания: "; 
		for (int i = 0; i <= (vertList.size() - h); i++)
		{
			cout << "\n";
			for (int j = 0; j <= (vertList.size() - h); j++)
			{
				cout << "\t" << NewMatrix_2[i][j];
			}
		}
		cout << endl;
		//переход на последнем шаге
		if (h == vertList.size() - 1)goto e;
		//Заполнение -111 (М)
		for (int i = 0; i <= (vertList.size() - h); i++) {
			for (int j = 0; j <= (vertList.size() - h); j++) {
				msh[i][j] = -111;
			}
		}
		//Вычисление оценок у нулей
		for (int i = 0; i <= (vertList.size() - h); i++) {
			for (int j = 0; j <= (vertList.size() - h); j++) {
				if (NewMatrix_2[i][j] == 0) {
					//оценки по строкам
					for (int a = 0; a <= (vertList.size() - h); a++) {
						if (NewMatrix_2[i][a] != -444) {
							if (a != j) {
								evstr[i][j] = NewMatrix_2[i][a]; goto A;
							}
						}
					}
				A:
					for (int a = 0; a <= (vertList.size() - h); a++) {
						if (NewMatrix_2[i][a] != -444) {
							if (a != j) {
								if (evstr[i][j] > NewMatrix_2[i][a])
									evstr[i][j] = NewMatrix_2[i][a];
							}
						}
					}
					//оценки по столбцам
					for (int b = 0; b <= (vertList.size() - h); b++) {
						if (NewMatrix_2[b][j] != -444) {
							if (b != i) {
								evstb[i][j] = NewMatrix_2[b][j]; goto B;
							}
						}
					}
				B:
					for (int b = 0; b <= (vertList.size() - h); b++) {
						if (NewMatrix_2[b][j] != -444) {
							if (b != i) {
								if (evstb[i][j] > NewMatrix_2[b][j])
									evstb[i][j] = NewMatrix_2[b][j];
							}
						}
					}
					//присвоение оценок
					msh[i][j] = evstr[i][j] + evstb[i][j];
				}
			}
		}
		//Печать оценок
		cout << " Печать оценок: ";
		for (int i = 0; i <= (vertList.size() - h); i++)
		{
			cout << "\n";
			for (int j = 0; j <= (vertList.size() - h); j++)
			{
				cout << "\t" << msh[i][j];
			}
		}
		cout << endl;
		//Нахождение макс оценки
		for (int i = 0; i <= (vertList.size() - h); i++) {
			for (int j = 0; j <= (vertList.size() - h); j++) {
				if (msh[i][j] != -111) {
					c[h - 1] = msh[i][j]; 
					d[h - 1][0] = i; 
					d[h - 1][1] = j; 
					goto C;
				}
			}
		}
	C:
		for (int i = 0; i <= (vertList.size() - h); i++) {
			for (int j = 0; j <= (vertList.size() - h); j++) {
				if (msh[i][j] != 111) {
					if (msh[i][j] > c[h - 1]) {
						c[h - 1] = msh[i][j]; 
						d[h - 1][0] = i; 
						d[h - 1][1] = j;
					}
				}
			}
		}
		//Присвоение м3 знач м1
		NewMatrix_3[h - 1][0] = NewMatrix_1[d[h - 1][0]][0];
		NewMatrix_3[h - 1][1] = NewMatrix_1[d[h - 1][1]][1];
		//урезание строки
		for (int i = 0; i <= (vertList.size() - h - 1); i++) {
			if (i == d[h - 1][0]) {
				for (int e = i; e <= (vertList.size() - h - 1); e++) {
					for (int f = 0; f <= (vertList.size() - h); f++) {
						NewMatrix_2[e][f] = NewMatrix_2[e + 1][f];
					}
				}
			}
		}
		cout << " Матрица, после урезания по строке: ";
		for (int i = 0; i <= (vertList.size() - h - 1); i++)
		{
			cout << "\n";
			for (int j = 0; j <= (vertList.size() - h); j++)
			{
				cout << "\t" << NewMatrix_2[i][j];
			}
		}
		cout << endl;
		//урезание столбца
		for (int j = 0; j <= (vertList.size() - h - 1); j++) {
			if (j == d[h - 1][1]) {
				for (int e = j; e <= (vertList.size() - h - 1); e++) {
					for (int f = 0; f <= (vertList.size() - h - 1); f++) {
						NewMatrix_2[f][e] = NewMatrix_2[f][e + 1];
					}
				}
			}
		}
		cout << " Матрица, после урезания по столбцу: ";
		for (int i = 0; i <= (vertList.size() - h - 1); i++)
		{
			cout << "\n";
			for (int j = 0; j <= (vertList.size() - h - 1); j++)
			{
				cout << "\t" << NewMatrix_2[i][j];
			}
		}
		cout << endl;
		
		//присвоение м1 номеров стрк и стб
		for (int i = d[h - 1][0]; i <= (vertList.size() - h - 1); i++)
			NewMatrix_1[i][0] = NewMatrix_1[i + 1][0];
		for (int i = d[h - 1][1]; i <= (vertList.size() - h - 1); i++)
			NewMatrix_1[i][1] = NewMatrix_1[i + 1][1];

		//присвоение -444
		for (int i = 0; i <= (vertList.size() - h - 1); i++) {
			for (int j = 0; j <= (vertList.size() - h - 1); j++) {
				if (NewMatrix_3[h - 1][0] == NewMatrix_1[j][1] && NewMatrix_3[h - 1][1] == NewMatrix_1[i][0]) {
					NewMatrix_2[i][j] = -444;
				}
			}
		}
		//присоед дуги в нач
		for (int i = 0; i < (h - 1); i++) {
			if (NewMatrix_3[h - 1][0] == NewMatrix_3[i][1]) {
				NewMatrix_4[h - 1][0] = NewMatrix_3[i][0]; 
				NewMatrix_4[h - 1][1] = NewMatrix_3[h - 1][1];
			}
		}
		//присоед дуги в кон
	    for (int i = 0; i < (h - 1); i++) {
			if (NewMatrix_3[h - 1][1] == NewMatrix_3[i][0]) {
				if (NewMatrix_4[h - 1][0] == 0) {
					NewMatrix_4[h - 1][0] = NewMatrix_3[h - 1][0];
					NewMatrix_4[h - 1][1] = NewMatrix_3[i][1];
				}
				else NewMatrix_4[h - 1][1] = NewMatrix_3[i][1];
			}
		}
		//присоед дуги
		for (int i = 0; i < h - 1; i++) {
			if (NewMatrix_4[i][0] != 0) {
				if (NewMatrix_3[h - 1][0] == NewMatrix_4[i][1]) {
					NewMatrix_4[h - 1][0] = NewMatrix_4[i][0];
				}
			}
		}
		for (int i = 0; i < h - 1; i++) {
			if (NewMatrix_4[i][0] != 0) {
				if (NewMatrix_3[h - 1][1] == NewMatrix_4[i][0]) {
					NewMatrix_4[h - 1][1] = NewMatrix_4[i][1];
				}
			}
		}
		//присвоение -444
		for (int i = 0; i <= (vertList.size() - h - 1); i++) {
			for (int j = 0; j <= (vertList.size() - h - 1); j++) {
				if (NewMatrix_4[h - 1][0] == NewMatrix_1[j][1] && NewMatrix_4[h - 1][1] == NewMatrix_1[i][0]) {
					NewMatrix_2[i][j] = -444;
				}
			}
		}
	}
e:
	//присвоение двух посл строк в массив 3
	int l = 2;
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 1; j++) {
			if (NewMatrix_2[i][j] == 0) {
				NewMatrix_3[vertList.size() - l][0] = NewMatrix_1[i][0]; 
				NewMatrix_3[vertList.size() - l][1] = NewMatrix_1[j][1]; 
				l = l - 1;
			}
		}
	}

	//расчет пути
	int s = 0;
	for (int i = 0; i <= vertList.size() - 1; i++) {
		s = s + Matrix[NewMatrix_3[i][0] - 1][NewMatrix_3[i][1] - 1];
	}
	cout << " Кратчайший путь равен: " << s << endl;
	for (int i = 0; i <= vertList.size() - 1; i++) {
		cout << " Отрезок: " << Matrix[NewMatrix_3[i][0] - 1][NewMatrix_3[i][1] - 1] << endl;
	}

}

template <class T>
bool Graph<T>::allVisit(bool* mass) {
	for (int i = 0; i < labelList.size(); i++) {
		if (labelList[i] == 1000000) {
			return false;
		}
	}
	return true;
}
void Coords()
{
	point p1(500, 100), p2(100, 100), p3(500, 350), p4(100, 500), p5(300, 600), p6(500, 650);
	coords.push_back(p1);
	coords.push_back(p2);
	coords.push_back(p3);
	coords.push_back(p4);
	coords.push_back(p5);
	coords.push_back(p6);
}

void drawCircle(int x1, int y1, int R) {

	float x, y;

	glColor3f(0.81f, 0.81f, 0.81f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);
	for (int j = 1; j <= R; j++) {
		for (int t = 0; t <= 360; t++) {
			x = j * sin(t) + x1;
			y = j * cos(t) + y1;
			glVertex2f(x, y);
		}
	}
	glEnd();
}
static void drawLine(int x1, int y1, int x2, int y2) {
	double u = atan2((x2 - x1), (y2 - y1));
	u += 1.576;
	glColor3f(0.81f, 0.81f, 0.81f);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
}
void drawText(string text, int text_x, int text_y, int R) {
	void* font = GLUT_STROKE_ROMAN;
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(text_x - R / 2, text_y - R / 2, 0.0);

	char* s1 = new char[text.size() + 1];
	for (int i = 0; i < text.size(); i++) {
		s1[i] = text.at(i);
	}

	char* c;
	int max_char_width = 0;
	int char_width = 0;
	for (c = s1; *c != '\0'; c++) {
		char_width = glutStrokeWidth(font, *c);
		if (max_char_width < char_width) max_char_width = char_width;
	}
	float expand_x = (float)R / (float)(100);
	float expand_y = (float)R / (float)(100);
	glScalef(expand_x, expand_y, 1.0);
	for (c = s1; *c != '\0'; c++)
		glutStrokeCharacter(font, *c);
	glPopMatrix();
}
void drawWeight(int x1, int y1, int x2, int y2, int key) {
	int x = (x1 + x2) / 2;
	int y = (y1 + y2) / 2;
	glColor3f(1, 1, 1);
	drawText(to_string(key), x, y, 30);
}

template <class T>
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0f);
	for (int i = 0; i < context.graph.vertList.size(); ++i) {
		for (int j = 0; j < context.graph.vertList.size(); ++j) {
			if (context.graph.Matrix[i][j]) {
				drawLine(coords[i].y, coords[i].x, coords[j].y, coords[j].x);
			}
		}
	}

	for (int i = 0; i < context.graph.vertList.size(); ++i) {
		for (int j = 0; j < context.graph.vertList.size(); ++j) {
			if (context.graph.Matrix[i][j]) {
				if (context.graph.Matrix[i][j] != -444) {
				drawWeight(coords[i].y, coords[i].x, coords[j].y, coords[j].x, context.graph.Matrix[i][j]);
				}
			}
		}
	}


	for (int i = 0; i < context.graph.vertList.size(); i++) {
		drawCircle(coords[i].y, coords[i].x, 50);
		char* c = new char[1];
		c[0] = (char)(context.graph.vertList[i]);
		c[1] = 0;
		string s(c);
		drawText(s, coords[i].y, coords[i].x, 50);
	}

	glutSwapBuffers();

}
static void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLsizei)w, 0, (GLsizei)h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutPostRedisplay();
}

template <class T>
void Graph<T>::drawGraph(int argc, char** argv) {

	context.graph = *this;
	Coords();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Graph");

	// регистрация обратных вызовов
	glutDisplayFunc(display<T>);
	glutReshapeFunc(reshape);

	// Основной цикл GLUT
	glutMainLoop();

}