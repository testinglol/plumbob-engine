
undefined4 __thiscall FUN_005c163f(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = FUN_004317d5(param_1 + 0xc,param_2 + 0xc);
  if ((cVar1 == '\0') || (*(int *)(param_1 + 0x1c) != *(int *)(param_2 + 0x1c))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

