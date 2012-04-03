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

#ifndef HASHER_H
#define HASHER_H

#include <QWidget>

class QLineEdit;
class QPushButton;
class QComboBox;
class QProgressBar;

class Hasher : public QWidget
{
  Q_OBJECT
public:
  explicit Hasher(QWidget *parent = 0);
    
signals:

public slots:

private:
  QLineEdit* filename_;
  QPushButton* filename_button_;
  QComboBox* hash_type_;
  QPushButton* generate_button_;
  QProgressBar* hash_progress_;
  QLineEdit* generated_hash_;
  QPushButton* compare_button_;
  QLineEdit* pasted_hash_;
  QPushButton* paste_button_;
  QPushButton* about_button_;
  QPushButton* exit_button_;
};

#endif // HASHER_H
