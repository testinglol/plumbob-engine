
void FUN_00426ba5(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined *puVar2;
  
  uVar1 = FUN_005bc722(1000);
  if (uVar1 % 100 < 0x21) {
    puVar2 = &DAT_006c1010;
  }
  else if (uVar1 % 100 < 0x42) {
    puVar2 = &DAT_006c100c;
  }
  else {
    puVar2 = &DAT_006c1008;
  }
  FUN_0040bfed(puVar2);
  FUN_00426c0a(param_1,param_2,param_3,param_4);
  return;
}

