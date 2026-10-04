
void __fastcall FUN_0051134c(int *param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    param_1[0x45] = 0;
    if (param_1[0x113] != 0) {
      param_1[0x113] = 0;
    }
    if (param_1[0x114] != 0) {
      param_1[0x114] = 0;
    }
    if (param_1[0x115] != 0) {
      param_1[0x115] = 0;
    }
    if (param_1[0x46] != 0) {
      param_1[0x46] = 0;
    }
    if (param_1[0x44] != 0) {
      param_1[0x44] = 0;
    }
    if (param_1[0x118] != 0) {
      cVar1 = (**(code **)(*param_1 + 0x38))(param_1[0x118]);
      if (cVar1 != '\0') {
        (**(code **)(*param_1 + 0x24))(param_1[0x118]);
      }
      FUN_005da4c7(param_1[0x118]);
      param_1[0x118] = 0;
    }
    if ((undefined4 *)param_1[0x47] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x47])(1);
      param_1[0x47] = 0;
    }
    if ((undefined4 *)param_1[0x48] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x48])(1);
      param_1[0x48] = 0;
    }
    param_1 = param_1 + 0x4a;
    iVar2 = 5;
    do {
      if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*param_1)(1);
        *param_1 = 0;
      }
      param_1 = param_1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    FUN_005a5e48(0);
  }
  FUN_005dbf4d();
  return;
}

