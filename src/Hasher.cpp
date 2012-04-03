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
  QGroupBox* data_group = new QGroupBox();
  QVBoxLayout* main_layout = new QVBoxLayout();

  filename_ = new QLineEdit();
  filename_button_ = new QPushButton(tr("Browse"));

  QHBoxLayout* filename_box = new QHBoxLayout();
  filename_box->addWidget(filename_, Qt::AlignLeft);
  filename_box->addWidget(filename_button_);
  filename_box->addStretch();

  hash_type_ = new QComboBox();
  hash_type_->addItem(tr("MD5"));
  hash_type_->addItem(tr("SHA-1"));
  hash_type_->addItem(tr("SHA-256"));

  generate_button_ = new QPushButton(tr("Generate"));

  QHBoxLayout* hash_type_box = new QHBoxLayout();
  hash_type_box->addWidget(hash_type_, Qt::AlignLeft);
  hash_type_box->addWidget(generate_button_);
  hash_type_box->addStretch();

  hash_progress_ = new QProgressBar();

  generated_hash_ = new QLineEdit();
  generated_hash_->setReadOnly(true);
  compare_button_ = new QPushButton(tr("Compare"));

  QHBoxLayout* compare_box = new QHBoxLayout();
  compare_box->addWidget(generated_hash_, Qt::AlignLeft);
  compare_box->addWidget(compare_button_);
  compare_box->addStretch();

  pasted_hash_ = new QLineEdit();
  paste_button_ = new QPushButton(tr("Paste"));

  QHBoxLayout* paste_box = new QHBoxLayout();
  paste_box->addWidget(pasted_hash_, Qt::AlignLeft);
  paste_box->addWidget(paste_button_);
  paste_box->addStretch();

  QVBoxLayout* data_box_layout = new QVBoxLayout();
  data_box_layout->addLayout(filename_box, Qt::AlignTop);
  data_box_layout->addLayout(hash_type_box);
  data_box_layout->addWidget(hash_progress_);
  data_box_layout->addLayout(compare_box);
  data_box_layout->addLayout(paste_box);
  data_group->setLayout(data_box_layout);

  QGroupBox* control_group = new QGroupBox();
  QHBoxLayout* control_box = new QHBoxLayout();
  about_button_ = new QPushButton(tr("About"));
  exit_button_ = new QPushButton(tr("Exit"));
  control_box->addWidget(about_button_, Qt::AlignLeft);
  control_box->addWidget(exit_button_);
  control_box->addStretch();
  control_box->insertSpacerItem(0, new QSpacerItem(350, 1));
  control_group->setLayout(control_box);

//  main_layout->addLayout(filename_box, Qt::AlignTop);
//  main_layout->addLayout(hash_type_box);
//  main_layout->addWidget(hash_progress_);
//  main_layout->addLayout(compare_box);
//  main_layout->addLayout(paste_box);
  main_layout->addWidget(data_group);
  main_layout->addWidget(control_group);
  main_layout->addStretch();

  setLayout(main_layout);
  setWindowTitle(tr("Hasher"));
  //setFixedSize(500, 290);
}
