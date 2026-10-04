
void __thiscall FUN_005bc6cb(uint *param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 == 0xffffffff) {
    param_2 = FUN_006388c5(0);
    uVar1 = FUN_0063884d();
    param_2 = (uVar1 << 0x10 | uVar1) ^ param_2;
  }
  *param_1 = param_2;
  param_1[1] = param_2;
  return;
}

