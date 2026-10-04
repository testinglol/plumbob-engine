
void __thiscall FUN_004cef2b(int param_1,undefined4 param_2)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x38) == 0) {
    uVar1 = 3;
  }
  else {
    uVar1 = *(int *)(param_1 + 0x38) - 1U & 3;
  }
  FUN_004ceefb(uVar1,param_2);
  return;
}

