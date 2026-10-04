
undefined4 __fastcall FUN_0050a45d(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    (**(code **)(*param_1 + 0x90))(1,0);
    if (param_1[0x37] != 0) {
      cVar1 = (**(code **)(*param_1 + 0x38))(param_1[0x37]);
      if (cVar1 != '\0') {
        (**(code **)(*param_1 + 0x24))(param_1[0x37]);
      }
      FUN_005da4c7(param_1[0x37]);
      param_1[0x37] = 0;
    }
    if (param_1[0x38] != 0) {
      cVar1 = (**(code **)(*param_1 + 0x38))(param_1[0x38]);
      if (cVar1 != '\0') {
        (**(code **)(*param_1 + 0x24))(param_1[0x38]);
      }
      FUN_005da4c7(param_1[0x38]);
      param_1[0x38] = 0;
    }
    if (param_1[0x39] != 0) {
      cVar1 = (**(code **)(*param_1 + 0x38))(param_1[0x39]);
      if (cVar1 != '\0') {
        (**(code **)(*param_1 + 0x24))(param_1[0x39]);
      }
      FUN_005da4c7(param_1[0x39]);
      param_1[0x39] = 0;
    }
    if (param_1[0x3a] != 0) {
      cVar1 = (**(code **)(*param_1 + 0x38))(param_1[0x3a]);
      if (cVar1 != '\0') {
        (**(code **)(*param_1 + 0x24))(param_1[0x3a]);
      }
      FUN_005da4c7(param_1[0x3a]);
      param_1[0x3a] = 0;
    }
    if (param_1[0x3b] != 0) {
      cVar1 = (**(code **)(*param_1 + 0x38))(param_1[0x3b]);
      if (cVar1 != '\0') {
        (**(code **)(*param_1 + 0x24))(param_1[0x3b]);
      }
      FUN_005da4c7(param_1[0x3b]);
      param_1[0x3b] = 0;
    }
    if (param_1[0x3d] != 0) {
      cVar1 = (**(code **)(*param_1 + 0x38))(param_1[0x3d]);
      if (cVar1 != '\0') {
        (**(code **)(*param_1 + 0x24))(param_1[0x3d]);
      }
      FUN_005da4c7(param_1[0x3d]);
      param_1[0x3d] = 0;
    }
    if (param_1[0x3c] != 0) {
      FUN_0042004f();
      FUN_005da4c7(param_1[0x3c]);
      param_1[0x3c] = 0;
    }
    if ((undefined4 *)param_1[0x40] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x40])(1);
    }
    param_1[0x40] = 0;
    if ((undefined4 *)param_1[0x41] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x41])(1);
    }
    param_1[0x41] = 0;
    if ((undefined4 *)param_1[0x42] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x42])(1);
    }
    param_1[0x42] = 0;
    if ((undefined4 *)param_1[0x43] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x43])(1);
    }
    param_1[0x43] = 0;
    FUN_005dbf4d();
  }
  return 1;
}

