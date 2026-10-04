
void FUN_006206d0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (0 < param_4) {
    param_2 = param_2 - param_1;
    do {
      if (0 < param_3) {
        puVar2 = (undefined4 *)(param_2 + param_1);
        puVar1 = (undefined4 *)(param_1 + -4 + param_3 * 4);
        iVar3 = param_3;
        do {
          *puVar2 = *puVar1;
          puVar1 = puVar1 + -1;
          puVar2 = puVar2 + 1;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      param_1 = param_1 + param_5;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}

