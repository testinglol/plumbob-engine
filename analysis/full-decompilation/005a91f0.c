
void FUN_005a91f0(uint param_1,uint param_2,int param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  if ((param_2 < param_1) && (uVar2 = param_2 + param_3, param_1 < uVar2)) {
    puVar3 = (undefined1 *)(param_1 + param_3);
    if (param_3 != 0) {
      do {
        puVar1 = (undefined1 *)(uVar2 - 1);
        uVar2 = uVar2 - 1;
        puVar3 = puVar3 + -1;
        param_3 = param_3 + -1;
        *puVar3 = *puVar1;
      } while (param_3 != 0);
      return;
    }
  }
  else {
    FUN_005a92b0(param_1,param_2,param_3);
  }
  return;
}

