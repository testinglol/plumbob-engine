
int __thiscall FUN_004ba5c5(int param_1,uint *param_2,undefined4 *param_3)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  char *pcVar4;
  bool bVar5;
  uint3 uVar8;
  int iVar6;
  uint uVar7;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  uint *puVar12;
  
  *param_3 = param_2;
  uVar8 = (uint3)((uint)param_3 >> 8);
  if (*(char *)(param_1 + 0x14) == '\0') {
    iVar6 = (uint)uVar8 << 8;
    bVar5 = false;
    puVar12 = param_2;
LAB_004ba5e8:
    while( true ) {
      while( true ) {
        pcVar4 = *(char **)(param_1 + 8);
        cVar2 = *pcVar4;
        bVar3 = pcVar4[1];
        uVar9 = (uint)bVar3;
        pcVar11 = pcVar4 + 2;
        *(char **)(param_1 + 8) = pcVar11;
        if (cVar2 != '\x01') break;
        puVar12 = (uint *)((int)puVar12 + uVar9);
        param_2 = puVar12;
      }
      if (cVar2 != '\x02') break;
      cVar2 = *pcVar11;
      uVar7 = CONCAT31((int3)((uint)iVar6 >> 8),cVar2);
      *(char **)(param_1 + 8) = pcVar4 + 4;
      if (uVar9 != 0) {
        uVar7 = CONCAT22(CONCAT11(cVar2,cVar2),CONCAT11(cVar2,cVar2));
        for (uVar10 = (uint)(bVar3 >> 2); uVar10 != 0; uVar10 = uVar10 - 1) {
          *puVar12 = uVar7;
          puVar12 = puVar12 + 1;
        }
        for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
          *(char *)puVar12 = cVar2;
          puVar12 = (uint *)((int)puVar12 + 1);
        }
        puVar12 = (uint *)((int)param_2 + uVar9);
        param_2 = puVar12;
      }
LAB_004ba690:
      iVar6 = CONCAT31((int3)(uVar7 >> 8),1);
    }
    if (cVar2 == '\x03') {
      if (3 < uVar9) {
        uVar7 = (uint)(bVar3 >> 2);
        do {
          uVar9 = uVar9 - 4;
          *puVar12 = **(uint **)(param_1 + 8);
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 4;
          puVar12 = puVar12 + 1;
          uVar7 = uVar7 - 1;
          param_2 = puVar12;
        } while (uVar7 != 0);
      }
      if (uVar9 == 1) {
LAB_004ba679:
        *(char *)puVar12 = **(char **)(param_1 + 8);
        puVar12 = (uint *)((int)puVar12 + 1);
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
        param_2 = puVar12;
      }
      else {
        if (uVar9 == 2) {
LAB_004ba66e:
          *(char *)puVar12 = **(char **)(param_1 + 8);
          puVar12 = (uint *)((int)puVar12 + 1);
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
          goto LAB_004ba679;
        }
        if (uVar9 == 3) {
          *(char *)puVar12 = **(char **)(param_1 + 8);
          puVar12 = (uint *)((int)puVar12 + 1);
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
          goto LAB_004ba66e;
        }
      }
      uVar7 = *(int *)(param_1 + 8) + 1U & 0xfffffffe;
      *(uint *)(param_1 + 8) = uVar7;
      goto LAB_004ba690;
    }
    if (cVar2 == '\x04') {
      if (bVar5) goto LAB_004ba708;
      if (((uVar9 == 2) && (*pcVar11 == '\x05')) && (pcVar4[3] == -1)) {
        *(char **)(param_1 + 8) = pcVar4 + 6;
      }
      bVar5 = true;
      goto LAB_004ba5e8;
    }
    if (cVar2 == '\x05') {
      *(undefined1 *)(param_1 + 0x14) = 1;
      return iVar6;
    }
    if (cVar2 != '\t') {
      return iVar6;
    }
    if (*(int *)(param_1 + 0xc) == 0) {
      if (bVar5) {
        *(uint *)(param_1 + 0xc) = uVar9;
        *(char **)(param_1 + 8) = pcVar4;
        return iVar6;
      }
      *(uint *)(param_1 + 0xc) = uVar9;
    }
    piVar1 = (int *)(param_1 + 0xc);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    if (*(int *)(param_1 + 0xc) == 0) {
      return iVar6;
    }
LAB_004ba708:
    *(char **)(param_1 + 8) = pcVar4;
  }
  else {
    iVar6 = (uint)uVar8 << 8;
  }
  return iVar6;
}

