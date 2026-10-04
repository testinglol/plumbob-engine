
undefined4 __thiscall FUN_005da4c7(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x30) < 1) {
    uVar2 = FUN_005da4f7(param_2);
  }
  else {
    cVar1 = FUN_005da5c4(param_2);
    if (cVar1 == '\0') {
      FUN_00601324(&param_2);
    }
    uVar2 = 1;
  }
  return uVar2;
}

