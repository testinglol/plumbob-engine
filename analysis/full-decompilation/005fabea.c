
undefined4 __thiscall FUN_005fabea(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = (**(code **)(*DAT_006fed70 + 8))();
  if (cVar1 == '\0') {
    uVar2 = 1;
  }
  else if (*(char *)(param_1 + 0x1a0) == '\0') {
    uVar2 = FUN_005f94c1(param_2 - *(int *)(param_1 + 0x1a4));
    *(int *)(param_1 + 0x28) = param_2;
  }
  else {
    uVar2 = FUN_005f94c1(param_2);
  }
  return uVar2;
}

