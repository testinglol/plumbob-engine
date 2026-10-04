
int __thiscall FUN_005942c4(int param_1,byte *param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  bool bVar7;
  int local_8;
  
  local_8 = 0;
  iVar3 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 3;
  if (0 < iVar3) {
    puVar2 = *(undefined4 **)(param_1 + 4);
    do {
      pbVar4 = (byte *)*puVar2;
      pbVar6 = param_2;
      do {
        bVar1 = *pbVar4;
        bVar7 = bVar1 < *pbVar6;
        if (bVar1 != *pbVar6) {
LAB_0059430b:
          iVar5 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_00594310;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar4[1];
        bVar7 = bVar1 < pbVar6[1];
        if (bVar1 != pbVar6[1]) goto LAB_0059430b;
        pbVar4 = pbVar4 + 2;
        pbVar6 = pbVar6 + 2;
      } while (bVar1 != 0);
      iVar5 = 0;
LAB_00594310:
      if (iVar5 == 0) {
        return local_8;
      }
      local_8 = local_8 + 1;
      puVar2 = puVar2 + 2;
    } while (local_8 < iVar3);
  }
  return -1;
}

