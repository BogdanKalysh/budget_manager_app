#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <QString>

namespace models{
    const QString USERS = "users";
    const QString CATEGORY = "category";
    const QString TRANSACTION = "transaction";

    const QString ID = "id";
    const QString NAME = "name";
    const QString TYPE = "type";
    const QString COLOR = "color";
    const QString AMOUNT = "amount";
    const QString DESCRIPTION = "description";
    const QString CATEGORY_ID = "category_id";
    const QString DATE = "date";
    const QString MAIL = "mail";
    const QString PASSWORD = "password";
    const QString CATEGORYNAME = "category_name";
    const QString INCOME = "income";
    const QString EXPENSE = "expense";
    const QString USER_ID = "user_id";
    const QString START_DATE = "start_date";
    const QString END_DATE = "end_date";
}

namespace urls{
    const QString USERURL = "http://localhost:5000/user";
    const QString CATEGORYURL = "http://localhost:5000/category";
    const QString TRANSACTIONURL = "http://localhost:5000/transaction";

    const QString CONTENTTYPE = "Content-Type";
    const QString APPLICATIONJSON = "application/json";
}

namespace resourcepath{
    const QString USERICONPATH = ":/new/img/user_icon.png";
}

namespace colors{
    const QString PIECHARTCOLOR = "#528bba";
    const QString WHITE = "#ffffff";
}

namespace messagebox{
    const QString INFO = "Інфо";
    const QString FAILED = "Помилка";
    const QString WRONGMAILPASS = "Неправильний Email чи пароль";
    const QString CHECK = "Перевірка";
    const QString FILLIN = "Будь ласка, заповніть усі поля";
    const QString PASSDONTMATCH = "Паролі не збігаються";
    const QString NOTVALIDMAILPASS = "Не валідний логін чи пароль (Пароль має містити щонайменш 8 символів, хоча б 1 букву та 1 цифру)";
    const QString ERRCREATEUSER = "Неможливо створити користувача";
    const QString ERROR = "Error: ";
    const QString WRONGNEWPASS = "Введено некоректний новий пароль";
    const QString WRONGOLDPASS = "Неправильний старий пароль";
    const QString NOCONNECTION = "Немає зв'язку з сервером";
    const QString ENTERNAME = "Будь ласка, введіть ім'я";
    const QString WRONGMAIL = "Введено некоректну пошту";
    const QString CHANGESSAVED = "Зміни збережено";
    const QString MAILOCCUPIED = "Дана пошта зайнята";
    const QString CATEGORYDELETED = "Категорію видалено";
}

#endif // CONSTANTS_H
