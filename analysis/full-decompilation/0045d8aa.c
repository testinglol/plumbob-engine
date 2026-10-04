
int __thiscall FUN_0045d8aa(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2;
  iVar2 = param_2 - param_1;
  param_2 = 8;
  iVar3 = param_1;
  do {
    FUN_0041edc1(iVar2 + iVar3);
    iVar3 = iVar3 + 0x44;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  *(undefined4 *)(param_1 + 0x220) = *(undefined4 *)(iVar1 + 0x220);
  *(undefined4 *)(param_1 + 0x224) = *(undefined4 *)(iVar1 + 0x224);
  return param_1;
}

