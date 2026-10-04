
void __fastcall FUN_004d1d8a(int *param_1)

{
  int iVar1;
  char cVar2;
  
  FUN_004d2944();
  FUN_004d20a6();
  if (param_1[0x46b] != 0) {
    cVar2 = (**(code **)(*param_1 + 0x38))(param_1[0x46b]);
    if (cVar2 != '\0') {
      iVar1 = param_1[0x46b];
      FUN_005ddfdc(0);
      (**(code **)(*param_1 + 0x24))(iVar1);
    }
    FUN_005da4c7(param_1[0x46b]);
    param_1[0x46b] = 0;
  }
  if (param_1[0x51] != 0) {
    cVar2 = (**(code **)(*param_1 + 0x38))(param_1[0x51]);
    if (cVar2 != '\0') {
      (**(code **)(*param_1 + 0x24))(param_1[0x51]);
    }
    FUN_005da4c7(param_1[0x51]);
    param_1[0x51] = 0;
  }
  if (param_1[0x4d] != 0) {
    cVar2 = (**(code **)(*param_1 + 0x38))(param_1[0x4d]);
    if (cVar2 != '\0') {
      (**(code **)(*param_1 + 0x24))(param_1[0x4d]);
    }
    FUN_005da4c7(param_1[0x4d]);
    param_1[0x4d] = 0;
  }
  if (param_1[0x4e] != 0) {
    cVar2 = (**(code **)(*param_1 + 0x38))(param_1[0x4e]);
    if (cVar2 != '\0') {
      (**(code **)(*param_1 + 0x24))(param_1[0x4e]);
    }
    FUN_005da4c7(param_1[0x4e]);
    param_1[0x4e] = 0;
  }
  if (param_1[0x4f] != 0) {
    cVar2 = (**(code **)(*param_1 + 0x38))(param_1[0x4f]);
    if (cVar2 != '\0') {
      (**(code **)(*param_1 + 0x24))(param_1[0x4f]);
    }
    FUN_005da4c7(param_1[0x4f]);
    param_1[0x4f] = 0;
  }
  if (param_1[0x50] != 0) {
    cVar2 = (**(code **)(*param_1 + 0x38))(param_1[0x50]);
    if (cVar2 != '\0') {
      (**(code **)(*param_1 + 0x24))(param_1[0x50]);
    }
    FUN_005da4c7(param_1[0x50]);
    param_1[0x50] = 0;
  }
  if (param_1[0x53] != 0) {
    cVar2 = (**(code **)(*param_1 + 0x38))(param_1[0x53]);
    if (cVar2 != '\0') {
      (**(code **)(*param_1 + 0x24))(param_1[0x53]);
    }
    FUN_005da4c7(param_1[0x53]);
    param_1[0x53] = 0;
  }
  if (param_1[0x48] != 0) {
    FUN_005e3581();
    param_1[0x48] = 0;
  }
  if ((undefined4 *)param_1[0x49] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x49])(1);
    param_1[0x49] = 0;
  }
  if ((undefined4 *)param_1[0x4a] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x4a])(1);
    param_1[0x4a] = 0;
  }
  if ((undefined4 *)param_1[0x4b] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x4b])(1);
    param_1[0x4b] = 0;
  }
  if ((undefined4 *)param_1[0x4c] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x4c])(1);
    param_1[0x4c] = 0;
  }
  if ((undefined4 *)param_1[0x5d] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x5d])(1);
  }
  param_1[0x5d] = 0;
  return;
}

