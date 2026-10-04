
undefined4 __thiscall FUN_004e8ada(int param_1,uint param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 < 7) {
    iVar3 = param_1 + 0xc + param_2 * 8;
  }
  else {
    iVar3 = 0;
  }
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    FUN_005a5e1c(param_3);
    cVar1 = FUN_005a5e72();
    if (cVar1 != '\0') {
      *(undefined1 *)(iVar3 + 4) = 0;
    }
    uVar2 = 1;
  }
  return uVar2;
}

