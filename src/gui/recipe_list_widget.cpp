#include "gui/recipe_list_widget.h"

RecipeListWidget::RecipeListWidget() :
  m_grid_layout (new QGridLayout()),
  m_small_font (new QFont("D-DIN", 12))
{
  setLayout(m_grid_layout);
}

void RecipeListWidget::add_recipe_list_widget_item(std::string _name, int _price, int _total_cooking_time, int _calories)
{
  m_recipe_widget_items[_name] = {
    {"price", _price},
    {"total_cooking_time", _total_cooking_time},
    {"calories", _calories}
  };

  int num_recipe_items = m_grid_layout->rowCount();

  QLabel* image = new QLabel();
  image->setPixmap(QPixmap(":/icons/fudie_logo_64.png"));
  image->setFixedSize(64, 64);
  m_grid_layout->addWidget(image, num_recipe_items, 0);

  QLabel* name_label = new QLabel(QString::fromStdString(_name));

  QGridLayout* name_info_layout = new QGridLayout();
  QGridLayout* info_layout = new QGridLayout();

  name_info_layout->addWidget(name_label, 0, 0);
  name_info_layout->addLayout(info_layout, 1, 0);
//  name_info_layout->setRowMinimumHeight(1, 70);

  m_grid_layout->addLayout(name_info_layout, num_recipe_items, 1);

  QString price_string = QString::number(_price);
  price_string.insert(-2, '.');

  QLabel* price_label = new QLabel(QString("£%1").arg(price_string));
  QLabel* time_label = new QLabel(QString("%1H: %2M").arg(QString::number(_total_cooking_time / 60), QString::number(_total_cooking_time % 60)));
  QLabel* calories_label = new QLabel(QString("%1 kcal").arg(QString::number(_calories)));

  price_label->setFont(*m_small_font);
  time_label->setFont(*m_small_font);
  calories_label->setFont(*m_small_font);
  name_label->setFont(*m_small_font);

  info_layout->addWidget(price_label, 0, 0);
  info_layout->addWidget(time_label, 1, 0);
  info_layout->addWidget(calories_label, 2, 0);

//  info_layout->setRowMinimumHeight(0, 20);
//  info_layout->setRowMinimumHeight(1, 20);
//  info_layout->setRowMinimumHeight(2, 20);
}
