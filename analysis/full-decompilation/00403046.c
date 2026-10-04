
int FUN_00403046(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = (param_2 - param_1) / 0x54;
  iVar2 = param_3;
  if (0 < iVar1) {
    puVar3 = (undefined4 *)(param_1 + 0x50);
    param_1 = param_3 - param_1;
    param_3 = iVar1;
    do {
      FUN_0046f8e4(puVar3 + -0x14);
      *(undefined4 *)(iVar2 + 0x4c) = puVar3[-1];
      *(undefined4 *)(param_1 + (int)puVar3) = *puVar3;
      iVar2 = iVar2 + 0x54;
      puVar3 = puVar3 + 0x15;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return iVar2;
}

