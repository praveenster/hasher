/*
  Copyright (c) 2011 Neevarp Yhtroom

  Permission is hereby granted, free of charge, to any person obtaining
  a copy of this software and associated documentation files (the
  "Software"), to deal in the Software without restriction, including
  without limitation the rights to use, copy, modify, merge, publish,
  distribute, sublicense, and/or sell copies of the Software, and to
  permit persons to whom the Software is furnished to do so, subject to
  the following conditions:

  The above copyright notice and this permission notice shall be
  included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <QtGui>
#include "Hasher.h"

Hasher::Hasher(QWidget *parent)
  : QWidget(parent)
{
  QGroupBox* filename_group = new QGroupBox(tr("Select File to hash"));
  QGroupBox* hash_type_group = new QGroupBox(tr("Select algorithm"));
  QVBoxLayout* main_layout = new QVBoxLayout();

  filename_ = new QLineEdit();
  filename_button_ = new QPushButton(tr("Browse"));

  QHBoxLayout* filename_layout = new QHBoxLayout();
  filename_layout->addWidget(filename_, Qt::AlignLeft);
  filename_layout->addWidget(filename_button_);
  filename_layout->addStretch();
  filename_group->setLayout(filename_layout);

  hash_type_ = new QComboBox();
  hash_type_->addItem(tr("MD5"));
  hash_type_->addItem(tr("SHA-1"));
  hash_type_->addItem(tr("SHA-256"));

  generate_button_ = new QPushButton(tr("Generate"));
  generated_hash_ = new QLineEdit();
  generated_hash_->setReadOnly(true);

  QHBoxLayout* hash_type_layout = new QHBoxLayout();
  hash_type_layout->addWidget(hash_type_, Qt::AlignLeft);
  hash_type_layout->addWidget(generate_button_);
  hash_type_layout->addWidget(generated_hash_);
  hash_type_layout->addStretch();

  hash_progress_ = new QProgressBar();

  compare_button_ = new QPushButton(tr("Compare"));

  QHBoxLayout* compare_layout = new QHBoxLayout();
  compare_layout->addWidget(compare_button_);
  compare_layout->addWidget(generated_hash_, Qt::AlignLeft);
  compare_layout->addStretch();

  pasted_hash_ = new QLineEdit();

  QHBoxLayout* paste_layout = new QHBoxLayout();
  paste_layout->addWidget(pasted_hash_, Qt::AlignLeft);
  paste_layout->insertSpacerItem(0, new QSpacerItem(50, 1));
  paste_layout->addStretch();

  QVBoxLayout* data_box_layout = new QVBoxLayout();
  data_box_layout->addLayout(hash_type_layout);
  data_box_layout->addLayout(compare_layout);
  data_box_layout->addLayout(paste_layout);
  data_box_layout->addWidget(hash_progress_);
  hash_type_group->setLayout(data_box_layout);

  QGroupBox* control_group = new QGroupBox();
  QHBoxLayout* control_box = new QHBoxLayout();
  about_button_ = new QPushButton(tr("About"));
  exit_button_ = new QPushButton(tr("Exit"));
  control_box->addWidget(about_button_, Qt::AlignRight);
  control_box->addWidget(exit_button_);
  control_box->addStretch();
  //control_box->insertSpacerItem(0, new QSpacerItem(350, 1));
  control_group->setLayout(control_box);

//  main_layout->addLayout(filename_box, Qt::AlignTop);
//  main_layout->addLayout(hash_type_box);
//  main_layout->addWidget(hash_progress_);
//  main_layout->addLayout(compare_box);
//  main_layout->addLayout(paste_box);
  main_layout->addWidget(filename_group);
  main_layout->addWidget(hash_type_group);
  main_layout->addWidget(control_group);
  main_layout->addStretch();

  setLayout(main_layout);
  setWindowTitle(tr("Hasher"));
  //setFixedSize(500, 290);
}
