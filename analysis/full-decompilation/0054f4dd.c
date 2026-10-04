
int __fastcall FUN_0054f4dd(int param_1)

{
  int *piVar1;
  uint3 uVar2;
  int *piVar3;
  
  piVar1 = (int *)FUN_00425e2d();
  piVar3 = (int *)*piVar1;
  piVar1 = (int *)piVar1[1];
  uVar2 = (uint3)((uint)piVar1 >> 8);
  if (piVar3 != piVar1) {
    do {
      if ((*(int *)(*piVar3 + 0x110) == *(int *)(param_1 + 0x1d8)) ||
         (*(int *)(*piVar3 + 0x13c) == *(int *)(param_1 + 0x1d8))) {
        return CONCAT31(uVar2,1);
      }
      piVar3 = piVar3 + 1;
    } while (piVar3 != piVar1);
  }
  return (uint)uVar2 << 8;
}

