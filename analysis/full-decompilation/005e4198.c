
undefined4 __thiscall FUN_005e4198(int *param_1,undefined4 *param_2,int param_3,int param_4)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  puVar2 = (undefined4 *)param_1[0x36];
  bVar5 = puVar2 != param_2;
  if ((param_1[0x3b] != param_4) || (param_1[0x3c] != param_3)) {
    bVar5 = true;
  }
  if (!bVar5) {
    return 1;
  }
  cVar1 = *(char *)((int)param_1 + 0x171);
  if ((*(char *)((int)param_1 + 0x16b) != '\0') && (cVar1 == '\0')) {
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
    param_1[0x36] = 0;
  }
  if (param_2 != (undefined4 *)0x0) {
    iVar4 = FUN_005e3596();
    if (iVar4 == 0) {
      *(undefined1 *)((int)param_1 + 0x171) = 0;
      goto LAB_005e4223;
    }
    FUN_005e357a();
    *(undefined1 *)((int)param_1 + 0x171) = 1;
  }
  *(undefined1 *)((int)param_1 + 0x16b) = 0;
LAB_005e4223:
  if ((cVar1 != '\0') && (puVar2 != (undefined4 *)0x0)) {
    FUN_005e3581();
  }
  param_1[0x36] = (int)param_2;
  param_1[0x3b] = param_4;
  param_1[0x3c] = param_3;
  if (param_2 == (undefined4 *)0x0) {
    param_1[0x3f] = param_1[0x1f];
    param_1[0x40] = param_1[0x20];
    param_1[0x41] = param_1[0x21];
    param_1[0x42] = param_1[0x22];
    iVar4 = param_1[0x40];
    iVar3 = param_1[0x3f];
    param_1[0x40] = param_1[0x40] + -iVar4;
    param_1[0x3f] = param_1[0x3f] + -iVar3;
    param_1[0x41] = param_1[0x41] + -iVar3;
    param_1[0x42] = param_1[0x42] + -iVar4;
    *(undefined1 *)((int)param_1 + 0x16d) = 1;
    *(undefined1 *)((int)param_1 + 0x16b) = 0;
    *(undefined1 *)((int)param_1 + 0x171) = 0;
  }
  else {
    iVar4 = param_2[7];
    iVar3 = param_2[8];
    param_1[0x41] = iVar4 / param_3;
    param_1[0x3f] = 0;
    param_1[0x40] = 0;
    param_1[0x42] = iVar3 / param_4;
    FUN_004ec186(iVar4 / param_3);
    FUN_004ec1a7(param_1[0x42] - param_1[0x40]);
  }
  (**(code **)(*param_1 + 0x1b4))();
  (**(code **)(*param_1 + 0x168))();
  return 1;
}

