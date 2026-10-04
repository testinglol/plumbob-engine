
void FUN_006104c0(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = *param_1;
  iVar6 = 0;
  if (0 < *(int *)(iVar1 + 0x14)) {
    do {
      iVar5 = 0;
      if (0 < *(int *)(iVar1 + 0x10)) {
        do {
          iVar1 = *(int *)(iVar1 + 0x18) * iVar5;
          uVar4 = *(undefined4 *)
                   (((int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3) + param_1[2] * iVar6 + param_1[1]);
          uVar2 = FUN_006105b0(param_1,iVar5,iVar6,param_4);
          iVar1 = FUN_00610cf0(uVar2,uVar4,param_3);
          if (iVar1 == 0) {
            uVar4 = FUN_00610980(param_1,uVar2,iVar5,iVar6,param_4);
            iVar1 = *(int *)(*param_2 + 0x18) * iVar5;
            iVar3 = ((int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3) + param_2[2] * iVar6;
            iVar1 = param_2[1];
          }
          else {
            iVar3 = *(int *)(*param_2 + 0x18) * iVar5;
            iVar1 = param_2[1];
            iVar3 = ((int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3) + param_2[2] * iVar6;
          }
          *(undefined4 *)(iVar3 + iVar1) = uVar4;
          iVar1 = *param_1;
          iVar5 = iVar5 + 1;
        } while (iVar5 < *(int *)(iVar1 + 0x10));
      }
      iVar1 = *param_1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(iVar1 + 0x14));
  }
  return;
}

