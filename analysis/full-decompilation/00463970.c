
uint FUN_00463970(int param_1)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = 1;
  piVar2 = *(int **)(param_1 + 0x84);
LAB_0046398f:
  do {
    if (piVar2 == *(int **)(param_1 + 0x88)) {
      piVar2 = *(int **)(param_1 + 0x90);
      while( true ) {
        if (piVar2 == *(int **)(param_1 + 0x94)) {
          return uVar1;
        }
        if (*(short *)(*piVar2 + 0x56) == (short)uVar1) break;
        piVar2 = piVar2 + 1;
      }
    }
    else if (*(short *)(*piVar2 + 0x56) != (short)uVar1) {
      piVar2 = piVar2 + 1;
      goto LAB_0046398f;
    }
    uVar1 = uVar1 + 1;
    piVar2 = *(int **)(param_1 + 0x84);
    if (9999 < (short)uVar1) {
      return uVar1 & 0xffff0000;
    }
  } while( true );
}

