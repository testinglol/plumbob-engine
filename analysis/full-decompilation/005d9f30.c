
char __fastcall FUN_005d9f30(int param_1)

{
  int *piVar1;
  float fVar2;
  char cVar3;
  DWORD DVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_1c;
  undefined1 local_18 [4];
  int local_14;
  int local_10;
  float local_c;
  char local_5;
  
  local_5 = '\0';
  cVar3 = FUN_005da398(*(undefined4 *)(param_1 + 0x18c));
  if (cVar3 == '\0') {
    *(undefined4 *)(param_1 + 0x18c) = 0;
    return '\0';
  }
  if (*(int **)(param_1 + 0x174) == (int *)0x0) goto LAB_005da062;
  cVar3 = (**(code **)(**(int **)(param_1 + 0x174) + 0x8c))(0x400);
  if (cVar3 == '\0') {
    if (*(int *)(param_1 + 0x178) != 3) goto LAB_005da062;
    DVar4 = timeGetTime();
    if ((int)(DVar4 - *(int *)(param_1 + 0x17c)) < *(int *)(*(int *)(param_1 + 0x174) + 0xa4))
    goto LAB_005da062;
    *(undefined4 *)(param_1 + 0x178) = 1;
    DVar4 = timeGetTime();
    *(DWORD *)(param_1 + 0x17c) = DVar4;
  }
  else {
    if (*(int *)(param_1 + 0x178) == 1) {
      DVar4 = timeGetTime();
      if ((*(int **)(param_1 + 0x174))[0x29] <= (int)(DVar4 - *(int *)(param_1 + 0x17c))) {
        *(undefined4 *)(param_1 + 0x178) = 2;
        *(DWORD *)(param_1 + 0x180) = DVar4;
        puVar5 = (undefined4 *)
                 (**(code **)(**(int **)(param_1 + 0x174) + 0xbc))
                           (local_18,*(undefined4 *)(param_1 + 0x18c),1);
        *(undefined4 *)(param_1 + 0x184) = *puVar5;
        *(undefined4 *)(param_1 + 0x188) = puVar5[1];
      }
      goto LAB_005da062;
    }
    if (((*(int *)(param_1 + 0x178) != 3) ||
        (cVar3 = (**(code **)(**(int **)(param_1 + 0x18c) + 0x8c))(0x40000), cVar3 != '\0')) ||
       (DVar4 = timeGetTime(), DVar4 - *(int *)(param_1 + 0x17c) < 0x1389)) goto LAB_005da062;
    *(undefined4 *)(param_1 + 0x178) = 0;
  }
  (**(code **)(**(int **)(param_1 + 0x2c) + 0x170))(param_1 + 0x1a4);
LAB_005da062:
  iVar8 = *(int *)(param_1 + 0x18c);
  local_c = 1.0;
  local_2c = 0;
  local_24 = *(int *)(iVar8 + 0x88) - *(int *)(iVar8 + 0x80);
  local_30 = 0;
  local_28 = *(int *)(iVar8 + 0x84) - *(int *)(iVar8 + 0x7c);
  iVar6 = 0;
  iVar8 = 0;
  if ((*(int *)(param_1 + 0x178) == 2) &&
     (iVar6 = local_30, iVar8 = local_2c, *(int *)(param_1 + 0x174) != 0)) {
    local_30 = 0;
    local_2c = 0;
    DVar4 = timeGetTime();
    local_10 = DVar4 - *(int *)(param_1 + 0x180);
    local_14 = *(int *)(*(int *)(param_1 + 0x174) + 0xa8);
    if ((local_10 < local_14) && (local_14 != 0)) {
      local_c = (float)local_10 / (float)local_14;
      iVar6 = __ftol();
      iVar7 = *(int *)(param_1 + 0x188) + (local_24 - iVar6);
      iVar8 = local_2c + iVar7;
      local_24 = (local_24 - (local_24 - iVar6)) + iVar7;
      iVar6 = local_30 + *(int *)(param_1 + 0x184);
      local_28 = local_28 + *(int *)(param_1 + 0x184);
      if (0 < local_24 - iVar8) {
        local_5 = '\x01';
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x178) = 3;
      DVar4 = timeGetTime();
      *(DWORD *)(param_1 + 0x17c) = DVar4;
      iVar6 = local_30;
      iVar8 = local_2c;
    }
  }
  local_2c = iVar8;
  local_30 = iVar6;
  if (*(int *)(param_1 + 0x178) == 3) {
    local_30 = local_30 + *(int *)(param_1 + 0x184);
    local_28 = local_28 + *(int *)(param_1 + 0x184);
    local_2c = local_2c + *(int *)(param_1 + 0x188);
    local_24 = local_24 + *(int *)(param_1 + 0x188);
    local_5 = '\x01';
  }
  if (local_5 == '\0') {
    if (*(int **)(param_1 + 0x18c) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x18c) + 0x98))();
    }
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x18c) + 0x94))();
    FUN_004cb21d(local_30,local_2c);
    iVar8 = *(int *)(param_1 + 0x18c);
    *(undefined4 *)(param_1 + 400) = *(undefined4 *)(iVar8 + 0x7c);
    *(undefined4 *)(param_1 + 0x194) = *(undefined4 *)(iVar8 + 0x80);
    *(undefined4 *)(param_1 + 0x198) = *(undefined4 *)(iVar8 + 0x84);
    *(undefined4 *)(param_1 + 0x19c) = *(undefined4 *)(iVar8 + 0x88);
    iVar8 = *(int *)(param_1 + 0x2c);
    local_1c = 0;
    iVar6 = *(int *)(iVar8 + 0x88) - *(int *)(iVar8 + 0x80);
    iVar9 = *(int *)(iVar8 + 0x84) - *(int *)(iVar8 + 0x7c);
    iVar7 = 0;
    iVar8 = 0;
    if (local_30 < 0) {
      iVar7 = -local_30;
    }
    else if (iVar9 <= local_28) {
      iVar7 = (iVar9 - local_28) + -1;
    }
    if (local_2c < 0) {
      iVar8 = -local_2c;
    }
    else if (iVar6 <= local_24) {
      iVar8 = (iVar6 - local_24) + -1;
    }
    if ((iVar7 != 0) || (iVar8 != 0)) {
      local_30 = local_30 + iVar7;
      local_28 = local_28 + iVar7;
      local_2c = local_2c + iVar8;
      local_24 = local_24 + iVar8;
    }
    fVar2 = local_c;
    if (*(int *)(param_1 + 0x178) != 2) {
      fVar2 = 1.0;
    }
    (**(code **)(**(int **)(param_1 + 0x18c) + 0xc0))(&local_30,fVar2);
    local_1c = *(int *)(param_1 + 0x1a8);
    piVar1 = (int *)(param_1 + 0x1a4);
    local_14 = *(int *)(param_1 + 0x1b0);
    iVar8 = *piVar1;
    iVar6 = *(int *)(param_1 + 0x1ac);
    iVar7 = *(int *)(param_1 + 0x18c);
    *piVar1 = *(int *)(iVar7 + 0xc);
    *(undefined4 *)(param_1 + 0x1a8) = *(undefined4 *)(iVar7 + 0x10);
    iVar9 = *(int *)(iVar7 + 0x14);
    *(int *)(param_1 + 0x1ac) = iVar9;
    *(undefined4 *)(param_1 + 0x1b0) = *(undefined4 *)(iVar7 + 0x18);
    if ((((iVar8 != *piVar1) || (iVar6 != iVar9)) || (local_1c != *(int *)(param_1 + 0x1a8))) ||
       (local_14 != *(int *)(param_1 + 0x1b0))) {
      (**(code **)(**(int **)(param_1 + 0x2c) + 0x170))(piVar1);
    }
    *(undefined1 *)(param_1 + 0x1b4) = 1;
  }
  return local_5;
}

