
undefined4 __thiscall FUN_00425f45(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_2 + 0x10c);
  if ((iVar1 != 0) && (*(int *)(param_2 + 0x110) == 0)) {
    for (piVar2 = *(int **)(param_1 + 0x154); piVar2 != *(int **)(param_1 + 0x158);
        piVar2 = piVar2 + 1) {
      if (*piVar2 == param_2) {
        FUN_0042ec52(piVar2);
        if (param_2 != 0) {
          FUN_00410173();
          FUN_006321f0(param_2);
        }
        FUN_0040766a(0x103,iVar1);
        return 0;
      }
    }
  }
  return 0xffffffff;
}

