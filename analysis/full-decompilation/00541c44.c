
void FUN_00541c44(int param_1,uint param_2,uint param_3,undefined4 param_4,code *param_5)

{
  char cVar1;
  uint uVar2;
  
  FUN_005420b2(param_1,param_2);
  for (uVar2 = param_2; uVar2 < param_3; uVar2 = uVar2 + 4) {
    cVar1 = (*param_5)();
    if (cVar1 != '\0') {
      FUN_005414bc(uVar2);
      FUN_00541eb5(param_1,param_2,uVar2);
    }
  }
  uVar2 = param_2 - param_1;
  while (4 < (int)(uVar2 & 0xfffffffc)) {
    param_2 = param_2 - 4;
    FUN_005422ef(param_1);
    uVar2 = param_2 - param_1;
  }
  return;
}

