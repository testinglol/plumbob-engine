
void __thiscall FUN_0052386b(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  int local_8;
  
  piVar2 = (int *)FUN_005e7743();
  local_8 = (**(code **)(*piVar2 + 0x24))(param_3,param_2);
  if (local_8 != 0) {
    if (*(int *)(local_8 + 0x84) - *(int *)(local_8 + 0x7c) < 100) {
      FUN_004ec186(100);
    }
    FUN_005e4b90(1);
    (**(code **)(*param_1 + 0x20))(local_8);
    FUN_00524c70(&local_8);
  }
  uVar3 = FUN_005e50fa(4);
  cVar1 = FUN_004317d5(param_2,uVar3);
  if (cVar1 == '\0') {
    uVar3 = FUN_005e50fa(2);
    cVar1 = FUN_004317d5(param_2,uVar3);
    if (cVar1 == '\0') {
      return;
    }
    local_10 = 0;
    local_14 = param_3;
    local_c = FUN_005e5119(2);
  }
  else {
    local_10 = 0;
    local_14 = param_3;
    local_c = FUN_005e5119(4);
  }
  FUN_00524c46(&local_14);
  return;
}

