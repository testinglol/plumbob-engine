
void __fastcall FUN_00445999(int param_1)

{
  undefined4 *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  uint local_90;
  uint local_70;
  undefined **local_64;
  undefined4 local_60;
  undefined1 local_58 [64];
  int local_18;
  int local_14;
  int local_10;
  int *local_c;
  int *local_8;
  
  FUN_006323d0(s_Action_Queues__006c3d88);
  for (local_8 = *(int **)(param_1 + 0x84); local_8 != *(int **)(param_1 + 0x88);
      local_8 = local_8 + 1) {
    uVar4 = *(undefined4 *)(*(int *)(*local_8 + 0x11c) + 0x18);
    local_70 = (uint)*(ushort *)(*local_8 + 0xf0);
    puVar5 = &DAT_006c08dc;
    puVar2 = &DAT_006c25a8;
    FUN_006323d0(s_Person_006c3d80);
    FUN_006330c7(local_70);
    FUN_006323d0(puVar2);
    FUN_006323d0(uVar4);
    FUN_006323d0(puVar5);
    for (local_10 = 0; local_10 < *(int *)(*local_8 + 0xa44) - *(int *)(*local_8 + 0xa40);
        local_10 = local_10 + 1) {
      local_14 = FUN_0045d8f7(local_10);
      puVar2 = &DAT_006c3d7c;
      iVar3 = local_10;
      FUN_006323d0(s_Position_006c3d70);
      FUN_006321fb(iVar3);
      FUN_006323d0(puVar2);
      if (local_14 == 0) {
        FUN_006323d0(s_NULL_006c3d50);
      }
      else {
        puVar1 = (undefined4 *)FUN_0041f169();
        puVar2 = &DAT_006c08dc;
        FUN_006323d0(*puVar1);
        FUN_006323d0(puVar2);
        FUN_006323d0(s_Object_006c3d68);
        local_18 = *(int *)(local_14 + 8);
        if (local_18 == 0) {
          FUN_006323d0(s_NULL_006c3d50);
        }
        else {
          uVar4 = *(undefined4 *)(*(int *)(local_18 + 0x11c) + 0x18);
          puVar5 = &DAT_006c08dc;
          puVar2 = &DAT_006c25a8;
          FUN_006330c7(*(undefined2 *)(local_18 + 0xf0));
          FUN_006323d0(puVar2);
          FUN_006323d0(uVar4);
          FUN_006323d0(puVar5);
          FUN_0046f824(local_58,0,0x40);
          local_64 = &PTR_FUN_0066651c;
          FUN_00402122(*(undefined2 *)(local_14 + 0x20),&local_64);
          local_90 = (uint)*(ushort *)(local_14 + 0x20);
          puVar5 = &DAT_006c08dc;
          puVar2 = &DAT_006c25a8;
          uVar4 = local_60;
          FUN_006323d0(s_Action_tree_006c3d58);
          FUN_006330c7(local_90);
          FUN_006323d0(puVar2);
          FUN_006323d0(uVar4);
          FUN_006323d0(puVar5);
        }
        uVar4 = *(undefined4 *)(local_14 + 0x1c);
        puVar2 = &DAT_006c08dc;
        FUN_006323d0(s_Priority_006c3d44);
        FUN_006321fb(uVar4);
        FUN_006323d0(puVar2);
        uVar4 = *(undefined4 *)(local_14 + 0x10);
        puVar2 = &DAT_006c08dc;
        FUN_006323d0(s_Entry_Index_006c3d34);
        FUN_006321fb(uVar4);
        FUN_006323d0(puVar2);
      }
    }
  }
  FUN_006323d0(s_Objects__006c3d28);
  for (local_c = *(int **)(param_1 + 0x18); local_c != *(int **)(param_1 + 0x1c);
      local_c = local_c + 1) {
    if (*local_c != 0) {
      uVar4 = *(undefined4 *)(*(int *)(*local_c + 0x11c) + 0x18);
      puVar5 = &DAT_006c08dc;
      puVar2 = &DAT_006c285c;
      FUN_006330c7(*(undefined2 *)(*local_c + 0xf0));
      FUN_006323d0(puVar2);
      FUN_006323d0(uVar4);
      FUN_006323d0(puVar5);
    }
  }
  return;
}

