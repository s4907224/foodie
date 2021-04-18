#include "gui/fudie_widget.h"

#include <iostream>

const int SCALE = 4;

FudieWidget::FudieWidget() :
  m_main_layout (new QVBoxLayout()),
  m_button_font (new QFont("D-DIN", 16))
{
  setWindowTitle(m_window_title);

  setLayout(m_main_layout);

  QLabel* title_label = new QLabel();
  QFont title_font("C800", 36);
  title_label->setText("FUDIE");
  title_label->setFont(title_font);
  title_label->setAlignment(Qt::AlignCenter);

  QHBoxLayout* title_layout = new QHBoxLayout();
  title_layout->addStretch(1);
  title_layout->addWidget(title_label);
  title_layout->addStretch(1);

  m_main_layout->addLayout(title_layout);

  setup_main_menu();

  setFixedSize(90*SCALE, 160*SCALE);
}

void FudieWidget::setup_main_menu()
{
  remove_active_layout();

  QVBoxLayout* menu_layout = new QVBoxLayout();
  QPushButton* edit_recipes_btn = new QPushButton("Edit Recipes");
  QPushButton* select_menu_btn = new QPushButton("Select Menu");
  QPushButton* shopping_list_btn = new QPushButton("Shopping List");



  edit_recipes_btn->setFont(*m_button_font);
  select_menu_btn->setFont(*m_button_font);
  shopping_list_btn->setFont(*m_button_font);

  menu_layout->addStretch(1);
  menu_layout->addWidget(edit_recipes_btn);
  menu_layout->addWidget(select_menu_btn);
  menu_layout->addWidget(shopping_list_btn);
  menu_layout->addStretch(1);

  connect(edit_recipes_btn, &QPushButton::clicked, this, &FudieWidget::setup_recipes_edit_menu);

  m_main_layout->addLayout(menu_layout);
  m_active_layout = menu_layout;
}

void FudieWidget::remove_active_layout()
{
  m_main_layout->removeItem(m_active_layout);
  if (m_active_layout != nullptr)
  {
    destroy_layout(m_active_layout);
  }
}

void FudieWidget::setup_recipes_edit_menu()
{
  remove_active_layout();

  QStringList DEBUG = {
    "Chicken Massaman Curry",
    "Mushroom Risotto",
    "Beef Stroganoff",
    "Jambalaya",
    "Pesto Pasta",
    "Chili",
    "Sweet & Sour Tofu",
    "Sweet Potato & Kale Satay"
  };

  QVBoxLayout* recipes_edit_layout = new QVBoxLayout();

  QScrollArea* scroll_a = new QScrollArea();
  RecipeListWidget* recipe_item_widget = new RecipeListWidget();
  scroll_a->setWidgetResizable(true);
  scroll_a->setWidget(recipe_item_widget);

  for (auto &item: DEBUG)
  {
    recipe_item_widget->add_recipe_list_widget_item(item.toStdString(), 456, 123, 987);
  }

  recipes_edit_layout->addWidget(scroll_a);

  QPushButton* back_button = new QPushButton("Back");
  back_button->setFont(*m_button_font);
  connect(back_button, &QPushButton::clicked, this, &FudieWidget::setup_main_menu);

  recipes_edit_layout->addStretch(1);
  recipes_edit_layout->addWidget(back_button);

  m_main_layout->addLayout(recipes_edit_layout);
  m_active_layout = recipes_edit_layout;
}

void FudieWidget::destroy_layout(QLayout *layout) {
  QLayoutItem *item;
  while((item = layout->takeAt(0)))
  {
    if (item->layout())
    {
      destroy_layout(item->layout());
      delete item->layout();
    }
    if (item->widget())
    {
      delete item->widget();
    }
    delete item;
  }
}
