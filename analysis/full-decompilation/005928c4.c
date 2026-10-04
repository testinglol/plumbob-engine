
void __fastcall FUN_005928c4(int param_1)

{
  short sVar1;
  
  sVar1 = *(short *)(*(int *)(param_1 + 0x138) + 0x58c);
  if (sVar1 == 0) {
    *(undefined4 *)(param_1 + 400) = 3;
  }
  else {
    if (sVar1 == 1) {
      *(undefined4 *)(param_1 + 400) = 1;
      return;
    }
    if (sVar1 == 2) {
      *(undefined4 *)(param_1 + 400) = 2;
      return;
    }
  }
  return;
}

