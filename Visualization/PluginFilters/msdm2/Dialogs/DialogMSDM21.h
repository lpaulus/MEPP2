// Copyright (c) 2012-2019 University of Lyon and CNRS (France).
// All rights reserved.
//
// This file is part of MEPP2; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published 
// by the Free Software Foundation; either version 3 of the License, 
// or (at your option) any later version.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
#pragma once

////////////////////////////////////////////////////////////////////////////////
#include <QDialog>
////////////////////////////////////////////////////////////////////////////////
namespace Ui {
class DialogMSDM21;
}
////////////////////////////////////////////////////////////////////////////////
namespace FEVV {

class DialogMSDM21 : public QDialog
{
  Q_OBJECT

public:
  explicit DialogMSDM21(QWidget *parent = 0);
  ~DialogMSDM21();

  void getProcess(bool &one_two, bool &two_one, int &scales, bool &colors);

private:
  Ui::DialogMSDM21 *ui;
};

} // namespace FEVV

////////////////////////////////////////////////////////////////////////////////
