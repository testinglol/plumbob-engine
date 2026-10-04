
int __fastcall FUN_0043e2dc(int param_1)

{
  int *piVar1;
  uint3 uVar2;
  
  piVar1 = *(int **)(param_1 + 0x1244);
  while( true ) {
    uVar2 = (uint3)((uint)piVar1 >> 8);
    if (piVar1 == *(int **)(param_1 + 0x1248)) {
      return (uint)uVar2 << 8;
    }
    if (*(int *)(*piVar1 + 0x14) != 2) break;
    piVar1 = piVar1 + 1;
  }
  return CONCAT31(uVar2,1);
}

