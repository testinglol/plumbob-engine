
undefined4 __thiscall FUN_005bc722(int *param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = __allmul(*param_1,0,0x41c64e6d,0);
    *param_1 = iVar2 + 0x3039;
    uVar3 = __aullshr();
    uVar1 = (undefined4)((ulonglong)uVar3 * (ulonglong)param_2 >> 0x20);
  }
  return uVar1;
}

