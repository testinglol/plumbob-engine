
void __fastcall FUN_0043e1d5(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined1 local_118 [256];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  char local_5;
  
  local_5 = '\x01';
  FUN_0046494e(&local_5);
  if (local_5 != '\0') {
    FUN_004645e3();
  }
  local_14 = *(int *)(param_1 + 0x1254) - *(int *)(param_1 + 0x1250) >> 2;
  FUN_00464a4e(&local_14,1);
  local_c = 0;
  if (0 < local_14) {
    do {
      local_18 = **(int **)(*(int *)(param_1 + 0x1250) + local_c * 4);
      FUN_00464a5e(&local_18,1);
      for (piVar1 = *(int **)(param_1 + 0x1250); piVar1 != *(int **)(param_1 + 0x1254);
          piVar1 = piVar1 + 1) {
        if (*(int *)*piVar1 == local_18) {
          iVar2 = *piVar1;
          goto LAB_0043e272;
        }
      }
      iVar2 = 0;
LAB_0043e272:
      if (iVar2 == 0) {
        iVar6 = 0x80;
        puVar5 = local_118;
      }
      else {
        iVar6 = *(int *)(iVar2 + 4);
        puVar5 = *(undefined1 **)(iVar2 + 8);
      }
      local_10 = iVar6;
      FUN_00464a4e(&local_10,1);
      if (iVar6 < local_10) {
        return;
      }
      FUN_00464973(puVar5,local_10);
      if (local_10 < iVar6) {
        uVar3 = iVar6 - local_10;
        puVar7 = (undefined4 *)(puVar5 + local_10 * 2);
        for (uVar4 = uVar3 >> 1; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
        }
        for (uVar3 = (uint)((uVar3 & 1) != 0); uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined2 *)puVar7 = 0;
          puVar7 = (undefined4 *)((int)puVar7 + 2);
        }
      }
      local_c = local_c + 1;
    } while (local_c < local_14);
  }
  return;
}

