
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00422462(int param_1,int *param_2,int param_3)

{
  ushort uVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined1 local_cc [8];
  undefined4 local_c4;
  undefined1 local_58 [24];
  float local_40;
  int local_38 [6];
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  FUN_00437961(&local_20,param_3);
  if ((*(short *)(param_1 + 0x1b0) == 0) && (*(int *)(param_1 + 0x1ac) != 0)) {
    cVar2 = FUN_00422665(param_1 + 0x1b4);
    if ((cVar2 == '\0') && (*(short *)(param_1 + 0x8e) == 0)) {
      FUN_0043908c(1);
      iVar4 = *(int *)(param_1 + 0x1ac);
      local_10 = *(undefined4 *)(iVar4 + 0xf4);
      local_c = *(undefined4 *)(iVar4 + 0xf8);
      local_38[5] = *(undefined4 *)(iVar4 + 0x110);
      FUN_00433ef5(param_1 + 0x1b4,*(undefined4 *)(param_1 + 0x1bc),0);
      FUN_004b45e2(param_3);
      uVar1 = *(ushort *)(*(int *)(param_1 + 0x1ac) + 0x52);
      if ((uVar1 & 1) == 0) {
        local_38[1] = 3;
        iVar4 = 2;
        local_38[2] = 4;
        local_38[0] = 2;
        local_38[3] = 8;
        local_38[4] = 0;
        local_8 = 0;
        piVar3 = local_38;
        do {
          if (((int)(short)uVar1 & 1 << ((char)iVar4 - 1U & 0x1f)) != 0) break;
          iVar4 = piVar3[1];
          local_8 = local_8 + 1;
          piVar3 = piVar3 + 1;
        } while (iVar4 != 0);
        iVar4 = local_38[local_8];
        if (iVar4 != 0) {
          FUN_0046dfaf();
          FUN_0046e014(iVar4);
          *(float *)(param_1 + 0x1c0) = *(float *)(param_3 + 8) + local_40;
        }
      }
      if (*(float *)(param_1 + 0x1c0) == _DAT_00666c18) {
        *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(param_3 + 8);
        iVar4 = param_1;
        iVar5 = *(int *)(param_1 + 400);
        if (*(int *)(param_1 + 400) != 0) goto LAB_004225b1;
        while (iVar5 = iVar4, iVar4 != 0) {
LAB_004225b1:
          *(undefined4 *)(iVar5 + 0x1c0) = *(undefined4 *)(param_1 + 0x1c0);
          iVar4 = *(int *)(iVar5 + 0x18c);
        }
      }
      local_c4 = *(undefined4 *)(param_1 + 0x1c0);
      FUN_004b9b69(local_cc);
      FUN_004b46f6(1);
      (**(code **)(**(int **)(param_1 + 0x1ac) + 0x30))(local_58,local_cc);
      FUN_00422698();
      FUN_00433ef5(&local_10,local_38[5],0);
      FUN_00439016(local_58,1);
    }
  }
  if ((local_1c < local_14) && (local_20 < local_18)) {
    FUN_00439016(&local_20,1);
  }
  *param_2 = local_20;
  param_2[1] = local_1c;
  param_2[2] = local_18;
  param_2[3] = local_14;
  return;
}

