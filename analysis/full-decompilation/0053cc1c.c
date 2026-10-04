
void __fastcall FUN_0053cc1c(int param_1)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  byte bVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  int *local_14;
  char local_10 [11];
  undefined1 local_5;
  
  local_10[4] = 0;
  local_10[5] = 0;
  local_10[6] = 0;
  *(undefined1 *)(param_1 + 9) = 0;
  local_10[7] = 0;
  local_10[0] = '\0';
  local_10[1] = 0;
  local_10[2] = 0;
  local_10[3] = 0;
  *(undefined1 *)(param_1 + 10) = *(undefined1 *)(param_1 + 8);
  *(undefined1 *)(param_1 + 0xb) = 0;
  *(undefined1 *)(param_1 + 0xc) = 0;
  local_14 = (int *)(param_1 + 0x10);
  iVar7 = 0;
  piVar10 = local_14;
  do {
    iVar1 = *piVar10;
    if (iVar1 != 0) {
      if (param_1 == *(int *)(iVar1 + 0x20)) {
        pbVar5 = *(byte **)(iVar1 + 0x30);
      }
      else {
        pbVar5 = (byte *)(*(int *)(iVar1 + 0x34) + -6);
      }
      bVar4 = pbVar5[1];
      local_10[iVar7 + 4] = *pbVar5 & 1;
      if ((((bVar4 == 0xff) || (bVar4 == 2)) || (bVar4 == 0xc)) ||
         ((bVar4 == 0xd || (bVar4 == 0xe)))) {
        cVar3 = '\0';
      }
      else {
        cVar3 = '\x01';
      }
      local_10[iVar7] = cVar3;
    }
    iVar7 = iVar7 + 1;
    piVar10 = piVar10 + 1;
  } while (iVar7 < 4);
  uVar11 = 1;
  do {
    if (local_10[uVar11 + 3] != '\0') {
      pbVar5 = (byte *)FUN_0053cd94(&local_5,param_1);
      bVar4 = *pbVar5;
      uVar6 = uVar11 & 3;
      uVar8 = uVar11 + 1 & 3;
      uVar9 = uVar11 - 2 & 3;
      if (((((*(int *)(param_1 + 0x10 + uVar6 * 4) == 0) || (local_10[uVar6 + 4] != '\0')) ||
           (local_10[uVar6] == '\0')) &&
          (((*(int *)(param_1 + 0x10 + uVar8 * 4) == 0 || (local_10[uVar8 + 4] != '\0')) ||
           (local_10[uVar8] == '\0')))) &&
         (((*(int *)(param_1 + 0x10 + uVar9 * 4) == 0 || (local_10[uVar9 + 4] != '\0')) ||
          (local_10[uVar9] == '\0')))) {
        if ((*(byte *)(param_1 + 10) & bVar4) != 0) {
          *(byte *)(param_1 + 9) = *(byte *)(param_1 + 9) | bVar4;
          *(byte *)(param_1 + 10) = *(byte *)(param_1 + 10) & ~bVar4;
        }
      }
      else {
        iVar7 = *local_14;
        if (param_1 == *(int *)(iVar7 + 0x20)) {
          pbVar5 = *(byte **)(iVar7 + 0x30);
        }
        else {
          pbVar5 = (byte *)(*(int *)(iVar7 + 0x34) + -6);
        }
        bVar4 = *pbVar5;
        if ((bVar4 & 6) == 0) {
          if ((uVar11 == 1) || (uVar11 == 4)) {
            if ((bVar4 & 1) == 0) goto LAB_0053cd5b;
LAB_0053cd67:
            if ((bVar4 & 4) != 0) goto LAB_0053cd7e;
            bVar4 = bVar4 | 2;
          }
          else {
            if ((bVar4 & 1) == 0) goto LAB_0053cd67;
LAB_0053cd5b:
            if ((bVar4 & 2) != 0) goto LAB_0053cd7e;
            bVar4 = bVar4 | 4;
          }
          *pbVar5 = bVar4;
        }
      }
    }
LAB_0053cd7e:
    local_14 = local_14 + 1;
    bVar2 = 3 < (int)uVar11;
    uVar11 = uVar11 + 1;
    if (bVar2) {
      return;
    }
  } while( true );
}

