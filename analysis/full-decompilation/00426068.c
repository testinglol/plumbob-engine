
undefined4 __thiscall FUN_00426068(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (*(short *)(param_2 + 0xee) != 0) {
    for (piVar1 = *(int **)(param_1 + 0x154); piVar1 != *(int **)(param_1 + 0x158);
        piVar1 = piVar1 + 1) {
      if (*(int *)(*piVar1 + 0x10c) == (int)*(short *)(param_2 + 0xee)) {
        iVar4 = *piVar1;
        goto LAB_004260a6;
      }
    }
    iVar4 = 0;
LAB_004260a6:
    if (iVar4 != 0) {
      uVar2 = FUN_00401f73();
      iVar3 = FUN_00410263(uVar2);
      if (iVar3 != 0) {
        uVar2 = FUN_00401f73();
        iVar3 = FUN_0044097d(uVar2);
        if (iVar3 != 0) {
          *(undefined2 *)(iVar3 + 0x606) = 0;
        }
        *(undefined2 *)(param_2 + 0xee) = 0;
        uVar2 = FUN_00401f73();
        FUN_00410917(uVar2);
        FUN_0042a2fe();
        *(uint *)(iVar4 + 0x138) = *(uint *)(iVar4 + 0x138) & 0xfffffff7;
        *(undefined1 *)(iVar4 + 0x124) = 1;
        FUN_0040766a(0xe8,0);
        return 0;
      }
    }
  }
  return 0xffffffff;
}

