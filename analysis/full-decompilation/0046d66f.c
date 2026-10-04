
uint __fastcall FUN_0046d66f(int param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  bool bVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  if ((*(short *)(param_1 + 0x32) == 0) &&
     ((*(short *)(param_1 + 0x36) == 0 || (*(short *)(param_1 + 0x24) == 0)))) {
    bVar6 = false;
  }
  else {
    bVar6 = true;
  }
  iVar2 = *(int *)(param_1 + 0xb0);
  iVar3 = *(int *)(iVar2 + 0x1c);
  iVar4 = *(int *)(iVar2 + 0x18);
  if (*(int *)(param_1 + 0x1a8) == 0) {
    *(undefined4 *)(param_1 + 0x1a8) = 1;
  }
  iVar8 = *(int *)(param_1 + 0x1a8);
  do {
    if ((iVar3 - iVar4 >> 2) + 1 <= iVar8) {
      *(undefined4 *)(param_1 + 0x1a8) = 0;
      return (uint)!bVar6;
    }
    iVar8 = *(int *)(param_1 + 0x1a8) * 4;
    piVar5 = *(int **)(*(int *)(iVar2 + 0x18) + -4 + iVar8);
    if (piVar5 != (int *)0x0) {
      if ((*(uint *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x24) + -4 + iVar8) >> 0x12 & 1) != 0) {
        sVar7 = FUN_0047471f();
        if (sVar7 == 0) {
          FUN_0044582f(*(undefined4 *)(param_1 + 0x1a8),4,0);
          goto LAB_0046d722;
        }
LAB_0046d7a8:
        uVar10 = FUN_00439b54();
LAB_0046d7af:
        return uVar10 & 0xffffff00;
      }
LAB_0046d722:
      iVar8 = *(int *)(param_1 + 0x1a8);
      iVar9 = *(int *)(*(int *)(param_1 + 0xb0) + 0x24);
      puVar1 = (uint *)(iVar9 + -4 + iVar8 * 4);
      if (((*(uint *)(iVar9 + -4 + iVar8 * 4) >> 0x10 & 1) != 0) &&
         ((!bVar6 || ((*puVar1 >> 0x11 & 1) != 0)))) {
        iVar9 = (int)(short)*puVar1;
        if (iVar9 < 1) {
          uVar10 = (**(code **)(*piVar5 + 0x14))(*(undefined4 *)(param_1 + 0x98));
          if ((char)uVar10 == '\0') goto LAB_0046d7af;
          sVar7 = FUN_0047471f();
          if (sVar7 != 0) goto LAB_0046d7a8;
        }
        else {
          FUN_00431e78(iVar8,iVar9 + -1);
        }
      }
    }
    *(int *)(param_1 + 0x1a8) = *(int *)(param_1 + 0x1a8) + 1;
    iVar8 = *(int *)(param_1 + 0x1a8);
  } while( true );
}

