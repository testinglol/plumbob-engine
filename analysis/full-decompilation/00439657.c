
void FUN_00439657(int param_1,uint param_2,uint param_3,undefined4 param_4,code *param_5)

{
  char cVar1;
  uint uVar2;
  
  FUN_0043991e();
  for (uVar2 = param_2; uVar2 < param_3; uVar2 = uVar2 + 0x10) {
    cVar1 = (*param_5)();
    if (cVar1 != '\0') {
      FUN_004393d9(uVar2);
      FUN_004397b7(param_1,param_2,uVar2);
    }
  }
  uVar2 = param_2 - param_1;
  while (0x10 < (int)(uVar2 & 0xfffffff0)) {
    param_2 = param_2 - 0x10;
    FUN_00439b06();
    uVar2 = param_2 - param_1;
  }
  return;
}

