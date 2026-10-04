
void FUN_004924fd(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = FUN_004893e4();
  uVar1 = uVar1 >> 5 & 1;
  if (param_2 == 0) {
    if (uVar1 == 0) {
      return;
    }
  }
  else if (uVar1 != 0) {
    return;
  }
  FUN_00461b74(param_1);
  FUN_0049256d();
  FUN_00492be0();
  return;
}

