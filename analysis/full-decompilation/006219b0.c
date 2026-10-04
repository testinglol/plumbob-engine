
undefined4
FUN_006219b0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)FUN_005a9320(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    puVar3 = puVar1;
    for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    puVar1[3] = param_3;
    puVar1[2] = param_2;
    puVar1[5] = param_5;
    puVar1[4] = param_4;
    *puVar1 = 1;
    *param_1 = puVar1;
    return 1;
  }
  *param_1 = 0;
  return 0;
}

