
void __thiscall FUN_005172e4(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((*(byte *)(param_2 + 0xe) & 0x40) == 0) {
    return;
  }
  FUN_004e609e();
  if (*(int *)(param_1 + 0x110) != 0) {
    uVar2 = FUN_004e60c2();
    FUN_005e4f65(uVar2);
  }
  if (*(int *)(param_1 + 0x114) != 0) {
    uVar2 = FUN_004e60ed();
    FUN_005e4f65(uVar2);
  }
  if (*(int *)(param_1 + 0x118) != 0) {
    uVar2 = FUN_004e6110();
    FUN_005e4f65(uVar2);
  }
  if (*(int *)(param_1 + 0x11c) != 0) {
    uVar2 = FUN_004e6133();
    FUN_005e4f65(uVar2);
  }
  if (*(int *)(param_1 + 0x120) != 0) {
    iVar3 = FUN_004e6141();
    if (iVar3 == 0) {
      uVar2 = 0;
    }
    else if (iVar3 == 1) {
      uVar2 = 1;
    }
    else {
      if (iVar3 != 2) goto LAB_00517396;
      uVar2 = 2;
    }
    FUN_005379e3(uVar2);
  }
LAB_00517396:
  if (*(int *)(param_1 + 0x124) != 0) {
    iVar3 = FUN_004e61ab();
    if (iVar3 == 0) {
      uVar2 = 0;
    }
    else if (iVar3 == 1) {
      uVar2 = 1;
    }
    else {
      if (iVar3 != 2) goto LAB_005173c3;
      uVar2 = 2;
    }
    FUN_005379e3(uVar2);
  }
LAB_005173c3:
  if (*(int **)(param_1 + 0x138) != (int *)0x0) {
    iVar3 = **(int **)(param_1 + 0x138);
    uVar2 = FUN_004e62a7();
    (**(code **)(iVar3 + 0x1a8))(uVar2);
  }
  if (*(int **)(param_1 + 0x13c) != (int *)0x0) {
    iVar3 = **(int **)(param_1 + 0x13c);
    uVar2 = FUN_004e62e0();
    (**(code **)(iVar3 + 0x1a8))(uVar2);
  }
  if (*(int **)(param_1 + 0x140) != (int *)0x0) {
    iVar3 = **(int **)(param_1 + 0x140);
    uVar2 = FUN_004e6319();
    (**(code **)(iVar3 + 0x1a8))(uVar2);
  }
  if (*(int *)(param_1 + 0x154) != 0) {
    uVar2 = FUN_004e6352();
    FUN_005e4f65(uVar2);
  }
  if (*(int *)(param_1 + 0x158) != 0) {
    uVar2 = FUN_004e6364();
    FUN_005e4f65(uVar2);
  }
  if (*(int *)(param_1 + 0x15c) != 0) {
    uVar2 = FUN_004e6383();
    FUN_005e4f65(uVar2);
  }
  if (*(int *)(param_1 + 0x160) != 0) {
    uVar2 = FUN_004e636a();
    FUN_005e4f65(uVar2);
  }
  if (*(int *)(param_1 + 0x178) != 0) {
    uVar2 = FUN_004e63de();
    FUN_005e4f65(uVar2);
  }
  if (*(int *)(param_1 + 0x17c) != 0) {
    uVar2 = FUN_004e642d();
    FUN_005e4f65(uVar2);
  }
  if (*(int *)(param_1 + 0x180) != 0) {
    uVar2 = FUN_004cffb7();
    FUN_005e4f65(uVar2);
  }
  if (*(int *)(param_1 + 0x184) != 0) {
    uVar2 = FUN_004e6445();
    FUN_005e4f65(uVar2);
  }
  (**(code **)(**(int **)(param_1 + 0xf8) + 0x98))();
  (**(code **)(**(int **)(param_1 + 0x110) + 0x98))();
  if ((*(byte *)(param_2 + 0xf) & 0x10) != 0) {
    cVar1 = FUN_004cebf4();
    if (cVar1 == '\x01') {
      (**(code **)(**(int **)(param_1 + 0xe4) + 0x98))();
    }
    else {
      (**(code **)(**(int **)(param_1 + 0xe4) + 0x94))();
    }
  }
  return;
}

