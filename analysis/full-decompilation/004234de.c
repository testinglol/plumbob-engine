
void __fastcall FUN_004234de(int param_1)

{
  char cVar1;
  
  cVar1 = FUN_00432644();
  if (cVar1 != '\0') {
    if (*(int *)(param_1 + 400) != 0) {
      param_1 = *(int *)(param_1 + 400);
    }
    for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x18c)) {
      FUN_0042350b();
    }
  }
  return;
}

