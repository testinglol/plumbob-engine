
void __fastcall FUN_0049c4f6(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  
  iVar1 = FUN_00635845(s_AdvSwatchColorTable_006c6304,&DAT_006c1300);
  if (iVar1 != 0) {
    local_14 = 0;
    if (0 < *(int *)(param_1 + 0x4c)) {
      do {
        local_10 = 0;
        do {
          local_c = 0;
          if (0 < *(int *)(param_1 + 0x7c)) {
            do {
              local_18 = 4;
              puVar3 = (undefined2 *)
                       (*(int *)(*(int *)(param_1 + 0x70) + local_c * 4) +
                       (local_10 + local_14 * 2) * 8);
              do {
                uVar2 = FUN_004a457f(*puVar3);
                local_8 = (undefined1)((uint)uVar2 >> 0x10);
                local_6 = (undefined1)uVar2;
                local_7 = (undefined1)((uint)uVar2 >> 8);
                FUN_006360af(&local_8,1,3,iVar1);
                puVar3 = puVar3 + 1;
                local_18 = local_18 + -1;
              } while (local_18 != 0);
              local_c = local_c + 1;
            } while (local_c < *(int *)(param_1 + 0x7c));
          }
          local_10 = local_10 + 1;
        } while (local_10 < 2);
        local_14 = local_14 + 1;
      } while (local_14 < *(int *)(param_1 + 0x4c));
    }
    FUN_0063558d(iVar1);
  }
  return;
}

