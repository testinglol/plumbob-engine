
undefined4 __fastcall FUN_005d3cf8(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (((byte)*(undefined4 *)(param_1 + 0x14) & 1) == 1) {
LAB_005d3d06:
    uVar2 = 1;
  }
  else {
    for (piVar3 = *(int **)(param_1 + 0x5c); piVar3 != *(int **)(param_1 + 0x60);
        piVar3 = piVar3 + 1) {
      cVar1 = (**(code **)(*(int *)*piVar3 + 0x1c))();
      if ((cVar1 != '\0') || ((*(uint *)(*piVar3 + 0x14) >> 1 & 1) != 0)) {
        *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 1;
        goto LAB_005d3d06;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}

