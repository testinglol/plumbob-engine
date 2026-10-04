
int FUN_0041adce(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = (param_2 - param_1) / 0x14;
  iVar2 = param_3;
  if (0 < iVar1) {
    puVar3 = (undefined4 *)(param_1 + 0x10);
    param_1 = param_3 - param_1;
    param_3 = iVar1;
    do {
      FUN_0041afab(puVar3 + -4);
      *(undefined4 *)(iVar2 + 0xc) = puVar3[-1];
      *(undefined4 *)(param_1 + (int)puVar3) = *puVar3;
      iVar2 = iVar2 + 0x14;
      puVar3 = puVar3 + 5;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return iVar2;
}

