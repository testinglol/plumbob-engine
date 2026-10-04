
void __thiscall FUN_0046a9d1(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  
  *param_1 = param_2;
  FUN_0046a7c5(param_2);
  FUN_004071be(param_1[1],param_1[2]);
  FUN_004071be(param_1[4],param_1[5]);
  FUN_0042ede2(param_1[7],param_1[8]);
  param_1[0x15] = 0xffffffff;
  param_1[10] = 0;
  param_1[0x16] = 0;
  param_1[0xb] = 0;
  cVar1 = FUN_0046a16d();
  if (cVar1 != '\0') {
    param_1[10] = 1;
  }
  return;
}

