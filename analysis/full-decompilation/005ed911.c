
LONG __fastcall FUN_005ed911(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 7);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x24))(1);
    }
    LVar1 = 0;
  }
  else {
    LVar1 = param_1[7];
  }
  return LVar1;
}

