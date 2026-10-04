
undefined4 * FUN_00469315(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = (param_2 - param_1) / 0xc;
  if (0 < iVar3) {
    puVar4 = (undefined4 *)(param_1 + 8);
    param_1 = (int)param_3 - param_1;
    do {
      uVar1 = *puVar4;
      *param_3 = puVar4[-2];
      uVar2 = puVar4[-1];
      *(undefined4 *)(param_1 + (int)puVar4) = uVar1;
      param_3[1] = uVar2;
      param_3 = param_3 + 3;
      puVar4 = puVar4 + 3;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return param_3;
}

