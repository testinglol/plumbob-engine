
void __thiscall FUN_0051d3e7(int *param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if ((param_1[0x3f] != param_2) && (param_1[0x56] != 0)) {
    FUN_0050fc0a(1);
  }
  iVar3 = param_1[0x3f];
  if ((((iVar3 == 1) || (iVar3 == 2)) || (iVar3 == 3)) ||
     (((iVar3 == 4 || (iVar3 == 5)) || ((iVar3 == 6 || (iVar3 == 7)))))) {
    FUN_005e46f0(0);
  }
  if ((param_2 == 4) && (cVar1 = FUN_004074bc(), cVar1 == '\0')) {
    param_2 = 0;
  }
  param_1[0x3f] = param_2;
  FUN_0051d7af(param_1[0x40],0);
  FUN_0051d7af(param_1[0x41],0);
  FUN_0051d7af(param_1[0x42],0);
  FUN_0051d7af(param_1[0x71],0);
  FUN_0051d7af(param_1[0x44],0);
  FUN_0051d7af(param_1[0x47],0);
  FUN_0051d7af(param_1[0x45],0);
  FUN_0051d7af(param_1[0x46],0);
  FUN_0051d7af(param_1[0x43],0);
  FUN_0051d7af(param_1[0x48],0);
  FUN_0051d7af(param_1[0x49],0);
  FUN_0051d7af(param_1[0xce],0);
  FUN_0051d7af(param_1[0x104],0);
  iVar3 = param_1[0x3f];
  if (iVar3 == 0) {
    return;
  }
  if (iVar3 == 1) {
    uVar2 = FUN_004e99a9();
    iVar3 = FUN_004e9744(uVar2);
    if ((iVar3 == 0) || (1 < *(short *)(iVar3 + 0x60e))) {
      FUN_0051d7af(param_1[0x40],0);
      uVar2 = 1;
    }
    else {
      FUN_0051d7af(param_1[0x40],1);
      uVar2 = 0;
    }
    FUN_0051d7af(param_1[0x41],uVar2);
    do {
      uVar2 = FUN_004e99a9();
      FUN_00513b1d(uVar2);
      uVar2 = FUN_004e99a9();
      FUN_00513b1d(uVar2);
      iVar4 = iVar4 + 4;
    } while (iVar4 < 0x20);
    FUN_004cee86(1);
  }
  else if (iVar3 == 2) {
    uVar2 = FUN_004e99a9();
    iVar4 = FUN_004e9744(uVar2);
    if ((iVar4 == 0) || (1 < *(short *)(iVar4 + 0x60e))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
    FUN_0051d7af(param_1[0x71],uVar2);
    FUN_0051d7af(param_1[0x42],1);
    FUN_004cee86(0x10000);
  }
  else if (iVar3 == 3) {
    uVar2 = FUN_004e99a9();
    iVar4 = FUN_004e9744(uVar2);
    uVar2 = FUN_004e99a9();
    if (((iVar4 == 0) || (*(short *)(iVar4 + 0x600) == 0)) || (0x11 < *(short *)(iVar4 + 0x600))) {
      if (((uint)(int)*(short *)(iVar4 + 0x60e) >> 1 & 1) != 0) {
        iVar4 = param_1[0x45];
        goto LAB_0051d68f;
      }
      if (((uint)(int)*(short *)(iVar4 + 0x60e) >> 2 & 1) != 0) {
        iVar4 = param_1[0x46];
        goto LAB_0051d68f;
      }
      cVar1 = FUN_004cffcb(uVar2);
      if (cVar1 == '\0') {
        iVar4 = param_1[0x44];
        goto LAB_0051d68f;
      }
      iVar4 = param_1[0x47];
      if (iVar4 != 0) goto LAB_0051d68f;
    }
    else {
      iVar4 = param_1[0x49];
LAB_0051d68f:
      FUN_0051d7af(iVar4,1);
    }
    FUN_004cee86(0x20000);
  }
  else if (iVar3 == 4) {
    FUN_0051d7af(param_1[0x48],1);
    FUN_004cee86(0x40000);
  }
  else if (iVar3 == 5) {
    FUN_0051d7af(param_1[0x43],1);
    FUN_004cee86(0x8000);
  }
  else if (iVar3 == 6) {
    FUN_0051d7af(param_1[0xce],1);
    FUN_004cee86(0x2000000);
  }
  else {
    if (iVar3 != 7) goto LAB_0051d791;
    FUN_0051d7af(param_1[0x104],1);
    FUN_004cee86(0x4000000);
  }
  FUN_005e46f0(1);
LAB_0051d791:
  FUN_0051ceee(param_1[0x39]);
  (**(code **)(*param_1 + 0x168))();
  return;
}

