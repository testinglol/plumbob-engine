
void FUN_00625260(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_14;
  
  iVar1 = *(int *)(*param_1 + 0x10);
  local_14 = *(int *)(*param_1 + 0x14);
  if (0 < local_14) {
    iVar2 = param_1[2];
    iVar3 = param_1[1];
    do {
      iVar4 = iVar3;
      iVar5 = iVar1;
      if (0 < iVar1) {
        do {
          FUN_006252f0(iVar4,param_2,param_3,param_4,param_5,param_6,param_7);
          iVar4 = iVar4 + 4;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      iVar3 = iVar3 + iVar2;
      local_14 = local_14 + -1;
    } while (local_14 != 0);
  }
  return;
}

