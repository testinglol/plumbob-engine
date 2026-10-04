
int FUN_0040313a(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar6;
  undefined4 *puVar5;
  
  iVar1 = (param_2 - param_1) / 0x54;
  iVar3 = param_3;
  if (0 < iVar1) {
    iVar6 = param_3 - param_2;
    iVar2 = param_3;
    puVar4 = (undefined4 *)(param_2 + 0x50);
    param_3 = iVar1;
    do {
      puVar5 = puVar4 + -0x15;
      iVar3 = iVar2 + -0x54;
      FUN_0046f8e4(puVar4 + -0x29);
      param_3 = param_3 + -1;
      *(undefined4 *)(iVar2 + -8) = puVar4[-0x16];
      *(undefined4 *)(iVar6 + (int)puVar5) = *puVar5;
      iVar2 = iVar3;
      puVar4 = puVar5;
    } while (param_3 != 0);
  }
  return iVar3;
}

