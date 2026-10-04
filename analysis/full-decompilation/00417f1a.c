
int FUN_00417f1a(int param_1,code *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_14 [4];
  int local_10;
  
  iVar2 = param_1;
  if (*(int *)(param_1 + 0x10) == 0) {
    iVar1 = FUN_004181b3(local_14,*(undefined4 *)(param_1 + 8));
    if (iVar1 != 0) {
      return iVar1;
    }
    param_1 = local_10 + -0x10;
    iVar1 = FUN_0041ffd9(param_1);
    *(int *)(iVar2 + 0x10) = iVar1;
    if (iVar1 != 0) {
      iVar1 = FUN_004131a0(*(int *)(iVar2 + 8) + 0x10);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_00420048(*(undefined4 *)(iVar2 + 0x10));
      if (iVar1 != 0) {
        iVar3 = FUN_00413178(iVar1,&param_1);
        if (iVar3 != 0) {
          return iVar3;
        }
        if (((~(*(byte *)(iVar2 + 6) >> 4) & 1) != 0) && (param_2 != (code *)0x0)) {
          (*param_2)(iVar1,param_1);
          *(byte *)(iVar2 + 6) = *(byte *)(iVar2 + 6) | 0x10;
        }
        FUN_0042004f(*(undefined4 *)(iVar2 + 0x10));
        goto LAB_00417fbc;
      }
    }
    iVar2 = FUN_00633a1e();
  }
  else {
LAB_00417fbc:
    iVar2 = 0;
  }
  return iVar2;
}

