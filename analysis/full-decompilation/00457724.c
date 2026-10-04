
undefined4 __fastcall FUN_00457724(int param_1)

{
  char cVar1;
  
  if (*(short *)(*(int *)(param_1 + 0x60) + 0x14) != 0) {
    cVar1 = FUN_0043aedc();
    if (cVar1 == '\0') {
      return 1;
    }
  }
  return 0;
}

