
undefined4 __thiscall FUN_0057c675(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = *(uint *)(param_1 + 0xc);
  if ((param_2 < uVar1) || (*(int *)(param_1 + 0x10) + uVar1 <= param_2)) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0057c62d(param_2 - uVar1);
  }
  return uVar2;
}

