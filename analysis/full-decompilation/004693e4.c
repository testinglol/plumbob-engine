
undefined4 * FUN_004693e4(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  
  iVar3 = (param_2 - param_1) / 0xc;
  if (0 < iVar3) {
    iVar6 = (int)param_3 - param_2;
    puVar4 = (undefined4 *)(param_2 + 8);
    puVar7 = param_3;
    do {
      puVar5 = puVar4 + -3;
      param_3 = puVar7 + -3;
      iVar3 = iVar3 + -1;
      uVar1 = *puVar5;
      *param_3 = puVar4[-5];
      uVar2 = puVar4[-4];
      *(undefined4 *)(iVar6 + (int)puVar5) = uVar1;
      puVar7[-2] = uVar2;
      puVar4 = puVar5;
      puVar7 = param_3;
    } while (iVar3 != 0);
  }
  return param_3;
}

