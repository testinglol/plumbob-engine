
undefined4 __fastcall FUN_005e8e14(int *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    if (param_1[0x41] == 0) {
      (**(code **)(*param_1 + 0x174))(0,0);
    }
    if (((char)param_1[0x3a] != '\0') && ((undefined4 *)param_1[0x39] != (undefined4 *)0x0)) {
      (*(code *)**(undefined4 **)param_1[0x39])(1);
    }
    param_1[0x39] = 0;
    *(undefined1 *)(param_1 + 0x3a) = 1;
    if ((param_1[0x36] != 0) && ((char)param_1[0x38] == '\0')) {
      piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
      (**(code **)(*piVar2 + 0x14))(param_1[0x36]);
      param_1[0x36] = 0;
    }
    (**(code **)(*param_1 + 0x90))(1,0);
    uVar3 = FUN_005dbf4d();
    return uVar3;
  }
  return 1;
}

