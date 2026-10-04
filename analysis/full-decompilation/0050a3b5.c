
void __thiscall FUN_0050a3b5(int *param_1,char param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == *(char *)((int)param_1 + 0xd5)) {
    return;
  }
  *(char *)((int)param_1 + 0xd5) = param_2;
  if (param_2 == '\0') {
    iVar1 = FUN_00401f6f();
    if (iVar1 == 0) {
      uVar2 = 2;
    }
    else if (iVar1 == 1) {
      uVar2 = 1;
    }
    else if (iVar1 == 2) {
      uVar2 = 0;
    }
    else if (iVar1 == 3) {
      uVar2 = 3;
    }
    else {
      if (iVar1 != 4) goto LAB_0050a409;
      uVar2 = 5;
    }
  }
  else {
    uVar2 = 4;
  }
  FUN_0050a8c0(uVar2);
LAB_0050a409:
  (**(code **)(*param_1 + 0x168))();
  return;
}

