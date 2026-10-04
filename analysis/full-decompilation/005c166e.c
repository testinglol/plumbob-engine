
undefined4 __thiscall FUN_005c166e(int param_1,char *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  bool bVar3;
  int *piVar4;
  undefined1 uVar5;
  int iVar6;
  size_t sVar7;
  char cVar8;
  int iVar9;
  char local_18 [12];
  int *local_c;
  undefined4 local_8;
  
  iVar9 = 0;
  local_8 = 0x80000000;
  if (*param_2 == '_') {
    iVar9 = 1;
    iVar6 = 0;
    cVar8 = param_2[1];
    while (cVar8 != '_') {
      local_18[iVar6] = cVar8;
      iVar2 = iVar9 + 1;
      iVar6 = iVar6 + 1;
      iVar9 = iVar9 + 1;
      cVar8 = param_2[iVar2];
    }
    local_18[iVar6] = '\0';
    iVar9 = iVar9 + 1;
    local_8 = FUN_00635f62(local_18);
  }
  bVar3 = false;
  local_c = (int *)(param_1 + 0xc);
  FUN_005d4bbf(param_2 + iVar9);
  sVar7 = _strlen(param_2);
  piVar4 = (int *)(param_1 + 0xc);
  while (sVar7 = sVar7 - 1, iVar9 <= (int)sVar7) {
    puVar1 = (undefined1 *)((sVar7 - iVar9) + *piVar4);
    cVar8 = *(char *)((sVar7 - iVar9) + *piVar4);
    if ((cVar8 != '.') || (bVar3)) {
      uVar5 = FUN_0063813a((int)cVar8);
      *puVar1 = uVar5;
      piVar4 = local_c;
    }
    else {
      *puVar1 = 0;
      bVar3 = true;
      piVar4 = local_c;
    }
  }
  return local_8;
}

