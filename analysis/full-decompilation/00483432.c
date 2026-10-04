
void __fastcall FUN_00483432(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  short sVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int local_44;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  int local_c;
  char local_5;
  
  iVar1 = *(int *)(param_1 + 0x4c);
  iVar2 = *(int *)(iVar1 + 0xf4);
  iVar3 = *(int *)(iVar1 + 0xf8);
  *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(iVar1 + 0xf4);
  uVar4 = *(undefined4 *)(iVar1 + 0xf8);
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x70) = uVar4;
  FUN_0043270d(iVar1);
  if (local_44 != 0) {
    FUN_00457da4();
    sVar6 = FUN_004561a0(0x1a);
    if (sVar6 != 0) {
      local_5 = '\0';
      local_c = 0;
      iVar1 = *(int *)(*(int *)(param_1 + 0x48) + 0xf4);
      local_10 = (uint)*(short *)(*(int *)(local_44 + 0x118) + 0x84);
      iVar5 = *(int *)(*(int *)(param_1 + 0x48) + 0xf8);
      do {
        local_14 = 1 << ((byte)local_c & 0x1f);
        if ((local_10 & local_14) != 0) {
          uVar10 = *(short *)(local_44 + 0x4c) + local_c & 7;
          local_20 = iVar2;
          local_1c = iVar3;
          piVar7 = (int *)FUN_004222bd(uVar10);
          local_1c = local_1c + piVar7[1];
          local_20 = local_20 + *piVar7;
          iVar8 = FUN_00481593(&local_20,uVar10);
          if (((iVar8 == 6) || (iVar8 == 5)) &&
             ((iVar9 = iVar5 - local_1c, iVar8 = iVar1 - local_20,
              iVar8 = iVar8 * iVar8 + iVar9 * iVar9, local_5 == '\0' || (iVar8 < local_18)))) {
            *(int *)(param_1 + 0x6c) = local_20;
            *(int *)(param_1 + 0x70) = local_1c;
            *(uint *)(param_1 + 0x74) = local_14;
            local_5 = '\x01';
            local_18 = iVar8;
          }
        }
        local_c = local_c + 1;
      } while (local_c < 8);
    }
  }
  return;
}

