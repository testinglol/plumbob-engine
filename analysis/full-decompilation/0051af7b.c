
undefined4 __fastcall FUN_0051af7b(int *param_1)

{
  char cVar1;
  int iVar2;
  
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
    if (param_1[0xce] != 0) {
      cVar1 = (**(code **)(*param_1 + 0x38))(param_1[0xce]);
      if (cVar1 != '\0') {
        (**(code **)(*param_1 + 0x24))(param_1[0xce]);
      }
      FUN_005da4c7(param_1[0xce]);
      param_1[0xce] = 0;
    }
    if (param_1[0x104] != 0) {
      cVar1 = (**(code **)(*param_1 + 0x38))(param_1[0x104]);
      if (cVar1 != '\0') {
        (**(code **)(*param_1 + 0x24))(param_1[0x104]);
      }
      FUN_005da4c7(param_1[0x104]);
      param_1[0x104] = 0;
    }
    if ((undefined4 *)param_1[0x10c] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x10c])(1);
      param_1[0x10c] = 0;
    }
    if (param_1[0x47] != 0) {
      cVar1 = (**(code **)(*param_1 + 0x38))(param_1[0x47]);
      if (cVar1 != '\0') {
        (**(code **)(*param_1 + 0x24))(param_1[0x47]);
      }
      FUN_005da4c7(param_1[0x47]);
      param_1[0x47] = 0;
    }
    param_1[0x35] = 0;
    if (param_1[0x36] != 0) {
      FUN_005e3581();
    }
    param_1[0x36] = 0;
    if ((undefined4 *)param_1[0xbc] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xbc])(1);
    }
    param_1[0xbc] = 0;
    if ((undefined4 *)param_1[0xbe] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xbe])(1);
    }
    param_1[0xbe] = 0;
    if ((undefined4 *)param_1[0x72] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x72])(1);
    }
    param_1[0x72] = 0;
    if ((undefined4 *)param_1[0xd6] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xd6])(1);
    }
    param_1[0xd6] = 0;
    if ((undefined4 *)param_1[0x5e] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x5e])(1);
    }
    param_1[0x5e] = 0;
    if ((undefined4 *)param_1[0x5f] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x5f])(1);
    }
    param_1[0x5f] = 0;
    if ((undefined4 *)param_1[0xc6] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xc6])(1);
    }
    param_1[0xc6] = 0;
    iVar2 = 0;
    if (0 < param_1[0x11b]) {
      do {
        FUN_005a5e48(0);
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1[0x11b]);
    }
    if (param_1[0x11a] != 0) {
      FUN_0051b216(3);
    }
    param_1[0x11a] = 0;
    param_1[0x11b] = 0;
    if ((undefined4 *)param_1[0x11c] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x11c])(1);
      param_1[0x11c] = 0;
    }
    if ((undefined4 *)param_1[0xbb] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xbb])(1);
    }
    param_1[0xbb] = 0;
    FUN_005dbf4d();
  }
  return 1;
}

