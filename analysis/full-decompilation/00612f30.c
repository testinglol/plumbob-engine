
void FUN_00612f30(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_c;
  
  iVar1 = *(int *)(*param_1 + 0x10);
  iVar2 = *(int *)(*param_1 + 0x14);
  iVar5 = 0;
  if (0 < param_4) {
    local_c = 0;
    do {
      iVar6 = 0;
      if (0 < param_3) {
        iVar4 = 0;
        do {
          uVar3 = FUN_00612fc0(param_1,iVar4 / param_3,local_c / param_4);
          FUN_00613000(param_2,iVar6,iVar5,uVar3);
          iVar6 = iVar6 + 1;
          iVar4 = iVar4 + iVar1;
        } while (iVar6 < param_3);
      }
      iVar5 = iVar5 + 1;
      local_c = local_c + iVar2;
    } while (iVar5 < param_4);
  }
  return;
}

