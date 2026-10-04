
undefined4 __thiscall FUN_004cffcb(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(char *)(param_1 + 0x44c) == '\0') {
    if ((param_2 == -1) || (*(short *)(DAT_006e486c + 0x66) < 0x40)) {
      uVar3 = 0;
    }
    else {
      iVar2 = FUN_004ea79e(param_2);
      sVar1 = *(short *)(iVar2 + 0xa0);
      iVar2 = FUN_004ea83d(param_2);
      if ((iVar2 == 0) && (0 < sVar1)) {
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

