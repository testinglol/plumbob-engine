
int FUN_004e3df5(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = param_2 - param_1 >> 4;
  if (0 < iVar2) {
    do {
      FUN_005d499c(param_1);
      puVar1 = (undefined4 *)(param_1 + 0xc);
      param_1 = param_1 + 0x10;
      *(undefined4 *)(param_3 + 0xc) = *puVar1;
      param_3 = param_3 + 0x10;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return param_3;
}

