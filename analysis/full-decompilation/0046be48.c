
undefined4 __thiscall FUN_0046be48(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  short sVar3;
  
  iVar1 = 0;
  sVar3 = 0;
  if (param_2 != 0) {
    iVar1 = FUN_0045741b();
    sVar3 = *(short *)(param_2 + 0xf0);
  }
  if ((iVar1 == *param_1) && (sVar3 == (short)param_1[1])) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

