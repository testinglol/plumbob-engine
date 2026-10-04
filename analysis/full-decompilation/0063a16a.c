
int FUN_0063a16a(int param_1,char *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  uint *puVar3;
  undefined1 *puVar4;
  undefined1 uVar5;
  int iVar6;
  BOOL BVar7;
  int iVar8;
  int *piVar9;
  char *pcVar10;
  uint uVar11;
  bool bVar12;
  uint local_40 [6];
  int *local_28;
  int local_24;
  uint local_20;
  HANDLE local_1c;
  uint local_18;
  HANDLE local_14;
  HANDLE local_10;
  uint local_c;
  undefined1 local_5;
  
  uVar11 = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (param_2 == (char *)0x0) {
    return 0;
  }
  if ((*param_2 != 'w') && (*param_2 != 'r')) {
    return 0;
  }
  if (param_2[1] == 't') {
    uVar11 = 0x4000;
  }
  else if (param_2[1] == 'b') {
    uVar11 = 0x8000;
  }
  iVar6 = FUN_00645ca2(local_40,0x400,uVar11 | 0x80);
  if (iVar6 == -1) {
    return 0;
  }
  bVar12 = *param_2 != 'w';
  local_c = (uint)bVar12;
  local_18 = (uint)!bVar12;
  local_20 = (uint)bVar12;
  local_40[3] = 1;
  local_40[2] = 1;
  local_10 = GetCurrentProcess();
  uVar11 = local_c;
  FUN_006459ff(local_c);
  piVar2 = &DAT_00704000 + ((int)uVar11 >> 5);
  iVar6 = (uVar11 & 0x1f) * 0x24;
  if ((*(HANDLE *)(iVar6 + *piVar2) == (HANDLE)0xffffffff) ||
     (BVar7 = DuplicateHandle(local_10,*(HANDLE *)(iVar6 + *piVar2),local_10,&local_1c,0,0,2),
     BVar7 == 0)) goto LAB_0063a47a;
  local_5 = *(undefined1 *)(iVar6 + 4 + *piVar2);
  local_40[5] = local_20 * 4;
  puVar3 = local_40 + local_20;
  BVar7 = DuplicateHandle(local_10,*(HANDLE *)
                                    ((&DAT_00704000)[(int)*puVar3 >> 5] + (*puVar3 & 0x1f) * 0x24),
                          local_10,&local_14,0,1,2);
  if (BVar7 != 0) {
    CloseHandle(*(HANDLE *)(iVar6 + *piVar2));
    FUN_0064593e(local_c);
    FUN_006458c2(local_c,local_14);
    *(undefined1 *)(iVar6 + 4 + *piVar2) =
         *(undefined1 *)((&DAT_00704000)[(int)*puVar3 >> 5] + 4 + (*puVar3 & 0x1f) * 0x24);
    FUN_0063cf81(*puVar3);
    *(undefined4 *)((int)local_40 + local_40[5] + 8) = 0;
    puVar3 = local_40 + local_18;
    local_40[5] = FUN_0063a63d(local_40[local_18],param_2);
    if (local_40[5] != 0) {
      FUN_0063d88b(0x10);
      local_28 = (int *)FUN_0063a50e(0);
      if (local_28 != (int *)0x0) {
        puVar1 = (undefined4 *)((&DAT_00704000)[(int)*puVar3 >> 5] + (*puVar3 & 0x1f) * 0x24);
        local_40[4] = *puVar1;
        *puVar1 = 0xffffffff;
        puVar4 = (undefined1 *)((&DAT_00704000)[(int)*puVar3 >> 5] + 4 + (*puVar3 & 0x1f) * 0x24);
        uVar5 = *puVar4;
        *puVar4 = 0;
        iVar8 = FUN_006384a8("COMSPEC");
        if (iVar8 == 0) {
LAB_0063a398:
          pcVar10 = "command.com";
          if ((DAT_00703ab5 & 0x80) == 0) {
            pcVar10 = "cmd.exe";
          }
          local_24 = FUN_00645c74(1,pcVar10,pcVar10,&DAT_00689380,param_1,0);
        }
        else {
          local_24 = FUN_00645c8a(1,iVar8,iVar8,&DAT_00689380,param_1,0);
          if ((local_24 == -1) &&
             ((piVar9 = (int *)FUN_0063d796(), *piVar9 == 2 ||
              (piVar9 = (int *)FUN_0063d796(), *piVar9 == 0xd)))) goto LAB_0063a398;
        }
        iVar8 = local_24;
        *(uint *)((&DAT_00704000)[(int)*puVar3 >> 5] + (*puVar3 & 0x1f) * 0x24) = local_40[4];
        *(undefined1 *)((&DAT_00704000)[(int)*puVar3 >> 5] + 4 + (*puVar3 & 0x1f) * 0x24) = uVar5;
        if (local_24 != -1) {
          DuplicateHandle(local_10,local_1c,local_10,&local_14,0,1,3);
          CloseHandle(*(HANDLE *)(iVar6 + *piVar2));
          FUN_0064593e(local_c);
          FUN_006458c2(local_c,local_14);
          *(undefined1 *)(iVar6 + 4 + *piVar2) = local_5;
          FUN_00645a5e(local_c);
          uVar11 = local_40[5];
          local_28[1] = iVar8;
          *local_28 = local_40[5];
          FUN_0063d8ec(0x10);
          return uVar11;
        }
        *local_28 = 0;
      }
      FUN_0063558d(local_40[5]);
      local_40[local_18 + 2] = 0;
      FUN_0063d8ec(0x10);
    }
    DuplicateHandle(local_10,local_1c,local_10,&local_14,0,1,2);
    CloseHandle(*(HANDLE *)(iVar6 + *piVar2));
    FUN_0064593e(local_c);
    FUN_006458c2(local_c,local_14);
    *(undefined1 *)(iVar6 + 4 + *piVar2) = local_5;
    FUN_00645a5e(local_c);
  }
  CloseHandle(local_1c);
LAB_0063a47a:
  if (local_40[local_20 + 2] != 0) {
    FUN_0063cf81(local_40[local_20]);
  }
  if (local_40[local_18 + 2] != 0) {
    FUN_0063cf81(local_40[local_18]);
  }
  return 0;
}

