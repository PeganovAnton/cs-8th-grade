#include "iconizedlineedit.h"

#include <QDebug>
#include <QEvent>
#include <QLabel>
#include <QStyle>


//Конструктор класса
IconizedLineEdit::IconizedLineEdit(QWidget *parent) :
    QLineEdit(parent), mIconVisibilityMode(IconAlwaysVisible)
{
    mIconLabel = new QLabel(this); //Создаём метку для того, чтобы показать пиктограмму
    //Обработка изменения текста в поле
    connect(
                this,
                SIGNAL(textChanged(QString)),
                this,
                SLOT(slotTextChanged(QString)),
                Qt::UniqueConnection
                );
    layout = new QHBoxLayout;
    setLayout(layout);
    layout->addWidget(mIconLabel, 0, Qt::AlignRight);
    layout->setContentsMargins(0, 0, 0, 0);
    mIconLabel->setFixedSize(21, 21);
    mIconLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mIconLabel->installEventFilter(this);
}


//Возвращает true, если пиктограмма видима
bool IconizedLineEdit::isIconVisible() const
{
    return mIconLabel->isVisible();
}


//Устанавливает пиктограмму
void IconizedLineEdit::setIconPixmap(const QPixmap &pPixmap)
{
    //Устанавливаем пиктограмму для метки
    mIconLabel->setPixmap(pPixmap);
    //Обновляем позицию и размеры
    updateIconPositionAndSize();
}


//Устанавливаем подсказку для пиктограммы
void IconizedLineEdit::setIconTooltip(const QString &pToolTip)
{
    //Подсказка будет видимой после наведения курсора на метку с пиктограммой
    mIconLabel->setToolTip(pToolTip);
}


void IconizedLineEdit::updateIconPositionAndSize()
{
    setLayout(layout);
    //Обновить размер пиктограммы
    mIconLabel->setScaledContents(true);
//    mIconLabel->setFixedSize(height(), height());
//    //Обновить размещение пиктограммы
//    QSize lSize = mIconLabel->size();
//    mIconLabel->move(rect().right() - lSize.width(), (rect().bottom() + 1 - lSize.height())/2);
    //Изменить отступы текста внутри поля ввода в зависимости от видимости
    if (mIconLabel->isVisible()){
        //Добавить отступ справа чтобы текст не накладывался на пиктограмму
        QMargins lMargins = textMargins();
        lMargins.setRight(mIconLabel->size().width() + 1);
        setTextMargins(lMargins);
    } else {
        //Убрать отступы
        setTextMargins(QMargins(0, 0, 0, 0));
    }
}


void IconizedLineEdit::setIconVisibility(IconVisibilityMode pIconVisibilityMode)
{
    //Сохранение режима
    mIconVisibilityMode = pIconVisibilityMode ;
    //Выполняем изменения соответсвенно к установленому значению
    switch (pIconVisibilityMode){
        case IconAlwaysVisible:
            setIconVisible(true);
            break ;
        case IconVisibleOnEmptyText:
        case IconVisibleOnTextPresence:
            slotTextChanged(text());
            break;
        default:
            setIconVisible(false);
            break;
    }
}


//Реализует реакцию на изменение текста в поле для режимов IconVisibleOnEmptyText
//и IconVisibleOnNotEmptyText
void IconizedLineEdit::slotTextChanged(const QString &pText)
{
    if (IconVisibleOnEmptyText == mIconVisibilityMode){
        setIconVisible(pText.isEmpty());
    } else if (IconVisibleOnTextPresence == mIconVisibilityMode){
        setIconVisible(!pText.isEmpty());
    }
}


//Сделать пиктограмму видимой или спрятать
void IconizedLineEdit::setIconVisible(bool pIsVisible)
{
    //Показать/скрыть метку с пиктограммой
    mIconLabel->setVisible(pIsVisible);
}


bool IconizedLineEdit::eventFilter(QObject *p_obj, QEvent *p_event)
{
    if (is_icon_clickable)
        if (p_obj==mIconLabel && p_event->type()==QEvent::MouseButtonPress){
            emit iconPressed();
            return true;
        }
    return false;
}


void IconizedLineEdit::setIconClickable(bool is_icon_clickable)
{
    this->is_icon_clickable = is_icon_clickable;
    //Устанавливаем вид курсора при наведении на метку с пиктограммой
    if (is_icon_clickable)
        mIconLabel->setCursor(Qt::PointingHandCursor);
    else
        mIconLabel->setCursor(Qt::ArrowCursor);
}


void IconizedLineEdit::slotClear()
{
    clear();
    slotTextChanged(text());
}
