
void FUN_00623930(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9,int param_10,int param_11)

{
  undefined4 *puVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  int iVar10;
  byte *local_24;
  int local_1c;
  int local_14;
  
  iVar4 = (param_9 * param_9) / (param_10 * param_10);
  iVar10 = 0;
  local_14 = param_9;
  iVar5 = (param_9 / 2 + -1) * (param_5 + 1);
  if (param_9 < param_4 - param_9) {
    param_3 = param_3 + param_9 * -2;
    pbVar7 = (byte *)((param_5 + 1) * param_9 + param_1);
    do {
      local_24 = pbVar7 + param_5 * param_8;
      if (param_3 != 0) {
        pbVar9 = pbVar7 + param_2 + (-param_1 - iVar5);
        pbVar8 = pbVar7;
        local_1c = param_3;
        do {
          bVar2 = pbVar8[param_8];
          bVar3 = *pbVar8;
          puVar1 = (undefined4 *)(param_6 + (uint)bVar3 * 4);
          iVar6 = FUN_00623b20(*puVar1,*(undefined4 *)(param_6 + (uint)bVar2 * 4));
          if (param_7 < iVar6) {
            bVar2 = *local_24;
            iVar6 = FUN_00623b20(*puVar1,*(undefined4 *)(param_6 + (uint)bVar2 * 4));
            if (iVar6 <= param_7) {
              FUN_00623b80((int)pbVar8 - iVar5,pbVar9,param_9,param_10,bVar3,bVar2,
                           param_11 + iVar10 * 4,param_5);
              iVar10 = iVar10 + iVar4;
              if (iVar4 * 0xb <= iVar10) goto LAB_00623ac0;
            }
          }
          else {
            FUN_00623b80((int)pbVar8 - iVar5,pbVar9,param_9,param_10,bVar3,bVar2,
                         param_11 + iVar10 * 4,param_5);
            iVar10 = iVar10 + iVar4;
            if (iVar4 * 0xb <= iVar10) {
LAB_00623ac0:
              iVar10 = 0;
            }
          }
          local_24 = local_24 + param_8;
          pbVar8 = pbVar8 + param_8;
          pbVar9 = pbVar9 + param_8;
          local_1c = local_1c + -1;
        } while (local_1c != 0);
      }
      local_14 = local_14 + param_8;
      pbVar7 = pbVar7 + param_5 * param_8;
    } while (local_14 < param_4 - param_9);
  }
  return;
}

