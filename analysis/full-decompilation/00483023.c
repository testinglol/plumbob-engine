
void __fastcall FUN_00483023(int *param_1)

{
  char cVar1;
  
  if (param_1[10] == 1) {
    param_1[0xb] = param_1[0xb] + 1;
    cVar1 = FUN_0046a1f7();
    if (cVar1 != '\0') {
      param_1[10] = -(uint)(*(char *)(*param_1 + 0x30) != '\0') & 2;
      return;
    }
  }
  else if (param_1[10] == 2) {
    param_1[0xb] = param_1[0xb] + 1;
    cVar1 = FUN_0046a497();
    if (cVar1 != '\0') {
      param_1[10] = 0;
    }
  }
  return;
}

