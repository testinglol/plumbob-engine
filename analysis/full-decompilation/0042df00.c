
uint FUN_0042df00(short *param_1,int *param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = *(int **)(*(int *)(*DAT_006e486c + 0x14) + 0x84);
  piVar4 = *(int **)(*(int *)(*DAT_006e486c + 0x14) + 0x88);
  do {
    if (piVar5 == piVar4) {
LAB_0042df8f:
      return (uint)piVar4 & 0xffffff00;
    }
    if ((*piVar5 != 0) && (*(short *)(*piVar5 + 0xf0) == *param_1)) {
      if (*piVar5 != 0) {
        uVar2 = FUN_004257ba(*(undefined4 *)(*piVar5 + 0x11c));
        iVar3 = FUN_0042e158(uVar2,0,0x1b);
        if (iVar3 != 0) {
          *param_1 = 0;
          iVar3 = FUN_0044097d(*(undefined4 *)(iVar3 + 4));
          uVar1 = *(undefined2 *)(iVar3 + 0xf0);
          *(undefined2 *)param_2 = uVar1;
          return CONCAT31((int3)(CONCAT22((short)((uint)iVar3 >> 0x10),uVar1) >> 8),1);
        }
        *(undefined2 *)param_2 = 0;
        piVar4 = param_2;
      }
      goto LAB_0042df8f;
    }
    piVar5 = piVar5 + 1;
  } while( true );
}

