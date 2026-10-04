
int FUN_005833a9(int param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int local_8;
  
  local_8 = 0;
  puVar6 = param_2;
  while( true ) {
    do {
      if ((int)param_3 < 1) {
        return local_8;
      }
      uVar1 = *(int *)(param_1 + 0x14) - (int)*(undefined4 **)(param_1 + 0x10);
      if ((int)param_3 < (int)uVar1) {
        uVar1 = param_3;
      }
      param_2 = puVar6;
      if (0 < (int)uVar1) {
        param_2 = (undefined4 *)((int)puVar6 + uVar1);
        puVar5 = *(undefined4 **)(param_1 + 0x10);
        for (uVar4 = uVar1 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        param_3 = param_3 - uVar1;
        for (uVar4 = uVar1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        }
        *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + uVar1;
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + uVar1;
        local_8 = local_8 + uVar1;
      }
      puVar6 = param_2;
    } while (*(int *)(param_1 + 0x14) != *(int *)(param_1 + 0x10));
    if (param_3 == 0) {
      return local_8;
    }
    iVar2 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);
    iVar3 = param_1 + 0x424;
    *(int *)(param_1 + 0x14) = iVar3;
    *(int *)(param_1 + 0x10) = iVar3;
    if (iVar2 < 0x2001) break;
    iVar2 = 0x2000;
LAB_00583428:
    iVar3 = FUN_005b8e6a(iVar3,iVar2);
    if (0 < iVar3) {
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x10) + iVar3;
    }
    if (iVar3 == 0) {
LAB_00583441:
      param_3 = 0;
    }
  }
  if (0 < iVar2) goto LAB_00583428;
  goto LAB_00583441;
}

