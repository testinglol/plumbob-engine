
undefined4 FUN_005cbac0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_3 + 0x24);
  if ((iVar3 == 0) || (param_1 == 0)) {
    uVar1 = 0;
  }
  else {
    for (iVar2 = *(int *)(param_3 + 8); iVar2 != 0; iVar2 = iVar2 + -1) {
      FUN_005cbcf8(param_1,iVar3,*(undefined4 *)(param_3 + 0xc),0);
      iVar3 = iVar3 + *(int *)(param_3 + 0x10);
      param_1 = param_1 + param_2;
    }
    uVar1 = 1;
  }
  return uVar1;
}

