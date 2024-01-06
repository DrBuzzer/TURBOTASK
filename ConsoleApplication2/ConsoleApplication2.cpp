#include <iostream>
#include <string>

using namespace std;
const int MAX_TASKS = 100;

// Структура для хранения задачи
struct Task {
    std::string title;
    int priority;
    std::string description;
    std::string dateTime;
};

// Функция для добавления задачи
void addTask(Task taskList[], int& taskCount) {
    if (taskCount < MAX_TASKS) {
        Task newTask;
        std::cout << "Введите название задачи: ";
        std::cin.ignore();
        std::getline(std::cin, newTask.title);
        std::cout << "Введите приоритет задачи (целое число): ";
        std::cin >> newTask.priority;
        std::cout << "Введите описание задачи: ";
        std::cin.ignore();
        std::getline(std::cin, newTask.description);
        std::cout << "Введите дату и время исполнения задачи (в формате ДД.ММ.ГГГГ ЧЧ:ММ): ";
        std::cin >> newTask.dateTime;

        taskList[taskCount++] = newTask;
        std::cout << "Задача добавлена." << std::endl;
    }
    else {
        std::cout << "Достигнут максимальный лимит задач." << std::endl;
    }
}

// Функция для удаления задачи
void removeTask(Task taskList[], int& taskCount) {
    if (taskCount > 0) {
        std::cout << "Выберите номер задачи для удаления: ";
        int taskNumber;
        std::cin >> taskNumber;

        if (taskNumber >= 1 && taskNumber <= taskCount) {
            for (int i = taskNumber - 1; i < taskCount - 1; ++i) {
                taskList[i] = taskList[i + 1];
            }
            taskCount--;
            std::cout << "Задача удалена." << std::endl;
        }
        else {
            std::cout << "Неверный номер задачи." << std::endl;
        }
    }
    else {
        std::cout << "Список дел пуст." << std::endl;
    }
}

// Функция для отображения списка задач
void displayTasks(const Task taskList[], int taskCount) {
    if (taskCount > 0) {
        for (int i = 0; i < taskCount; ++i) {
            std::cout << "Задача " << i + 1 << ":" << std::endl;
            std::cout << "Название: " << taskList[i].title << std::endl;
            std::cout << "Приоритет: " << taskList[i].priority << std::endl;
            std::cout << "Описание: " << taskList[i].description << std::endl;
            std::cout << "Дата и время исполнения: " << taskList[i].dateTime << std::endl;
            std::cout << "-------------------------" << std::endl;
        }
    }
    else {
        std::cout << "Список дел пуст." << std::endl;
    }
}

int main() {
    // Устанавливаем локаль для корректного отображения кириллицы
    setlocale(LC_ALL, "RUS");
    Task taskList[MAX_TASKS];
    int taskCount = 0;

    int choice;
    do {
        std::cout << "\nМеню:" << std::endl;
        std::cout << "1. Добавить задачу" << std::endl;
        std::cout << "2. Удалить задачу" << std::endl;
        std::cout << "3. Отобразить список задач" << std::endl;
        std::cout << "4. Выйти" << std::endl;
        std::cout << "Выберите действие: ";

        if (!(std::cin >> choice)) {
            std::cout << "Ошибка ввода. Выход из программы." << std::endl;
            break;
        }

        switch (choice) {
        case 1:
            addTask(taskList, taskCount);
            break;
        case 2:
            removeTask(taskList, taskCount);
            break;
        case 3:
            displayTasks(taskList, taskCount);
            break;
        case 4:
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Повторите попытку." << std::endl;
            std::cin.clear();  // Очищаем флаг ошибки ввода
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Очищаем буфер ввода
        }

    } while (choice != 4);

    return 0;
}
