
void FUN_00534caa(int param_1,uint param_2,uint param_3,undefined4 param_4,code *param_5)

{
  char cVar1;
  uint uVar2;
  
  FUN_00534f67();
  for (uVar2 = param_2; uVar2 < param_3; uVar2 = uVar2 + 0x28) {
    cVar1 = (*param_5)();
    if (cVar1 != '\0') {
      FUN_00533d58(uVar2);
      FUN_00534e65(param_1,param_2,uVar2);
    }
  }
  for (; 1 < (int)(param_2 - param_1) / 0x28; param_2 = param_2 - 0x28) {
    FUN_005350f1();
  }
  return;
}

