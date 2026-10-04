
int FUN_0041d2e1(int param_1,code *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_50;
  int local_4c;
  
  iVar2 = param_1;
  if (*(int *)(param_1 + 8) == 0) {
    iVar1 = FUN_0041a545(&local_50,*(undefined4 *)(param_1 + 0xc));
    if (iVar1 != 0) {
      return iVar1;
    }
    param_1 = local_4c + -0x4c;
    if (((param_1 < 0) || (0x40000000 < param_1)) || (local_50 != param_3)) {
      return -1;
    }
    iVar1 = FUN_0041ffd9(param_1);
    *(int *)(iVar2 + 8) = iVar1;
    if (iVar1 != 0) {
      iVar1 = FUN_004131a0(*(int *)(iVar2 + 0xc) + 0x4c);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_00420048(*(undefined4 *)(iVar2 + 8));
      if (iVar1 != 0) {
        iVar3 = FUN_00413178(iVar1,&param_1);
        if (iVar3 != 0) {
          FUN_00420028(*(undefined4 *)(iVar2 + 8));
          *(undefined4 *)(iVar2 + 8) = 0;
          return iVar3;
        }
        if (((~(*(byte *)(iVar2 + 4) >> 4) & 1) != 0) && (param_2 != (code *)0x0)) {
          (*param_2)(iVar1,param_1);
          *(ushort *)(iVar2 + 2) = *(ushort *)(iVar2 + 2) | 0x10;
        }
        FUN_0042004f(*(undefined4 *)(iVar2 + 8));
        goto LAB_0041d3c7;
      }
    }
    iVar2 = FUN_00633a1e();
  }
  else {
LAB_0041d3c7:
    iVar2 = 0;
  }
  return iVar2;
}

