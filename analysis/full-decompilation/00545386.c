
void __fastcall FUN_00545386(int param_1)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  char *pcVar6;
  char **ppcVar7;
  uint uVar8;
  int iVar9;
  undefined1 local_34 [16];
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  char *local_10;
  char *local_c;
  char *local_8;
  
  iVar9 = 200;
  local_c = (char *)(*(int *)((*(int **)(param_1 + 0xd8))[1] + 0x80) -
                    *(int *)(**(int **)(param_1 + 0xd8) + 0x80));
  iVar5 = **(int **)(param_1 + 0x130);
  sVar1 = _strlen((char *)(param_1 + 0x148));
  iVar2 = (**(code **)(iVar5 + 0x68))(param_1 + 0x148,sVar1);
  iVar5 = **(int **)(param_1 + 0xd8);
  if ((*(int *)(iVar5 + 0x84) - *(int *)(iVar5 + 0x7c)) + 0xd7 < iVar2) {
    iVar9 = (iVar2 - *(int *)(iVar5 + 0x84)) + -0xf + *(int *)(iVar5 + 0x7c);
  }
  *(undefined4 *)(param_1 + 0xf0) = 0xf;
  *(undefined4 *)(param_1 + 0xf4) = 10;
  iVar5 = **(int **)(param_1 + 0xd8);
  iVar2 = *(int *)(iVar5 + 0x84);
  iVar5 = *(int *)(iVar5 + 0x7c);
  iVar3 = (**(code **)(**(int **)(param_1 + 0x130) + 0x58))();
  iVar3 = *(int *)(param_1 + 0xf4) + iVar3;
  *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf0) + (iVar2 - iVar5) + 0xf + iVar9;
  *(int *)(param_1 + 0xfc) = iVar3;
  *(undefined4 *)(param_1 + 0x100) = *(undefined4 *)(param_1 + 0xf0);
  *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0xf4) + (iVar3 - *(int *)(param_1 + 0xf4)) + 10;
  uVar8 = 0;
  *(int *)(param_1 + 0x108) =
       *(int *)(param_1 + 0x100) +
       (*(int *)(**(int **)(param_1 + 0xd8) + 0x84) - *(int *)(**(int **)(param_1 + 0xd8) + 0x7c));
  *(int *)(param_1 + 0x10c) =
       *(int *)(param_1 + 0x104) +
       (*(int *)(param_1 + 0xdc) - *(int *)(param_1 + 0xd8) >> 2) * (int)local_c;
  if (*(int *)(param_1 + 0xdc) - *(int *)(param_1 + 0xd8) >> 2 != 0) {
    local_8 = (char *)0x0;
    do {
      FUN_004cb21d(*(undefined4 *)(param_1 + 0x100),local_8 + *(int *)(param_1 + 0x104));
      uVar8 = uVar8 + 1;
      local_8 = local_8 + (int)local_c;
    } while (uVar8 < (uint)(*(int *)(param_1 + 0xdc) - *(int *)(param_1 + 0xd8) >> 2));
  }
  local_24 = 0;
  local_20 = 0;
  local_18 = 0;
  local_14 = (*(int *)(param_1 + 0x108) - *(int *)(param_1 + 0x100)) + 0xf +
             *(int *)(param_1 + 0x100);
  local_10 = *(char **)(param_1 + 0x104);
  local_1c = iVar9;
  puVar4 = (undefined4 *)FUN_004e84f4(local_34,&local_24);
  *(undefined4 *)(param_1 + 0x110) = *puVar4;
  *(undefined4 *)(param_1 + 0x114) = puVar4[1];
  *(undefined4 *)(param_1 + 0x118) = puVar4[2];
  *(undefined4 *)(param_1 + 0x11c) = puVar4[3];
  local_c = (char *)(**(code **)(**(int **)(param_1 + 0x134) + 100))
                              (*(int *)(param_1 + 0x13c),
                               *(int *)(param_1 + 0x140) - *(int *)(param_1 + 0x13c),iVar9);
  iVar5 = (**(code **)(**(int **)(param_1 + 0x134) + 0x58))();
  pcVar6 = (char *)((*(int *)(param_1 + 0x10c) - *(int *)(param_1 + 0x104)) / iVar5);
  iVar5 = (**(code **)(**(int **)(param_1 + 0x134) + 0x58))();
  if ((*(int *)(param_1 + 0x10c) - *(int *)(param_1 + 0x104)) % iVar5 != 0) {
    pcVar6 = pcVar6 + 1;
  }
  if ((int)pcVar6 < (int)local_c) {
    iVar5 = (**(code **)(**(int **)(param_1 + 0x134) + 0x58))();
    iVar5 = iVar5 * (int)pcVar6 + *(int *)(param_1 + 0x114);
    *(int *)(param_1 + 0x11c) = iVar5;
    *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(param_1 + 0x100);
    *(int *)(param_1 + 0x124) = iVar5;
    local_10 = *(char **)(param_1 + 0x13c);
    *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x118);
    local_8 = local_10;
    if (0 < (int)pcVar6) {
      do {
        local_c = pcVar6;
        iVar5 = **(int **)(param_1 + 0x134);
        iVar2 = iVar9;
        sVar1 = _strlen(local_8);
        iVar5 = (**(code **)(iVar5 + 0x60))(local_8,sVar1,iVar2);
        local_8 = local_8 + iVar5;
        local_c = local_c + -1;
        pcVar6 = local_c;
      } while (local_c != (char *)0x0);
    }
    iVar9 = (int)local_8 - (int)local_10;
    *(int *)(param_1 + 0x138) = iVar9;
    iVar9 = (**(code **)(**(int **)(param_1 + 0x134) + 100))
                      (*(int *)(param_1 + 0x13c) + iVar9,
                       (*(int *)(param_1 + 0x140) - *(int *)(param_1 + 0x13c)) - iVar9,
                       *(int *)(param_1 + 0x128) - *(int *)(param_1 + 0x120));
    iVar5 = (**(code **)(**(int **)(param_1 + 0x134) + 0x58))();
    *(int *)(param_1 + 300) = iVar5 * iVar9 + *(int *)(param_1 + 0x124);
    local_10 = (char *)(*(int *)(param_1 + 0x10c) - *(int *)(param_1 + 0x104));
    local_c = (char *)(*(int *)(param_1 + 0x11c) - *(int *)(param_1 + 0x114));
    ppcVar7 = &local_10;
    if ((int)local_10 <= (int)local_c) {
      ppcVar7 = &local_c;
    }
    FUN_004cb1a2((*(int *)(param_1 + 0x128) - *(int *)(param_1 + 0x120)) + 0x1e,
                 *ppcVar7 +
                 ((*(int *)(param_1 + 0xfc) - *(int *)(param_1 + 0xf4)) - *(int *)(param_1 + 0x124))
                 + *(int *)(param_1 + 300) + 0x1e);
    if ((iVar9 == 1) &&
       (iVar9 = (**(code **)(**(int **)(param_1 + 0x134) + 0x68))
                          (*(int *)(param_1 + 0x13c) + *(int *)(param_1 + 0x138),
                           (*(int *)(param_1 + 0x140) - *(int *)(param_1 + 0x13c)) -
                           *(int *)(param_1 + 0x138)),
       iVar9 < *(int *)(param_1 + 0x118) - *(int *)(param_1 + 0x110))) {
      *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(param_1 + 0x110);
    }
  }
  else {
    iVar9 = (**(code **)(**(int **)(param_1 + 0x134) + 0x58))();
    *(undefined4 *)(param_1 + 0x138) = 0;
    iVar9 = iVar9 * (int)local_c + *(int *)(param_1 + 0x114);
    *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(param_1 + 0x100);
    *(int *)(param_1 + 0x11c) = iVar9;
    *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x118);
    *(int *)(param_1 + 0x124) = iVar9;
    *(int *)(param_1 + 300) = iVar9;
    local_c = (char *)(*(int *)(param_1 + 0x10c) - *(int *)(param_1 + 0x104));
    local_8 = (char *)(*(int *)(param_1 + 0x11c) - *(int *)(param_1 + 0x114));
    ppcVar7 = &local_c;
    if ((int)local_c <= (int)local_8) {
      ppcVar7 = &local_8;
    }
    FUN_004cb1a2((*(int *)(param_1 + 0x128) - *(int *)(param_1 + 0x120)) + 0x1e,
                 *ppcVar7 +
                 ((*(int *)(param_1 + 300) - *(int *)(param_1 + 0x124)) - *(int *)(param_1 + 0xf4))
                 + *(int *)(param_1 + 0xfc) + 0x1e);
  }
  return;
}

