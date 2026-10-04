
void FUN_0060e980(uint *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,uint param_7)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = FUN_0060ea10(param_3);
  uVar2 = FUN_0060ea10(param_4);
  uVar3 = FUN_0060ea10(param_5);
  uVar4 = FUN_0060ea10(param_6);
  if (0 < param_2) {
    param_3 = param_2;
    do {
      if (((*param_1 & uVar3) == uVar1) != param_7) {
        *param_1 = ~uVar4 & *param_1 | uVar4 & uVar2;
      }
      param_1 = param_1 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

