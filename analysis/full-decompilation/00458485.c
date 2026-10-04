
void FUN_00458485(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int *piVar4;
  char cVar5;
  short sVar6;
  undefined4 uVar7;
  undefined2 *puVar8;
  byte bVar9;
  uint uVar10;
  undefined2 *puVar11;
  undefined1 *puVar12;
  ushort local_1c;
  ushort local_1a;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 *local_14;
  int local_10;
  short *local_c;
  undefined1 local_6 [2];
  
  piVar4 = param_1;
  iVar1 = param_1[2];
  iVar2 = param_1[1];
  param_1[0x10] = param_1[0x10] & 0xfffffff7U | 4;
  if (iVar1 == 0) {
    return;
  }
  local_c = (short *)FUN_0041f101();
  if (local_c == (short *)0x0) {
    return;
  }
  local_18 = 0;
  local_16 = 0;
  local_1c = (ushort)(*(char *)(local_10 + 8) != '\0');
  if (*param_1 == 1) {
    local_18 = (undefined2)param_1[6];
  }
  local_1a = (ushort)(*param_1 == 1);
  *(undefined2 *)(iVar2 + 0xae) = 0;
  bVar3 = true;
  if (((*(ushort *)(iVar1 + 0x5a) & 0x200) == 0) &&
     ((*(char *)(local_10 + 8) == '\0' || (*(short *)(iVar1 + 0x7c) < 1)))) {
    if ((((*(byte *)(local_c + 10) & 1) == 0) && (*(short *)(iVar2 + 0x5cc) != 0)) &&
       ((cVar5 = FUN_004074bc(), cVar5 == '\x01' || ((*(uint *)(local_c + 10) >> 5 & 1) == 0)))) {
      bVar3 = false;
      if ((*(short *)(iVar1 + 0xc0) == 4) || (*(short *)(iVar1 + 0xc0) == 7)) {
        local_14 = (undefined2 *)FUN_0042a8e3(*(undefined2 *)(iVar2 + 0x5ca));
        puVar12 = local_6;
        uVar7 = FUN_0043e2ff(puVar12);
        sVar6 = FUN_0041f662(0,uVar7,puVar12);
        if (0 < sVar6) {
          bVar3 = true;
        }
      }
    }
  }
  else {
    bVar3 = false;
  }
  if ((*(short *)(iVar2 + 0x600) == 0) || (0x11 < *(short *)(iVar2 + 0x600))) {
    if (((uint)(int)*(short *)(iVar2 + 0x60e) >> 1 & 1) != 0) {
      uVar10 = *(uint *)(local_c + 10) >> 10;
      goto LAB_004585f6;
    }
    if (((uint)(int)*(short *)(iVar2 + 0x60e) >> 2 & 1) != 0) {
      uVar10 = *(uint *)(local_c + 10) >> 9;
      goto LAB_004585f6;
    }
    bVar9 = (byte)(*(uint *)(local_c + 10) >> 6);
  }
  else {
    bVar9 = (byte)(*(uint *)(local_c + 10) >> 4);
  }
  uVar10 = (uint)(byte)~bVar9;
LAB_004585f6:
  if ((uVar10 & 1) == 0) {
    bVar3 = false;
  }
  cVar5 = '\0';
  if (bVar3) {
    if (param_2 != (int *)0x0) {
      *param_2 = (int)PTR_DAT_006c436c;
      FUN_0047653c(local_c);
    }
    local_14 = (undefined2 *)CONCAT22((short)((uint)local_c >> 0x10),*local_c);
    if (*local_c == 0) {
      cVar5 = '\x01';
    }
    else {
      puVar8 = local_14;
      if (*(int *)(local_10 + 0x1c) == 0) {
        *(int *)(local_10 + 0x1c) = iVar2;
        puVar11 = (undefined2 *)(local_10 + 10);
        puVar8 = (undefined2 *)(iVar2 + 0x3a);
        param_1 = (int *)0x8;
        do {
          *puVar11 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar11 = puVar11 + 1;
          param_1 = (int *)((int)param_1 + -1);
        } while (param_1 != (int *)0x0);
      }
      cVar5 = FUN_00474b22(*(undefined4 *)(*(int *)(iVar1 + 0x11c) + 0xc),
                           CONCAT22((short)((uint)puVar8 >> 0x10),*(undefined2 *)(iVar1 + 0xf0)),
                           local_14,&local_1c);
      if (DAT_006e50e4 != '\0') {
        *(undefined2 *)(iVar2 + 0xae) = 0;
        cVar5 = '\x01';
      }
    }
    if ((param_2 != (int *)0x0) && (*(short *)(iVar1 + 0x84) != *(short *)(iVar2 + 0x84))) {
      *(short *)(*(int *)(*param_2 + 8) + 0x52) = -*(short *)(*(int *)(*param_2 + 8) + 0x50);
    }
  }
  piVar4[0x10] = piVar4[0x10] & 0xfffffff7;
  if (cVar5 != '\0') {
    piVar4[0x10] = piVar4[0x10] | 8;
  }
  sVar6 = *(short *)(iVar2 + 0xae);
  piVar4[0x10] = piVar4[0x10] & 0xffffffef;
  if (sVar6 != 0) {
    piVar4[0x10] = piVar4[0x10] | 0x10;
  }
  return;
}

