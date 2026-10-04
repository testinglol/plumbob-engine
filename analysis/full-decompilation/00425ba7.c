
uint __thiscall FUN_00425ba7(int param_1,short param_2,undefined2 param_3,undefined4 *param_4)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  iVar3 = FUN_0042573e((int)param_2);
  iVar6 = *(int *)(*DAT_006e486c + 0x14);
  puVar8 = param_4;
  if (param_4 == (undefined4 *)0x0) {
    puVar8 = (undefined4 *)&param_2;
  }
  *puVar8 = 0;
  if (iVar3 != 0) {
    switch(param_3) {
    case 0:
      piVar5 = *(int **)(iVar6 + 0x84);
      while( true ) {
        if (piVar5 == *(int **)(iVar6 + 0x88)) {
          return 0;
        }
        if ((*piVar5 != 0) && (*(int *)(*piVar5 + 0x11c) == *(int *)(iVar3 + 8))) break;
        piVar5 = piVar5 + 1;
      }
      if (*piVar5 == 0) {
        return 0;
      }
      return (int)*(short *)(*piVar5 + 0xf0);
    case 1:
      if (*(int *)(*DAT_006e486c + 0x10) != 0) {
        uVar4 = FUN_0045741b();
        bVar1 = FUN_00410285(uVar4);
        return (uint)bVar1;
      }
      break;
    case 2:
      return (uint)*(ushort *)(iVar3 + 0xe8);
    case 5:
      uVar7 = FUN_00427192(iVar3);
      return uVar7;
    case 6:
      for (piVar5 = *(int **)(param_1 + 0x154); piVar5 != *(int **)(param_1 + 0x158);
          piVar5 = piVar5 + 1) {
        uVar4 = FUN_00401f73();
        cVar2 = FUN_00410285(uVar4);
        if (cVar2 != '\0') {
          return (uint)*(ushort *)(*piVar5 + 0x110);
        }
      }
      break;
    case 7:
      if (*(short *)(iVar3 + 0xee) != 0) {
        for (piVar5 = *(int **)(param_1 + 0x154); piVar5 != *(int **)(param_1 + 0x158);
            piVar5 = piVar5 + 1) {
          if (*(int *)(*piVar5 + 0x10c) == (int)*(short *)(iVar3 + 0xee)) {
            iVar6 = *piVar5;
            goto code_r0x00425cdc;
          }
        }
        iVar6 = 0;
code_r0x00425cdc:
        if ((iVar6 != 0) && (*(int *)(iVar6 + 0x110) != 0)) {
          uVar7 = (uint)*(byte *)(iVar6 + 0x138);
code_r0x00425cf6:
          return uVar7 & 1;
        }
      }
      break;
    case 8:
      if (*(short *)(iVar3 + 0xee) != 0) {
        for (piVar5 = *(int **)(param_1 + 0x154); piVar5 != *(int **)(param_1 + 0x158);
            piVar5 = piVar5 + 1) {
          if (*(int *)(*piVar5 + 0x10c) == (int)*(short *)(iVar3 + 0xee)) {
            iVar6 = *piVar5;
            goto code_r0x00425d2e;
          }
        }
        iVar6 = 0;
code_r0x00425d2e:
        if ((iVar6 != 0) && (*(int *)(iVar6 + 0x110) != 0)) {
          uVar7 = *(uint *)(iVar6 + 0x138) >> 1;
          goto code_r0x00425cf6;
        }
      }
      break;
    case 9:
      if (*(short *)(iVar3 + 0xee) != 0) {
        for (piVar5 = *(int **)(param_1 + 0x154); piVar5 != *(int **)(param_1 + 0x158);
            piVar5 = piVar5 + 1) {
          if (*(int *)(*piVar5 + 0x10c) == (int)*(short *)(iVar3 + 0xee)) {
            iVar6 = *piVar5;
            goto code_r0x00425d74;
          }
        }
        iVar6 = 0;
code_r0x00425d74:
        if (iVar6 != 0) {
          uVar7 = FUN_004102f3();
          return uVar7;
        }
      }
    }
  }
  return 0;
}

